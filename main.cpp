#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Hashtable.h"
#include "AvlTree.h"


using namespace std;

//template <class Reader> void static readingMethod(string file, Reader r){
//    string line;
//    ifstream myfile (file);
//    if (myfile.is_open())
//    {
//        while ( getline (myfile,line) )
//        {
////            int a, b;
////            myfile >> a >> b;
//            int a;
//            myfile >> a;
//            r.insert(r,a);
//        }
//        myfile.close();
//    }
//
//    else cout << "Unable to open file";
//
//}


int main () {
    ofstream myFileToWrite;
    bool hashTableExistence = false;
    bool avlTreeExistence = false;
    bool maxHeapExistence = false;
    bool minHeapExistence = false;
    bool graphExistence = false;

    HashTable hashTable;
    AvlTree testAvl;
    node *treeNode = nullptr;
    string lineFromCommands;
    ifstream commandsFile;
    commandsFile.open("commands.txt");
    while (!commandsFile.eof()) {
        vector<string> lineFromCommandsToStore;
        string token;
        string delimiter = " ";
        size_t pos = 0;
        getline(commandsFile, lineFromCommands);
        while ((pos = lineFromCommands.find(delimiter) != std::string::npos)) {
            token = lineFromCommands.substr(0, lineFromCommands.find(delimiter));
            lineFromCommandsToStore.push_back(token);
            lineFromCommands.erase(0, lineFromCommands.find(delimiter) + delimiter.length());
        }
        lineFromCommandsToStore.push_back(lineFromCommands);
        string command = lineFromCommandsToStore[0] + " " + lineFromCommandsToStore[1];
        if (command == "BUILD AVLTREE") {
            avlTreeExistence = true;
            auto start = std::chrono::steady_clock::now();
            string line;
            ifstream myFileToRead(lineFromCommandsToStore[2]);
            if (myFileToRead.is_open()) {
                while (getline(myFileToRead, line)) {
                    int a;
                    myFileToRead >> a;
                    treeNode = testAvl.insertItem(treeNode, a);
                }
                myFileToRead.close();

            } else {
                cout << "Unable to open file";
            }
            auto stop = std::chrono::steady_clock::now();
            auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
            myFileToWrite << "Time taken to build AVLTREE: '" << ftime << "' microseconds.\n\n";
            myFileToWrite.flush();
            myFileToWrite.close();
        } else if (command == "BUILD HASHTABLE") {
            hashTableExistence = true;
            hashTable = HashTable(1, lineFromCommandsToStore[2]);
        } else if (command == "DELETE HASHTABLE") {
            if (hashTableExistence) {
                int x = stoi(lineFromCommandsToStore[2]);
                hashTable.deleteItem(x);
            }
        } else if (command == "GETSIZE HASHTABLE") {
            if (hashTableExistence) {
                hashTable.getSize();
            }
        } else if (command == "SEARCH HASHTABLE") {
            if (hashTableExistence) {
                int x = stoi(lineFromCommandsToStore[2]);
                hashTable.search(x);
            }
        } else if (command == "INSERT HASHTABLE") {
            if (hashTableExistence) {
                int x = stoi(lineFromCommandsToStore[2]);
                hashTable.insertItem(x);
            }
        } else if (command == "INSERT AVLTREE") {
            if (avlTreeExistence) {
                auto start = std::chrono::steady_clock::now();
                int x = stoi(lineFromCommandsToStore[2]);
                testAvl.insertItem(treeNode, x);
                auto stop = std::chrono::steady_clock::now();
                auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                myFileToWrite << x << " inserted in AVLTREE in: " << ftime<< "' microseconds.\n\n";
                myFileToWrite.flush();
                myFileToWrite.close();
            }
        } else if (command == "FINDMIN AVLTREE") {
            if (avlTreeExistence) {
                auto start = std::chrono::steady_clock::now();
                node *temp = testAvl.findMin(treeNode);
                auto stop = std::chrono::steady_clock::now();
                auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                myFileToWrite << "MIN in AVLTREE is: '" << temp->value << " and found in: " << ftime<< "' microseconds.\n\n";
                myFileToWrite.flush();
                myFileToWrite.close();
            }
        } else if (command == "SEARCH AVLTREE") {
            if (avlTreeExistence) {
                auto start = std::chrono::steady_clock::now();
                int x = stoi(lineFromCommandsToStore[2]);
                if (testAvl.search(treeNode, x)) {
                    auto stop = std::chrono::steady_clock::now();
                    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                    myFileToWrite << "Value found in: '" << ftime << "' microseconds.\n\n";
                    myFileToWrite.flush();
                    myFileToWrite.close();
                } else {
                    auto stop = std::chrono::steady_clock::now();
                    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                    myFileToWrite << "Value not found in: '" << ftime << "' microseconds.\n\n";
                    myFileToWrite.flush();
                    myFileToWrite.close();
                }
            }
        } else if (command == "GETSIZE AVLTREE") {
            if (avlTreeExistence) {
                auto start = std::chrono::steady_clock::now();
                int temp = testAvl.size(treeNode);
                auto stop = std::chrono::steady_clock::now();
                auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                myFileToWrite << "Size of AvlTree is " << temp << " and found in: '" << ftime << "' microseconds.\n\n";
                myFileToWrite.flush();
                myFileToWrite.close();
            }
        }else if (command == "DELETE AVLTREE") {
            if (avlTreeExistence) {
                auto start = std::chrono::steady_clock::now();
                int x = stoi(lineFromCommandsToStore[2]);
                if (testAvl.remove(treeNode,x) != nullptr) {
                    auto stop = std::chrono::steady_clock::now();
                    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                    myFileToWrite << "Value " << x << " removed in: '" << ftime << "' microseconds.\n\n";
                    myFileToWrite.flush();
                    myFileToWrite.close();
                } else {
                    auto stop = std::chrono::steady_clock::now();
                    auto ftime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                    myFileToWrite.open("output.txt", std::ios::out | std::ios::app);
                    myFileToWrite << "Value " << x << " not found to be removed in: '" << ftime << "' microseconds.\n\n";
                    myFileToWrite.flush();
                    myFileToWrite.close();
                }
            }
        }
    }
    commandsFile.close();
    return 0;
}


//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//    if (command == "BUILD MINHEAP"){
//        minHeapExistence = true;
//    }else if(command == "BUILD MAXHEAP"){
//        maxHeapExistence = true;
//    }else if(command == "BUILD AVLTREE"){
//
//    }else if(command == "BUILD GRAPH"){
//        graphExistence = true;
//    }else if(command == "BUILD HASHTABLE"){
//        hashTableExistence = true;
//        hashTable = HashTable(1,line[2]);
//    }else if(command == "GETSIZE MINHEAP"){
//        if(minHeapExistence){
//
//        } else{
//            cout << "unable to execute GETSIZE MINHEAP" << endl;
//        }
//    }else if(command == "GETSIZE MAXHEAP"){
//        if(maxHeapExistence){
//
//        }else{
//            cout << "unable to execute GETSIZE MAXHEAP" << endl;
//        }
//    }else if(command == "GETSIZE AVLTREE"){
//        if(avlTreeExistence){
//
//        }else{
//            cout << "unable to execute GETSIZE AVLTREE" << endl;
//        }
//    }else if(command == "GETSIZE GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute GETSIZE GRAPH" << endl;
//        }
//    }else if(command == "GETSIZE HASHTABLE"){
//        if(hashTableExistence){
//            hashTable.getSize();
//        }else{
//            cout << "unable to execute GETSIZE HASHTABLE" << endl;
//        }
//    }else if(command == "FINDMIN MINHEAP"){
//        if(minHeapExistence){
//
//        }else{
//            cout << "unable to execute FINDMIN MINHEAP" << endl;
//        }
//    }else if(command == "FINDMAX MAXHEAP"){
//        if(maxHeapExistence){
//
//        }else{
//            cout << "unable to execute FINDMAX MAXHEAP" << endl;
//        }
//    }else if(command == "FINDMIN AVLTREE"){
//        if(avlTreeExistence){
//        }else{
//            cout << "unable to execute FINDMIN AVLTREE" << endl;
//        }
//    }else if(command == "SEARCH AVLTREE"){
//        if(avlTreeExistence){
//
//        }else{
//            cout << "unable to execute SEARCH AVLTREE" << endl;
//        }
//    }else if(command == "SEARCH HASHTABLE"){
//        if(hashTableExistence){
//            int x = stoi(line[2]);
//            hashTable.search(x);
//        }else{
//            cout << "unable to execute SEARCH HASHTABLE" << endl;
//        }
//    }else if(command == "COMPUTESHORTESTPATH GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute COMPUTESHORTESTPATH GRAPH" << endl;
//        }
//    }else if(command == "COMPUTESPANNINGTREE GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute COMPUTESPANNINGTREE GRAPH" << endl;
//        }
//    }else if(command == "FINDCONNECTEDCOMPONENTS GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute FINDCONNECTEDCOMPONENTS GRAPH" << endl;
//        }
//    }else if(command == "INSERT MIXHEAP"){
//        if(minHeapExistence){
//
//        }else{
//            cout << "unable to execute INSERT MIXHEAP" << endl;
//        }
//    }else if(command == "INSERT MAXHEAP"){
//        if(maxHeapExistence){
//
//        }else{
//            cout << "unable to execute INSERT MAXHEAP" << endl;
//        }
//    }else if(command == "INSERT AVLTREE"){
//        if(avlTreeExistence){
//
//        }else{
//            cout << "unable to execute INSERT AVLTREE" << endl;
//        }
//    }else if(command == "INSERT HASHTABLE"){
//        if(hashTableExistence){
//            int x = stoi(line[2]);
//            hashTable.insertItem(x);
//        }else{
//            cout << "unable to execute INSERT HASHTABLE" << endl;
//        }
//    }else if(command == "INSERT GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute INSERT GRAPH" << endl;
//        }
//    }else if(command == "DELETEMIN MINHEAP"){
//        if(minHeapExistence){
//
//        }else{
//            cout << "unable to execute DELETEMIN MINHEAP" << endl;
//        }
//    }else if(command == "DELETEMAX MAXHEAP"){
//        if(maxHeapExistence){
//
//        }else{
//            cout << "unable to execute DELETEMIN MAXHEAP" << endl;
//        }
//    }else if(command == "DELETE AVLTREE"){
//        if(avlTreeExistence){
//
//        }else{
//            cout << "unable to execute DELETEMIN AVLTREE" << endl;
//        }
//    }else if(command == "DELETE GRAPH"){
//        if(graphExistence){
//
//        }else{
//            cout << "unable to execute DELETEMIN GRAPH" << endl;
//        }
//    }else if(command == "DELETE HASHTABLE"){
//        if(hashTableExistence){
//            int x = stoi(line[2]);
//            hashTable.deleteItem(x);
//        }else{
//            cout << "unable to execute DELETEMIN HASHTABLE" << endl;
//        }
//    } else{
//        cout << "Not matching command\n";
//        continue;
//    }
//}