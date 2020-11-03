//
// Created by Chris on 10/27/2020.
//
#include <string>
#ifndef PROJECT_1_B_TREE_BTREENODE_H
#define PROJECT_1_B_TREE_BTREENODE_H


class BTreeNode {

    std::string *keys;       //String array for keys
    int degree;              //Minimum Degree
    int countTerms;              //Number of Entries
    BTreeNode **childs; //Array of child pointers
    bool isLeaf;        //true if node is leaf, else false.

    BTreeNode(int _t, bool Is_Leaf);

    void traverse();
    void InsertToNode(std::string term);
    void breakUpChild(int i, BTreeNode *y);


    BTreeNode *search(std::string term);
friend class BTree;
};
class BTree{
    BTreeNode *root;
    int t;

    BTree(int _t);
    void AddTerm(std::string term);
    BTreeNode* search(std::string key);

};


#endif //PROJECT_1_B_TREE_BTREENODE_H
