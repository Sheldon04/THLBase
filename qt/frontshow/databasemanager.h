#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
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

    static bool countLens(std::map<int, int> &lens);

    static bool getSummary(std::map<int, int> &lens, std::map<int, int> &type, std::map<int, int> &level);
};

#endif // DATABASEMANAGER_H
