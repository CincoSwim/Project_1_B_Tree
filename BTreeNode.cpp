//
// Created by Chris on 10/27/2020.
//

#include "BTreeNode.h"
#include <iostream>;
using namespace std;

BTreeNode::BTreeNode(int _t, bool Is_Leaf) {
    degree = _t;
    isLeaf = Is_Leaf;

    keys = new string[2*degree-1];
    children = new BTreeNode *[2 * degree];
}



void BTreeNode::traverse() {
    int i;
    for (i=0; i < countTerms; i++){
        if (!isLeaf){
            children[i]->traverse();
        }
        cout << "" << keys[i];
    }
};


BTreeNode *BTreeNode::search(string term) {
    int i = 0;
    while (i < countTerms && term > keys[i]){
        i++;
    }
    if (keys[i] == term){
        return this;
    }
    if (isLeaf == true){
        return NULL;
    }
    return children[i]->search(term);
}

void BTree::AddTerm(string term) {
    if (root == NULL){
        root = new BTreeNode(t, true);
        root->keys[0] = term;
        root->countTerms = 1;
    }else{
        if(root->countTerms == 2*t-1){
            BTreeNode *placehold = new BTreeNode(t, false);
            placehold->children[0] = root;
            placehold->breakUpChild(0, root);
            int i = 0;
            if (placehold->keys[0] < term) {
                i++;
            }
            placehold->children[i]->InsertToNode(term);
        }
    }
}