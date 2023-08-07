#include "teamenu.h"
#include "ui_teamenu.h"
/**************************************************
Name:            TeaMenu
Inputs:          None
Return Value:
Description:     设置背景控件
**************************************************/
TeaMenu::TeaMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeaMenu)
{

    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("教师界面"));  //设置教师窗口名称
    ui->edt_File->setText("score.txt");              //设置文件目录

    /**************************************************
    Name:            btn_Over
    Inputs:
    Return Value:
    Description:     判卷完毕，将学生信息导入score.txt文件
    **************************************************/
    connect(ui->btn_Over,&QPushButton::clicked,[=]()//判卷完毕按钮lamda表达式
    {


        QString t_strID = ui->spb_StuID->text();
        QString t_strSc = ui->edt_Total->text();


            QString str = QString("insert into student(t_strID, t_strSc) values('%1', '%2')").arg(t_strID).arg(t_strSc);
            QSqlQuery query;
            query.exec(str); //执行插入操作




        QFile file("D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt");    //定义学生成绩文件
        file.open(QIODevice::ReadOnly | QIODevice::Text);                       //打开学生成绩文件


        //利用文件流操作
        QString line;
        QTextStream in(&file);              //用文件构造流
        line = in.readLine();               //读取一行放到字符串
        bool t_flag=false;                  //利用t_flag遍历判断是否有该学生，默认为false
        while(!line.isNull())               //字符串有内容
        {
            if(line==ui->spb_StuID->text()) //学生存在
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
            QString data_1=ui->spb_StuID->text()+"\n";            //学生学号
            QString data_2=ui->edt_Total->text()+"\n";            //学生成绩
            QTextStream dataStr(&file);                           //用文件输出流
            dataStr << data_1<<data_2;                            //录入成绩
            file.close();                                         //用完后关闭文件防止误操作

        }
        else
        {
            QMessageBox::warning(this,"提示","此学生已录入系统",QMessageBox::Ok);
        }
       });
    /**************************************************
    Name:            btn_Cal
    Inputs:
    Return Value:
    Description:     计算学生总分，写入总分edit栏

    **************************************************/
    connect(ui->btn_Cal,&QPushButton::clicked,[=]() //计算总分lamda表达式
    {

        if(ui->edt_S1->text()==""||ui->edt_S2->text()==""||
           ui->edt_S3->text()==""||ui->edt_S4->text()==""||
           ui->edt_S5->text()==""||ui->edt_S6->text()=="")                            //判断信息是否填写完全
        {
            QMessageBox::warning(this,"提示","请将信息填写完整",QMessageBox::Ok);         //利用QMessageBox提示未填写完全
        }
        else
        {

            int t_nSum=ui->edt_S1->text().toInt()+ui->edt_S2->text().toInt()
            +ui->edt_S3->text().toInt()+ui->edt_S4->text().toInt()
            +ui->edt_S5->text().toInt()+ui->edt_S6->text().toInt();                    //将QString转为int计算总成绩

            if(t_nSum>30)//总分超过30提示重新批卷
            {
                QMessageBox::warning(this,"提示","总分超过30，分数填写有误",QMessageBox::Ok);//利用QMessageBox提示批错了
            }
            else
            {
                QString t_strSum=QString::number(t_nSum); //将int类型的总分转为QString类型
                ui->edt_Total->setText(t_strSum);         //将总分显示在总分栏
            }
        }
    });
    /**************************************************
    Name:            btn_Exe
    Inputs:
    Return Value:
    Description:     退出按钮，清空信息
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()//退出按钮的lamda表达式
    {
        //清空所有信息
        ui->edt_S1->clear();
        ui->edt_S2->clear();
        ui->edt_S3->clear();
        ui->edt_S4->clear();
        ui->edt_S5->clear();
        ui->edt_S6->clear();
        ui->edt_Total->clear();
        ui->edt_Paper->clear();

        this->reject();//退出
    });

    /**************************************************
    Name:            btn_Score
    Inputs:
    Return Value:
    Description:     成绩管理，查询/修改成绩
    **************************************************/
    connect(ui->btn_Score,&QPushButton::clicked,[=]()//成绩管理按钮的lamda表达式
    {

        m_Sm.exec();//进入成绩管理界面

    });
    /**************************************************
    Name:            btn_New
    Inputs:
    Return Value:
    Description:     判新卷，清屏
    **************************************************/
    connect(ui->btn_New,&QPushButton::clicked,[=]()//判新卷的lamda的表达式
    {
        //清空所有信息
        ui->edt_S1->clear();
        ui->edt_S2->clear();
        ui->edt_S3->clear();
        ui->edt_S4->clear();
        ui->edt_S5->clear();
        ui->edt_S6->clear();
        ui->edt_Total->clear();
        ui->edt_Paper->clear();

    });

    /**************************************************
    Name:            btn_Exe
    Inputs:
    Return Value:
    Description:     退出按钮，清空信息
    **************************************************/
    connect(ui->btn_Paper,&QPushButton::clicked,[=]()//显示卷面的lamda表达式
    {

        if(ui->cmb_Paper->currentText()=="改错")      //进入改错界面
        {
            Student t_nStu;
            t_nStu.setID(ui->spb_StuID->text());     //创建临时学生类记录学生学号

            //创建学生试卷文件路径
            QString path_1="D:\\qtstudy\\summer_school\\school\\SCHOOL\\paper\\";
            QString path_2=t_nStu.getID();
            QString path_3="g.txt";
            QString path=path_1+path_2+path_3;

            //利用文件流操作
            QFileInfo fi(path);
            if(fi.isFile())                          //判断文件是否存在
            {
                QFile file(path);
                file.open(QIODevice::ReadOnly);
                QByteArray array=file.readAll();     //将试卷信息读入QBytearray
                ui->edt_Paper->setText(array);       //将学生试卷显示到textEdit上
                file.close();                        //用完及时关掉，防止误用
            }
            else
            {
                QMessageBox::warning(this,"提示","学生缺考，手动设置成绩-1",QMessageBox::Ok);//利用QMessageBox提示学生缺号
            }
        }//改错界面结束

        if(ui->cmb_Paper->currentText()=="编程")     //进入编程界面
        {
            Student t_nStu;
            t_nStu.setID(ui->spb_StuID->text());    //创建临时学生类记录学生学号
            //创建学生试卷文件路径
            QString path_1="D:\\qtstudy\\summer_school\\school\\SCHOOL\\paper\\";
            QString path_2=t_nStu.getID();
            QString path_3="b.txt";
            QString path=path_1+path_2+path_3;

            //利用文件流操作
            QFileInfo fi(path);
            if(fi.isFile())                         //判断文件是否存在
            {

                QFile file(path);
                file.open(QIODevice::ReadOnly);
                QByteArray array=file.readAll();    //将试卷信息读入QBytearray

                ui->edt_Paper->setText(array);      //将学生试卷显示到textEdit上
                file.close();                       //用完及时关掉，防止误用

            }
            else
            {
            QMessageBox::warning(this,"提示","无此学号的学生",QMessageBox::Ok);
            }
        }//编程界面结束
    });


    /**************************************************
    Name:            btn_Doubt
    Inputs:
    Return Value:
    Description:     显示学生问题信息
    **************************************************/
      connect(ui->btn_Doubt,&QPushButton::clicked,[=]()//显示卷面的lamda表达式
      {
          QString path="D:\\qtstudy\\summer_school\\school\\SCHOOL\\doubt.txt";

          //利用文件流操作
          QFileInfo fi(path);
          if(fi.isFile())                          //判断文件是否存在
          {
              QFile file(path);
              file.open(QIODevice::ReadOnly);
              QByteArray array=file.readAll();     //将试卷信息读入QBytearray
              ui->edt_Paper->setText(array);       //将学生试卷显示到textEdit上
              file.close();                        //用完及时关掉，防止误用
          }
          else
          {
              QMessageBox::warning(this,"提示","无问题",QMessageBox::Ok);//利用QMessageBox提示
          }
      });
}
/**************************************************
Name:            ~TeaMenu()
Inputs:
Return Value:
Description:     析构函数
**************************************************/
TeaMenu::~TeaMenu()
{
    delete ui;
}
