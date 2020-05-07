/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Sezin Zeydan
* ID: 21702567
* Section : 1
* Assignment : 4
* Description : main code for the hashtables.
 * I implemented both and insertion, retrieval and deletion works correctly for both open and separate chained hash tables.
 * I also print both hashtables.
 * I did not have time to implement the last part that calculated averages of operations.
*/
#include <iostream>
#include <fstream>
using namespace std;
#include "openHashTable.h"
#include "chainHashTable.h"

int main(int argc , char ** argv) {
    std::cout << "Hello, World!" << std::endl;
    string fileName ( argv [1]);
    ifstream myFile;
    string str;
    int count  = 0;
    openHashTable hash;
    chainHashTable cHash;
    string arr[149];
    myFile.open("items.txt");
    int c =0;
    int a = 0;
    int arrSize = 0;
    while (!myFile.eof()) {
        getline(myFile, str);

        int num = stoi(str.substr(0,4));
        int i = 5;
        while(str[i] == ' '){
            i++;
        }
        string name =  str.substr(i,str.length());
        arr[arrSize] = name;
        count++;
        hash.addItem(name,num,c);
        cHash.addItem(name,num,a);
        arrSize++;
    }
    myFile.close();
    cout<<"-----Open Hash Table After Insertion of All Items-----"<<endl;
    hash.printHash();

    cout<<"-----Chained Hash Table After Insertion of All Items-----"<<endl;
    cHash.printHash();

    cout<<"-----Retrieving 20 Random Values From Open Hash Table-----"<<endl;
    for(int i = 0; i < 20; i++){
        string str = arr[rand() % 149];

        hash.findItem(str);
    }
    cout<<endl;
    cout<<"-----Retrieving 20 Random Values From Chained Hash Table-----"<<endl;
    for(int i = 0; i < 20; i++){
        cout<<"RAND "<<rand()%149<<endl;
        cHash.findItem(arr[rand() % 149]);
    }
    cout<<endl;
    cout<<"-----After 50 Random Values Deleted From Open Hash Table-----"<<endl;
    for(int i = 0; i < 50; i++){
        hash.deleteItem(arr[rand() % 149]);
    }
    hash.printHash();
    cout<<endl;
    cout<<"-----After 40 Random Values Deleted From Chained Hash Table-----"<<endl;
    for(int i = 0; i < 50; i++){
        cHash.deleteItem(arr[rand() % 149]);
    }
    cHash.printHash();



    /*hash.findItem("potato russet loose");
    hash.deleteItem("potato russet loose");*/
    cHash.findItem("potato russet loose");
    cHash.deleteItem("potato russet loose");
    cHash.findItem("potato russet loose");

    return 0;
}
