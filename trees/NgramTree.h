/**
* Title : Binary Search Trees
* Author : Sezin Zeydan
* ID: 21702567
* Section : 1
* Assignment : 2
*/

#ifndef CS202_HW2_NGRAMTREE_H
#define CS202_HW2_NGRAMTREE_H
#include <string>
#include "NgramNode.h"

class NgramTree {
public:
    NgramTree ();
    NgramTree (const std:: string &word);
    ~ NgramTree ();
    void addNgram ( std :: string ngram );
    int getTotalNgramCount ();
    void printNgramFrequencies ();
    bool isComplete ();
    bool isFull ();
    void generateTree ( std :: string fileName , int n );

    NgramNode* retrieve(std::string key);

    void deleteNode( std::string key);
    int height(NgramNode* root);
    void generateHelper(std::string str, int n);
protected:
    void addHelper(NgramNode *& nodePtr, std:: string);
    NgramNode* realRetrieve(NgramNode *& nodePtr, std:: string key);
    void inorderTra(NgramNode*& nodePtr);
    int totalNgramCount(NgramNode *& nodePtr,int &total);
    bool complete(NgramNode *&nodePtr, bool &retType);
    bool full(NgramNode *&nodePtr, bool & retType);
    void deleteItemRoot(NgramNode*& treePtr, std::string key);
    void deleteNodeItem(NgramNode *&nodePtr);
    void processLeftmost(NgramNode *& nodePtr,  std::string &treeItem, int & count);
    void destroyNgramTree(NgramNode *& treePtr);


private:
    NgramNode *rootPtr;
};


#endif //CS202_HW2_NGRAMTREE_H
