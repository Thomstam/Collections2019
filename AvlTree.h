//
// Created by Thomas on 5/21/2019.
//

#ifndef COLLECTIONPROJECT2019_AVLTREE_H
#define COLLECTIONPROJECT2019_AVLTREE_H

#endif //COLLECTIONPROJECT2019_AVLTREE_H
# include <stdlib.h>
# include <conio.h>
using namespace std;

struct node // the structure for representing tree nodes
{
    int value;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { value = k; left = right = 0; height = 1; }
};

class AvlTree
{

public:
    unsigned char height(node* p);
    int bFactor(node *p);
    void fixHeight(node* p);
    node* rotateRight(node* p);
    node* rotateLeft(node *p);
    node* balance(node* p);
    node* insert(node* p, int val);;
    node* findMin(node* p);
    node* removeMin(node* p);
    node* remove(node* p, int val);
};