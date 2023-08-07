/**************************************************
//文件名:         rank.h
//版本:           1.0
//目的及主要功能:  打印并排名
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
#ifndef RANK_H
#define RANK_H
/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include"ui_rank.h"
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include<QList>
#include"student.h"
#include<QStringList>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<QVector>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QTextCodec>
namespace Ui {
class Rank;
}

class Rank : public QDialog
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = nullptr); //构造析构函数
    ~Rank();


    static bool compareBarData(const Student &barAmount_1, const Student &barAmount_2);//判断student的score大小
    int m_value=1;



private:
    Ui::Rank *ui;
};

#endif // RANK_H
