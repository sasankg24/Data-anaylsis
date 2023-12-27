#include <fstream>
#include "BST.h"
//reads file and gets the file information
class DataAnalysis {
private:
    BST mTreeSold;
    BST mTreePurchased;
    std::ifstream mCsvStream;

    void openFile();
    void parseLine();
    void processFile();
    void buildTrees();
    void displayTrends();

public:
    void runAnalysis();
};