#ifndef TEAPASSMOD_H
#define TEAPASSMOD_H
#include <QRegExpValidator>
#include <QValidator>
#include <QRegExp>
#include <QDialog>
#include "teacher.h"
#include<QString>
#include<QStringList>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
namespace Ui {
class TeaPassMod;
}

class TeaPassMod : public QDialog
{
    Q_OBJECT

public:
    explicit TeaPassMod(QWidget *parent = nullptr);
    ~TeaPassMod();

private:
    Ui::TeaPassMod *ui;
};

#endif // TEAPASSMOD_H
