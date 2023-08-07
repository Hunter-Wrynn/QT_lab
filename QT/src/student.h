/**************************************************
//文件名:         student.h
//版本:           1.0
//目的及主要功能:  学生登录界面
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/


#ifndef STUDENT_H
#define STUDENT_H
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
#include "stuscore.h"
#include "ui_stuscore.h"
namespace Ui {
class Student;
}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);   //构造/析构函数
   ~Student();

    //get返回函数
    QString getID() const;
    QString getscore() const;
    QString getpss();


    //set获取函数
    void setID(const QString &value);
    void setscore(const QString &value);
    void setpss(const QString &value);


private:
    Ui::Student *ui;    //ui界面

    QString m_strID;      //学生账号
    QString m_strScore;   //学生成绩
    QString m_strPss;     //学生密码
    Stuscore m_Stusc;  //学生成绩查询界面

};

#endif // STUDENT_H
