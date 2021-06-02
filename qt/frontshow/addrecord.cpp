#include "addrecord.h"
#include "ui_addrecord.h"
#include <QFileDialog>
#include <ActiveQt/QAxObject>
#include <QVariant>
#include <QDebug>
#include <QMessageBox>
AddRecord::AddRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddRecord)
{
    ui->setupUi(this);
}

AddRecord::~AddRecord()
{
    delete ui;
}

void AddRecord::on_pushButton_clicked()
{

    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选中文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.xls)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();
    }

    for (auto aFile: fileNames) {
        ui->textEdit->append(aFile);
    }

}

void AddRecord::on_pushButton_2_clicked()
{
    int time = 0;
    for (auto aFile: fileNames) { // 对于每一个文件
        QAxObject* excel = new QAxObject("Excel.Application");
        //是否可视化excel
        excel->dynamicCall("SetVisible(bool Visible)", false);
        //是否弹出警告窗口
        excel->setProperty("DisplayAlerts", false);

        QAxObject *workbooks = excel->querySubObject("WorkBooks");
        workbooks->dynamicCall("Open(const QString&)",aFile);

        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取活动工作簿
        QAxObject *worksheets = workbook->querySubObject("Sheets");//获取所有的工作表
        QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)", 1);

        //QAxObject *range = worksheet->querySubObject("Cells(int,int)",1,1); //获取cell的值
        //QString strVal = range->dynamicCall("Value2()").toString();

        //qDebug() << strVal;
        QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
        QAxObject * rows = usedrange->querySubObject("Rows");
        QAxObject * columns = usedrange->querySubObject("Columns");
        int intRows = rows->property("Count").toInt();
        int intCols = columns->property("Count").toInt();
        //qDebug() << intRows;
        //qDebug() << intCols;

        // 批量载入数据，这里默认读取B13:C最后
        QString Range = "A2:AV" +QString::number(intRows);
        QAxObject *allEnvData = worksheet->querySubObject("Range(QString)", Range);
        QVariant allEnvDataQVariant = allEnvData->property("Value");
        QVariantList allEnvDataList = allEnvDataQVariant.toList();

        std::vector<std::vector<QString> > data;
        for(int i=0; i<= intRows-2; i++) // 对于每一行的数据
        {
            QVariantList allEnvDataList_i =  allEnvDataList[i].toList(); // 获取到此行的数据

            // 判断数据个数是否为48 如果不是  则报错
            if (allEnvDataList_i.size() != 48) {
                qDebug() << "Wrong value number!" << endl;
                return;
            }

            std::vector<QString> item;
            // 将获得的行数据导入数据库
            for(QVariant v : allEnvDataList_i) {
                item.push_back(v.toString());
            }
            data.push_back(item);
        }
        time = DataBaseManager::insertData(data);
        workbooks->dynamicCall("Close()");
    }

    QString dlgTitle="Info";
    QString strInfo="Successfully Add Data To DataBase! Time: " + QString::number(time);
    QMessageBox::information(this, dlgTitle, strInfo,
                             QMessageBox::Ok,QMessageBox::NoButton);
}

void AddRecord::on_pushButton_3_clicked()
{

}
