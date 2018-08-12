//  Sedak Puri
//  main.cpp
//  StockSymbolLookup
//  Compiler: Xcode
//  Created by Sedak Puri on 8/11/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#include "Header.h"
#include "Stocks.h"
using namespace std;

int main() {
    //Initial setup
    Stocks *stocksMap = new Stocks;
    string symbol;
    cout<<"Welcome to the stock symbol searcher user!"<<endl;
    
    //Taking in user input
    do{
        do{
            cout<<"Enter a stock symbol of a stock listed in the NASDAQ to find the company!"<<endl;
            cin>>symbol;
            if(isalpha(symbol[0]) && symbol.length() <= 5){
                //Formatting the user input
                string sentinel = "";
                for(int i = 0; i < symbol.length(); i++){
                    sentinel += toupper(symbol[i]);
                }
                symbol = sentinel;
                
                //Looking up stock!
                cout<<endl;
                stocksMap->lookupStock(symbol);
                cout<<endl;
            }
        } while(!isalpha(symbol[0]) || symbol.length() > 5);
        
        //Asking user if they want to retry with another symbol!
        string resp;
        cout<<"Would you like to look up another symbol? (y or n)"<<endl;
        cin>>resp;
        if((resp == "n") || (resp == "N")){break;}
        cout<<endl;
    } while(true);
    return 0;
}

