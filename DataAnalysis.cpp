#include <string>
#include <iostream>
#include <sstream>
#include "DataAnalysis.h"
using namespace std;
void DataAnalysis::openFile(){
    //opens file 
    mCsvStream.open("data.csv");
    string str;
    mCsvStream>>str;
}

void DataAnalysis::processFile(){
    string units, type, trans, line;
    while (mCsvStream >> line) {
        stringstream ss(line);
        //gets each part
        getline(ss, units, ',');
        getline(ss, type, ',');
        getline(ss, trans, ',');
        TransactionNode* newNode = new TransactionNode(trans, stoi(units));
        if (trans == "Sold") {
            mTreeSold.insert(newNode);
        } else if (trans == "Purchased") {
            mTreePurchased.insert(newNode);
        }
        newNode->printData();
        cout << endl;
    }
}

void DataAnalysis::runAnalysis(){
    openFile();
    processFile();
    displayTrends();
}

void DataAnalysis::displayTrends() {
    TransactionNode &leastSold = mTreeSold.findSmallest();
    TransactionNode &mostSold = mTreeSold.findLargest();

    TransactionNode &leastPurchased = mTreePurchased.findSmallest();
    TransactionNode &mostPurchased = mTreePurchased.findLargest();

    cout << "Least Sold Transaction: ";
    leastSold.printData();
    cout << " (Units: " << leastSold.getUnits() << ")" << endl;

    cout << "Most Sold Transaction: ";
    mostSold.printData();
    cout << " (Units: " << mostSold.getUnits() << ")" << endl;

    cout << "Least Purchased Transaction: ";
    leastPurchased.printData();
    cout << " (Units: " << leastPurchased.getUnits() << ")" << endl;

    cout << "Most Purchased Transaction: ";
    mostPurchased.printData();
    cout << " (Units: " << mostPurchased.getUnits() << ")" << endl;
}
