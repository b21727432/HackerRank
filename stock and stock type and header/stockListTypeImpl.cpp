
#include <algorithm>
#include "stockListType.h"
#include "stockType.h"

void stockListType::insert(const stockType &item){
	list.push_back(item);
}
void stockListType::printStocks(){
	int i;
	double assets = 0;
	cout << "*********     Financial Report     *********"<< endl;
	cout << "Stock         Today            Previous   Percent"<< endl;
	cout << "Symbol   Open     Close    High     Low      Close    Volume   Gain" << endl;
	cout << "------   ----     -----    ----     ---      ----     ------   ----" << endl;
	for(i = 0; i < list.size(); i++){
		cout << list[i];
		assets += list[i].getClosePrice() * (double)list[i].getShares();
	}
	cout << "Closing Assets: " << assets << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}
void stockListType::sortStocks(){
	sort(list.begin(), list.end());
	cout << "*********    Sorted Financial Report     *********"<< endl;
	cout << "Stock         Today            Previous   Percent"<< endl;
	cout << "Symbol   Open     Close    High     Low      Close    Volume   Gain" << endl;
	cout << "------   ----     -----    ----     ---      ----     ------   ----" << endl;
	int i;
	double assets = 0;
    for (i = 0; i < list.size(); i++){
    	cout << list[i];
    	assets += list[i].getClosePrice() * (double)list[i].getShares();
	}
	cout << "Closing Assets: " << assets << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        
}

stockListType::stockListType(){
	
}
