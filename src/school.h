#ifndef SCHOOL_H
#define SCHOOL_H

#include <QDialog>

namespace Ui {
class School;
}

class School : public QDialog
{
    Q_OBJECT

public:
    explicit School(QWidget *parent = nullptr);
    ~School();

private:
    Ui::School *ui;
};

#endif // SCHOOL_H
