#include "tsearch.h"
#include "ui_tsearch.h"
/**************************************************
Name:           Tsearch
Inputs:
Return Value:
Description:    设置控件背景
**************************************************/
Tsearch::Tsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tsearch)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("查询成绩界面"));

    /**************************************************
    Name:           btn_Search
    Inputs:
    Return Value:
    Description:    成绩查询
    **************************************************/
    connect(ui->btn_Search,&QPushButton::clicked,[=]()//查询按钮lamda表达式
    {
        Student t_stu;
        t_stu.setID(ui->edt_ID->text());//创建临时学生类读入该学生ID


        //文件流操作
        QFile file("D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);  //打开学生成绩文件
        QString line;
        QTextStream in(&file);                             //用文件构造流
        line = in.readLine();                              //读取一行放到字符串
        qDebug() << line;
        while(!line.isNull())                              //字符串有内容
        {
            if(line==t_stu.getID())                        //查询有该学生ID
            {
                line=in.readLine();                        //循环读取下行
                break;
            }
            line=in.readLine();
        }
        ui->edt_Score->setText(line);
        file.close();
    });

    /**************************************************
    Name:            btn_Exe
    Inputs:
    Return Value:
    Description:     退出窗口
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()//退出按钮lamda表达式
    {
        //退出前清空信息
        ui->edt_ID->clear();
        ui->edt_Score->clear();

        this->reject();//退出

    });
}

Tsearch::~Tsearch()
{
    delete ui;
}
