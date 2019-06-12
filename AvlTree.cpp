//
// Created by Thomas on 5/21/2019.
//

#include <commctrl.h>
#include "AvlTree.h"
using namespace std;

unsigned char AvlTree:: height(node* p){
    return p ? p->height : 0;
}

node* AvlTree:: findMin(node* p) // find a node with minimal key in a p tree
{
    return p->left?findMin(p->left):p;
}

void AvlTree:: fixHeight(node* p){
    unsigned char heightL = height(p->left);
    unsigned char heightR = height(p->right);
    if ( heightL > heightR ) {
        p ->height = heightL + 1;
    } else{
        p ->height = heightR + 1;
    }
}

int AvlTree:: bFactor(node* p){
    return height(p->right)-height(p->left);
}

node* AvlTree:: rotateLeft(node* q){ // the left rotation round q
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

node* AvlTree:: rotateRight(node* p){ // the right rotation round p
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

node* AvlTree:: balance(node *p){
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

node * AvlTree:: insert(node* p,int val){
    if(!p){
        return  new node(val);
    }
    if( val < p->value){
        p-> left = insert(p->left, val);
    } else{
        p-> right = insert(p-> right, val);
    }
    return balance(p);
}

node* AvlTree:: removeMin(node* p){
    if ( p->left == 0){
        return p-> right;
    }
    p->left = removeMin(p-> left);
    return balance(p);
}

node* AvlTree:: remove(node* p, int val){
    if(!p) return 0;
    if(val < p-> value){
        p->left = remove(p->left, val);
    } else if(val > p-> value){
        p->right = remove(p->right, val);
    } else {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if (!r){
            return q;
        }
        node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(p);
    }
    return balance(p);
}