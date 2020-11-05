//
// Created by Chris on 10/27/2020.
//

#include "BTreeNode.h"
#include <iostream>
using namespace std;

BTreeNode::BTreeNode(int _t, bool Is_Leaf) {//can replace with hardcoded amount of 15 per node, methinks
    degree = _t;
    isLeaf = Is_Leaf;

    keyArray = new int[2 * degree - 1];
    children = new BTreeNode *[2 * degree];
    countTerms = 0;
}

void BTree::traverse() {
    if(root = NULL){
        cout<< "Nothing in Tree." <<endl;
    }else{
        root->traverse();
    }
}

void BTreeNode::traverse() {
    int i;
    for (i=0; i < countTerms; i++){
        if (!isLeaf){
            children[i]->traverse();
        }
        cout << " - " << keyArray[i];
    }
    cout << endl;
};


BTreeNode *BTreeNode::findNode(int term) {
    int i = 0;
    while (i < countTerms && term > keyArray[i]){
        i++;
    }
    if (keyArray[i] == term){
        return this;
    }
    if (isLeaf == true){
        return NULL;
    }
    return children[i]->findNode(term);
}

void BTree::AddTerm(int term) {
    if (root == NULL){
        root = new BTreeNode(degree, true);
        root->keyArray[0] = term;
        root->countTerms = 1;
    }else{
        if(root->countTerms == 2*degree-1){
            BTreeNode *placehold = new BTreeNode(degree, false);
            placehold->children[0] = root;
            placehold->breakUpChild(0, root);
            int i = 0;
            if (placehold->keyArray[0] < term) {
                i++;
            }
            placehold->children[i]->InsertToNode(term);

            root = placehold;
        }else{
            root->InsertToNode(term);
        }
    }
}
void BTree::RemoveTerm(int term) {
    if (root = NULL){
        cout << "No tree" << endl;
        return;
    }
    root->removeKey(term);
    if (root->countTerms == 0){
        if (root->isLeaf){
            root == NULL;
        }else{
            root = root->children[0];
        }
    }
    return;
}
BTreeNode* BTree::search(int term) {
    if (root = NULL){
        return NULL;
    }else{
        return root->findNode(term);
    }
}
void BTreeNode::InsertToNode(int term) {
    int index = countTerms - 1;
    if(isLeaf){
        while (index >=0 && keyArray[index] > term){
            keyArray[index + 1] = keyArray[index];
            index--;
        }
        keyArray[index + 1] = term;
        countTerms++;
    }else{
        while (index >=0 && keyArray[index] > term){
            index--;
        }
        if (children[index+1]->countTerms = 2*degree-1){
            breakUpChild(index+1, children[index+1]);
            if (keyArray[index+1] < term ){
                index++;
            }
        }
        children[index+1]->InsertToNode(term);

    }
}

void BTreeNode::breakUpChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->degree, y->isLeaf);
    for(int j=0; j<degree-1; j++){
        z->children[j]=y->children[j+degree];
    }

    if (!y->isLeaf){
        for(int j = 0; j<degree; j++){
            z->children[j]=y->children[j+degree];
        }
    }
    z->countTerms = degree - 1;
    y->countTerms = degree - 1;

    for (int j = countTerms; j >= i+1; j--){
        children[j+1] = children[j]; //shifts node to open a spot for new child
    }
    children[i+1] = z;

    for (int j = countTerms-1; j >= i; j--){
        keyArray[j+1] = keyArray[j];
    }
    keyArray[i] = y->keyArray[degree-1];

    countTerms++;
}
int BTreeNode::findKeyIndex(int term) {
    int index = 0;
    while (index < countTerms & keyArray[index] < term){
        ++index;

    }
    return index;
}

void BTreeNode::removeKey(int term) {
    bool preFillChk;
    int index = findKeyIndex(term);

        if (index < countTerms && keyArray[index]== term){ //key found in node
            if(this->isLeaf){
                for (int i = index+1; i<countTerms; ++i){
                    keyArray[i-1] = keyArray[i];
                }
                countTerms = countTerms - 1;

            } else{
                if (children[index]->countTerms >= degree){
                    int pred = getPredecessorKey(index);
                    keyArray[index] = pred;
                    children[index]->removeKey(pred);
                }else if (children[index + 1]->countTerms >= degree){
                    int suc = getSuccessorKey(index);
                    keyArray[index] = suc;
                    children[index]->removeKey(suc);

                }else{
                    mergeNodes(index);
                    children[index]->removeKey(term);
                }
            }

        }else{
            if (this->isLeaf){
                cout << "Term not found, ending..." << endl;
                return;
            }
            if (index = countTerms){
                preFillChk = true;
            }else
                preFillChk = false;

            if (children[index]->countTerms < degree){
                fillToMin(index);
            }
            if (preFillChk && index > countTerms){
                index--;
            }

            children[index]->removeKey(term);
        }
}
int BTreeNode::getPredecessorKey(int index) {
    BTreeNode *cursor = children[index];
    while(!cursor->isLeaf){
        cursor = cursor->children[cursor->countTerms];
    }
    return cursor->keyArray[cursor->countTerms - 1];
}
int BTreeNode::getSuccessorKey(int index) {
    BTreeNode *cursor = children[index + 1];
    while(!cursor->isLeaf){
        cursor = cursor->children[0];
    }
    return cursor->keyArray[0];
}
void BTreeNode::fillToMin(int index) {

    if (index != 0 && children[index-1]->countTerms >= degree){
        //borrowfromprevious
        BTreeNode *child = children[index];
        BTreeNode *prevChild = children[index -1];

        for (int i = (child->countTerms -1); i >= 0; --i){
            child->keyArray[i+1] = child->keyArray[i];
        }
        if (!child->isLeaf){
            for (int i = (child->countTerms); i >= 0; --i) {
                child->children[i + 1] = child->children[i];
            }
        }

        child->keyArray[0] = keyArray[index - 1];

        if (!child->isLeaf){
            child->children[0] = prevChild->children[prevChild->countTerms];
        }

        keyArray[index-1] = prevChild->keyArray[prevChild->countTerms - 1];

        child->countTerms++;
        prevChild->countTerms--;
    }else if (index != countTerms && children[index+1]->countTerms >= degree) {
        //borrowfromnext
        BTreeNode *child = children[index];
        BTreeNode *nextChild = children[index + 1];

        child->keyArray[child->countTerms] = keyArray[index];

        if (!child->isLeaf){
            child->children[child->countTerms + 1] = nextChild->children[0];
        }

        keyArray[index] = nextChild->keyArray[0];
        for (int i = 1; i < nextChild->countTerms; ++i){
            nextChild->keyArray[i-1] = nextChild->keyArray[i];
        }

        if (!nextChild->isLeaf){
            for (int i = 1; i < nextChild->countTerms; ++i) {
                nextChild->children[i - 1] = nextChild->children[i];
            }
        }

        child->countTerms++;
        nextChild->countTerms--;
    }else{
        if(index = countTerms){
            mergeNodes(index-1);
        }else{
            mergeNodes(index);
        }
    }
    return;
}
void BTreeNode::mergeNodes(int index) {
    BTreeNode *child = children[index];
    BTreeNode *mrgChild = children[index + 1];

    child->keyArray[degree-1] = keyArray[index];

    for (int i = 0; i < mrgChild->countTerms; ++i){
        child->keyArray[i+degree] = mrgChild->keyArray[i];
    }
    if (!child->isLeaf){
        for (int i = 0; i <= mrgChild->countTerms; ++i){
            child->children[i+degree] = mrgChild->children[i];
        }
    }
    for (int i = index + 1; i < countTerms; ++i){
        keyArray[i-1] = keyArray[i];
    }
    for (int i = index+2; i <= countTerms; ++i){
        children[i-1] = children[i];
    }
    child->countTerms += (mrgChild->countTerms + 1);
    countTerms--;

    delete(mrgChild);
    return;
}