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

    oneSearchInfo(const oneSearchInfo & info)
    {
        this->miR_index = info.miR_index;
        this->miR_name = info.miR_name;
        this->miR_seq = info.miR_seq;
        this->rep_miRIDl = info.rep_miRIDl;
        this->miRbase_seq = info.miRbase_seq;
        this->type = info.type;
        this->CG = info.CG;
        this->dG = info.dG;
        this->sum1_raw = info.sum1_raw;
        this->sum2_raw = info.sum2_raw;
        this->spr1_raw = info.spr1_raw;
        this->spr3_raw = info.spr3_raw;
        this->sum1_norm = info.sum1_norm;
        this->sum2_norm = info.sum2_norm;
        this->spr1_norm = info.spr1_norm;
        this->spr3_norm = info.spr3_norm;
        this->expression_level = info.expression_level;
    }

    oneSearchInfo & operator=(const oneSearchInfo & info)
    {
        if (this == &info)
            return *this;
        this->miR_index = info.miR_index;
        this->miR_name = info.miR_name;
        this->miR_seq = info.miR_seq;
        this->rep_miRIDl = info.rep_miRIDl;
        this->miRbase_seq = info.miRbase_seq;
        this->type = info.type;
        this->CG = info.CG;
        this->dG = info.dG;
        this->sum1_raw = info.sum1_raw;
        this->sum2_raw = info.sum2_raw;
        this->spr1_raw = info.spr1_raw;
        this->spr3_raw = info.spr3_raw;
        this->sum1_norm = info.sum1_norm;
        this->sum2_norm = info.sum2_norm;
        this->spr1_norm = info.spr1_norm;
        this->spr3_norm = info.spr3_norm;
        this->expression_level = info.expression_level;
        return *this;
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
