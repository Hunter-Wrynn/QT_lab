#include "admin.h"
#include "ui_admin.h"
/**************************************************
Name:             Admin()
Inputs:
Return Value:     None
Description:      设置背景空间
**************************************************/
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("管理员登录界面"));

}
/**************************************************
Name:             getID() const
Inputs:           None
Return Value:     m_nID;
Description:      获取ID
**************************************************/
QString Admin::getID() const
{
    return m_strID;
}
/**************************************************
Name:             getpss() const
Inputs:           None
Return Value:     m_nPss;
Description:      获取pss
**************************************************/
QString Admin::getpss() const
{
    return m_strPss;
}
/**************************************************
Name:             setID(const QString &value)
Inputs:           const QString &value
Return Value:     None
Description:      设置ID
**************************************************/
void Admin::setID(const QString &value)
{
    m_strID = value;
}
/**************************************************
Name:             setpss(const QString &value)
Inputs:           const QString &value
Return Value:     None
Description:      设置Pss
**************************************************/
void Admin::setpss(const QString &value)
{
    m_strPss= value;
}
/**************************************************
Name:             ~Admin()
Inputs:
Return Value:     None
Description:      析构
**************************************************/
Admin::~Admin()
{
    delete ui;
}
