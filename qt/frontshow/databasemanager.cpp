#include "databasemanager.h"

QSqlDatabase DataBaseManager::db = QSqlDatabase::addDatabase("QODBC");

DataBaseManager::DataBaseManager()
{
    // 通过ODBC连接数据库
//    db = QSqlDatabase::addDatabase("QODBC");
}

// mode为0，表示按照mir_name进行检索，mode为1，表示按照mir_seq进行检索
bool DataBaseManager::searchAllInfo(QString mir_name_seq, std::vector<oneSearchInfo> &resultInfos, int mode)
{
    bool find = false;
    // 从数据库中查询景点信息
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT * FROM thl_database.all_expressed_mirna WHERE miR_name LIKE '%" + mir_name_seq + "%'");//查询语法
    strSqlText = mode == 0 ? "SELECT * FROM thl_database.all_expressed_mirna WHERE miR_name LIKE '%" + mir_name_seq + "%'" :
                             "SELECT * FROM thl_database.all_expressed_mirna WHERE miR_seq LIKE '%" + mir_name_seq + "%'";
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    while (qsQuery.next()) //依次取出查询结果的每一条记录，直至结束
    {
        std::vector<QString> sum1_raw;
        std::vector<QString> sum2_raw;
        std::vector<QString> spr1_raw;
        std::vector<QString> spr3_raw;
        std::vector<QString> sum1_norm;
        std::vector<QString> sum2_norm;
        std::vector<QString> spr1_norm;
        std::vector<QString> spr3_norm;
        for (int i = 8; i <= 12; i++)
        {
            sum1_raw.push_back(qsQuery.value(i).toString());
            sum2_raw.push_back(qsQuery.value(i + 5).toString());
            spr1_raw.push_back(qsQuery.value(i + 10).toString());
            spr3_raw.push_back(qsQuery.value(i + 15).toString());
            sum1_norm.push_back(qsQuery.value(i + 20).toString());
            sum2_norm.push_back(qsQuery.value(i + 25).toString());
            spr1_norm.push_back(qsQuery.value(i + 30).toString());
            spr3_norm.push_back(qsQuery.value(i + 35).toString());
        }
        oneSearchInfo temp(qsQuery.value(0).toString(), qsQuery.value(1).toString(), qsQuery.value(2).toString(),
                           qsQuery.value(3).toString(), qsQuery.value(4).toString(), qsQuery.value(5).toString(),
                           qsQuery.value(6).toString(), qsQuery.value(7).toString(), sum1_raw, sum2_raw,
                           spr1_raw, spr3_raw, sum1_norm, sum2_norm, spr1_norm, spr3_norm, qsQuery.value(48).toString());
        resultInfos.push_back(temp);
        find = true;
    }
    return find ? true : false;
}

bool DataBaseManager::registerUserInfo(QString userid, QString phoneNumber, QString password, QString realName, QString email)
{
    // 判断id是否存在
//    select 1 from user where id = xxx limit 1；
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT 1 FROM thl_database.register_info WHERE user_id = '" + userid + "' LIMIT 1");//查询语法
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    if (qsQuery.next())
    {
//        QMessageBox::information(nullptr, "Warning", "User id exist");
        return false;
    }

    QString info = QString("INSERT INTO thl_database.register_info (user_id, phone_number, password, real_name, email) "
                 "VALUES ('%1', '%2', '%3', '%4', '%5')").arg(userid).arg(phoneNumber).arg(password).arg(realName).arg(email);

    qDebug() << info << endl;
    qsQuery.prepare(info);
    if (qsQuery.exec())
        qDebug() << "s" << endl;
    else
        qDebug() << "f" << endl;

    return true;
}

bool DataBaseManager::init()
{
    db.setHostName("rm-j6c1pi4d3j4u787x3mo.mysql.rds.aliyuncs.com");
    db.setPort(3306);
    db.setDatabaseName("mirnadatabase");
    db.setUserName("thl_admin");
    db.setPassword("Ll5028852");
    bool ok = db.open();
    if (ok)
    {
        qDebug() << "open databases" << endl;
        return true;
    }
    else
    {
        qDebug() << "Wrong" << endl;
        return false;
    }
}

bool DataBaseManager::countLens(std::map<int, int> &lens)
{
    QTime time;
    time.start();
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT miR_seq FROM thl_database.all_expressed_mirna");     //查询语法
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    while (qsQuery.next())
    {
        lens[qsQuery.value(0).toString().length()]++;
    }

    qDebug() << "miRNA长度查询结束，用时" << time.elapsed() << "ms" << endl;

    return true;
}

bool DataBaseManager::getSummary(std::map<int, int> &lens, std::map<int, int> &type, std::map<int, int> &level)
{
    QTime time;
    time.start();
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT miR_seq, type, expression_level FROM thl_database.all_expressed_mirna");     //查询语法
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    while (qsQuery.next())
    {
        lens[qsQuery.value(0).toString().length()]++;
        type[qsQuery.value(1).toString().compare("3'") == 0 ? 0 : 1]++;
        if (qsQuery.value(2).toString().compare("low")) level[0]++;
        else if (qsQuery.value(2).toString().compare("middle")) level[1]++;
        else level[2]++;
    }

    qDebug() << "查询结束，用时" << time.elapsed() << "ms" << endl;

    return true;
}


