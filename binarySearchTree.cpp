/*
  binarySearchTree.cpp
  Assignment6

  This is the binary search tree. This class implements the
  binaryseatchtree.h.

  Created by Sung Ho Park on 12/2/19.
  Copyright © 2019 Sung Ho Park. All rights reserved.
 */

#include  "account.h"
#include "binarySearchTree.h"
#include <assert.h>
#include <iostream>
#include <sstream>

BSTree::BSTree()
{
    //Set the root to null.
    root = nullptr;
}

BSTree::~BSTree()
{
    //Call empty because empty is the same thing as
    //a destructor.
    Empty();
}

bool BSTree::isEmpty() const
{
    //If the root is null, then return true.
    //False otherwise.
    if(root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BSTree::Empty()
{
    //Delete everything and set the pointers to null
    delete root;
    root = nullptr;
}

bool BSTree::Insert(Account *item)
{
    //If it is found, then return true.
    bool found = insertHelper(root, item);
    
    if(found == true)
    {
        return true;
    }
    else
    {
        //Otherwise return false.
        return false;
    }
}

bool BSTree::insertHelper(Node *&root, Account *item)
{
    //If there is nothing in the node and the root is
    //not pointed to anything, then make a new node and
    //place the items inside it and make left and right
    //NULL. BASE CASE.
    if(root == nullptr)
    {
        root = newNode(item);
        return true;
    }
    //If the data in the root is the same as the passed in
    //item, then do nothing. It's already there.
    else if(root->pAcct->getID() == item->getID())
    {
        //Convert the id into a string.
        stringstream ss;
        string str;
        int mychar = item->getID();
        ss << mychar;
        ss >> str;
        
        string error = "This Account (" + str + ") is already open. Transaction Refused.";
        cout << error << endl;
        
        return false;
    }
    //If the root's data is greater than the passed in item then...
    else if(root->pAcct->getID() > item->getID())
    {
        //...Go left and keep recursing until you get to the base case.
        insertHelper(root->left, item);
    }
    else
    {
        //The right side case.
        insertHelper(root->right, item);
    }
    return false;
}

bool BSTree::Retrieve(const int& id, Account*& item) const
{
    //Uses the helper method to retrieve.
    if (retrieveHelper(root, id, item) == true)
    {
        return true;
    }
    else
    {
        //If not set the item to nullptr. 
        item = nullptr;
        return false;
    }
}

bool BSTree::retrieveHelper(Node *root, const int& id, Account*& item) const
{
    //While the root is not null
    while (root != NULL)
    {
        //If the id is greater than the root's id
        if (id > root->pAcct->getID())
        {
            //go right
            root = root->right;
        }
        else if (id < root->pAcct->getID())
        {
            //If not, go right
            root = root->left;
        }
        else
        {
            //if you found it, then set it equal to each other.
            item = root->pAcct;
            return true;
        }
    }
    //Rare case, but needed if not found.
    return false;
}
void BSTree::DisplayTheTree() const
{
    print(root);
}

void BSTree::print(Node *root) const
{
    //If the root is null, don't do anything.
    if(root == nullptr)
    {
        return;
    }
    //If the root is pointing to something,
    
        //Do a preorder
        root->pAcct->finalHistory();
        cout << endl;
        
        //Recurse Left
        print(root->left);
        //root->pAcct->finalHistory();
        //Recurse Right
        print(root->right);
    
}



