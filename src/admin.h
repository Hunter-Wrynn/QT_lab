#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QDialog>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCodec>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include "admenu.h"
#include "ui_admenu.h"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);  //构造/析构函数
    ~Admin();


    //获取ID,Pss
    QString getID() const;
    QString getpss() const;


    //设置ID,Pss
    void setID(const QString &value);
    void setpss(const QString &value);

private:
    Ui::Admin *ui;

    QString m_strID;
    QString m_strPss;
    Admenu m_Am;

};

#endif // ADMIN_H
