#include <iostream>
#include "Node.h"

Node::Node(string str)
{
    mData = str;
    mpLeft = nullptr;
    mpRight = nullptr;
}

Node::~Node() {
}

void Node::printData() {
    cout << "Data: " << mData << endl;
}