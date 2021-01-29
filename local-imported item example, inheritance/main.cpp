#include "item.h"
#include "localItem.h"
#include "importedItem.h"
#include <iomanip>
using std::left;
using std::setw;
#include <iostream>
using std::cout;
using std::endl;
#include <string>

int main(void)
{
// declare a local item object with description "kalem" and price 1.5
	localItem kalem("kalem", 1.5);
	localItem defter("defter", 5.0);
	importedItem bilgisayar("bilgisayar",5000.0);
	importedItem telefon("telefon", 2500.0);
	
	localItem::setTaxRate(0.01);
	importedItem::setTaxRate(0.05);
	
	item arr[4];
	
	arr[0] = kalem;
	arr[1] = defter;
	arr[2] = bilgisayar;
	arr[3] = telefon;
	
// declare a local item object with description "defter" and price 5.0
// declare an imported item object with description "bilgisayar" and price 5000.0
// declare an imported item object with description "telefon" and price 2500.0
// set local item tax rate to 0.01
// set imported item tax rate to 0.05
// put all declared local and imported item objects in an array
	double totalTax;
	cout << "local item tax : " << localItem::getTaxRate() << endl
	<< "imported item tax: " << importedItem::getTaxRate() << endl
	<< endl
	<< setw(40) << left << "Description" << setw(20) << left << "Price" << setw(20) << left << "Taxed Price" << endl;
	totalTax = 0.0;
	for(int i=0; i<4; i++)
	{
		cout << setw(40) << left << arr[i].getDescription() << endl
		<< setw(20) << left << arr[i].getPrice() << endl
		<< setw(20) << left << arr[i].tax() << endl;
		totalTax += arr[i].tax() - arr[i].getPrice();
	}
	cout << "Total Tax: " << totalTax << endl;
	return 0;
}
