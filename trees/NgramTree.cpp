/**
* Title : Binary Search Trees
* Author : Sezin Zeydan
* ID: 21702567
* Section : 1
* Assignment : 2
*/
#include <string>
#include "NgramTree.h"
#include <fstream>
using namespace std;
#include <cmath>
#include <iostream>

#include <cstring>


NgramTree :: NgramTree(){
    rootPtr = NULL;
}

NgramTree :: NgramTree(const std::string &word){
    rootPtr = new NgramNode(word);
}

NgramTree :: ~ NgramTree (){
    destroyNgramTree(rootPtr);
}
void NgramTree ::destroyNgramTree(NgramNode *&treePtr) {
    if(treePtr == NULL){
        return;
    }
    destroyNgramTree(treePtr->leftPtr);
    destroyNgramTree(treePtr->rightPtr);
    delete treePtr;
}

void NgramTree ::addNgram(std::string ngram) {

    string cleanStr = "";
    int strL = ngram.length() ;

    int i = 0, j = 0;
    while (ngram[i])
    {
        if (ngram[i] != ' ')
           cleanStr = cleanStr + ngram[i];
        i++;
    }

    addHelper(rootPtr, cleanStr);
}

void NgramTree ::addHelper(NgramNode *&nodePtr, std::string ngram) {

    if(nodePtr == NULL){
        nodePtr = new NgramNode(ngram);
    }
    else if(nodePtr->getNgram() > ngram){

        addHelper(nodePtr->leftPtr, ngram);
    }
    else if(nodePtr->getNgram() < ngram){

        addHelper(nodePtr->rightPtr, ngram);
    }
    else if(nodePtr->getNgram() == ngram){

        nodePtr->setFreq(nodePtr->getFreq() + 1);
    }
}

NgramNode* NgramTree ::retrieve(std::string key) {
   NgramNode* answer = realRetrieve(rootPtr, key);
    return answer;
}

NgramNode* NgramTree ::realRetrieve(NgramNode *&nodePtr, std::string key) {
    NgramNode * ans = NULL;
    if(key == nodePtr->getNgram()){
        ans = nodePtr;
    }
    if(key < nodePtr->getNgram()){
        realRetrieve(nodePtr->leftPtr, key);
    }
    else{
        realRetrieve(nodePtr->rightPtr, key);
    }
    return ans;
}

void NgramTree ::printNgramFrequencies (){
    inorderTra(rootPtr);
}

void NgramTree ::inorderTra(NgramNode *&nodePtr) {
    if(nodePtr != NULL){
        inorderTra(nodePtr->leftPtr);
        cout<<nodePtr->getNgram()<< " appears "<<nodePtr->getFreq()<< " time(s)"<<endl;
        inorderTra(nodePtr->rightPtr);
    }
}

int NgramTree ::getTotalNgramCount() {
    int total = 0;
    totalNgramCount(rootPtr,total);
    return total;
}

int NgramTree ::totalNgramCount(NgramNode *&nodePtr, int &total) {
    if(nodePtr == NULL){        return total;
    }
    total++;
    totalNgramCount(nodePtr->leftPtr, total);
    totalNgramCount(nodePtr->rightPtr,total);
}

int NgramTree :: height(NgramNode * root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->leftPtr), height(root->rightPtr));
}

bool NgramTree :: isComplete (){

    bool ret;
    bool ans;
    ans = complete(rootPtr, ret);
    return ans;
}

bool NgramTree :: complete(NgramNode *&nodePtr, bool &retType){

    if(nodePtr == NULL){
        retType = true;
        return retType;
    }
    if(abs(height( nodePtr->leftPtr) - height(nodePtr->rightPtr)) <= 1){
        retType = true;
        complete(nodePtr->leftPtr, retType);
        complete(nodePtr->rightPtr, retType);
    }
    else{
        retType = false;
        return retType;
    }
}





bool NgramTree ::isFull() {
    bool ret;
    bool ans;
    ans = full(rootPtr, ret);
    return ans;
}

bool NgramTree :: full(NgramNode *& nodePtr, bool &retType){

    if(nodePtr == NULL){
        retType = true;
        return retType;
    }
    if(height(nodePtr->leftPtr) == height(nodePtr->rightPtr)){
        retType = true;
        full(nodePtr->leftPtr, retType);
        full(nodePtr->rightPtr, retType);
    }
    else{
        retType = false;
        return retType;
    }
}

void NgramTree :: deleteNode(std::string key){

    deleteItemRoot(rootPtr, key);
}

void NgramTree :: deleteItemRoot(NgramNode*& treePtr, std:: string key){

    if(rootPtr == NULL){
        return;
    }

    if(treePtr->getNgram() == key){
        cout<<"deleteNode "<<key<<endl;
        deleteNodeItem(treePtr);
    }
    else if( key < treePtr->getNgram()){
        deleteItemRoot(treePtr->leftPtr , key);
    }
    else{
        deleteItemRoot(treePtr->rightPtr, key);
    }
}

void NgramTree ::deleteNodeItem(NgramNode *&nodePtr) {
    NgramNode *temp;
    if (nodePtr->getFreq() > 1) {
        nodePtr->setFreq(nodePtr->getFreq() - 1);
    } else {
        if (nodePtr->rightPtr == NULL && nodePtr->leftPtr == NULL) {
            delete nodePtr;
            nodePtr = NULL;
        } else if (nodePtr->leftPtr == NULL && nodePtr->rightPtr != NULL) {
            temp = nodePtr;
            nodePtr = nodePtr->rightPtr;
            temp->rightPtr = NULL;
            delete temp;
        } else if (nodePtr->rightPtr == NULL && nodePtr->leftPtr != NULL) {
            temp = nodePtr;
            nodePtr = nodePtr->leftPtr;
            temp->leftPtr = NULL;
            delete temp;
        } else {
            string str;
            int count;
            processLeftmost(nodePtr, str, count);
            nodePtr->setNgram(str);
            nodePtr->setFreq(count);
        }
    }
}

void NgramTree ::processLeftmost(NgramNode *&nodePtr, std::string &treeItem, int &count) {
    NgramNode* temp;
    if(nodePtr->leftPtr == NULL){
        treeItem = nodePtr->getNgram();
        count = nodePtr->getFreq();
        temp = nodePtr;
        //right child going up
        nodePtr = nodePtr->rightPtr;
        temp->rightPtr = NULL;
        delete temp;
    }
    else{
        processLeftmost(nodePtr->leftPtr,treeItem, count);
    }
}

void NgramTree :: generateTree ( std :: string fileName , int n ){
    ifstream myFile;
    string str;
    string sTotal ="";
    myFile.open("sample.txt");
    while (!myFile.eof()) {
        getline(myFile, str);
        sTotal += str + "\n";
    }
    myFile.close();
    if(sTotal == ""){
        return;
    }
    generateHelper(sTotal, n);

}
 void NgramTree :: generateHelper(string str, int n){
    int strLength = 0;
    int nGramStart;
    while(str[strLength] != '\0'){
        strLength++;

    }

    int wordLength = 0;
    int i = 0;
    int start = 0;
    while(i < strLength){
        start = i;

        while(str[i] != ' ' && (i < strLength)){
            i++;
        }
        wordLength = i - start;

        if((str[i] == ' ') && wordLength >= n ){

            int wordStart = i - wordLength;
            int follower = wordStart + n;



            while(follower <=  i){
                addNgram(str.substr(wordStart, n));
                wordStart++;
                follower++;
            }
        }
        wordLength = 0;
        i++;
    }





 }



