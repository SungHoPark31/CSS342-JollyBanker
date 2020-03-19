/*
 funds.cpp
  Assignment6
 
 This implements the funds.cpp

  Created by Sung Ho Park on 12/5/19.
  Copyright © 2019 Sung Ho Park. All rights reserved.
 
 */

#include "funds.h"
#include <iostream>

using namespace std;

Funds::Funds()
{
    //Default constructor
    fundName = "";
    money = 0;
}
Funds::Funds(string &fund)
{
    //Set the name and set the money to 0
    fundName = fund;
    money = 0;
}

int Funds::getMoney() const
{
    return money;
}

void Funds::setMoney(int mon)
{
    money = mon;
}

string Funds::getFundName()
{
    return fundName;
}
void Funds::setFundName(string fundN)
{
    fundName = fundN;
}


int Funds::deposit(int &mon)
{
    //Add the total amount of money wuith the passed in value.
    return money += mon;
}

bool Funds::transferDeposit(int amount, Funds *& transfer2)
{
    //Just to differentiate. 
    //Add the total amount of money wuith the passed in value.
    //But this is for transfer.
    money += amount;
    return true;
}

bool Funds::transferWithdraw(int amount, Funds *& transfer1)
{
    //Check if the amount is greater than total. If it is return false
    //and don't withdraw.
    if(amount < money)
    {
        money -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

int Funds::withdraw(int &mon)
{
    //Check for cases in the withdraw.
    int result = money - mon;
    if(result < 0 || result > money)
    {
        return money;
    }
    else
    {
        //Subtract it.
        money = result;
        return money;
    }
    return -1;
}

void Funds::print() const
{
    //Print out the string of a fund
    for(auto i = ls.begin(); i != ls.end(); i++)
    {
        cout << *i << endl;
    }
}

void Funds::history(string &history)
{
    //Push the string for the fund.
    ls.push_back(history);
}
