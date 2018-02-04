#include "Node.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
Node::Node(string newString) {
	mData = newString;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node() {

}

void Node::setData(string newString) {
	mData = newString;
}

void Node::setLeft(Node* newLeft) {
	mpLeft = newLeft;
}

void Node::setRight(Node* newRight) {
	mpLeft = newRight;
}

string Node::getData() const {
	return mData;
}

Node*& Node::getLeft() {
	return mpLeft;
}

Node *& Node::getRight() {
	return mpRight;
}

void Node::printData() {
	cout << getData() << endl;
}
