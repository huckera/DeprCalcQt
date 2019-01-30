#ifndef DEPRCALC_H
#define DEPRCALC_H

#include <QMainWindow>
#include "Asset.h"

namespace Ui {
class DeprCalc;
}

class DeprCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeprCalc(QWidget *parent = nullptr);
    ~DeprCalc();

private slots:
    void on_btn_Start_clicked();

    void on_btn_Start_pressed();

    void disp_asset(Asset& a);

//declare a member variable which is a pointer to the Notepad UI class
    void on_actionExit_Program_triggered();

private:
    Ui::DeprCalc *ui;


};


#endif // DEPRCALC_H
