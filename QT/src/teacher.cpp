#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher)
{

    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("教师登录界面"));//设置窗口名称


}
/**************************************************
Name:           getID() const
Inputs:         None
Return Value:   m_nID
Description:    获取教师ID
**************************************************/
QString Teacher::getID() const
{
    return m_strID;
}
/**************************************************
Name:           getpss() const
Inputs:         None
Return Value:   m_nPss
Description:    获取教师pss
**************************************************/
QString Teacher::getpss() const
{
    return m_strPss;
}
/**************************************************
Name:           setID(const QString &value)
Inputs:         const QString &value
Return Value:   None
Description:    设置教师ID
**************************************************/
void Teacher::setID(const QString &value)
{
    m_strID = value;
}
/**************************************************
Name:           setpss(const QString &value)
Inputs:         const QString &value
Return Value:   None
Description:    设置教师pss
**************************************************/
void Teacher::setpss(const QString &value)
{
    m_strPss= value;
}
/**************************************************
Name:           ~Teacher()
Inputs:
Return Value:   None
Description:    析构
**************************************************/
Teacher::~Teacher()
{
    delete ui;
}
