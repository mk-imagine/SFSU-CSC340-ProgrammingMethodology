//	LinkedBagClient340.cpp
//	Created by: Duc Ta
//  Modified by: Mark Kim

#include "Include.h"

void displayBag(const unique_ptr<LinkedBag<string>>&);

int main() {

	cout << "----- LINKED BAG 340 C++ Part D - I am creative -----" << endl << endl;

	// 1. Create a bag and add initial nodes
	cout << "--->>>>> Test 1 --->>>>>" << endl;
	unique_ptr<LinkedBag<string>> bag = make_unique <LinkedBag<string>>();
	
	// A mall vector of small objects to test the bag
	vector<string> items { "#-END", "5-FIVE", "4-FOUR", "4-FOUR", "3-THREE", "2-TWO", "1-ONE", "0-ZERO", "#-BEGIN" };
	cout << " !add()...     ";
	vector<string>::const_iterator cItr;
	for (cItr = items.begin(); cItr  != items.end(); cItr++) {
		cout << *cItr << " ";
		bool success = bag->add(*cItr);
		if ( !success) {
			cout << " !add() FAILED: " << *cItr << endl;
		}
	}
	displayBag(bag);
	
	// 2. Add nodes to the end of the linked list
	bag->addEnd340("9-NINE");
	bag->addEnd340("4-FOUR"); 
	bag->addEnd340("9-NINE");
	bag->addEnd340("0-ZERO");
	displayBag(bag);

	// 3. getMostFrequent()
	cout << "\n--->>>>> Test 1 --->>>>>";
	cout << "\n !getMostFrequent()... ";
	cout << "\n  ---> " << bag->getMostFrequent();					// get most frequent item
	cout << "\n  ---> " << bag->getPtrToMostFrequent()->getItem() << endl;	// get pointer to most frequent item

	// 4. removeMostFrequent()
	cout << "\n--->>>>> Test 2 --->>>>>";
	cout << "\n !removeMostFrequent()... ";
	cout << "\n  Number of items removed: " << bag->removeMostFrequent(bag->getPtrToMostFrequent()) << endl;
	displayBag(bag);

	cout << endl;
	return 0;
}

// Display the current contents in the bag
void displayBag(const unique_ptr<LinkedBag<string>>& bag) {
	cout << "\n !Display bag: ";
	auto bagItems = make_unique<vector<string>>(bag->toVector());

	vector<string>::const_iterator cItr;
	for (cItr = bagItems->begin(); cItr  != bagItems->end(); cItr++) {
		cout << *cItr << " ";
	}
	
	cout << "\n  -----------> " << bagItems->size() << " item(s) total";
	cout << endl;
}