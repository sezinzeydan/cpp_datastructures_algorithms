//
// Created by User on 12/24/2019.
//

#include <iostream>
using namespace std;
#include <cstring>

//#include "Item.h"
class openHashTable{
public:
    openHashTable();

    int hash (const string &key);
    void addItem(string key, int amount, int&c);
    void findItem(string type);
    void deleteItem(string key);
    void printHash();


private:
    static const int tableSize = 193;
    struct Item{
        string type;
        int numOfItems;
    };
    Item *items[tableSize];
    struct Bools{
        bool empty;
        bool occupied;
        bool deleted;
    };
    Bools *checkLocation[tableSize];

};

