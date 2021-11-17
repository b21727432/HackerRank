#ifndef H_stockListType
#define H_stockListType

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stockType.h"

using namespace std;

class stockListType
{
public:
    stockListType();
 
    void insert(const stockType &item);
    void sortStocks();
    void printStocks();
private:
    vector<stockType> list;
};
#endif
