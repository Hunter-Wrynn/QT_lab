#include "tmodify.h"
#include "ui_tmodify.h"
/**************************************************
Name:          Tmodify
Inputs:
Return Value:
Description:   设置背景控件
**************************************************/
Tmodify::Tmodify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tmodify)
{
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("修改成绩界面"));//设置窗口名称

    /**************************************************
    Name:           btn_Exe
    Inputs:
    Return Value:
    Description:    退出，清屏
    **************************************************/
    connect(ui->btn_Exe,&QPushButton::clicked,[=]()//退出按钮lamda表达式
    {
        //退出前清空信息
        ui->edt_ID->clear();
        ui->edt_Score->clear();

        this->reject();//退出

    });


    /**************************************************
    Name:           btn_Modify
    Inputs:
    Return Value:
    Description:    修改成绩
    **************************************************/
    connect(ui->btn_Modify,&QPushButton::clicked,[=]()//修改按钮lamda表达式
    {

        QString strALL;       //用于储存文件全部信息
        QStringList strList;  //利用QString链表用于后续文件操作

        //读文件流操作
        QFile readFile("D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt");    
        if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))  //判断文件是否存在标准操作
        {
            QTextStream stream(&readFile);                        //构造输入流
            strALL=stream.readAll();                              //将strALL变为文本全部信息
        }
        readFile.close();                                         //及时关闭文件方式误操作


        //写文件流操作
        QFile writeFile("D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt");
        if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))  //判断文件是否存在标准操作
        {
            QTextStream stream(&writeFile);                       //构造输出流
            strList=strALL.split("\n");                           //通过换行符将文件每一行信息读如QString链表
            for(int i=0;i<strList.count();i++)                    //遍历链表
            {
                if(strList.at(i).contains(ui->edt_ID->text()))    //当读到该学生学号时
                {
                    stream<<ui->edt_ID->text()<<"\n";             //通过输出流将学生ID写入文件
                    QString t_Str=strList.at(i+1);                //链表向后移动到该学生成绩
                    //将该学生成绩替换为修改后的成绩
                    t_Str.replace(0,t_Str.length(),ui->edt_Score->text());
                    stream<<t_Str<<"\n";                          //写入
                    i++;                                          //链表后移到下一位同学
                    //利用提示信息通知修改成功
                    QMessageBox::warning(this,"恭喜","修改成功",QMessageBox::Ok);
                }
                else                                              //最后一行特殊处理
                {
                    if(i==strList.count()-1)
                    {
                        stream<<strList.at(i);
                    }
                    else
                    {
                        stream<<strList.at(i)<<"\n";
                    }
                }
            }
        }
        //及时关闭防止误操作
        writeFile.close();

        //及时将学生反馈文件中的学号清理掉
        QString strALL_2;       //用于储存文件全部信息
        QStringList strList_2;  //利用QString链表用于后续文件操作

        //读文件流操作
        QFile readFile_2("D:\\qtstudy\\summer_school\\school\\SCHOOL\\doubt.txt");
        if(readFile_2.open((QIODevice::ReadOnly|QIODevice::Text)))  //判断文件是否存在标准操作
        {
            QTextStream stream_2(&readFile_2);                        //构造输入流
            strALL_2=stream_2.readAll();                              //将strALL变为文本全部信息
        }
        readFile_2.close();                                         //及时关闭文件方式误操作


        //写文件流操作
        QFile writeFile_2("D:\\qtstudy\\summer_school\\school\\SCHOOL\\doubt.txt");
        if(writeFile_2.open(QIODevice::WriteOnly|QIODevice::Text))  //判断文件是否存在标准操作
        {
            QTextStream stream_2(&writeFile_2);                       //构造输出流
            strList_2=strALL_2.split("\n");                       //通过换行符将文件每一行信息读如QString链表
            for(int i=0;i<strList_2.count();i++)                    //遍历链表
            {
                if(strList_2.at(i).contains(ui->edt_ID->text()))    //当读到该学生学号时
                {
/*                    i++;                                        //链表后移到下一位同学
                    stream<<strList.at(i)<<"\n";*/                //通过输出流将学生ID写入文件
                }
                else                                              //最后一行特殊处理
                {
                    if(i==strList_2.count()-1)
                    {
                        stream_2<<strList_2.at(i);
                    }
                    else
                    {
                        stream_2<<strList_2.at(i)<<"\n";
                    }
                }
            }
        }
    });
}

/**************************************************
Name:        ~Tmodify()
Inputs:
Return Value:
Description:  析构函数
**************************************************/
Tmodify::~Tmodify()
{
    delete ui;
}
