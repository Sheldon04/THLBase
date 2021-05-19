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
//    QString Sum11_raw;
//    QString Sum12_raw;
//    QString Sum13_raw;
//    QString Sum14_raw;
//    QString Sum15_raw;
//    QString Sum21_raw;
//    QString Sum22_raw;
//    QString Sum23_raw;
//    QString Sum24_raw;
//    QString Sum25_raw;
//    QString Spr11_raw;
//    QString Spr12_raw;
//    QString Spr13_raw;
//    QString Spr14_raw;
//    QString Spr15_raw;
//    QString Spr31_raw;
//    QString Spr32_raw;
//    QString Spr33_raw;
//    QString Spr34_raw;
//    QString Spr35_raw;
//    QString Sum11_norm;
//    QString Sum12_norm;
//    QString Sum13_norm;
//    QString Sum14_norm;
//    QString Sum15_norm;
//    QString Sum21_norm;
//    QString Sum22_norm;
//    QString Sum23_norm;
//    QString Sum24_norm;
//    QString Sum25_norm;
//    QString Spr11_norm;
//    QString Spr12_norm;
//    QString Spr13_norm;
//    QString Spr14_norm;
//    QString Spr15_norm;
//    QString Spr31_norm;
//    QString Spr32_norm;
//    QString Spr33_norm;
//    QString Spr34_norm;
//    QString Spr35_norm;
};

#endif // ONESEARCHINFO_H
