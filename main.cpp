#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Hashtable.h"
#include "bstree.h"
#include "TestAvl.h"


using namespace std;

template <class Reader> void static readingMethod(string file, Reader r){
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
//            int a, b;
//            myfile >> a >> b;
            int a;
            myfile >> a;
            r.insert(r,a);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

}


int main () {
    bool hashTableExistence = false;
    bool avlTreeExistence = false;
    bool maxHeapExistence = false;
    bool minHeapExistence = false;
    bool graphExistence = false;

    HashTable hashTable;
    bstree bst;
    nodeptr root;
    root = NULL;

    string STRING;
    ifstream infile;
    infile.open ("commands.txt");
    while(!infile.eof()) // To get you all the lines.
    {
        vector<string> line;
        string token;
        string delimiter =" ";
        size_t pos = 0;
        getline(infile,STRING); // Saves the line in STRING.
        while ((pos = STRING.find(delimiter)) != std::string::npos) {
            token = STRING.substr(0, pos);
            line.push_back(token);
            STRING.erase(0, STRING.find(delimiter) + delimiter.length());
        }
        line.push_back(STRING);
        string command = line[0] + " " +  line [1];
        if (command == "BUILD MINHEAP"){
            minHeapExistence = true;
        }else if(command == "BUILD MAXHEAP"){
            maxHeapExistence = true;
        }else if(command == "BUILD AVLTREE"){
            avlTreeExistence = true;
            string myLineToRead;
            ifstream myfile (line[2]);
            if (myfile.is_open())
            {
                while ( getline (myfile,myLineToRead) )
                {
//            int a, b;
//            myfile >> a >> b;
                    int a;
                    myfile >> a;
                    bst.insert(a,root);
                }
                myfile.close();
            }
        }else if(command == "BUILD GRAPH"){
            graphExistence = true;
        }else if(command == "BUILD HASHTABLE"){
            hashTableExistence = true;
            hashTable = HashTable(1,line[2]);
        }else if(command == "GETSIZE MINHEAP"){
            if(minHeapExistence){

            } else{
                cout << "unable to execute GETSIZE MINHEAP" << endl;
            }
        }else if(command == "GETSIZE MAXHEAP"){
            if(maxHeapExistence){

            }else{
                cout << "unable to execute GETSIZE MAXHEAP" << endl;
            }
        }else if(command == "GETSIZE AVLTREE"){
            if(avlTreeExistence){

            }else{
                cout << "unable to execute GETSIZE AVLTREE" << endl;
            }
        }else if(command == "GETSIZE GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute GETSIZE GRAPH" << endl;
            }
        }else if(command == "GETSIZE HASHTABLE"){
            if(hashTableExistence){
                hashTable.getSize();
            }else{
                cout << "unable to execute GETSIZE HASHTABLE" << endl;
            }
        }else if(command == "FINDMIN MINHEAP"){
            if(minHeapExistence){

            }else{
                cout << "unable to execute FINDMIN MINHEAP" << endl;
            }
        }else if(command == "FINDMAX MAXHEAP"){
            if(maxHeapExistence){

            }else{
                cout << "unable to execute FINDMAX MAXHEAP" << endl;
            }
        }else if(command == "FINDMIN AVLTREE"){
            if(avlTreeExistence){
            }else{
                cout << "unable to execute FINDMIN AVLTREE" << endl;
            }
        }else if(command == "SEARCH AVLTREE"){
            if(avlTreeExistence){

            }else{
                cout << "unable to execute SEARCH AVLTREE" << endl;
            }
        }else if(command == "SEARCH HASHTABLE"){
            if(hashTableExistence){
                int x = stoi(line[2]);
                hashTable.search(x);
            }else{
                cout << "unable to execute SEARCH HASHTABLE" << endl;
            }
        }else if(command == "COMPUTESHORTESTPATH GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute COMPUTESHORTESTPATH GRAPH" << endl;
            }
        }else if(command == "COMPUTESPANNINGTREE GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute COMPUTESPANNINGTREE GRAPH" << endl;
            }
        }else if(command == "FINDCONNECTEDCOMPONENTS GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute FINDCONNECTEDCOMPONENTS GRAPH" << endl;
            }
        }else if(command == "INSERT MIXHEAP"){
            if(minHeapExistence){

            }else{
                cout << "unable to execute INSERT MIXHEAP" << endl;
            }
        }else if(command == "INSERT MAXHEAP"){
            if(maxHeapExistence){

            }else{
                cout << "unable to execute INSERT MAXHEAP" << endl;
            }
        }else if(command == "INSERT AVLTREE"){
            if(avlTreeExistence){

            }else{
                cout << "unable to execute INSERT AVLTREE" << endl;
            }
        }else if(command == "INSERT HASHTABLE"){
            if(hashTableExistence){
                int x = stoi(line[2]);
                hashTable.insertItem(x);
            }else{
                cout << "unable to execute INSERT HASHTABLE" << endl;
            }
        }else if(command == "INSERT GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute INSERT GRAPH" << endl;
            }
        }else if(command == "DELETEMIN MINHEAP"){
            if(minHeapExistence){

            }else{
                cout << "unable to execute DELETEMIN MINHEAP" << endl;
            }
        }else if(command == "DELETEMAX MAXHEAP"){
            if(maxHeapExistence){

            }else{
                cout << "unable to execute DELETEMIN MAXHEAP" << endl;
            }
        }else if(command == "DELETE AVLTREE"){
            if(avlTreeExistence){

            }else{
                cout << "unable to execute DELETEMIN AVLTREE" << endl;
            }
        }else if(command == "DELETE GRAPH"){
            if(graphExistence){

            }else{
                cout << "unable to execute DELETEMIN GRAPH" << endl;
            }
        }else if(command == "DELETE HASHTABLE"){
            if(hashTableExistence){
                int x = stoi(line[2]);
                hashTable.deleteItem(x);
            }else{
                cout << "unable to execute DELETEMIN HASHTABLE" << endl;
            }
        } else{
            cout << "Not matching command\n";
            continue;
        }
    }
    infile.close();

//    size_t pos = 0;
//    string line;
//    ifstream myfile ("example.txt");
//    if (myfile.is_open())
//    {
//        while ( getline (myfile,line) )
//        {
//            int a, b;
//            myfile >> a >> b;
//        }
//        myfile.close();
//    }
//
//    else cout << "Unable to open file";

    return 0;
}