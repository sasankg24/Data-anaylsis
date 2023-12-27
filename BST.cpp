#include "BST.h"
#include <iostream>
//constructor
BST::BST(){
    mpRoot = nullptr;
}
//deconstructor
BST::~BST() {
    destroyTree(mpRoot);
}

void BST::destroyTree(Node *&pT) {
    if (pT) {
        destroyTree(pT->mpLeft);
        destroyTree(pT->mpRight);
        delete pT;
        pT = nullptr;
    }
}

void BST::insert(Node *&pT, Node *&newNode) {
    if (pT == nullptr) {
        pT = newNode;
    } else if (newNode->mData < pT->mData) {
        insert(pT->mpLeft, newNode);
    } else {
        insert(pT->mpRight, newNode);
    }
}

void BST::inOrderTraversal(Node *&pT) {
    if (pT) {
        inOrderTraversal(pT->mpLeft);
        pT->printData();  // Assuming printData() prints the data to the console
        inOrderTraversal(pT->mpRight);
    }
}

TransactionNode &BST::findSmallest(Node *&pT) {
    if (pT == nullptr || pT->mpLeft == nullptr) {
        return dynamic_cast<TransactionNode&>(*pT);  // Assume pT is never nullptr
    } else {
        return findSmallest(pT->mpLeft);
    }
}

TransactionNode &BST::findLargest(Node *&pT) {
    if (pT == nullptr || pT->mpRight == nullptr) {
        return dynamic_cast<TransactionNode&>(*pT);  // Assume pT is never nullptr
    } else {
        return findLargest(pT->mpRight);
    }
}

void BST::insert(Node *newNode) {
    insert(mpRoot, newNode);
}

void BST::inOrderTraversal() {
    inOrderTraversal(mpRoot);
}

TransactionNode &BST::findSmallest() {
    return findSmallest(mpRoot);
}

TransactionNode &BST::findLargest() {
    return findLargest(mpRoot);
}