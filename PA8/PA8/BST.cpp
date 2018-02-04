#include "BST.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
BST::BST(Node* newRoot) {
	mpRoot = newRoot;
}

BST::~BST() {
	destroyTree(mpRoot);
}

void BST::setRoot(Node* newRoot) {
	mpRoot = newRoot;
}

Node* BST::getRoot() const {
	return mpRoot;
}

void BST::insert(string newString, int newUnits) {
	TransactionNode* pMem = new TransactionNode();
	pMem->setData(newString);
	pMem->setUnits(newUnits);
	insert(pMem, mpRoot);
}

void BST::insert(TransactionNode* &pNew, Node* &pRoot) {
	if (pRoot == nullptr) {
		pRoot = pNew;
	}
	else if (pNew->getUnits() > (dynamic_cast <TransactionNode*>(pRoot)->getUnits())) {
		insert(pNew, pRoot->getRight());
	}
	else if (pNew->getUnits() < (dynamic_cast <TransactionNode*>(pRoot)->getUnits())) {
		insert(pNew, pRoot->getLeft());
	}
}

void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}

void BST::inOrderTraversal(Node* const &pRoot) const {
	if (pRoot != nullptr) {
		inOrderTraversal(pRoot->getLeft());
		dynamic_cast <TransactionNode*>(pRoot)->printData();
		inOrderTraversal(pRoot->getRight());
	}
}

TransactionNode & BST::findSmallest() {
	Node * temp;
	TransactionNode * r;
	temp = getRoot();
	while (temp->getLeft() != nullptr) {
		temp = temp->getLeft();
	}
	r = dynamic_cast<TransactionNode*>(temp);
	return *r;

}

TransactionNode & BST::findLargest() {
	Node * temp;
	TransactionNode * r;
	temp = getRoot();
	while (temp->getRight() != nullptr) {
		temp = temp->getRight();
	}
	r = dynamic_cast<TransactionNode*>(temp);
	return *r;

}

void BST::destroyTree(Node* &pRoot){
	if (pRoot->getLeft() != nullptr) {
		Node* temp = pRoot->getLeft();
		destroyTree(temp);
	}
	if (pRoot->getRight() != nullptr) {
		Node* temp = pRoot->getRight();
		destroyTree(temp);
	}
	delete pRoot;
}