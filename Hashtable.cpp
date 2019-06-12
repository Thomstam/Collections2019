//
// Created by Thomas on 5/21/2019.
//
#include <list>
#include <wingdi.h>
#include "Hashtable.h"
using namespace std;



HashTable::HashTable(int x) {
    this ->BUCKET = x;
    table = new list<int>[BUCKET];
}

void HashTable::insertItem(int value){
    int index = hashFunction(value);
    table[index].push_back(value);
}

void HashTable::deleteItem(int x) {
    int index = hashFunction(x);
    list <int> :: iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++) {
        if (*i == x)
            break;
    }

    if(i != table[index].end()){
        table[index].erase(i);
    }
}

bool HashTable::search(int value){
    int index = hashFunction(value);
    list <int> :: iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++) {
        if (*i == value)
            break;
    }
    if(i != table[index].end()){
        return true;
    } else{
        return false;
    }
}