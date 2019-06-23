//
// Created by Thomas on 5/21/2019.
//

#include "Hashtable.h"
using namespace std;


HashTable::HashTable() = default;


HashTable::HashTable(int x, string file) {
    auto start = std::chrono::steady_clock::now();
    this ->BUCKET = x;
    table2 = new vector<int>[BUCKET];
    string line;
    ifstream myFileToRead (file);

    if (myFileToRead.is_open())
    {
        while ( getline (myFileToRead,line) )
        {
            int a;
            myFileToRead >> a;
            this->insertItemForConstractor(a);
        }
        myFileToRead.close();
    }
    sort( table2->begin(), table2->end());
    table2->erase( unique( table2->begin(), table2->end() ), table2->end() );
    auto stop = std::chrono::steady_clock::now();
    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
    myFileToWrite << "Time taken to build HashTable: '" << ftime << "' microseconds.\n\n";
    myFileToWrite.flush();
    myFileToWrite.close();


}

void HashTable::insertItem(int value){
    auto start = std::chrono::steady_clock::now();
    int index = hashFunction(value);
    table2[index].push_back(value);
    sort( table2->begin(), table2->end());
    table2->erase( unique( table2->begin(), table2->end() ), table2->end() );
    auto stop = std::chrono::steady_clock::now();
    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
    myFileToWrite << "Time taken to insert " << value <<" to HashTable: '" << ftime << "' microseconds.\n\n";
    myFileToWrite.flush();
    myFileToWrite.close();

}

void HashTable::insertItemForConstractor(int value){
    //int index = hashFunction(value);
   // table2[index].push_back(value);
    int index = hashFunction(value);
    table2[index].push_back(value);
}

void HashTable::deleteItem(int x) {
    auto start = std::chrono::steady_clock::now();
    int index = hashFunction(x);
    vector <int> :: iterator i;
    for (i = table2[index].begin();
         i != table2[index].end(); i++) {
        if (*i == x)
            break;
    }

    if(i != table2[index].end()){
        table2[index].erase(i);
        auto stop = std::chrono::steady_clock::now();
        auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
        myFileToWrite << x << "Found and deleted in HashTable: '" << ftime << "' microseconds.\n\n";
        myFileToWrite.flush();
        myFileToWrite.close();
    } else{
        auto stop = std::chrono::steady_clock::now();
        auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
        myFileToWrite << x << "Not found to delete in HashTable: '" << ftime << "' microseconds.\n\n";
        myFileToWrite.flush();
        myFileToWrite.close();
    }
}

void HashTable::search(int value){
    auto start = std::chrono::steady_clock::now();
    int index = hashFunction(value);
    vector <int> :: iterator i;
    for (i = table2[index].begin();
         i != table2[index].end(); i++) {
        if (*i == value)
            break;
    }
    if(i != table2[index].end()){
        table2[index].erase(i);
        auto stop = std::chrono::steady_clock::now();
        auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
        myFileToWrite << value << " Found and in HashTable: '" << ftime << "' microseconds.\n\n";
        myFileToWrite.flush();
        myFileToWrite.close();
    } else{
        auto stop = std::chrono::steady_clock::now();
        auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
        myFileToWrite << value << " Not found in HashTable: '" << ftime << "' microseconds.\n\n";
        myFileToWrite.flush();
        myFileToWrite.close();
    }
}

void HashTable::getSize() {
    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
    myFileToWrite << "The size of HashTable : "<< table2->size() << "\n\n";
    myFileToWrite.flush();
    myFileToWrite.close();
}

void HashTable::deleteMin() {
    int min = *min_element(table2->begin(), table2->end());
    cout << min;
}