/*
 account.hpp
 Assignment6
 
 This is the account class. Each account has their own of 10 funds.
 Each fund is initialized to 0 and this class does the transaction.

 Created by Sung Ho Park on 12/2/19.
 Copyright © 2019 Sung Ho Park. All rights reserved.
 
 */



#ifndef account_h
#define account_h
#include <stdio.h>
#include <iostream>
#include "funds.h"

using namespace std;


class Account
{
private:
    Funds fundsA[10];
    string firstname;
    string lastname;
    int identifier;
    string funds[10] = {"Money Market", "Prime Money Market",
        "Long-Term Bond", "Short-Term Bond", "500 Index Fund",
        "Capital Value Fund", "Growth Equity Fund",
        "Growth Index Fund", "Value Fund","Value Stock Fund"};
    
public:
    /*
     This is the Constructor. This will initialize every private variable
     to a default variable
     */
    Account();
    
    /*
     This is the destructor and it will destroy the contents of funds.
     */
    ~Account();
    
    /*
     This is another constructor that will set the private variables to the
     values that are passed in.
     */
    Account(string first, string last, int id);
    
    /*
     This is the used to help the transfer case in the bank.cpp.
     This will withdraw the amount that needs to be transferred.
     */
    void transferWithdraw(int fifth, Account *&item,
                          int amount, string action);
    
    /*
     This is also used as to help the transfer case in the bank.cpp
     This will deposit the transferring amount.
     */
    void transferDeposit(int fifth, Account *&item,
                                  int amount, string action);
    
    /*
     A very big switch case. This is to check the fifth element and if it
     corresponds with the funds. The fifth element in an id is the fund so
     a switch case is needed. The char is the action. In the account, we are
     focusing on the deposit and the withdraw mostly. The action is pushing the
     string into a vector that keeps track of the funds history.
     */
    void transaction(int &fifth, int& amount, char &arr, string &action);
    
    /*
     Displays the contents of just this account and the funds.
     */
    void displayHistory() const;
    
    /*
     Displays the final history of the entire bank
     */
    void finalHistory() const;
    
    /*
     Displays the contents of an individual fund of this account.
     */
    void displayHistory(int fifth) const;
    
    /*
     Getter just in case if we need to get the fund of the fifth element.
     */
    int getFund(int &index) const;
    
    /*
     Setter that will set the amount of money in a certain account.
     */
    void setFund(int &fifth, int &amount);
    
    /*
     This is mostly needed for the bank.cpp to just what the fund name is. 
     */
    string getIndividualFund(int fifth);
    
    //Just some getters and setters just in case.
    string getFirstName();
    void setFirstName(string &n);
    string getLastName();
    void setLastName(string &n);
    int getID();
    void setID(int &id);
};

#endif /* account_h */
