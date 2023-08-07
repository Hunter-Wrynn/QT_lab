/**************************************************
//文件名:         mainwindow.h
//版本:           1.0
//目的及主要功能:  登录界面,转入各UI
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**************************************************
Library Files Include
**************************************************/
#include <QMainWindow>
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "ui_student.h"
#include "ui_teacher.h"
#include "ui_admin.h"
#include"stuscore.h"
#include"teamenu.h"
#include"admenu.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QValidator>
#include <QRegExp>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QDebug>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QTextCodec>
#include <QSqlTableModel>
#include <QHostInfo>
#include <QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//登录界面,转入各UI
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //构造,析构函数
    ~MainWindow();


protected:
    bool eventFilter(QObject *watched, QEvent *event);  //鼠标点击时间触发器

private:
    Ui::MainWindow *ui;

    Student m_Stu;  // 学生
    Teacher m_Tea;  // 教师
    Admin m_Adm;    // 管理

    Stuscore m_Stusc;// 学生登录界面
    TeaMenu m_Tm;    // 教师登录界面
    Admenu m_Am;     // 管理登录界面



};
#endif // MAINWINDOW_H
