#include "Node.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         TransactionNode.h
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
class TransactionNode : public Node {
public:
	TransactionNode(string newString = "", int newUnits = 0);
	~TransactionNode();
	void setUnits(int newUnits);
	int getUnits() const;
	void printData() override;
private:
	int mUnits;

};
