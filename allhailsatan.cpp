#include "allhailsatan.h"
#include "ui_allhailsatan.h"

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
