#include "TransactionNode.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         TransactionNode.cpp
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
TransactionNode::TransactionNode(string newString, int newUnits):Node(newString) {
	mUnits = newUnits;
}

TransactionNode::~TransactionNode() {
	
}

void TransactionNode::setUnits(int newUnits) {
	mUnits = newUnits;
}

int TransactionNode::getUnits() const {
	return mUnits;
}

void TransactionNode::printData() {
	cout << "Name: " << getData() << " ||  Units:" << getUnits() << endl;
}