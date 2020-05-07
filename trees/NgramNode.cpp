#include "NgramNode.h"
#include<iostream>
#include <string>
NgramNode::NgramNode() {

}

NgramNode :: NgramNode(const std::string &word){
    ngram = word;
    if(freq != 1){
        freq = 1;
    }
    leftPtr = NULL;
    rightPtr = NULL;
}

NgramNode :: NgramNode(const std::string &word,  NgramNode *left, NgramNode * right) {
    ngram = word;
    freq++;
    leftPtr = left;
    rightPtr = right;
}

void NgramNode ::setFreq(const int &newFreq) {
    freq = newFreq;
}

void NgramNode ::setNgram(const std::string &word) {
    ngram = word;
}

int NgramNode ::getFreq() const {
    return freq;
}

std:: string NgramNode ::getNgram() const {
    return ngram;
}
