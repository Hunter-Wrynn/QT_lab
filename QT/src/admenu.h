/**************************************************
//文件名:         admenu.h
//版本:           1.0
//目的及主要功能:  修改成绩，打印全校成绩排名
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/

#ifndef ADMENU_H
#define ADMENU_H
/**************************************************
Name:
Inputs:
Return Value:
Description:
**************************************************/
#include <QDialog>
#include"stupassmod.h"
#include"teapassmod.h"
#include"rank.h"
namespace Ui {
class Admenu;
}

class Admenu : public QDialog
{
    Q_OBJECT

public:
    explicit Admenu(QWidget *parent = nullptr);   //构造/析构函数
    ~Admenu();

private:
    Ui::Admenu *ui;

    StuPassMod m_Spm;   //学生密码修改界面
    TeaPassMod m_Tpm;   //教师密码修改界面
    Rank m_Rank;        //校成绩单打印界面

};

#endif // ADMENU_H
