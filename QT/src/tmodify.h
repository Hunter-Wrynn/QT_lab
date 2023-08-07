/**************************************************
//文件名:         tmodify
//版本:           1.0
//目的及主要功能:  修改学生成绩
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
/*该类为教师修改学生成绩界面
*原理：利用QStringlist链表将文件每一行从尾部接入链表
* 链表组成 stu1_ID+stu1_SCORE+stu2_ID+stu2_score...
* 读到需要修改成绩学生的ID后，链表向后移动一位，修改成绩，然后接着移动
*/
#ifndef TMODIFY_H
#define TMODIFY_H

/**************************************************
Library Files Include
**************************************************/
#include <QDialog>
#include"student.h"
#include<QString>
#include<QStringList>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
namespace Ui {
class Tmodify;
}

class Tmodify : public QDialog
{
    Q_OBJECT

public:
    explicit Tmodify(QWidget *parent = nullptr);  //构造/析构函数
    ~Tmodify();

private:
    Ui::Tmodify *ui;
};

#endif // TMODIFY_H
