#ifndef ONESEARCHINFO_H
#define ONESEARCHINFO_H

#include<string>
#include "global.h"

class oneSearchInfo{
public:
    oneSearchInfo(QString miR_index, QString miR_name, QString miR_seq, QString rep_miRIDl,
                  QString miRbase_seq, QString type, QString CG, QString dG, std::vector<QString> sum1_raw,
                  std::vector<QString> sum2_raw, std::vector<QString> spr1_raw, std::vector<QString> spr3_raw,
                  std::vector<QString> sum1_norm, std::vector<QString> sum2_norm, std::vector<QString> spr1_norm,
                  std::vector<QString> spr3_norm, QString expression_level)
    {
        this->miR_index = miR_index;
        this->miR_name = miR_name;
        this->miR_seq = miR_seq;
        this->rep_miRIDl = rep_miRIDl;
        this->miRbase_seq = miRbase_seq;
        this->type = type;
        this->CG = CG;
        this->dG = dG;
        this->sum1_raw = sum1_raw;
        this->sum2_raw = sum2_raw;
        this->spr1_raw = spr1_raw;
        this->spr3_raw = spr3_raw;
        this->sum1_norm = sum1_norm;
        this->sum2_norm = sum2_norm;
        this->spr1_norm = spr1_norm;
        this->spr3_norm = spr3_norm;
        this->expression_level = expression_level;
    }

    QString miR_index;
    QString miR_name;
    QString miR_seq;
    QString rep_miRIDl;
    QString miRbase_seq;
    QString type;
    QString CG;
    QString dG;
    std::vector<QString> sum1_raw;
    std::vector<QString> sum2_raw;
    std::vector<QString> spr1_raw;
    std::vector<QString> spr3_raw;
    std::vector<QString> sum1_norm;
    std::vector<QString> sum2_norm;
    std::vector<QString> spr1_norm;
    std::vector<QString> spr3_norm;
    QString expression_level;
};

#endif // ONESEARCHINFO_H
