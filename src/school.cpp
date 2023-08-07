#include "school.h"
#include "ui_school.h"

School::School(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::School)
{
    ui->setupUi(this);
}

School::~School()
{
    delete ui;
}
