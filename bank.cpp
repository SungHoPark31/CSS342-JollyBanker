/*
 bank.cpp
 Assignment6
 
 This implements the bank.h

 Created by Sung Ho Park on 12/2/19.
 Copyright © 2019 Sung Ho Park. All rights reserved.
 
 */


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>

#include "bank.h"
#include "account.h"
#include "binarySearchTree.h"


using namespace std;

void Bank::readFile(string fileName)
{
    //Create the ifstream
    ifstream inFile;
    
    //Open it
    inFile.open(fileName);
    
    //If it fails, then don't open
    if (inFile.fail())
    {
        cout << "Error Opening file" << endl;
        exit(1);
    }
    
    //Make the string.
    string transaction;
    
    //While it is not the end of file...
    while(!inFile.eof())
    {
        //Get each of the line. 
        getline(inFile, transaction);
        account.push(transaction);
    }
    //Close inFile
    inFile.close();
}

int Bank::convertToInt(string &str)
{
    stringstream stringInt(str);
    int intNum = 0;
    stringInt >> intNum;
    return intNum;
}

void Bank::theTransaction()
{
    while(!account.empty())
    {
        //Split the string into 4 sections.
        //1. The action
        //2. First name
        //3. Last Name
        //4. The amount
        string splitArray[4];
    
        //The act of splitting
        stringstream str(account.front());
        for(int i = 0; i < 4; i++)
        {
            //Put them inside of splitArray
            str >> splitArray[i];
            //cout << splitArray[i] << endl;
        }

        //Set what each of the items inside of the array are.
        string action = splitArray[0];
    
        //Since the action is a char, convert the action to a char.
        char actionChar[action.size() - 1];
        strcpy(actionChar, action.c_str());
        
        //Make a new account
        
        //Switch Statement for the char.
        switch(actionChar[0])
        {
            case 'O':
            {
                //If it is O, add it to binary Search tree
                string firstName = splitArray[1];
                string lastName = splitArray[2];
                string idString = splitArray[3];
                
                //Convert the id to an integer.
                int idInt = convertToInt(idString);
                
                //Set everything to the private variables of account.
                Account *acc = new Account(firstName, lastName, idInt);
                //Insert the account item in the tree.
                accountsAndBalances.Insert(acc);
                break;
            }
            case 'D':
            {
                //Check if there is a fifth element in the id.
                Account *acc;
                string idString = splitArray[1];
                string id;
                string fifthId;

                if(idString.size() > 5 || idString.size() < 4)
                {
                    cout << "ERROR" << endl;
                }
                //If there is a length of 5, meaning that there is a fifth number...
                else
                {
                    //4 digits
                    id = idString.substr(0, 4);

                    //5th digit
                    fifthId = idString.substr(4);

                    //Convert both the numberString to integer.
                    int identifier = convertToInt(id);
                    int fifthIdentifier = convertToInt(fifthId);

                    //Find it
                    bool found = accountsAndBalances.Retrieve(identifier, acc);

                    if(found == true)
                    {
                        //If you found it, then do the transaction
                        //Convert the amount to an integer.
                        string amount = splitArray[2];
                        int amountInt = convertToInt(amount);
                        
                        stringstream ss;
                        string str;
                        char mychar = actionChar[0];
                        ss << mychar;
                        ss >> str;
                        
                        string str1 = str + " " + idString  + " " + amount;
                        
                        acc->transaction(fifthIdentifier, amountInt, actionChar[0], str1);
                    }
                }
                break;
            }
            case 'W':
            {
                //Subtract
                Account *acc;

                //Check if there is a fifth element in the id.
                string idString = splitArray[1];
                string id;
                string fifthId;

                //If there is a length of 5, meaning that there is a fifth number...
                if(idString.size() > 5 || idString.size() < 4)
                {
                    cout << "ERROR" << endl;
                }
                else
                {
                    //4 digits
                    id = idString.substr(0, 4);

                    //5th digit
                    fifthId = idString.substr(4);

                    //Convert both the numberString to integer.
                    int identifier = convertToInt(id);
                    int fifthIdentifier = convertToInt(fifthId);

                    //Find it
                    bool found = accountsAndBalances.Retrieve(identifier, acc);

                    if(found == true)
                    {
                        //If you found it, then do the transaction
                        string amount = splitArray[2];

                        //Convert the amount to an integer.
                        int amountInt = convertToInt(amount);
                        stringstream ss;
                        string str;
                        char mychar = actionChar[0];
                        ss << mychar;
                        ss >> str;
                        
                        string str1 = str + " " + idString  + " " + amount;
                        
                        //Do the transaction
                        acc->transaction(fifthIdentifier, amountInt, actionChar[0], str1);
                    }
                }
                break;
            }
            case 'T':
            {
                //Transfer
                Account *acc;
                Account *accTransfer;
                
                //Check if there is a fifth element in the id.
                string idString = splitArray[1];
                string id;
                string fifthId;
                //If there is a length of 5, meaning that there is a fifth number...
                if(idString.size() > 5)
                {
                    cout << "ERROR" << endl;
                }
                else
                {
                    //4 digits
                    id = idString.substr(0, 4);

                    //5th digit
                    fifthId = idString.substr(4);

                    //Convert both the numberString to integer.
                    int identifier = convertToInt(id);
                    int fifthIdentifier = convertToInt(fifthId);


                    string idStringTransfer = splitArray[3];
                    string idTransfer;
                    string fifthIdTransfer;

                    //4 digits
                    idTransfer = idStringTransfer.substr(0, 4);
                    int identifierTrans = convertToInt(idTransfer);

                    //5th digit
                    fifthIdTransfer = idStringTransfer.substr(4);
                    int fifthIdentifierTransfer = convertToInt(fifthIdTransfer);
                    
                    //Find both accounts in the tree.
                    if(accountsAndBalances.Retrieve(identifier, acc) == false)
                    {
                        //If you don't then don't do it.
                        cout << "ERROR: Account " << identifier <<
                        " not found. Transferal Refused." << endl;
                        break;
                    }
                    else if(accountsAndBalances.Retrieve(identifierTrans, accTransfer) == false)
                    {
                        //If you don't then don't do it.
                        cout << "ERROR: Account " << identifierTrans <<
                        " not found. Transferal Refused." << endl;
                        
                        break;
                    }
                    
                    //Convert the amount to an integer.
                    string amount = splitArray[2];
                    int amountInt = convertToInt(amount);

                    stringstream ss;
                    string str;
                    char mychar = actionChar[0];
                    ss << mychar;
                    ss >> str;
                        
                    string str1 = str + " " + idString  + " " + amount + " " + idStringTransfer;
                        
                    //Transfer
                    acc->transferWithdraw(fifthIdentifier, acc, amountInt, str1);
                    accTransfer->transferDeposit(fifthIdentifierTransfer, accTransfer, amountInt, str1);
                }
                break;
            }
            case 'H':
            {
                Account *acc;
                
                if(splitArray[1].length() == 4)
                {
                    int id = convertToInt(splitArray[1]);
                    accountsAndBalances.Retrieve(id, acc);
                    cout << "Displaying Transaction History for " << acc->getFirstName()
                    << " " << acc->getLastName() << " by Fund" << endl;
                    acc->displayHistory();
                    break;
                }
                else
                {
                    if(splitArray[1].length() == 5)
                    {
                        //Check if there is a fifth element in the id.
                        string idString = splitArray[1];
                        string id;
                        string fifthId;
                        
                        //4 digits
                        id = idString.substr(0, 4);

                        //5th digit
                        fifthId = idString.substr(4);
                        
                        //Convert the two numbers.
                        int idInt = convertToInt(id);
                        int fifthInt = convertToInt(fifthId);
                        
                        //Retrieve the item.
                        accountsAndBalances.Retrieve(idInt, acc);
            
                        cout << "Displaying Transaction History for " << acc->getFirstName()
                        << " " << acc->getLastName() << " " << acc->getIndividualFund(fifthInt)<< endl;
                        
                        acc->displayHistory(fifthInt);
                    }
                }
                //Display history
                break;
            }
            default:
            {
                cout << "Must be D, W, T, H!" << endl;
                break;
            }
            
        }
        account.pop();
    }
}

void Bank::display() const
{
    //Display the final balance. 
    accountsAndBalances.DisplayTheTree();
}


