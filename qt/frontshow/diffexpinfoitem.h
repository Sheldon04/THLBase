#ifndef DIFFEXPINFOITEM_H
#define DIFFEXPINFOITEM_H

#include "global.h"

class DiffExpInfoItem
{
public:
    DiffExpInfoItem(QString id, QString mir_name, QString mir_seq, QString p_value)
    {
        this->id = id;
        this->mir_seq = mir_seq;
        this->mir_name = mir_name;
        this->p_value = p_value;
    }

private:
    QString id;
    QString mir_name;
    QString mir_seq;
    QString p_value;
};

#endif // DIFFEXPINFOITEM_H
