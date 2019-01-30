#include <cmath>
#include <QMainWindow>


class Asset {

    const double cost; //cost of asset
    double s_value; //salvage value
    int u_life; //useful life in years

   public:
    int curr_year; //spent life in years
    double curr_depr; //current year depreciation
    double cum_depr; //cumulated_depreciation

    Asset (double a, double b, int c) : cost (a), s_value (b), u_life (c) {curr_year=0; curr_depr=0; cum_depr=0;}

    int getcurr_year () {return curr_year;}
    double getcurr_depr () {return curr_depr;}
    double getcum_depr () {return cum_depr;}
    double getcost () {return cost;}
    double gets_value () {return s_value;}
    int getu_life () {return u_life;}
    double getnet_value() {return cost - cum_depr;}


    };

