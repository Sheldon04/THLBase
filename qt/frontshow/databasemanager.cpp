#include "databasemanager.h"

QSqlDatabase DataBaseManager::db = QSqlDatabase::addDatabase("QODBC");
DataBaseManager * DataBaseManager::instance = nullptr;

//const QString DataBaseManager::itemNames[50] = {

//}

DataBaseManager::DataBaseManager() : QObject(nullptr)
{

}

// mode为0，表示按照mir_name进行检索，mode为1，表示按照mir_seq进行检索
QString DataBaseManager::searchAllInfo(QString mir_name_seq, std::vector<oneSearchInfo> &resultInfos, int mode)
{
    QTime time;
    QString info;
    time.start();
    bool find = false;
    int cnt = 0;
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
        cnt++;
    }
    if (find)
        info = QString("Search success, find %1 records, cost %2 ms").arg(cnt).arg(time.elapsed());
    else
        info = "No such record";
    return info;
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

int DataBaseManager::insertData(const std::vector<std::vector<QString> > &data)
{
    QTime time;
    time.start();
    for (auto record : data)
    {
        QSqlQuery query;
        QString sql = "INSERT INTO thl_database.all_expressed_mirna (`miR_name`, `miR_seq`, `rep_miRID`, `miRbase_seq`, "
                      "`type`, `CG`, `dG`, "
                      "`Sum11(raw)`, `Sum12(raw)`, `Sum13(raw)`, `Sum14(raw)`, `Sum15(raw)`, `Sum21(raw)`, `Sum22(raw)`, `Sum23(raw)`, `Sum24(raw)`, `Sum25(raw)`,"
                      "`Spr11(raw)`, `Spr12(raw)`, `Spr13(raw)`, `Spr14(raw)`, `Spr15(raw)`, `Spr31(raw)`, `Spr32(raw)`, `Spr33(raw)`, `Spr34(raw)`, `Spr35(raw)`,"
                      "`Sum11(norm)`, `Sum12(norm)`, `Sum13(norm)`, `Sum14(norm)`, `Sum15(norm)`, `Sum21(norm)`, `Sum22(norm)`, `Sum23(norm)`, `Sum24(norm)`, `Sum25(norm)`,"
                      "`Spr11(norm)`, `Spr12(norm)`, `Spr13(norm)`, `Spr14(norm)`, `Spr15(norm)`, `Spr31(norm)`, `Spr32(norm)`, `Spr33(norm)`, `Spr34(norm)`, `Spr35(norm)`,"
                      "`expression_level`) VALUES (";
        for (auto item : record)
        {
            sql.append("'" + item + "', ");
        }
        sql = sql.left(sql.length() - 2);
        sql.append(")");
        query.prepare(sql);
        qDebug() << sql << endl;
        if(!query.exec()) qDebug() << "fail" << endl;
    }
    return time.elapsed();
}

int DataBaseManager::modifyData(const std::map<QString, std::map<QString, QString> > &mData)
{
    QTime time;
    time.start();
    for(auto changeItem : mData)
    {
        QSqlQuery query;
        QString sql = "UPDATE thl_database.all_expressed_mirna SET ";
        for(auto item : changeItem.second)
        {
            QString temp;
            temp = QString("`%1` = '%2', ").arg(item.first).arg(item.second);
            if (item.first.compare("type == 0"))
                temp.insert(temp.length() - 4, "\\");
            sql.append(temp);
        }
        sql = sql.left(sql.length() - 2);
        sql.append(" WHERE (`miR_index` = " + changeItem.first + ")");
        query.prepare(sql);
        qDebug() << sql << endl;
        if(!query.exec()) qDebug() << "fail" << endl;
        else qDebug() << "Success" << endl;
    }
    return time.elapsed();
}

int DataBaseManager::deleteRecords(const std::vector<QString> &dItemNames)
{
    QTime time;
    QSqlQuery query;
    time.start();
    QString sql = "DELETE FROM thl_database.all_expressed_mirna WHERE ";
    for (auto name : dItemNames)
    {
        sql.append(QString("`miR_index` = %1 or ").arg(name));
    }
    sql = sql.left(sql.length() - 4);
    query.prepare(sql);
    qDebug() << sql << endl;
    if(!query.exec()) qDebug() << "fail" << endl;
    else qDebug() << "Success" << endl;
    return time.elapsed();
}

bool DataBaseManager::searchDiffExpInfo(QString mir_name_seq, std::vector<DiffExpInfoItem> &ret, int mode)
{
    QTime time;
    time.start();
    bool find = false;
    int cnt = 0;
    // 从数据库中查询景点信息
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT * FROM thl_database.all_expressed_mirna WHERE miR_name LIKE '%" + mir_name_seq + "%'");//查询语法
    strSqlText = mode == 0 ? "SELECT * FROM thl_database.sum1_sum2_spr1_spr3 WHERE miR_name LIKE '%" + mir_name_seq + "%'" :
                             "SELECT * FROM thl_database.sum1_sum2_spr1_spr3 WHERE miR_seq LIKE '%" + mir_name_seq + "%'";
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    while (qsQuery.next()) //依次取出查询结果的每一条记录，直至结束
    {
        DiffExpInfoItem temp(qsQuery.value(0).toString(), qsQuery.value(1).toString(), qsQuery.value(2).toString(), qsQuery.value(3).toString());
        ret.push_back(temp);
        find = true;
        cnt++;
    }

    return true;
}

bool DataBaseManager::getPassword(QString id, QString &password)
{
    bool find = false;
    // 从数据库中查询景点信息
    QSqlQuery qsQuery = QSqlQuery(db);
    QString strSqlText;//查询语法
    strSqlText = "SELECT * FROM thl_database.register_info WHERE account_name = '" + id + "'";
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    if (qsQuery.next()) //依次取出查询结果的每一条记录，直至结束
    {
        password = qsQuery.value(2).toString();
        find = true;
    }

    return find;
}
