//
// Created by Chris on 10/27/2020.
//
#include <string>
#ifndef PROJECT_1_B_TREE_BTREENODE_H
#define PROJECT_1_B_TREE_BTREENODE_H
using namespace std;

class BTreeNode {

    string *keyArray;       //String array for keyArray
    static int degree;              //Minimum Degree
    int countTerms;              //Number of Entries
    int diskAddress;
    BTreeNode **children; //Array of child pointers
    bool isLeaf;        //true if node is leaf, else false.


    BTreeNode(int _t, bool Is_Leaf);

    void traverse();
    void InsertToNode(string term);
    void breakUpChild(int i, BTreeNode *y);
    BTreeNode *findNode(string term);
    int findKeyIndex(string term);
    void removeKey(string term);
        //removefromleaf()
        //removefromnonleaf()
    std::string getPredecessorKey(int index);
    std::string getSuccessorKey(int index);
    void fillToMin(int index);
        //borrowfromprev() and borrowfromnext() implemented in this too.
    void mergeNodes(int index);



friend class BTree;
};
class BTree{
    BTreeNode *root;
    int degree;
public:
    BTree(int _t){
        root = NULL;
        degree = _t;
    };
    void AddTerm(string term);
    void RemoveTerm(string term);
    BTreeNode* search(string key);
    void traverse();

};


#endif //PROJECT_1_B_TREE_BTREENODE_H
