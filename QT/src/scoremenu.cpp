#include "scoremenu.h"
#include "ui_scoremenu.h"
/**************************************************
Name:         ScoreMenu()
Inputs:
Return Value:
Description:  设置背景控件
**************************************************/
ScoreMenu::ScoreMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreMenu)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("成绩界面"));

    /**************************************************
    Name:         btn_In
    Inputs:
    Return Value:
    Description:  进入
    **************************************************/
    connect(ui->btn_In,&QPushButton::clicked,[=]()    //确定按钮lamda公式
    {

        if(ui->rb_Search->isChecked())                 //checkBox为查询
        {
            m_Ts.exec();
        }
        if(ui->rb_Modify->isChecked())                 //checkBox为修改
        {
            m_Tm.exec();
        }
    });
    /**************************************************
    Name:         btn_Exe
    Inputs:
    Return Value:
    Description:  退出清屏
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()    //退出按钮lamda表达式
    {

        this->reject();

    });
}
/**************************************************
Name:         ~ScoreMenu()
Inputs:
Return Value:
Description:  析构函数
**************************************************/
ScoreMenu::~ScoreMenu()
{
    delete ui;
}
