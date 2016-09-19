#include "allhailsatan.h"
#include "ui_allhailsatan.h"
#include <QMessageBox>

AllHailSatan::AllHailSatan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllHailSatan)
{
    ui->setupUi(this);
}

AllHailSatan::~AllHailSatan()
{
    delete ui;
}

void AllHailSatan::on_diePastrana_clicked()
{
    QMessageBox mq;
    mq.setText("Muere Pastrana");
    mq.exec();
}
