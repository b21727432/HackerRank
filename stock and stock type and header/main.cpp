#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stockType.h"
#include "stockListType.h"
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

int main(){
	
	ifstream infile("stocks.txt");
	string symbol;
	double opening, closing, today_high, today_low, prev_close;
	int volume;
	
	stockListType stocklar;
	
	while (infile >> symbol >> opening >> closing >> today_high >> today_low >> prev_close >> volume)
	{
    	stockType newStock(symbol, opening, closing, today_high, today_low, prev_close, volume);
    	stocklar.insert(newStock);
	}
	stocklar.printStocks();
	stocklar.sortStocks();
	
	cout << "Enter new stock details symbol, opening, closing, today high, today low, prev close and volume : " << endl;
    stockType newStockwithInput;
    cin >> newStockwithInput;
    cout << "Stock details : " << endl;
    cout << newStockwithInput;
    cout << "Symbol : " << newStockwithInput.getSymbols() << " Opening : " << newStockwithInput.getOpenPrice() << endl;
    stocklar.insert(newStockwithInput);
    cout << "Stock list after new stock : " << endl;
    stocklar.printStocks();
    
    cout << "Enter second new stock details symbol, opening, closing, today high, today low, prev close and volume : " << endl;
    stockType newStockwithInput2;
    cin >> newStockwithInput2;
    cout << "Stock details : " << endl;
    cout << newStockwithInput2;
    cout << "Symbol : " << newStockwithInput2.getSymbols() << " Opening : " << newStockwithInput2.getOpenPrice() << endl;
    stocklar.insert(newStockwithInput2);
    cout << "Stock list after new stock : " << endl;
    stocklar.printStocks();
    
    cout << "Are they equal or not equal or bigger or less? 0 false 1 true "<< endl;
    bool x1 = newStockwithInput == newStockwithInput2;
    bool x2 = newStockwithInput != newStockwithInput2;
    bool x3 = newStockwithInput >= newStockwithInput2;
    bool x4 = newStockwithInput > newStockwithInput2;
    bool x5 = newStockwithInput <= newStockwithInput2;
    bool x6 = newStockwithInput < newStockwithInput2;
    cout << "Equal? : " << x1 << endl;
    cout << "Not Equal? : " << x2 << endl;
    cout << "Bigger or equal? : " << x3 << endl;
    cout << "Bigger? : " << x4 << endl;
    cout << "Less or equal? : " << x5 << endl;
    cout << "Less? : " << x6 << endl;
    
    
	return 0;
}
