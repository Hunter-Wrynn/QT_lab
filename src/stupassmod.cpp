#include "stupassmod.h"
#include "ui_stupassmod.h"

StuPassMod::StuPassMod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuPassMod)
{
    ui->setupUi(this);
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->edt_Pss );
    ui->edt_Pss->setValidator(validator);
    ui->edt_Pss->setMaxLength(6);
    ui->edt_Pss_2->setValidator(validator);
    ui->edt_Pss_2->setMaxLength(6);

    this->setWindowTitle(QStringLiteral("学生密码修改界面"));

    connect(ui->btn_Modify,&QPushButton::clicked,[=]()
    {

        if(ui->edt_Pss->text()!=ui->edt_Pss_2->text())
        {
            QMessageBox::warning(this,"提示","密码不一致",QMessageBox::Ok);
        }
        else
        {
            Student t_Stu;

            t_Stu.setID(ui->edt_User->text());

            QString strALL;
            QStringList strList;
            QFile readFile("D:\\qtstudy\\summer_school\\school\\SCHOOL\\pass.txt");
            if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
            {
                QTextStream stream(&readFile);
                strALL=stream.readAll();
            }
            readFile.close();

            QFile writeFile("D:\\qtstudy\\summer_school\\school\\SCHOOL\\pass.txt");
            if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
            {

                QTextStream stream(&writeFile);
                strList=strALL.split("\n");
                for(int i=0;i<strList.count();i++)
                {
                    if(strList.at(i).contains(ui->edt_User->text()))
                    {
                        stream<<ui->edt_User->text()<<"\n";
                        QString t_Str=strList.at(i+1);
                        t_Str.replace(0,t_Str.length(),ui->edt_Pss->text());
                        stream<<t_Str<<"\n";
                        i++;
                        QMessageBox::warning(this,"恭喜","修改成功",QMessageBox::Ok);
                    }
                    else
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
        writeFile.close();
        }

    });

    connect(ui->btn_Exe,&QPushButton::clicked,[=]()
    {

        ui->edt_User->clear();
        ui->edt_Pss->clear();
        ui->edt_Pss_2->clear();
        this->reject();

    });
}

StuPassMod::~StuPassMod()
{
    delete ui;
}
