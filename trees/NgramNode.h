

#ifndef CS202_HW2_NGRAMNODE_H
#define CS202_HW2_NGRAMNODE_H

#include <string>

class NgramNode{
private:
    int freq;
    std::string ngram;
    NgramNode * leftPtr;
    NgramNode * rightPtr;
public:
    NgramNode();
    NgramNode(const std::string &word);
    NgramNode(const std::string &word,  NgramNode *left, NgramNode * right);
    void setNgram(const std::string &word);

    std::string getNgram() const;

    int getFreq() const;

    void setFreq(const int &count);

friend class NgramTree;
};

#endif //CS202_HW2_NGRAMNODE_H
