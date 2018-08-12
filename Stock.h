//  Sedak Puri
//  Stocks.h
//  StockSymbolLookup
//  Compiler: Xcode
//  Created by Sedak Puri on 8/11/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#ifndef Stocks_h
#define Stocks_h
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <unordered_map>
#include "Stock.h"
#include <cctype>

class Stocks{
public:
    Stocks();
    unsigned int totalNum = 0;
    std::unordered_map<std::string, Stock> allStocks;
    void lookupStock(std::string);
};

#endif /* Stocks_h */
