//
// Created by User on 12/24/2019.
//

#include "openHashTable.h"


openHashTable::openHashTable(){

    for(int i = 0; i < tableSize;i++){
        checkLocation[i] = new Bools;
        checkLocation[i]->empty = true;
        checkLocation[i]->deleted = false;
        checkLocation[i]->occupied = false;
    }
}



int openHashTable :: hash (const string &key)
{
    int hashVal = 0;
    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];
    hashVal %=tableSize;
    if (hashVal < 0) /* in case overflows occur in computation
*/
        hashVal += tableSize;
    return hashVal;
}

void openHashTable::addItem(string key, int amount, int& c) {

    Item *itemToAdd = new Item();
    itemToAdd->type = key;
    itemToAdd->numOfItems = amount;
    int index = hash(itemToAdd->type);
    if(checkLocation[index]->empty != 0){
        items[index] = itemToAdd;
        checkLocation[index]->occupied = true;
        checkLocation[index]->empty = false;
        c++;

        return;
    }
    int quadratic = 1;
    int orgIndex = index;
    while(checkLocation[index]->empty == 0){
        index = orgIndex + quadratic*quadratic;

        if(index > tableSize){
            index  = index % orgIndex;
            quadratic = 0;
            orgIndex = index;
        }
        if(checkLocation[index]->empty != 0){

            items[index] = itemToAdd;
            checkLocation[index]->occupied = true;
            checkLocation[index]->empty = false;
            c++;
            return;
        }
        quadratic++;
    }

}



void openHashTable::findItem(string type) {
    int index = hash(type);

    int orgIndex = index;

    if(checkLocation[index]->empty == 0 && items[index]->type == type){
        cout << items[index]->type << " = " << items[index]->numOfItems;
        return;
    }

    int quadratic = 1;
    while(checkLocation[index]->occupied == 1 || checkLocation[index]->deleted == 1
    || checkLocation[index]->empty == 1){
        index = orgIndex + quadratic*quadratic;

        if(index > tableSize){
            index  = index % orgIndex;
            quadratic = 0;
            orgIndex = index;
        }

        if(checkLocation[index]->occupied == true) {
            if (items[index]->type == type) {
                cout << items[index]->type << " = " << items[index]->numOfItems;
                return;
            }
        }

        quadratic++;
    }
}

void openHashTable::deleteItem(string key) {
    int index = hash(key);
    int quadratic = 1;
    int orgIndex = index;
    if(checkLocation[index]->occupied ==  1 && items[index]->type == key){
        checkLocation[index]->occupied = false;
        checkLocation[index]->empty = true;
        checkLocation[index]->deleted = true;
        return;
    }
    while(checkLocation[index]->occupied == 1){
        index = orgIndex + quadratic*quadratic;
        if(index > tableSize){
            index  = index % orgIndex;
            quadratic = 0;
            orgIndex = index;
        }
        if(items[index]->type == key){
            checkLocation[index]->occupied = false;
            checkLocation[index]->empty = true;
            checkLocation[index]->deleted = true;
            return;
        }
        quadratic++;
    }

}

void openHashTable::printHash() {
    int count = 0;
    int size = 0;
    while(count< tableSize){
        if(checkLocation[count]->empty == false && checkLocation[count]->deleted == false ){
            cout<<count<<": "<<items[count]->type<<" = "<<items[count]->numOfItems<<endl;
            size++;
        }
        count++;


    }
}






