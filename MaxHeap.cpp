#include "MaxHeap.h"

using namespace std::chrono;

MaxHeap::MaxHeap() = default;
MaxHeap::MaxHeap(string filename) {

    auto start = steady_clock::now();

    int val;
    std::ifstream ifile;
    ifile.open(filename);
    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    if (ifile.is_open()) {
        ofile << "\n--------------\nBuilding the Max Heap\n\n";
        while (ifile >> val)
        {data.push_back(val);}
        ifile.close();

        for (int j = data.size() / 2; j>=0; j--) {
            Max_Heapify(j);
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

    ofile << "\nTime taken to build MaxHeap: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
}

void MaxHeap::Max_Heapify(int index) {


    int biggest = index;
    if (index*2+1 < data.size() && data[biggest] < data[index*2+1]) {
        biggest = (index*2+1);
    }

    if (index*2+2 < data.size() && data[biggest] < data[index*2+2]){
        biggest = (index*2+2);
    }

    if (index != biggest) {
        std::swap(data[index], data[biggest]);
        Max_Heapify(biggest);
    }

}

void MaxHeap::GETSIZE() {
    auto start = steady_clock::now();
    int count=0;
    for(std::vector<int>::const_iterator i=data.begin();i<data.end();++i)
        ++count;

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);
    ofile << "\n--------------\nThe size of the MaxHeap is: '" <<count<<"'\n";

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "Time taken to find the size: '"<< ftime <<"' microseconds\n\n";
    ofile.flush();
    ofile.close();

}


void MaxHeap::INSERT(int value) {


    auto start = steady_clock::now();
    std::ofstream ofile;
    data.push_back(value);
    int current=data.size()-1;
    while (current!=0) {
        if (data[current] > data[floor(double(current - 1)/2)]) {
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

void MaxHeap::FINDMAX() {

    auto start = steady_clock::now();

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile<<"\n--------------\nThe maximum element of the Max Heap, is: '"<<data[0]<<"'\n";
    ofile<<"Time taken to find Max, is: '"<<ftime<<"' microseconds\n\n";
    ofile.flush();
    ofile.close();

}

void MaxHeap::DELETEMAX() {

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
        int biggest = current;
        if ((current * 2 + 1) < data.size() && data[current * 2 + 1] > data[biggest]) {
            biggest = current * 2 + 1;
        }
        if ((current * 2 + 2) < data.size() && data[current * 2 + 2] > data[biggest]) {
            biggest = current * 2 + 2;
        }
        if (current != biggest) {
            std::swap(data[current], data[biggest]);
            current = biggest;
        } else break;
    }


    ofile << "\n--------------\nThe maximum element of the Heap, was deleted. Max Heap was recalculated with the new elements\n\n";
    for (std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        ofile << *i << "\n";
    }
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();

    ofile<<"\nTime taken to delete Maximum and recalculate Max Heap: '"<<ftime<<"' microseconds.\n\n";

    ofile.flush();
    ofile.close();
}
