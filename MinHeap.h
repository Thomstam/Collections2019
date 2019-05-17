#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <tgmath.h>

class MinHeap {

public:
    MinHeap();
    void GETSIZE();
    void INSERT(int);
    void FINDMIN();
    void DELETEMIN();

private:
    void Min_Heapify(int);
    std::vector<int>data;

};



#endif //DATASTRUCTURES_MINHEAP_H
