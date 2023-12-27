#include <iostream>
#include "TransactionNode.h"

TransactionNode::TransactionNode(string str, int units) : Node(str), mUnits(units) {}

TransactionNode::~TransactionNode() {
}

void TransactionNode::printData() {
    cout << "Transaction Data: " << mData << " (Units: " << mUnits << ")" << endl;
}

int TransactionNode::getUnits() {
    return mUnits;
}

void TransactionNode::setUnits(int units) {
    mUnits = units;
}