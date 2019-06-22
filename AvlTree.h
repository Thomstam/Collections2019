//
// Created by Thomas on 5/21/2019.
//

#ifndef COLLECTIONPROJECT2019_AVLTREE_H
#define COLLECTIONPROJECT2019_AVLTREE_H

#endif //COLLECTIONPROJECT2019_AVLTREE_H
# include <stdlib.h>
# include <conio.h>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;

struct node
{
    int value;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { value = k; left = right = 0; height = 1; }
};

class AvlTree
{
    ofstream myFileToWrite;


public:
    AvlTree();
    AvlTree(string file, node* p);
    unsigned char height(node* p);
    int bFactor(node *p);
    void fixHeight(node* p);
    node* rotateLeft(node* p);
    node* rotateRight(node *p);
    node* balance(node* p);
    node* findMin(node* p);
    node* removeMin(node* p);
    node* remove(node* p, int val);
    node* insertItem(node* p, int val);
    bool search(node* node, int key);
    int size(node* node);
};