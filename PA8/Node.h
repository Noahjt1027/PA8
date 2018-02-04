#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
///////////////////////////////////////////////////////////////////////////////
/// \file         Node.h
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
class Node {
public:
	Node(string newString);
	virtual ~Node();
	void setData(string newString);
	void setLeft(Node* newLeft);
	void setRight(Node* newRight);
	string getData() const;
	Node*& getLeft();
	Node*& getRight();
	virtual void printData();

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;

};