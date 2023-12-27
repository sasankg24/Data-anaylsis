#include <string>
using namespace std;
//creates node for BST
class Node{
    public:
        string mData;
        Node *mpLeft;
        Node *mpRight;
    public:
        virtual ~Node();
        Node(string str);
        virtual void printData() = 0;
};