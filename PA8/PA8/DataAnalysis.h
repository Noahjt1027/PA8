#include"BST.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         DataAnalysis.h
/// \author		  Noah J Taylor
/// \date         
/// \brief        This program checks the contents of two bst generated from a csv file and outputs data about the trees to the user
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////
class DataAnalysis {
public:
	void runAnalysis();
private:
	//data members
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;
	//functions
	void csvOpen();
	void readLine(int & units, string & type, string & transaction, std::ifstream & csv);
	void insertToTree(int units, string type, string transaction);
	void readLinesAndDisplay();
	void writeTrends();
};