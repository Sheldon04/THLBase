#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <vector>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <map>

#define INF 999999

static const QString itemNames[50] = {
    "miR_index", "miR_name", "miR_seq", "rep_miRID", "miRbase_seq",
    "type", "CG", "dG",
    "Sum11(raw)", "Sum12(raw)", "Sum13(raw)", "Sum14(raw)", "Sum15(raw)", "Sum21(raw)", "Sum22(raw)", "Sum23(raw)", "Sum24(raw)", "Sum25(raw)",
    "Spr11(raw)", "Spr12(raw)", "Spr13(raw)", "Spr14(raw)", "Spr15(raw)", "Spr31(raw)", "Spr32(raw)", "Spr33(raw)", "Spr34(raw)", "Spr35(raw)",
    "Sum11(norm)", "Sum12(norm)", "Sum13(norm)", "Sum14(norm)", "Sum15(norm)", "Sum21(norm)", "Sum22(norm)", "Sum23(norm)", "Sum24(norm)", "Sum25(norm)",
    "Spr11(norm)", "Spr12(norm)", "Spr13(norm)", "Spr14(norm)", "Spr15(norm)", "Spr31(norm)", "Spr32(norm)", "Spr33(norm)", "Spr34(norm)", "Spr35(norm)",
    "expression_level"
};

enum SortKey {
    ID, DG, CG, MIR_NAME
};

#endif // GLOBAL_H
