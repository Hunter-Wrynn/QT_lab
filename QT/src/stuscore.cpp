#include "stuscore.h"
#include "ui_stuscore.h"
/**************************************************
Name:          Stuscore
Inputs:        None
Return Value:  None
Description:   背景，控件设置
**************************************************/

Stuscore::Stuscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stuscore)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("学生界面"));   //设置窗口名称

    /**************************************************
    Name:           btn_Exe
    Inputs:         None
    Return Value:   None
    Description:    退出
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()//退出按钮lamda表达式
    {
        //退出前清空信息
        ui->edt_Pss->clear();

        this->reject();

    });

    /**************************************************
    Name:           btn_Search
    Inputs:         None
    Return Value:   None
    Description:    利用文件流查找
    **************************************************/
    connect(ui->btn_Search,&QPushButton::clicked,[=]()//查询成绩按钮lamda表达式
    {

        QString path="D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt";  //打开文件



        //利用文件流验证
        QFile file(path);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readLine();//读取一行放到字符串
        while(!line.isNull())//字符串有内容
        {
            if(line==ui->edt_User->text())
            {
               line=in.readLine();//循环读取下行
               break;
            }
            line=in.readLine();
        }
        ui->edt_Pss->setText(line);  //导入成绩


        file.close();//及时关闭文件防止误操作
    });
    /**************************************************
    Name:           btn_Doubt
    Inputs:         None
    Return Value:   None
    Description:    学生问题反馈
    **************************************************/
    connect(ui->btn_Doubt,&QPushButton::clicked,[=]()//成绩有误按钮lamda表达式
    {

        QFile file("D:\\qtstudy\\summer_school\\school\\SCHOOL\\doubt.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);                       //打开学生成绩文件

        //利用文件流操作
        QString line;
        QTextStream in(&file);              //用文件构造流
        line = in.readLine();               //读取一行放到字符串
        bool t_flag=false;                  //利用t_flag遍历判断是否有该学生，默认为false
        while(!line.isNull())               //字符串有内容
        {
            if(line==ui->edt_User->text()) //学生存在
            {
                line=in.readLine();         //循环读取下行
                t_flag=true;
                break;                      //判断成功，跳出循环
            }
            line=in.readLine();
        }
        file.close();                       //用完后关闭文件防止误操作


        if(t_flag==false)                                         //成绩单无该学生，录入该学生成绩
        {
            file.open(QIODevice::WriteOnly|QIODevice::Append);    //在尾部打开学生成绩单
            QString data_1=ui->edt_User->text()+"\n";             //学生学号
            QTextStream dataStr(&file);                           //用文件输出流
            dataStr << data_1;                                    //录入成绩
            file.close();                                         //用完后关闭文件防止误操作
        }
        else
        {
            QMessageBox::warning(this,"提示","此学生已录入系统",QMessageBox::Ok);
        }
    });
}

/**************************************************
Name:           ~Stuscore()
Inputs:         None
Return Value:   None
Description:    析构函数
**************************************************/
Stuscore::~Stuscore()
{
    delete ui;
}
