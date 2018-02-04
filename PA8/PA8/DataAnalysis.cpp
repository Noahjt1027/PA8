#include "DataAnalysis.h"
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
void DataAnalysis::runAnalysis() {
	readLinesAndDisplay();
	writeTrends();
}

void DataAnalysis::csvOpen() {
	mCsvStream.open("data.csv");
}

void DataAnalysis::readLine(int & units, string & type, string & transaction, std::ifstream & csv) {
	string unitsString = "";
	std::getline(csv, unitsString, ',');
	units = std::stoi(unitsString);
	std::getline(csv, type, ',');
	std::getline(csv, transaction, '\n');

}

void DataAnalysis::readLinesAndDisplay() {
	string type = "", transaction = "";
	int units = 0;
	string line = "";
	csvOpen();
	std::getline(mCsvStream, line);
	readLine(units, type, transaction, mCsvStream);
	while (mCsvStream.good()) {
		insertToTree(units, type, transaction);
		readLine(units, type, transaction, mCsvStream);
	}
	insertToTree(units, type, transaction);
	cout << "Sold Tree:\n" << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;
	cout << "Purchased Tree\n" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;
	mCsvStream.close();
}

void DataAnalysis::insertToTree(int units, string type, string transaction) {
	if (transaction == "Purchased") {
		mTreePurchased.insert(type, units);
	}
	else if (transaction == "Sold") {
		mTreeSold.insert(type, units);
	}
}

void DataAnalysis::writeTrends() {
	cout << "Least purchased item: " << mTreePurchased.findSmallest().getData() << " - Units: " << mTreePurchased.findSmallest().getUnits() << endl;
	cout << "Most purchased item: " << mTreePurchased.findLargest().getData() << " - Units: " << mTreePurchased.findLargest().getUnits() << endl;
	cout << "Least sold item: " << mTreeSold.findSmallest().getData() << " - Units: " << mTreeSold.findSmallest().getUnits() << endl;
	cout << "Most sold item: " << mTreeSold.findLargest().getData() << " - Units: " << mTreePurchased.findLargest().getUnits() << endl;
}