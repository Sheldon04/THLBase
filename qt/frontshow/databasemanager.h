#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QObject>
#include "global.h"
#include "oneSearchInfo.h"

class DataBaseManager : public QObject
{
Q_OBJECT

public:
    DataBaseManager();

    ~DataBaseManager() {

    }

    static QSqlDatabase db;                    // 用于数据库操作

public:
    static QString searchAllInfo(QString mir_name_seq, std::vector<oneSearchInfo> &resultInfos, int mode);

    static bool registerUserInfo(QString userid, QString phoneNumber, QString password, QString realName, QString email);

    static bool init();

    static bool countLens(std::map<int, int> &lens);

    static bool getSummary(std::map<int, int> &lens, std::map<int, int> &type, std::map<int, int> &level);

    static int insertData(const std::vector<std::vector<QString> > &data);

    static int modifyData(const std::map<QString, std::map<QString, QString> > &mData);

    static int deleteRecords(const std::vector<QString> &dItemNames);

    static DataBaseManager* getInstance()
    {
        if(instance == NULL)
            instance = new DataBaseManager();
        return instance;
    }

private:
    static DataBaseManager *instance;

signals:
    void updateInfo(QString info);

    //    static const QString itemNames[50];
};

#endif // DATABASEMANAGER_H
