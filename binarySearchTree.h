/*
  binarySearchTree.h
  Assignment6
  
  This is the binary search tree. In this class, after reading in the
  txt file, whenever there is an 'O', then it will be inserted into the
  binary tree. Each node in the binary search tree represents an object
  of Account in the account.h.

  Created by Sung Ho Park on 12/2/19.
  Copyright © 2019 Sung Ho Park. All rights reserved.
*/

#ifndef binarySearchTree_h
#define binarySearchTree_h

#include <stdio.h>
#include <string>
#include <iostream>

#include "account.h"

using namespace std;

class BSTree
{
private:
    struct Node
    {
        Account *pAcct;
        Node *right;
        Node *left;
    };
    Node* root;
    
    //Method in case a new node needs to be made.
    struct Node* newNode(Account *item)
    {
        Node *temp = new Node;
        temp->pAcct = item;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    };
    
public:
    /*
     Constructor. All it does is set the root to null.
     */
    BSTree();
    
    /*
     Destructor. This destroys everything in the binary search tree.
     */
    ~BSTree();
    
    /*
     This is the insert. If an account is opened, then it is added to the
     tree.
     */
    bool Insert(Account *);
    
    /*
     This is the helper for the method. This will do the action of adding
     A new node if 'O' is found.
     */
    bool insertHelper(Node*& root, Account *item);
    
    /*
     retrieve object, first parameter is the ID of the account
     second parameter holds pointer to found object, NULL if not
     found.
     */
    bool Retrieve(const int &id, Account* &item) const;
    
    /*
     This is the helper for the retrieve. This will be done iteratively
     and this will make sure that if an item is inside of the tree.
     
     If it is found, then it will return true and set the parameter item
     to the object Account that is found.
     */
    bool retrieveHelper(Node *root, const int& id, Account*& item) const;

    /*
     This displays the contents of the tree.
     */
    void DisplayTheTree() const;
    
    /*
     Helper for the destructor.
     */
    void Empty();
    
    /*
     This checks if the tree is empty. If it is, then return true.
     */
    bool isEmpty() const;
    
    /*
     Another helper method for the display. This will also display the
     contents of the tree. 
     */
    void print(Node *root) const;
};

#endif /* binarySearchTree_h */
