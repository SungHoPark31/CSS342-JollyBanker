/*
 funds.hpp
 Assignment6
 
 This is the funds class. This contains 10 funds and is in the array
 This is mostly for the fifth number if the id contains the fifth id.
 Each time the fund is done an action, it is enqueued into the action
 history.

 Created by Sung Ho Park on 12/5/19.
 Copyright © 2019 Sung Ho Park. All rights reserved.
 */


#ifndef funds_h
#define funds_h

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Funds
{
private:
    //Total amount of money.
    int money;
    //Fund name
    string fundName;
    
    //List of actions
    vector<string> ls;
    
public:
    /*
     Constructor. Initializes the private variables.
     */
    Funds();
    
    /*
     Another constructor that initializes the fund name.
     */
    Funds(string &fund);
    
    //Couple of getters and setters just in case.
    int getMoney() const;
    void setMoney(int mon);
    string getFundName();
    void setFundName(string fundN);
    
    /*
     This will deposit the money in the fund. Since the fund
     has the total money, this will update the total money.
     This is also the main Main MAIN way that this program will
     deposit
     */
    int deposit(int &mon);
    
    /*
     This will withdraw the money in the fund. Since the fund
     has the total money, this will update the total money.
     This is also the main Main MAIN way that this program will
     withdraw
     */
    int withdraw(int &mon);
    
    /*
     This will withdraw the money in the fund by withdrawing the
     original fund account. Since the fund
     has the total money, this will update the total money.
     This is also the main Main MAIN way that this program will
     withdraw transfer
     */
    bool transferWithdraw(int amount, Funds *&transfer1);
    
    /*
    This will deposit the money in the fund by withdrawing the
    original fund account. Since the fund
    has the total money, this will update the total money.
    This is also the main Main MAIN way that this program will
    deposit transfer.
    */
    bool transferDeposit(int amount, Funds *&transfer2);
    
    /*
     This will enqueue the string of actions to the vector of
     actions.
     */
    void history(string &history);
    
    /*
     This will print out the vector. 
     */
    void print() const;
};

#endif /* funds_hpp */
