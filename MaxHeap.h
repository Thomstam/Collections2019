#ifndef DATASTRUCTURES_MAXHEAP_H
#define DATASTRUCTURES_MAXHEAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <tgmath.h>

class MaxHeap {

public:
    MaxHeap();
    void GETSIZE();
    void INSERT(int);
    void FINDMAX();
    void DELETEMAX();

private:
    void Max_Heapify(int);
    std::vector<int>data;

};


#endif //DATASTRUCTURES_MAXHEAP_H
