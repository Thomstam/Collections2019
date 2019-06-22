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

struct nodeTest
{
    int value;
    unsigned char height;
    nodeTest* left;
    nodeTest* right;
    nodeTest(int k) { value = k; left = right = 0; height = 1; }
};

class AvlTree
{
    ofstream myFileToWrite;

public:
    AvlTree();
    AvlTree(string file, nodeTest* p);
    unsigned char height(nodeTest* p);
    int bFactor(nodeTest *p);
    void fixHeight(nodeTest* p);
    nodeTest* rotateLeft(nodeTest* p);
    nodeTest* rotateRight(nodeTest *p);
    nodeTest* balance(nodeTest* p);
    nodeTest* insertItemForConstractor(nodeTest* p, int val);;
    nodeTest* findMin(nodeTest* p);
    nodeTest* removeMin(nodeTest* p);
    nodeTest* remove(nodeTest* p, int val);
};