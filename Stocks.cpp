//  Sedak Puri
//  Stocks.cpp
//  StockSymbolLookup
//  Compiler: Xcode
//  Created by Sedak Puri on 8/11/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#include "Stocks.h"
using namespace std;

Stocks:: Stocks(){
    //File input setup
    ifstream finN ("nasdaqlisted.txt");
    if(finN.fail()){
        cout<<"Unable to read file"<<endl;
        exit(-1);
    }
    ifstream finU ("otherlisted.txt");
    if(finU.fail()){
        cout<<"Unable to read other"<<endl;
        exit(-1);
    }
    
    //Reading in finN
    string line;
    getline(finN, line);            //Initial iteration for the heading of file
    while(!finN.eof()){
        //Reading in file
        getline(finN, line);
        
        //Parsing through symbol
        string symbol = "";
        int letterIndex = 0;
        while(line[letterIndex] != '|'){
            symbol += line[letterIndex];
            letterIndex++;
        }
        letterIndex++;
        
        //Parsing through security name
        string security = "";
        while(line[letterIndex] != '|'){
            security += line[letterIndex];
            letterIndex++;
        }
        
        //Making stock object and adding it to the map
        Stock s(symbol, security);
        pair<string, Stock> symSec (symbol, s);
        allStocks.insert(symSec);
        totalNum++;
    }
    
    while(!finU.eof()){
        //Reading in file
        getline(finU, line);
        
        //Parsing through symbol
        string symbol = "";
        int letterIndex = 0;
        while(line[letterIndex] != '|'){
            symbol += line[letterIndex];
            letterIndex++;
        }
        letterIndex++;
        
        //Parsing through security name
        string security = "";
        while(line[letterIndex] != '|'){
            security += line[letterIndex];
            letterIndex++;
        }
        
        //Making stock object and adding it to the map
        Stock s(symbol, security);
        pair<string, Stock> symSec (symbol, s);
        allStocks.insert(symSec);
        totalNum++;
    }
}

void Stocks:: lookupStock(string symb){
    //Stock looup
    Stocks s;
    unordered_map<string, Stock>::const_iterator iter = s.allStocks.find(symb);
    if(iter == s.allStocks.end()){
        cout<<"Stock not found!"<<endl;
    } else {
        cout<<iter->first<<" is the stock ticker for: "<<iter->second.securityName<<endl;
    }
}
