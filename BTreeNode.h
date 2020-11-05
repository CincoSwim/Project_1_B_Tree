//
// Created by Chris on 10/27/2020.
//
#include <string>
#ifndef PROJECT_1_B_TREE_BTREENODE_H
#define PROJECT_1_B_TREE_BTREENODE_H
using namespace std;

class BTreeNode {

    int * keyArray;       //String array for keyArray
    int degree;              //Minimum Degree
    int countTerms;              //Number of Entries
    int diskAddress;
    BTreeNode **children; //Array of child pointers
    bool isLeaf;        //true if node is leaf, else false.


    BTreeNode(int _t, bool Is_Leaf);

    void traverse();
    void InsertToNode(int term);
    void breakUpChild(int i, BTreeNode *y);
    BTreeNode *findNode(int term);
    int findKeyIndex(int term);
    void removeKey(int term);
        //removefromleaf()
        //removefromnonleaf()
    int getPredecessorKey(int index);
    int getSuccessorKey(int index);
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
    void AddTerm(int term);
    void RemoveTerm(int term);
    BTreeNode* search(int key);
    void traverse();

};


#endif //PROJECT_1_B_TREE_BTREENODE_H
