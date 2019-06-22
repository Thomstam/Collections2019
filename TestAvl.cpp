//
// Created by Thomas on 5/21/2019.
//


#include "TestAvl.h"
using namespace std;

AvlTree::AvlTree() = default;

AvlTree::AvlTree(string file, nodeTest* p) {
    nodeTest *root = NULL;
    string line;
    ifstream myFileToRead (file);
    if (myFileToRead.is_open())
    {
        while ( getline (myFileToRead,line) )
        {
            int a;
            myFileToRead >> a;
            root= insertItemForConstractor(root,a);
        }
        myFileToRead.close();

    }
    else {
        cout << "Unable to open file";
    }
}

unsigned char AvlTree:: height(nodeTest* p){
    return p ? p->height : 0;
}

nodeTest* AvlTree:: findMin(nodeTest* p) // find a node with minimal key in a p tree
{
    return p->left?findMin(p->left):p;
}

void AvlTree:: fixHeight(nodeTest* p){
    unsigned char heightL = height(p->left);
    unsigned char heightR = height(p->right);
    if ( heightL > heightR ) {
        p ->height = heightL + 1;
    } else{
        p ->height = heightR + 1;
    }
}

int AvlTree:: bFactor(nodeTest* p){
    return height(p->right)-height(p->left);
}

nodeTest* AvlTree:: rotateLeft(nodeTest* q){ // the left rotation round q
    nodeTest* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

nodeTest* AvlTree:: rotateRight(nodeTest* p){ // the right rotation round p
    nodeTest* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

nodeTest* AvlTree:: balance(nodeTest *p){
    fixHeight(p);
    if(bFactor(p) == 2){
        if (bFactor(p-> right) < 0){
            p-> right = rotateRight(p-> right);
        }
        return rotateLeft(p);
    }
    if(bFactor(p) == -2){
        if (bFactor(p-> left) > 0){
            p-> left = rotateLeft(p-> left);
        }
        return rotateRight(p);
    }
    return p;
}

nodeTest * AvlTree:: insertItemForConstractor(nodeTest* p,int val){
    if(!p){
        return  new nodeTest(val);
    }
    if( val < p->value){
        p-> left = insertItemForConstractor(p->left, val);
    } else if (val > p->value){
        p-> right = insertItemForConstractor(p-> right, val);
    }
    return balance(p);
}

nodeTest* AvlTree:: removeMin(nodeTest* p){
    if ( p->left == 0){
        return p-> right;
    }
    p->left = removeMin(p-> left);
    return balance(p);
}

nodeTest* AvlTree:: remove(nodeTest* p, int val){
    if(!p) return 0;
    if(val < p-> value){
        p->left = remove(p->left, val);
    } else if(val > p-> value){
        p->right = remove(p->right, val);
    } else {
        nodeTest* q = p->left;
        nodeTest* r = p->right;
        delete p;
        if (!r){
            return q;
        }
        nodeTest* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(p);
    }
    return balance(p);
}