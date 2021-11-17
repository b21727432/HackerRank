#ifndef H_stockType
#define H_stockType

#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>

using namespace std;

class stockType
{
public:
    stockType(string symbol, double openPrice, double closePrice, double highPrice,
              double lowPrevPrice, double closePrevPrice, int shares);
              
    stockType();
    
    void setStockInfo(string syms, double open, double close, double high,
                      double lowPrev, double closePrev, int noOfShares);

    friend istream &operator>>(istream &ins, stockType &stock);
    friend ostream &operator<<(ostream &outs, stockType &stock);
    
    
    void calculateGain(double closeP, double prevP);

    bool operator==(const stockType &stock1) const;
    bool operator!=(const stockType &stock1) const;
    bool operator<=(const stockType &stock1) const;
    bool operator<(const stockType &stock1) const;
    bool operator>=(const stockType &stock1) const;
    bool operator>(const stockType &stock1) const;

    string getSymbols() const ;
    double getOpenPrice() const ;
    double getClosePrice() const ;
    double getHighPrice() const ;
    double getLowPrevPrice() const ;
    double getClosePrevPrice() const ;
    double getShares() const ;
    double getGain() const ;

private:
    string symbols;
    double open_price, close_price, high_price, low_prev_price, close_prev_price, gain;
    int no_shares;
};
#endif
