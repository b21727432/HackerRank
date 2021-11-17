#include "stockType.h"
#include<string>

istream &operator>>(istream &ins, stockType &stock)
{
    ins >> stock.symbols;
    ins >> stock.open_price;
    ins >> stock.close_price;
    ins >> stock.high_price;
    ins >> stock.low_prev_price;
    ins >> stock.close_prev_price;
    ins >> stock.no_shares;
    stock.calculateGain(stock.close_price, stock.close_prev_price);
    return ins;
}

ostream &operator<<(ostream &output, stockType &stock)
{
    output << setw(5) << right << stock.getSymbols() << " " << setw(7) << right << stock.getOpenPrice() << "   " << setw(7) << right<<stock.getClosePrice() << "  " <<setw(7) << right<< stock.getHighPrice() << " " << setw(7) << right << stock.getLowPrevPrice() << " " << setw(8) << right << stock.getClosePrevPrice()  << "  " << setw(8) << right << stock.getShares() << " " << setw(9) << right << stock.getGain() << endl;
}

void stockType::calculateGain(double closeP, double prevP)
{
    gain = ((closeP - prevP) / (prevP)*100);
}

bool stockType::operator==(const stockType &stock1) const
{
    return (symbols == stock1.symbols);
}
bool stockType::operator!=(const stockType &stock1) const
{
    return (symbols != stock1.symbols);
}
bool stockType::operator<=(const stockType &stock1) const
{
    return (symbols <= stock1.symbols);
}
bool stockType::operator<(const stockType &stock1) const
{
    return (symbols < stock1.symbols);
}
bool stockType::operator>=(const stockType &stock1) const
{
    return (symbols >= stock1.symbols);
}
bool stockType::operator>(const stockType &stock1) const
{
    return (symbols > stock1.symbols);
}

void stockType::setStockInfo(string syms, double open, double close, double high, double lowPrev, double closePrev, int noOfShares)
{
	symbols = syms;
	open_price = open;
	close_price = close;
	high_price = high;
	low_prev_price = lowPrev;
	close_prev_price = closePrev;
	no_shares = noOfShares;
	gain = ((close_price - close_prev_price) / (close_prev_price)*100);     	
}

stockType::stockType(string symbol, double openPrice, double closePrice, double highPrice, double lowPrevPrice, double closePrevPrice, int shares)
{
	setStockInfo(symbol, openPrice, closePrice, highPrice, lowPrevPrice, closePrevPrice, shares);
}
stockType::stockType(){
	
};

string stockType::getSymbols() const { return symbols; }
double stockType::getOpenPrice() const { return open_price; }
double stockType::getClosePrice() const { return close_price; }
double stockType::getHighPrice() const { return high_price; }
double stockType::getLowPrevPrice() const { return low_prev_price; }
double stockType::getClosePrevPrice() const { return close_prev_price; }
double stockType::getShares() const { return no_shares; }
double stockType::getGain() const { return gain; }
