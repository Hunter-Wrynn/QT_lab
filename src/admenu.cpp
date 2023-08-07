#include "admenu.h"
#include "ui_admenu.h"
/**************************************************
Name:           Admenu
Inputs:
Return Value:
Description:    设置背景空间
**************************************************/
Admenu::Admenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admenu)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("管理员窗口"));

    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QString t_strCmd="create table if not exists admin (id varchar(64),psswd varchar(64))";
    QSqlQuery query;
    query.exec(t_strCmd);
    connect(ui->pushButton,&QPushButton::clicked,[=]()
    {

        QString id = ui->lineEdit_1->text();
        if(ui->lineEdit_2->text()==ui->lineEdit_3->text())
        {
            QString psswd=ui->lineEdit_2->text();
            QString str = QString("insert into admin values('%1', '%2')").arg(id).arg(psswd);
            QSqlQuery query;
            query.exec(str);
            QMessageBox::warning(this,"提示","注册成功",QMessageBox::Ok);//利用QMessageBox提示批错了
        }
        else
        {
            QMessageBox::warning(this,"提示","密码不一致",QMessageBox::Ok);//利用QMessageBox提示批错了
        }
    });

    /**************************************************
    Name:          btn_Stu
    Inputs:
    Return Value:
    Description:   修改学生成绩界面
    **************************************************/
    connect(ui->btn_Stu,&QPushButton::clicked,[=]()
    {

        ui->lineEdit_1->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();

        m_Spm.exec();

    });
    /**************************************************
    Name:          btn_Tea
    Inputs:
    Return Value:
    Description:   修改教师成绩界面
    **************************************************/
    connect(ui->btn_Tea,&QPushButton::clicked,[=]()
    {

        m_Tpm.exec();

    });
    /**************************************************
    Name:          btn_Rank
    Inputs:
    Return Value:
    Description:   成绩打印界面
    **************************************************/
    connect(ui->btn_Rank,&QPushButton::clicked,[=]()
    {

        m_Rank.exec();

    });
    /**************************************************
    Name:          btn_Exe
    Inputs:
    Return Value:
    Description:   退出
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()
    {

        this->reject();

    });
}
/**************************************************
Name:          ~Admenu()
Inputs:
Return Value:
Description:   析构
**************************************************/
Admenu::~Admenu()
{
    delete ui;
}
