/**************************************************
//文件名:         stuscore.h
//版本:           1.0
//目的及主要功能:  学生查询成绩，反馈问题，退出
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
#ifndef STUSCORE_H
#define STUSCORE_H

/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include <QDialog>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
namespace Ui {
class Stuscore;
}

class Stuscore : public QDialog
{
    Q_OBJECT

public:

    explicit Stuscore(QWidget *parent = nullptr);  //构造/析构函数
    ~Stuscore();
    Ui::Stuscore *ui;

private:

};

#endif // STUSCORE_H
