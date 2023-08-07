
/**************************************************
//文件名:         teamenu.h
//版本:           1.0
//目的及主要功能:  教师进行批卷操作
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
/* 本类为教师操作界面，其中包含了教师批卷的各个功能，其中，学号利用的doubleSpinBox滚动条可选择3210-3220的学号的学生
 * 总分右边的文本栏可显示学生的总分情况
 * 输入各项得分用6个lineEdit记录学生小分用以计算
 * 判新卷用于清空
 * 改错/编程 用了comboBox切换选择，显示卷面调出各自的卷面信息
 * 成绩管理界面调用checkBox选择进入查询/修改成绩界面
 * 计算总分可将各项小分计算总分置总分栏
 * 本卷判毕将学生学号与总分导入系统
 * 学生问题情况反馈可显示学生对自己试卷有误情况
 * 退出-----顺便clear各项信息
*/
#ifndef TEAMENU_H
#define TEAMENU_H
/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include"student.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include "tsearch.h"
#include "tmodify.h"
#include"scoremenu.h"
#include <QTime>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QTextCodec>
namespace Ui {
class TeaMenu;
}

class TeaMenu : public QDialog
{
    Q_OBJECT

public:
    explicit TeaMenu(QWidget *parent = nullptr);   //构造析构函数
    ~TeaMenu();

private:
    Ui::TeaMenu *ui; //初始化UI



    Tsearch m_Ts;  //查询界面
    Tmodify m_Tm;  //改错界面
    ScoreMenu m_Sm;//成绩反馈界面

};

#endif // TEAMENU_H
