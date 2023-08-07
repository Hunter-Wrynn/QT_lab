/**************************************************
//文件名:         scoremenu.h
//版本:           1.0
//目的及主要功能:  成绩查询/修改
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
/*本类利用checkBox选择查询/修改成绩*/

#ifndef SCOREMENU_H
#define SCOREMENU_H
/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include"ui_scoremenu.h"
#include"tsearch.h"
#include"tmodify.h"
namespace Ui {
class ScoreMenu;
}

class ScoreMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreMenu(QWidget *parent = nullptr); //构造/析构函数
    ~ScoreMenu();

private:
    Ui::ScoreMenu *ui;

    Tsearch m_Ts;    //查询界面
    Tmodify m_Tm;    //修改界面


};

#endif // SCOREMENU_H
