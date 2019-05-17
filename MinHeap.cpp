#include "MinHeap.h"

using namespace std::chrono;



MinHeap::MinHeap() {

    auto start = steady_clock::now();

    int val;
    std::ifstream ifile;
    ifile.open("a.txt");
    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    if (ifile.is_open()) {
        ofile << "\n--------------\nBuilding the Min Heap\n\n";
        while (ifile >> val)
        {data.push_back(val);}
        ifile.close();

        for (int j = data.size() / 2; j>=0; j--) {
            Min_Heapify(j);
        }
    }
    else {
        ofile << "Couldn't open your input file\n\n";
    }

    for (std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        ofile << *i << "\n";
    }

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();

    ofile << "\nTime taken to build MinHeap: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
}

void MinHeap::Min_Heapify(int index) {


    int smallest = index;
    if (index*2+1 < data.size() && data[smallest] > data[index*2+1]) {
        smallest = (index*2+1);
    }

    if (index*2+2 < data.size() && data[smallest] > data[index*2+2]){
        smallest = (index*2+2);
    }

    if (index != smallest) {
        std::swap(data[index], data[smallest]);
        Min_Heapify(smallest);
    }

}

void MinHeap::GETSIZE() {
    auto start = steady_clock::now();
    int count=0;
    for(std::vector<int>::const_iterator i=data.begin();i<data.end();++i)
        ++count;

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);
    ofile << "\n--------------\nThe size of the MinHeap is: '" <<count<<"'\n";

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "Time taken to find the size: '"<< ftime <<"' microseconds\n\n";
    ofile.flush();
    ofile.close();

}


void MinHeap::INSERT(int value) {


    auto start = steady_clock::now();
    std::ofstream ofile;
    data.push_back(value);
    int current=data.size()-1;
    while (current!=0) {
        if (data[current] < data[floor(double(current - 1)/2)]) {
            std::swap(data[current], data[floor(double(current - 1) / 2)]);
            current = floor(double(current - 1)/2);
        }
        else break;
    }


    ofile.open("output.txt", std::ios::out | std::ios::app);
    ofile << "\n--------------\nInserting the new element.\n\n";
    for (std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        ofile << *i << "\n";
    }

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();

    ofile << "\nTime taken to insert: '" <<value<<"' was: '"<< ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();


}

void MinHeap::FINDMIN() {

    auto start = steady_clock::now();

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile<<"\n--------------\nThe minimum element of the Min Heap, is: '"<<data[0]<<"'\n";
    ofile<<"Time taken to find Min, is: '"<<ftime<<"' microseconds\n\n";
    ofile.flush();
    ofile.close();

}

void MinHeap::DELETEMIN() {

    auto start = steady_clock::now();
    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    if (data.size() == 1){
        ofile<<"Only one element in the Heap.\n";
        return;}

    std::swap(data[0],data[data.size()-1]);
    data.pop_back();
    int current=0;
    while(current < data.size()) {
        int smallest = current;
        if ((current * 2 + 1) < data.size() && data[current * 2 + 1] < data[smallest]) {
            smallest = current * 2 + 1;
        }
        if ((current * 2 + 2) < data.size() && data[current * 2 + 2] < data[smallest]) {
            smallest = current * 2 + 2;
        }
        if (current != smallest) {
            std::swap(data[current], data[smallest]);
            current = smallest;
        } else break;
    }


    ofile << "\n--------------\nThe minimum element of the Heap, was deleted. Min Heap was recalculated with the new elements\n\n";
    for (std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        ofile << *i << "\n";
    }
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();

    ofile<<"\nTime taken to delete Minimum and recalculate Min Heap: '"<<ftime<<"' microseconds.\n\n";

    ofile.flush();
    ofile.close();
}