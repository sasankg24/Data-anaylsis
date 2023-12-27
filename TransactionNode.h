#include "Node.h"
//creates a node for transactions
class TransactionNode : public Node{
    private:
        int mUnits;
    public:
        int getUnits();
        void setUnits(int units);
        ~TransactionNode();
        TransactionNode(string str, int units);
        void printData();
};