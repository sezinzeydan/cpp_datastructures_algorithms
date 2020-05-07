//
// Created by User on 12/25/2019.
//

#include "chainHashTable.h"

chainHashTable::chainHashTable() {
    for(int i = 0; i < tableSize;i++){
        items[i] = new Item;
        items[i]->type = "";
        items[i]->numOfItems = 0;
        items[i]->next = NULL;
    }

}

int chainHashTable :: hash (const string &key) {
    int hashVal = 0;
    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];
    hashVal %= tableSize;
    if (hashVal < 0) /* in case overflows occur in computation
*/
        hashVal += tableSize;
    return hashVal;
}

void chainHashTable::addItem(string key, int amount, int &c) {
    int index = hash(key);
    if(items[index]->type == ""){
        items[index]->type = key;
        items[index]->numOfItems = amount;
        c++;
        return;
    }
    else{
        //if(c != 50){
            Item*curr = items[index];
            Item *itemToAdd = new Item;
            itemToAdd->type = key;
            itemToAdd->numOfItems = amount;
            itemToAdd->next = NULL;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = itemToAdd;
            c++;
            return;
       // }
    }
}

void chainHashTable::findItem(string type) {
    int index = hash(type);
    if(items[index]->type == ""){
        return;
    }
    Item* curr = items[index];
    while(curr != NULL){
        if(curr->type == type){
            cout<<curr->type<<" = "<<curr->numOfItems;
            return;
        }
        curr = curr->next;
    }
}

void chainHashTable::deleteItem(string key) {
    cout<<"**********deleted geldi "<<key<<endl;
    int index = hash(key);
    if(items[index]->type == ""){
        return;
    }

    Item *curr = items[index];
    if(curr->type == key){
        Item *temp = curr;
        temp->type = "";
        curr = curr->next;
        delete temp;
        return;
    }
    curr = curr->next;
    Item *prev = items[index];
    while(curr != NULL){
        if(curr->type == key){
            Item *temp = curr;
            temp->type = "";
            curr = curr->next;
            prev->next = curr;
            temp->next = NULL;
            delete temp;
        }
    }
}

void chainHashTable::printHash() {
    for(int i = 0; i < tableSize;i++){
        Item *curr = items[i];

    }
    int i = 0;
    while (i < tableSize){
        Item *curr = items[i];
        while(curr->next != NULL){
            if(curr->type != ""){
                cout<<i<<": "<<curr->type<<" = "<<curr->numOfItems<<", ";
            }
            curr = curr->next;
        }
        if(curr->type != ""){
            cout<<endl;
        }
        i++;
    }
}

