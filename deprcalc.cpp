#include "deprcalc.h"
#include "ui_deprcalc.h"
#include <QLocale>

//definition of the DeprCalc constructor
DeprCalc::DeprCalc(QWidget *parent) :
    QMainWindow(parent), //calling the QMAinWindow constructor
    ui(new Ui::DeprCalc) //creates the UI class instance and assigns it to the ui member
{
    ui->setupUi(this); //setting up the ui

    //set background color
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::lightGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    //set input fields' validation rules
    QDoubleValidator *dval= new QDoubleValidator(this);
    dval->setNotation(QDoubleValidator::StandardNotation);
    dval->setBottom(0.00);
    dval->setDecimals(4);
    dval->setTop(9999999999.0000);
    ui->ledit_cost->setValidator(dval);
    ui->ledit_s_value->setValidator(dval);

    QIntValidator *ival= new QIntValidator(this);
    ival->setBottom(0);
    ival->setTop(100);
    ui->ledit_u_life->setValidator(ival);



    //initialize combobox to input method
    QStringList citems = {"Straight-line", "Sum-of-year-digits", "Net-value-based, fixed rate", "Double-declining"};
    ui->cmb_Method->insertItems(0,citems);

    //initialize result table headers
    QStringList headers = {"Year", "Current d.", "Cumulated d.", "Net value"};
    ui->table_Result->setHorizontalHeaderLabels(headers);


    ui->table_Result->setColumnWidth(0,20);
    ui->table_Result->setColumnWidth(1,177);
    ui->table_Result->setColumnWidth(2,177);
    ui->table_Result->setColumnWidth(3,177);
}

DeprCalc::~DeprCalc()
{
    delete ui;
}

void DeprCalc::disp_asset(Asset& a)
{
        QString strcurr_year, strcurr_depr, strcum_depr, strnet_value;
        strcurr_year.setNum(a.getcurr_year());
        strcurr_depr.setNum(a.getcurr_depr());
        strcum_depr.setNum(a.getcum_depr());
        strnet_value.setNum(a.getnet_value());

        QTableWidgetItem *qtwicurr_year = new QTableWidgetItem(strcurr_year,0);
        qtwicurr_year->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *qtwicurr_depr = new QTableWidgetItem(strcurr_depr,0);
        qtwicurr_depr->setTextAlignment(Qt::AlignRight);
        QTableWidgetItem *qtwicum_depr = new QTableWidgetItem(strcum_depr,0);
        qtwicum_depr->setTextAlignment(Qt::AlignRight);
        QTableWidgetItem *qtwinet_value = new QTableWidgetItem(strnet_value,0);
        qtwinet_value->setTextAlignment(Qt::AlignRight);

        //ui->table_Result->setRowCount(a.getu_life());
        ui->table_Result->insertRow(a.curr_year-1);
        QString row_header = "";
        QTableWidgetItem *qtwi_row_header = new QTableWidgetItem(row_header,0);
        ui->table_Result->setVerticalHeaderItem(a.curr_year-1, qtwi_row_header);
        ui->table_Result->setItem(a.curr_year-1,0,qtwicurr_year);
        ui->table_Result->setItem(a.curr_year-1,1,qtwicurr_depr);
        ui->table_Result->setItem(a.curr_year-1,2,qtwicum_depr);
        ui->table_Result->setItem(a.curr_year-1,3,qtwinet_value);

}


void DeprCalc::on_btn_Start_clicked()
{
    ui->table_Result->setRowCount(0);

    QLocale loc(QLocale::system());
    double t_cost = loc.toDouble(ui->ledit_cost->text());
    double s_value = loc.toDouble(ui->ledit_s_value->text());
    int u_life = (ui->ledit_u_life->text()).toInt();

    Asset a (t_cost, s_value, u_life);

    int method = ui->cmb_Method->currentIndex();

    switch (method)
    {

    //straight line method

        case 0:

        for (int i = 1;i<=a.getu_life();i++)
            {
            a.curr_year++;
            a.curr_depr = (a.getcost() - a.gets_value())/a.getu_life();
            a.cum_depr += a.curr_depr;

            disp_asset(a);

            }

        break;


    //sum-of-year-digits
        case 1:
        {
            double sod = (pow(a.getu_life(), 2.0) + a.getu_life())/2;
            double sdv = (a.getcost() - a.gets_value()) / sod;

            for (int i = 1;i<=a.getu_life();i++)
                {
                a.curr_year++;
                a.curr_depr = sdv * ((a.getu_life()+1)-i);
                a.cum_depr += a.curr_depr;

                disp_asset(a);

                }

         }
        break;

  //net-based, fix-rate method

    case 2:
            {



        for (int i = 1;i<=a.getu_life();i++)
                {
                a.curr_year++;
                a.curr_depr = a.getnet_value() * (1 - (pow((a.gets_value()/a.getcost()),(1/static_cast<double>(a.getu_life())))));
                a.cum_depr += a.curr_depr;

                disp_asset(a);

                }
                break;
            }

//double declining method

   case 3:
            {


         for (int i = 1;i<=a.getu_life();i++)
                {
                a.curr_year++;
                a.curr_depr = (a.getnet_value() * 2)/a.getu_life(); //multiplier = 2
                a.cum_depr += a.curr_depr;

                disp_asset(a);
                }

                break;
            }

       }


}


void DeprCalc::on_btn_Start_pressed()
{

}

void DeprCalc::on_actionExit_Program_triggered()
{
    QApplication::quit();
}
