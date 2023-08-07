#include "rank.h"
#include "ui_rank.h"
/**************************************************
Name:             Rank
Inputs:
Return Value:
Description:      设置背景控件
**************************************************/
Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database();
    db.open();

    this->setWindowTitle(QStringLiteral("全校成绩"));//设置窗口名称
    /**************************************************
    Name:         btn_Pin
    Inputs:
    Return Value:
    Description:  打印排名
    **************************************************/
    connect(ui->btn_Pin,&QPushButton::clicked,[=]()                       //btn_pin的lamda表达式
    {


        //初始化
        ui->tb_Rank->setHorizontalHeaderLabels(QStringList() << "学号" << "成绩");

        //文件流操作
        QString path="D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt";;
        QFile file(path);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString line;
        QTextStream in(&file);                //用文件构造流
        line = in.readLine();                 //读取一行放到字符
        QString strALL;                       //全部读出成绩
        QStringList strList;                  //调用QString链表

        //文件读入
        QFile readFile("D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt");
        if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
        {
            QTextStream stream(&readFile);
            strALL=stream.readAll();
        }
        readFile.close();                           //即使关闭文件
        strList=strALL.split("\n");                 //链表导入学号与成绩
        int t_num=strList.count()/2;                //学生总数
        Student t_nStu[t_num];                      //创建学生临时变量
        int t_d=0;                                  //计数器
        for(int i=0;i<strList.count()-1;i++)        //遍历
        {
            t_nStu[t_d].setID(strList.at(i));       //设置学号
            t_nStu[t_d].setscore(strList.at(i+1));  //设置成绩
            t_d++;                                  //学号加一
            i++;

        }

        //利用插入排序排名成绩
        for( int i =0;i<t_num;i++)
        {

             for(int j=i;j>=1;j--)
             {
                  if(t_nStu[j].getscore().toInt()<t_nStu[j-1].getscore().toInt())
                  {
                      Student t_s;
                      t_s.setID(t_nStu[j].getID());
                      t_s.setscore(t_nStu[j].getscore());
                      t_nStu[j].setID(t_nStu[j-1].getID());
                      t_nStu[j].setscore(t_nStu[j-1].getscore());
                      t_nStu[j-1].setID(t_s.getID());
                      t_nStu[j-1].setscore(t_s.getscore());
                  }
                  else
                      break;
             }
        }


        //将成绩写入tablewidget
        for(int i=0;i<t_num;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(j==0)

                    ui->tb_Rank->setItem(i,j,new QTableWidgetItem(t_nStu[t_num-1-i].getID()));
                if(j==1)
                    ui->tb_Rank->setItem(i,j,new QTableWidgetItem(t_nStu[t_num-1-i].getscore()));
            }
        }

    });
}

/**************************************************
Name:          compareBarData
Inputs:        const Student &barAmount_1, const Student &barAmount_2
Return Value:  true/false
Description:   比较student.score
**************************************************/
bool Rank::compareBarData(const Student &barAmount_1, const Student &barAmount_2)
{
    return barAmount_1.getscore().toInt()>barAmount_2.getscore().toInt();
}
/**************************************************
Name:         ~Rank()
Inputs:
Return Value:
Description:  析构函数
**************************************************/
Rank::~Rank()
{
    delete ui;
}
