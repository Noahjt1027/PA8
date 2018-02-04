#include "TransactionNode.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.h
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

class BST {
public:
	BST(Node* newRoot = nullptr);
	~BST();
	void setRoot(Node* newRoot);
	Node* getRoot() const;
	void insert(string newString, int newUnits);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();
	
private:
	//Data members
	Node* mpRoot;
	//functions
	void destroyTree(Node* &pRoot);
	void insert(TransactionNode* &pNew, Node* &pRoot);
	void inOrderTraversal(Node* const &pRoot) const;
};