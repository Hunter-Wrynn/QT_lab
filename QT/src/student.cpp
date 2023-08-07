#include "student.h"
#include "ui_student.h"
/**************************************************
Name:            Student
Inputs:          None
Return Value:    None
Description:     设置背景控件
**************************************************/
Student::Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student)

{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("学生登录界面"));   //设置窗口文字

}


/**************************************************
Name:             getID() const
Inputs:           None
Return Value:     m_nID
Description:      ID获取
**************************************************/
QString Student::getID() const
{
    return m_strID;
}
/**************************************************
Name:             getScore() const
Inputs:           None
Return Value:     m_nScore
Description:      score获取
**************************************************/
QString Student::getscore() const
{
    return m_strScore;
}
/**************************************************
Name:             getpss() const
Inputs:           None
Return Value:     m_nPss
Description:      pss获取
**************************************************/
QString Student::getpss()
{
    return m_strPss;
}
/**************************************************
Name:             setID(const QString &value)
Inputs:           const QString &value
Return Value:     None
Description:      ID设置
**************************************************/
void Student::setID(const QString &value)
{
    m_strID = value;
}
/**************************************************
Name:             setscore(const QString &value)
Inputs:           const QString &value
Return Value:     None
Description:      score设置
**************************************************/
void Student::setscore(const QString &score)
{
    m_strScore=score;
}
/**************************************************
Name:             setpss(const QString &value)
Inputs:           const QString &value
Return Value:     None
Description:      pss设置
**************************************************/
void Student::setpss(const QString &value)
{
    m_strPss=value;
}
/**************************************************
Name:             ~Student()
Inputs:
Return Value:     None
Description:      析构
**************************************************/
Student::~Student()
{
    delete ui;
}
