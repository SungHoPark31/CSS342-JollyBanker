/*
 bank.h
 Assignment6
 
 This is the main bank class. This will read the txt file and
 store each line into a stl queue and judging by the lines
 actions, it will execute a transaction.

 Created by Sung Ho Park on 12/2/19.
 Copyright © 2019 Sung Ho Park. All rights reserved.
 */

#ifndef bank_h
#define bank_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>

#include "account.h"
#include "binarySearchTree.h"

class Bank
{
public:
    /*
     This is to read the file. As it is reading each line, the line is
     stored into a queue as a string.
     */
    void readFile(string fileName);
    
    /*
     This is the banks transaction that checks the first character
     and what action that it needs to take.
     
     'O' = open
     'D' = deposit
     'W' = Withdraw
     'H' = distory
     'T' = transfer.
     */
    void theTransaction();
    
    /*
     Display the banks history and get the total balance
     */
    void display() const;
    
    /*
     This is very important because each time we are getting id or the
     fifth element, it is a string in the queue. We need to make it into
     an integer in order to move on.
     */
    int convertToInt(string &str);
    
private:
    BSTree accountsAndBalances;
    //Queue of strings
    queue<string> account;
};

#endif /* bank_hpp */
