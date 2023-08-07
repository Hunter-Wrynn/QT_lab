/**************************************************
//文件名:         tsearch.h
//版本:           1.0
//目的及主要功能:   查询成绩
//创建日期:       2022.8.8
//修改日期:
//作者:           Hunter Ma
//修改者:
//联系方式:       13089680976
**************************************************/
/*查询学生成绩类设置了成绩栏lineEdit只读
 * 利用文件流操作按顺序查找学生成绩
 */

#ifndef TSEARCH_H
#define TSEARCH_H

#include <QDialog>
#include "student.h"

namespace Ui {
class Tsearch;
}

class Tsearch : public QDialog
{
    Q_OBJECT

public:
    explicit Tsearch(QWidget *parent = nullptr);   //构造/析构函数
    ~Tsearch();

private:
    Ui::Tsearch *ui;
};

#endif // TSEARCH_H
