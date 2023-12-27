#include "TransactionNode.h"
//creates the BST for purchesed and sold
class BST{
    private:
        Node *mpRoot;
        void destroyTree(Node *&pT);
        void insert(Node*& pT, Node*& newNode);
        void inOrderTraversal(Node *&pT);
        TransactionNode &findSmallest(Node *&pT);
        TransactionNode &findLargest(Node *&pT);
    public:
        BST();
        ~BST();
        void insert(Node* newNode);
        void inOrderTraversal();
        TransactionNode &findSmallest();
        TransactionNode &findLargest();
};