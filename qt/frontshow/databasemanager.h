#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "global.h"
#include "oneSearchInfo.h"

class DataBaseManager
{
public:
    DataBaseManager();

    static QSqlDatabase db;                    // 用于数据库操作

public:
    static bool searchAllInfo(QString mir_name_seq, std::vector<oneSearchInfo> &resultInfos, int mode);

    static bool registerUserInfo(QString userid, QString phoneNumber, QString password, QString realName, QString email);

    static bool init();
};

#endif // DATABASEMANAGER_H
