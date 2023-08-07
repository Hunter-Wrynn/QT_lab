/**************************************************
//文件名:         teacher.h
//版本:           1.0
//目的及主要功能:  教师登录界面
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
#ifndef TEACHER_H
#define TEACHER_H
/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include "teamenu.h"
#include "ui_teacher.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QTextCodec>

namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);  //构造析构函数
    ~Teacher();


    //获取ID,Pss
    QString getID() const;
    QString getpss() const;


    //设置ID，Pss
    void setID(const QString &value);
    void setpss(const QString &value);

private:
    Ui::Teacher *ui;


    QString m_strID;
    QString m_strPss;
    TeaMenu m_Tm;

};

#endif // TEACHER_H
