#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class Reader> void readingMethod(string file, Reader r){
        size_t pos = 0;
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            int a, b;
            myfile >> a >> b;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

}


int main () {
    bool hashTableΕxistence = false;
    bool avlTreeΕxistence = false;
    bool maxHeapExistence = false;
    bool MinHeapΕxistence = false;
    bool graphΕxistence = false;
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
            string fileToRead = line[3];

        }else if(command == "BUILD MAXHEAP"){

        }else if(command == "BUILD AVLTREE"){

        }else if(command == "BUILD GRAPH"){

        }else if(command == "BUILD HASHTABLE"){

        }else if(command == "GETSIZE MINHEAP"){

        }else if(command == "GETSIZE MAXHEAP"){

        }else if(command == "GETSIZE AVLTREE"){

        }else if(command == "GETSIZE GRAPH"){

        }else if(command == "GETSIZE HASHTABLE"){

        }else if(command == "FINDMIN MINHEAP"){

        }else if(command == "FINDMAX MAXHEAP"){

        }else if(command == "FINDMIN AVLTREE"){

        }else if(command == "SEARCH AVLTREE"){

        }else if(command == "SEARCH HASHTABLE"){

        }else if(command == "COMPUTESHORTESTPATH GRAPH"){

        }else if(command == "COMPUTESPANNINGTREE GRAPH"){

        }else if(command == "FINDCONNECTEDCOMPONENTS GRAPH"){

        }else if(command == "INSERT MIXHEAP"){

        }else if(command == "INSERT MAXHEAP"){

        }else if(command == "INSERT AVLTREE"){

        }else if(command == "INSERT HASHTABLE"){

        }else if(command == "INSERT GRAPH"){

        }else if(command == "DELETEMIN MINHEAP"){

        }else if(command == "DELETEMIN MANHEAP"){

        }else if(command == "DELETEMIN AVLTREE"){

        }else if(command == "DELETEMIN GRAPH"){

        }else if(command == "DELETEMIN HASHTABLE"){

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