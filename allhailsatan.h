#ifndef ALLHAILSATAN_H
#define ALLHAILSATAN_H

#include <QMainWindow>

namespace Ui {
class AllHailSatan;
}

class AllHailSatan : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllHailSatan(QWidget *parent = 0);

    ~AllHailSatan();

private slots:
    void on_diePastrana_clicked();

private:
    Ui::AllHailSatan *ui;
};

#endif // ALLHAILSATAN_H
