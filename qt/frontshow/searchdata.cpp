#include "searchdata.h"
#include "ui_searchdata.h"
#include <QButtonGroup>
#include <QDebug>
#include <QMovie>
#include <QMessageBox>
#include <QFileDialog>
#include <ActiveQt/QAxObject>
#include <QVariant>
#include <baseEncode.h>
SearchData::SearchData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchData)
{
    ui->setupUi(this);

    bg=new QButtonGroup(this);
    bg->addButton(ui->radioButton,0);//一个值为0
    bg->addButton(ui->radioButton_2,1);//一个值为1
    ui->radioButton->setChecked(true);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方

    ui->movieLabel->setScaledContents(true);
    QMovie *iconShow = new QMovie(":/new/prefix1/images/back.png");
    ui->movieLabel->setMovie(iconShow);
    iconShow->start();

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->tableWidget->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    //ui->textEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->lineEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_menu(QPoint)));
}

SearchData::~SearchData()
{
    delete ui;
}


// 确认按钮  开始查找
void SearchData::on_pushButton_clicked()
{
    // 获取当前输入文本
    QString searchStr = ui->lineEdit->text();
    int sel= bg->checkedId();//取到所选的radioButton的值

    switch(sel)
    {
    case 0:
        // 查找miR_name
        //qDebug() << "miR_name" << endl;

        // 注意 这里涉及到大数组的拷贝 可能会影响程序运行速度  建议把函数内的内容直接写这里
        MIR_NamesFromDB(searchStr, searchResult);

        break;
    case 1:
        // 查找miR_seq
        //qDebug() << "miR_seq" << endl;

        // 注意 这里涉及到大数组的拷贝 可能会影响程序运行速度  建议把函数内的内容直接写这里
        MIR_SeqFromDB(searchStr, searchResult);
        break;
    default:
        qDebug() << "Program Wrong! You select no 1 or 2" << endl;
        return; // 函数终止
    }

    // 在得到结果之后

    if (searchResult.size() == 0) { // 如果数组大小为空

    } else { // 数组不为空  含有查找信息
        // 将查找信息呈现并统计
        for (size_t i = 0; i < searchResult.size(); i++) {
            ui->tableWidget->setItem(int(i), 0, new QTableWidgetItem(searchResult[i].miR_index));
            ui->tableWidget->setItem(int(i), 1, new QTableWidgetItem(searchResult[i].miR_name));
            ui->tableWidget->setItem(int(i), 2, new QTableWidgetItem(searchResult[i].miR_seq));
            ui->tableWidget->setItem(int(i), 3, new QTableWidgetItem(searchResult[i].rep_miRIDl));
            ui->tableWidget->setItem(int(i), 4, new QTableWidgetItem(searchResult[i].miRbase_seq));
            ui->tableWidget->setItem(int(i), 5, new QTableWidgetItem(searchResult[i].type));
            ui->tableWidget->setItem(int(i), 6, new QTableWidgetItem(searchResult[i].CG));
            ui->tableWidget->setItem(int(i), 7, new QTableWidgetItem(searchResult[i].dG));

            int numLabel = 8;
            for (size_t m = 0; m < searchResult[i].sum1_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum1_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum1_raw.size());

            for (size_t m = 0; m < searchResult[i].sum2_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum2_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum2_raw.size());

            for (size_t m = 0; m < searchResult[i].spr1_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr1_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr1_raw.size());

            for (size_t m = 0; m < searchResult[i].spr3_raw.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr3_raw[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr3_raw.size());

            for (size_t m = 0; m < searchResult[i].sum1_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum1_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum1_norm.size());

            for (size_t m = 0; m < searchResult[i].sum2_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].sum2_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].sum2_norm.size());

            for (size_t m = 0; m < searchResult[i].spr1_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr1_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr1_norm.size());

            for (size_t m = 0; m < searchResult[i].spr3_norm.size(); m++) {
                ui->tableWidget->setItem(int(i), int(numLabel+m), new QTableWidgetItem(searchResult[i].spr3_norm[m]));
            }
            numLabel = numLabel + int(searchResult[i].spr3_norm.size());

            ui->tableWidget->setItem(int(i), numLabel, new QTableWidgetItem(searchResult[i].expression_level));
        }
    }
}

// 通过miR_name 的一部分来从数据库中查找所有有可能的值并返回
bool SearchData::MIR_NamesFromDB(QString partStr, vector<oneSearchInfo> &resultInfos) {
    QString info = DataBaseManager::searchAllInfo(partStr, resultInfos, 0);
    ui->stateLabel->setText(info);
    return true;
}


// 通过miR_seq 的一部分来从数据库中查找所有有可能的值并返回
bool SearchData::MIR_SeqFromDB(QString partStr, vector<oneSearchInfo> &resultInfos) {
    QString info = DataBaseManager::searchAllInfo(partStr, resultInfos, 1);
    ui->stateLabel->setText(info);////////////////////
    return true;
}

void SearchData::on_pushButton_2_clicked()
{
    ui->tableWidget->clearContents();
    searchResult.clear(); // 清空所有搜索数据
    ui->checkBox->setCheckState(Qt::Unchecked);
    std::map<QString, std::map<QString, QString> > temp;
    this->modifyBuffer.swap(temp);
}

void SearchData::on_pushButton_3_clicked()
{
    // 由得到的searchResult搜索结果从数据库中删除这些数据
}

void SearchData::on_checkBox_stateChanged(int state)
{
    if (state == Qt::Checked) // "选中"
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        for(int i=0; i<ui->tableWidget->columnCount()-1; i++)
        {
            QTableWidgetItem* item = ui->tableWidget->item(i,0); //获取每行第1列的单元格指针
            item->setFlags(Qt::ItemIsEnabled);//设置改item不可修改；
        }
        this->modifyMode = true;
    }
//    else if(state == Qt::PartiallyChecked) // "半选"
//    {
//        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
//    }
    else // 未选中 - Qt::Unchecked
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->modifyMode = false;
    }
}

void SearchData::show_menu(const QPoint pos)
{
    //设置菜单选项
    QMenu *menu = new QMenu(ui->tableWidget);
    QAction *pnew = new QAction("Delete selected items",ui->tableWidget);
    connect(pnew,SIGNAL(triggered()),this,SLOT(deleteItems()));
    menu->addAction(pnew);
    menu->move(cursor().pos());
    menu->show();
    //获得鼠标点击的x，y坐标点
    int x = pos.x ();
    int y = pos.y ();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x,y));
    int row = index.row ();//获得QTableWidget列表点击的行数
    qDebug() << "row: " << row << endl;
}

void SearchData::on_tableWidget_cellChanged(int row, int column)
{
    if (this->modifyMode)
    {
//        this->blockSignals(true);
        QString miR_index = ui->tableWidget->item(row, 0)->text();
        qDebug() << ">>> Notice: " << miR_index << "changed" << endl;
        this->modifyBuffer[miR_index][itemNames[column]] = ui->tableWidget->item(row, column)->text();
//        this->blockSignals(false);
    }
}

void SearchData::show()
{
    for(auto item : this->modifyBuffer)
    {
        qDebug() << "Index: " << item.first << endl;
        for(auto changeItem : item.second)
        {
            qDebug() << changeItem.first << " ---> " << changeItem.second << endl;
        }
        qDebug() << endl;
    }
}

void SearchData::on_pushButton_4_clicked()
{
//    show();
    DataBaseManager::modifyData(this->modifyBuffer);
//    QList<QTableWidgetSelectionRange> temp = ui->tableWidget->selectedRanges();
//    for (QTableWidgetSelectionRange i : temp)
//    {
//        qDebug() << "top: " << i.topRow() << " bottom: " << i.bottomRow() << endl;
//    }
}

void SearchData::on_tableWidget_cellClicked(int row, int column)
{
    if (column == 0)
    {
        // TODO 选中一行
    }
}

void SearchData::deleteItems()
{
    std::vector<QString> dItemNames;
    std::map<QString, bool> selected;
    QList<QTableWidgetSelectionRange> temp = ui->tableWidget->selectedRanges();
    for (QTableWidgetSelectionRange i : temp)
    {
        for(int j = i.topRow(); j <= i.bottomRow(); j++)
            selected[ui->tableWidget->item(j, 0)->text()] = true;
    }
    for (auto item : selected)
    {
        dItemNames.push_back(item.first);
    }
    DataBaseManager::deleteRecords(dItemNames);
}

void SearchData::on_pushButton_5_clicked()
{
    QString srcDirPath = QFileDialog::getExistingDirectory(this, "Choose Directory","/");
    if (srcDirPath.length() > 0) {
        qDebug() << srcDirPath;
        // 获取到了路径信息 在此路径下生成Excel文件
        // searchResult : 49 infos
        QAxObject* excel = new QAxObject("Excel.Application");
        //是否可视化excel
        excel->dynamicCall("SetVisible(bool Visible)", false);
        //是否弹出警告窗口
        excel->setProperty("DisplayAlerts", false);

        QAxObject *workbooks = excel->querySubObject("Workbooks");
        workbooks->dynamicCall("Add");

        QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
        QAxObject* sheets = workbook->querySubObject("Sheets");
        QAxObject* sheet = sheets->querySubObject("Item(int)", 1);


        QAxObject* speCell;
        // 设置创建出的单元格的值
        for (size_t i = 0; i < searchResult.size(); i++) {
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 1); speCell->dynamicCall("Value",searchResult[i].miR_index);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 2); speCell->dynamicCall("Value",searchResult[i].miR_name);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 3); speCell->dynamicCall("Value",searchResult[i].miR_seq);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 4); speCell->dynamicCall("Value",searchResult[i].rep_miRIDl);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 5); speCell->dynamicCall("Value",searchResult[i].miRbase_seq);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 6); speCell->dynamicCall("Value",searchResult[i].type);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 7); speCell->dynamicCall("Value",searchResult[i].CG);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 8); speCell->dynamicCall("Value",searchResult[i].dG);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 9); speCell->dynamicCall("Value",searchResult[i].sum1_raw[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 10); speCell->dynamicCall("Value",searchResult[i].sum1_raw[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 11); speCell->dynamicCall("Value",searchResult[i].sum1_raw[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 12); speCell->dynamicCall("Value",searchResult[i].sum1_raw[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 13); speCell->dynamicCall("Value",searchResult[i].sum1_raw[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 14); speCell->dynamicCall("Value",searchResult[i].sum2_raw[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 15); speCell->dynamicCall("Value",searchResult[i].sum2_raw[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 16); speCell->dynamicCall("Value",searchResult[i].sum2_raw[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 17); speCell->dynamicCall("Value",searchResult[i].sum2_raw[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 18); speCell->dynamicCall("Value",searchResult[i].sum2_raw[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 19); speCell->dynamicCall("Value",searchResult[i].spr1_raw[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 20); speCell->dynamicCall("Value",searchResult[i].spr1_raw[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 21); speCell->dynamicCall("Value",searchResult[i].spr1_raw[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 22); speCell->dynamicCall("Value",searchResult[i].spr1_raw[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 23); speCell->dynamicCall("Value",searchResult[i].spr1_raw[4]);



            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 24); speCell->dynamicCall("Value",searchResult[i].spr3_raw[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 25); speCell->dynamicCall("Value",searchResult[i].spr3_raw[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 26); speCell->dynamicCall("Value",searchResult[i].spr3_raw[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 27); speCell->dynamicCall("Value",searchResult[i].spr3_raw[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 28); speCell->dynamicCall("Value",searchResult[i].spr3_raw[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 29); speCell->dynamicCall("Value",searchResult[i].sum1_norm[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 30); speCell->dynamicCall("Value",searchResult[i].sum1_norm[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 31); speCell->dynamicCall("Value",searchResult[i].sum1_norm[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 32); speCell->dynamicCall("Value",searchResult[i].sum1_norm[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 33); speCell->dynamicCall("Value",searchResult[i].sum1_norm[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 34); speCell->dynamicCall("Value",searchResult[i].sum2_norm[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 35); speCell->dynamicCall("Value",searchResult[i].sum2_norm[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 36); speCell->dynamicCall("Value",searchResult[i].sum2_norm[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 37); speCell->dynamicCall("Value",searchResult[i].sum2_norm[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 38); speCell->dynamicCall("Value",searchResult[i].sum2_norm[4]);


            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 39); speCell->dynamicCall("Value",searchResult[i].spr1_norm[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 40); speCell->dynamicCall("Value",searchResult[i].spr1_norm[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 41); speCell->dynamicCall("Value",searchResult[i].spr1_norm[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 42); speCell->dynamicCall("Value",searchResult[i].spr1_norm[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 43); speCell->dynamicCall("Value",searchResult[i].spr1_norm[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 44); speCell->dynamicCall("Value",searchResult[i].spr3_norm[0]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 45); speCell->dynamicCall("Value",searchResult[i].spr3_norm[1]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 46); speCell->dynamicCall("Value",searchResult[i].spr3_norm[2]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 47); speCell->dynamicCall("Value",searchResult[i].spr3_norm[3]);
            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 48); speCell->dynamicCall("Value",searchResult[i].spr3_norm[4]);

            speCell = sheet->querySubObject("Cells(int,int)", 2+i, 49); speCell->dynamicCall("Value",searchResult[i].expression_level);

        }

        QDate D; D=QDate::currentDate();
        QTime T; T=QTime::currentTime();
        QString bagname =QString("%1-%2-%3-%4-%5-%6").arg(D.year()).arg(D.month()).arg(D.day()).arg(T.hour()).arg(T.minute()).arg(T.second());//指定文件路径

        QString outFilePath1 = srcDirPath + "/" + bagname;
        QString outFilePath = outFilePath1 +".xlsx";

        // 导出Excel数据
        workbook->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(outFilePath));

        // 释放excel
        if (excel != NULL)
        {
            excel->dynamicCall("Quit()");
            delete excel;
            excel = NULL;
        }

        if (this->encryption) { // 如果导出数据需要加密
            QString outFilePath3 = outFilePath1 + ".THL";
            huffEncode he; he.encode(outFilePath.toStdString().c_str(), outFilePath3.toStdString().c_str());
            QFile fileTemp(outFilePath); fileTemp.remove();
            //huffDecode hd; hd.decode(outFilePath3.toStdString().c_str(), "C:/Users/lenovo/Desktop");
        }
    }
}

void SearchData::on_checkBox_2_stateChanged(int state)
{
    if (state == Qt::Checked) // "选中"
    {
        this->encryption = true;
    }
    else // 未选中 - Qt::Unchecked
    {
        this->encryption = false;
    }
}

void SearchData::on_pushButton_6_clicked()
{
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("选中THL文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("File(*.THL)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if (fileDialog->exec()) {
        fileNames = fileDialog->selectedFiles();
        //QDate D; D=QDate::currentDate();
        //QTime T; T=QTime::currentTime();
        //QString bagname =QString("%1-%2-%3-%4-%5-%6").arg(D.year()).arg(D.month()).arg(D.day()).arg(T.hour()).arg(T.minute()).arg(T.second());//指定文件路径

        for (auto aFile : fileNames) {
            qDebug() << aFile.toStdString().substr(0, aFile.toStdString().find_last_of('/')).c_str();
            huffDecode hd; hd.decode(aFile.toStdString().c_str(), aFile.toStdString().substr(0, aFile.toStdString().find_last_of('/')).c_str());
        }
    }
}
