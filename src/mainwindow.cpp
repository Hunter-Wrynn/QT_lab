#include "mainwindow.h"
#include "ui_mainwindow.h"
/**************************************************
Name:             MainWindow
Inputs:           None
Return Value:     None
Description:      设置背景控件
**************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();//打印qt支持的数据库类型
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//设置显示中文
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//a
    db.setHostName("127.0.0.1");             //b
    db.setDatabaseName("admin.db");              //c
    db.setUserName("root");                  //d
    db.setPassword("123456");                //e
    db.open();

    this->setWindowTitle(QStringLiteral("东大考试系统"));//设置窗口名称

    //设置背景颜色
    ui->widget->setStyleSheet("background-color:rgba(244,244,244,200)");

    //设置edit栏字体，字号，提示信息，输入限制
    ui->btn_Login->setFont(QFont("宋体", 18));
    ui->edt_User->setFont(QFont("宋体", 18));
    ui->edt_Pss->setFont(QFont("宋体", 18));
    ui->cmb_Job->setFont(QFont("宋体", 12));
    ui->edt_User->setPlaceholderText("账号");
    ui->edt_Pss->setPlaceholderText("密码");
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->edt_Pss );
    ui->edt_Pss->setValidator(validator);
    ui->edt_Pss->setMaxLength(6);

    //设置确定按钮点击样式
    QString btnStyle2 =
            "QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px;  \
            }\
            QPushButton:hover{\
                color: rgb(255, 255, 255); \
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\
                border:1px;  \
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px; \
            }\
            QPushButton:pressed{    \
                color: rgb(255, 255, 255); \
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \
                border:1px;  \
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px; \
            }";
     ui->btn_Login->setStyleSheet(btnStyle2);


     //设置账号，密码前前置，后置图案
     ui->label_E->setAlignment(Qt::AlignCenter);
     ui->label_E->setPixmap(QPixmap(":/image.qrc/EYE.JPG").scaled(20, 20));
     ui->label_U->setAlignment(Qt::AlignCenter);
     ui->label_U->setPixmap(QPixmap(":/image.qrc/pic/user_3.png").scaled(20, 20));
     ui->label->setAlignment(Qt::AlignCenter);
     ui->label->setPixmap(QPixmap(":/image.qrc/pic/seu.png").scaled(20, 20));


     //设置密码隐藏功能
     ui->edt_Pss->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     ui->edt_Pss->setEchoMode(QLineEdit::Password);
     ui->label_E->installEventFilter(this);//安装事件触发器


/**************************************************
Name:             btn_Login
Inputs:
Return Value:
Description:      转到学生登录界面
**************************************************/
    connect(ui->btn_Login,&QPushButton::clicked,[=]()
    {
       if(ui->cmb_Job->currentText()=="学生")//判断cmb_Job选择为学生
       {
           Student t_Stu;
           t_Stu.setID(ui->edt_User->text());//创建临时学生类并读入ID

           m_Stusc.ui->edt_User->setText(t_Stu.getID());  //设置学生查询成绩界面ID
           m_Stusc.ui->edt_User->setReadOnly(true);        //将学生查询成绩界面ID设为只读

           QString path_1="D:\\qtstudy\\summer_school\\school\\SCHOOL\\pass.txt";  //打开学生密码文件
           QString path_2="D:\\qtstudy\\summer_school\\school\\SCHOOL\\score.txt"; //打开学生成绩文件

           //文件读写操作验证密码是否正确
           QFile file_1(path_1);
           QFile file_2(path_2);
           file_1.open(QIODevice::ReadOnly | QIODevice::Text);
           file_2.open(QIODevice::ReadOnly | QIODevice::Text);
           QString line_1;
           QString line_2;
           QTextStream in_1(&file_1);    //用文件构造流
           QTextStream in_2(&file_2);
           line_1 = in_1.readLine();     //读取一行放到字符串
           line_2 = in_2.readLine();
           bool t_nFlag=false;           //定义flag用于判定是否找到该学生
           while(!line_2.isNull())       //字符串有内容
           {
               if(line_2==t_Stu.getID())//查询到该学生
               {
                  line_2=in_2.readLine();//循环读取下行
                  t_nFlag=true;          //flag为true
                  break;
               }
               line_2=in_2.readLine();
           }
           if(t_nFlag==false)

               QMessageBox::warning(this,"提示","没有您的成绩",QMessageBox::Ok);  //利用 QMessageBox 提示

           else
           {
               while(!line_1.isNull())         //字符串有内容
               {
                   if(line_1==t_Stu.getID())
                   {
                      line_1=in_1.readLine();  //循环读取下行
                      break;
                   }
                   line_1=in_1.readLine();
               }
               if(line_1==ui->edt_Pss->text())  //密码正确
               {
                    m_Stusc.exec();
               }
               else
               {  //利用 QMessageBox 提示
                   QMessageBox::warning(this,"提示","密码错误",QMessageBox::Ok);
               }
           }
           file_1.close();  //及时关闭文件防止误操作
           file_2.close();
       }//学生界面结束


       if(ui->cmb_Job->currentText()=="教师")                                     //判断cmb_Job选择为学生
       {
           if(ui->edt_User->text()==""||ui->edt_Pss->text()=="")                  //未输入账号或密码
           {
               QMessageBox::warning(this,"提示","请填写账号或密码",QMessageBox::Ok); //利用 QMessageBox提示
           }
           else
           {
               Teacher t_Tea;
               t_Tea.setID(ui->edt_User->text());//创建临时学生类并读入ID

               //打开教师密码文件
               QString path="D:\\qtstudy\\summer_school\\school\\SCHOOL\\tpass.txt";

               //文件读写操作验证密码是否正确
               QFile file(path);
               file.open(QIODevice::ReadOnly | QIODevice::Text);
               QString line;
               QTextStream in(&file);          //用文件构造流
               line = in.readLine();           //读取一行放到字符串
               while(!line.isNull())           //字符串有内容
               {

                   if(line==t_Tea.getID())
                   {
                       line=in.readLine();     //循环读取下行
                       break;
                   }
                   line=in.readLine();
               }
               if(line==ui->edt_Pss->text())   //密码正确

                   m_Tm.exec();               //转至教师界面

               else
                     //未输入账号或密码
                   QMessageBox::warning(this,"提示","密码错误",QMessageBox::Ok);

               file.close();                   //及时关闭文件防止误操作
           }


       }//教师界面结束

       if(ui->cmb_Job->currentText()=="管理员")                                  //判断cmb_Job选择为学生
       {
           QString id=ui->edt_User->text();
           QString psswd=ui->edt_Pss->text();
           QSqlDatabase db = QSqlDatabase::database();
           db.open();
           QString t_strCmd="create table if not exists admin (id varchar(64),psswd varchar(64))";
           QSqlQuery query;
           query.exec(t_strCmd);
           QString id_1="5811";
           QString psswd_2="123456";
           QString str = QString("insert into admin values('%1', '%2')").arg(id_1).arg(psswd_2);
           query.exec(str);
           QSqlTableModel *model=new QSqlTableModel;
           model->setTable("admin");
           model->setFilter(QString("id='%1' and psswd='%2'").arg(id).arg(psswd));
           model->select();
           int row=model->rowCount();
           if(row>0)
           {
               m_Am.exec();
           }
           else
           {
               QMessageBox::warning(this,"提示","密码错误",QMessageBox::Ok);
           }
       }
    });



}
/**************************************************
Name:            eventFilter
Inputs:          QObject *watched, QEvent *event
Return Value:    bool
Description:     鼠标碰事件触发
**************************************************/
    bool MainWindow::eventFilter(QObject *watched, QEvent *event)
    {
        switch (event->type()) {
            case QEvent::Enter:
                ui->edt_Pss->setEchoMode(QLineEdit::Normal);
                break;
            case QEvent::Leave:
                ui->edt_Pss->setEchoMode(QLineEdit::Password);
                break;
            default:
                break;
        }
        return QWidget::eventFilter(watched, event);
    }


/**************************************************
Name:            ~MainWindow()
Inputs:
Return Value:
Description:     析构
**************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

