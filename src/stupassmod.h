#ifndef STUPASSMOD_H
#define STUPASSMOD_H
#include <QRegExpValidator>
#include <QValidator>
#include <QRegExp>
#include <QDialog>
#include "student.h"
#include<QString>
#include<QStringList>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
namespace Ui {
class StuPassMod;
}

class StuPassMod : public QDialog
{
    Q_OBJECT

public:
    explicit StuPassMod(QWidget *parent = nullptr);
    ~StuPassMod();

private:
    Ui::StuPassMod *ui;
};

#endif // STUPASSMOD_H
