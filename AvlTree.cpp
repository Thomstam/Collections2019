
#include "AvlTree.h"
using namespace std;

//Default Constractor
AvlTree::AvlTree() = default;

//Returns the height of the tree
unsigned char AvlTree:: height(node* p){
    return p ? p->height : 0;
}

//Goes left on every node to find min and returns tha last node
node* AvlTree:: findMin(node* p) // find a node with minimal key in a p tree
{
    return p->left?findMin(p->left):p;
}


//Fixes the height of the Treeb
void AvlTree:: fixHeight(node* p){
    unsigned char heightL = height(p->left);
    unsigned char heightR = height(p->right);
    if ( heightL > heightR ) {
        p ->height = heightL + 1;
    } else{
        p ->height = heightR + 1;
    }
}


//Calculates the balance of the node
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


//Here we check th conditions and we perform the rotations
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

//The place we insert new values to the tree
node * AvlTree::insertItem(node* p,int val){

    if(!p){
        return  new node(val);
    }
    if( val < p->value){
        p-> left = insertItem(p->left, val);
    } else if (val > p->value){
        p-> right = insertItem(p-> right, val);
    }
    return balance(p);
}

//Removal of min in an AvlTree
node* AvlTree:: removeMin(node* p){
    if ( p->left == 0){
        return p-> right;
    }
    p->left = removeMin(p-> left);
    return balance(p);
}

//Removal of a value in an AvlTree
node* AvlTree:: remove(node* p, int val){
    if(!p) return nullptr;
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

//Search of a value in an AvlTree
bool AvlTree::search(node* node, int key) {
    if (node == NULL) {
        return false;  // missing from tree

    } else if (key < node->value) {

        return search(node->left, key);

    } else if (key > node->value) {

        return search(node->right, key);

    } else {

        return true;  // found it
    }
}

//Return of the size of an AvlTree
int AvlTree::size(node* node){
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}