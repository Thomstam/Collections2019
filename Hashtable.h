//
// Created by Thomas on 5/21/2019.
//

#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>
#include <bits/stdc++.h>

#ifndef COLLECTIONPROJECT2019_HASHTABLE_H
#define COLLECTIONPROJECT2019_HASHTABLE_H

#endif //COLLECTIONPROJECT2019_HASHTABLE_H
using namespace std;

class HashTable {
    int BUCKET;

    vector<int> *table2;

    ofstream myFileToWrite;


public:
    HashTable(int x, string file);

    HashTable();

    void insertItem(int value);

    void deleteItem(int x);

    int hashFunction(int x) {
        return (x % BUCKET);
    }
    void search(int value);

    void insertItemForConstractor(int value);

    void getSize();

    void deleteMin();
};