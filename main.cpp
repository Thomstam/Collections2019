#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Hashtable.h"
#include "AvlTree.h"
#include "myGraph.h"


using namespace std;

int main () {
    ofstream myFileToWrite;
    bool hashTableExistence = false;
    bool avlTreeExistence = false;
    bool maxHeapExistence = false;
    bool minHeapExistence = false;
    bool graphExistence = false;

    myGraph graph;
    MinHeap minheap;
    MaxHeap maxheap;
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
                node *temp = nullptr;
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
        }else if ( command == "BUILD MINHEAP"){
            minheap = MinHeap(lineFromCommandsToStore[2]);
            minHeapExistence = true;
        }else if ( command == "GETSIZE MINHEAP"){
            if (minHeapExistence)
                minheap.GETSIZE();
        }else if ( command == "INSERT MINHEAP"){
            if (minHeapExistence){
                int x = stoi(lineFromCommandsToStore[2]);
                minheap.INSERT(x);}
        }else if ( command == "DELETE MINHEAP"){
            if (minHeapExistence)
                minheap.DELETEMIN();
        }else if ( command == "FINDMIN MINHEAP"){
            if (minHeapExistence)
                minheap.FINDMIN();
        }else if ( command == "BUILD MAXHEAP"){
            maxheap = MaxHeap(lineFromCommandsToStore[2]);
            maxHeapExistence = true;
        }else if ( command == "GETSIZE MAXHEAP"){
            if (maxHeapExistence)
                maxheap.GETSIZE();
        }else if ( command == "INSERT MAXHEAP"){
            if (maxHeapExistence){
                int x = stoi(lineFromCommandsToStore[2]);
                maxheap.INSERT(x);}
        }else if ( command == "DELETE MAXHEAP"){
            if (maxHeapExistence)
                maxheap.DELETEMAX();
        }else if ( command == "FINDMAX MAXHEAP"){
            if (maxHeapExistence)
                maxheap.FINDMAX();
        }else if ( command == "BUILD GRAPH"){
            graph = myGraph(lineFromCommandsToStore[2]);
            graphExistence = true;
        }else if ( command == "GETSIZE GRAPH"){
            if (graphExistence)
                graph.getSize();
        }else if ( command == "INSERT GRAPH"){
            if (graphExistence){
                int x = stoi(lineFromCommandsToStore[2]);
                int y = stoi(lineFromCommandsToStore[3]);
                graph.insertGraph(x,y);}
        }else if ( command == "DELETE GRAPH"){
            if (graphExistence){
                int x = stoi(lineFromCommandsToStore[2]);
                int y = stoi(lineFromCommandsToStore[3]);
                graph.deleteGraph(x,y);}
        }else if ( command == "COMPUTESHORTESTPATH GRAPH"){
            if (graphExistence){
                int x = stoi(lineFromCommandsToStore[2]);
                int y = stoi(lineFromCommandsToStore[3]);
                graph.shortestPath(x,y);}
        }else if ( command == "FINDCONNECTEDCOMPONENTS GRAPH"){
            if (graphExistence){
                graph.connectedComp();
            }
        }
        else if ( command == "COMPUTESPANNINGTREE GRAPH"){
            if (graphExistence)
                graph.connectedComp();
        }
    }
    commandsFile.close();
    return 0;
}