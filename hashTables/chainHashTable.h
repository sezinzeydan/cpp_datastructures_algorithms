#include <iostream>
using namespace std;
#include <cstring>

//#include "Item.h"
class chainHashTable{
public:
    chainHashTable();

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
        Item *next;
    };
    Item *items[tableSize];

};
