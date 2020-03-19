//
//  main.cpp
//  Assignment6
//
//  Created by Sung Ho Park on 12/2/19.
//  Copyright © 2019 Sung Ho Park. All rights reserved.
//

#include <iostream>
#include "bank.h"
#include "account.h"
#include <assert.h>
#include <sstream>

int main1(int argc, const char * argv[])
{
    Bank s;
    s.readFile("BankTransIn.txt");
    s.theTransaction();
    cout << endl;
    cout << "Processing Done. Final Balance." << endl;
    cout << endl;
    s.display();
    return 0;
}

int main(int argc, const char * argv[])
{
    Bank s;
    
    if (argc == 1)
    {
        cout << "Please enter text file name" << endl;
        exit(1);
    }
    else if (argc == 2)
    {
        s.readFile(argv[1]);
        s.theTransaction();
        cout << endl;
        cout << "Processing Done. Final Balance." << endl;
        cout << endl;
        s.display();
    }
    else if (argc == 3)
    {
        string str;
        stringstream ss;
        ss << argv[1];
        ss >> str;

        if (str == "-d")
        {
            s.readFile(argv[1]);
            s.theTransaction();
            cout << endl;
            cout << "Processing Done. Final Balance." << endl;
            cout << endl;
            s.display();
        }
        else
        {
            cout << "Please enter -d and file name for output" << endl;
        }
    }
    return 0;
}


