/*
 account.cpp
 
 This is the account.cpp and it implements account.h.
 
 author: sunghopark
 */

#include "account.h"

Account::Account()
{
    //Constructor
    firstname = "";
    lastname = "";
    identifier = 0;
}

Account::Account(string first, string last, int id)
{
    //Set everything.
    firstname = first;
    lastname = last;
    identifier = id;
    
    for(int i = 0; i < 10; i++)
    {
        fundsA[i].setFundName(funds[i]);
        fundsA[i].setMoney(0);
    }
}

string Account::getFirstName()
{
    return firstname;
}

void Account::setFirstName(string &n)
{
    firstname = n;
}

string Account::getLastName()
{
    return lastname;
}

void Account::setLastName(string& n)
{
    lastname = n;
}

int Account::getID()
{
    return identifier;
}

void Account::setID(int &id)
{
    identifier = id;
}

int Account::getFund(int &index) const
{
    //Check the index
    if(index >= 10 || index < 0)
    {
        return -1;
    }
    else
    {
        //Get the money
        return fundsA[index].getMoney();
    }
}

void Account::setFund(int &fifth, int &amount)
{
    //Check for the fifth index.
    if(fifth >= 10 || fifth < 0)
    {
        return;
    }
    else
    {
        //Set the value in the index.
        fundsA[fifth].setMoney(amount);
    }
}

void Account::transaction(int &fifth, int &amount, char &arr, string &action)
{
    //Switch cases for the individual funds
    switch(fifth)
    {
        //If it is case 0,
        case 0:
        {
            //If it is D,
            if(arr == 'D')
            {
                //Deposit and put it in the string action in the history
                fundsA[0].deposit(amount);
                fundsA[0].history(action);
            }
            else if(arr == 'W')
            {
                //Check if the result is less than 0
                int result = fundsA[0].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[0].history(action);
                    break;
                }
                else
                {
                    //If it is not, then put it in the history.
                    fundsA[0].history(action);
                }
            }
            else
            {
                //Very rare case, but added just in case.
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 1:
        {
            //Do the same thing for everything else.
            if(arr == 'D')
            {
                fundsA[1].deposit(amount);
                fundsA[1].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[1].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[1].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[1].history(action);
                    break;
                }
                else
                {
                    fundsA[1].history(action);
                }
            }
            else
            {
               cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 2:
        {
            if(arr == 'D')
            {
                fundsA[2].deposit(amount);
               fundsA[2].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[2].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    //Just in case, the value is still positive.
                    if(result == 0)
                    {
                        fundsA[2].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[2].history(action);
                    break;
                }
                else
                {
                    fundsA[2].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 3:
        {
            if(arr == 'D')
            {
                fundsA[3].deposit(amount);
                fundsA[3].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[3].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[3].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[3].history(action);
                    break;
                }
                else
                {
                    fundsA[3].history(action);
                }
            }
            else
            {
               cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 4:
        {
            if(arr == 'D')
            {
                fundsA[4].deposit(amount);
                fundsA[4].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[4].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[4].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[4].history(action);
                    break;
                }
                else
                {
                    fundsA[4].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 5:
        {
            if(arr == 'D')
            {
                fundsA[5].deposit(amount);
                fundsA[5].history(action);
                
            }
            else if(arr == 'W')
            {
                int result = fundsA[5].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[5].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[5].history(action);
                    break;
                }
                else
                {
                    fundsA[5].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 6:
        {
            if(arr == 'D')
            {
                fundsA[6].deposit(amount);
                fundsA[6].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[6].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[6].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[6].history(action);
                    break;
                }
                else
                {
                    fundsA[6].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 7:
        {
            if(arr == 'D')
            {
                fundsA[7].deposit(amount);
                fundsA[7].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[7].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[7].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[7].history(action);
                }
                else
                {
                    fundsA[7].history(action);
                }
            }
            else if(arr == 'T')
            {
                fundsA[7].history(action);
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 8:
        {
            if(arr == 'D')
            {
                fundsA[8].deposit(amount);
                fundsA[8].history(action);
            }
            else if(arr == 'W')
            {
                int result = fundsA[8].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[8].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[8].history(action);
                    break;
                }
                else
                {
                    fundsA[8].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        case 9:
        {
            if(arr == 'D')
            {
                fundsA[9].deposit(amount);
                fundsA[9].history(action);
                
            }
            else if(arr == 'W')
            {
                int result = fundsA[8].withdraw(amount);

                if(result < 0 || result < amount)
                {
                    if(result == 0)
                    {
                        fundsA[9].history(action);
                        break;
                    }
                    cout << "ERROR: Not enough funds to withdraw $" <<
                    amount << " from " << getFirstName() << " " << getLastName() << endl;
                    action.append(" (failed)");
                    fundsA[9].history(action);
                    break;
                }
                else
                {
                    fundsA[9].history(action);
                }
            }
            else
            {
                cout << "Must be D, W, T, H!" << endl;
            }
            break;
        }
        default:
            cout << "There is no fifth digit in this account." << endl;
            break;
    }
}

void Account::transferWithdraw(int fifth, Account *&item,
                                  int amount, string action)
{
    //Withdraw from the original account.
    item->fundsA[fifth].withdraw(amount);
    item->fundsA[fifth].history(action);
}

void Account::transferDeposit(int fifth, Account *&item,
                                  int amount, string action)
{
    //Withdraw from the original account.
    int total = item->getFund(fifth);
    total += amount;
        
    item->setFund(fifth, total);
    item->fundsA[fifth].history(action);
    
}

string Account::getIndividualFund(int fifth)
{
    //This is for the individual funds.
    //Check if the fifth digit is valid.
    if(fifth >= 0 && fifth <10)
    {
        //return the string.
        return funds[fifth];
    }
    else
    {
        string error = "There are no funds. Funds must be between 0 and 9.";
        return error;
    }
}

void Account::displayHistory() const
{
    //For each fund for an account,
    for(int i = 0; i < 10; i++)
    {
        //Other than that, print out what fund it is and the history.
        cout << funds[i] << ": $" << fundsA[i].getMoney() <<endl;
        //fundsA[0].print();
        fundsA[i].print();
    }
    cout << endl;
}

void Account::displayHistory(int fifth) const
{
    //For each fund for an account,
    for(int i = 0; i < 10; i++)
    {
        if(i == fifth)
        {
            //fundsA[0].print();
            fundsA[i].print();
        }
    }
    cout << endl;
}

void Account::finalHistory() const
{
    //Final balance of everything. 
    cout << firstname << " " << lastname << " Account: "
    << identifier << endl;
    
    for(int i = 0; i < 10; i++)
    {
        cout << funds[i] << ": $" << fundsA[i].getMoney() << endl;
    }
}
