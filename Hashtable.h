//
// Created by Thomas on 5/21/2019.
//

#ifndef COLLECTIONPROJECT2019_HASHTABLE_H
#define COLLECTIONPROJECT2019_HASHTABLE_H

#endif //COLLECTIONPROJECT2019_HASHTABLE_H
using namespace std;

class HashTable {
    int BUCKET;

    list<int> *table;
public:
    HashTable(int x);

    void insertItem(int value);

    void deleteItem(int x);

    int hashFunction(int x) {
        return (x % BUCKET);
    }
    bool search(int value);
};