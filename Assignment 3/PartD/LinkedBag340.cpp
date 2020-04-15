//	LinkedBag340.cpp
//	Created by: CSC340
//  Author: Mark Kim

#include <iostream>
#include <ctime>
#include "Node.h"
#include "LinkedBag.h"

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	return remove(headPtr->getNext()->getItem());
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
	// Node<ItemType>* nextNodePtr{ new Node<ItemType>(newEntry) };
	// Node<ItemType>* tempPtr{ headPtr };
	shared_ptr<Node<ItemType>> nextNodePtr{ new Node<ItemType>(newEntry) };	// constructor sets next to nullptr
	shared_ptr<Node<ItemType>> tempPtr{ headPtr };
	while (tempPtr->getNext() != nullptr) {
		tempPtr = tempPtr->getNext();
	}
	tempPtr->setNext(nextNodePtr);
	nextNodePtr = nullptr;  // not really necessary in this case, but added for safety and completeness
	itemCount++;
	return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	if (headPtr == nullptr) {
		return 0;
	}
	// Node<ItemType>* tempPtr{ headPtr };
	shared_ptr<Node<ItemType>> tempPtr{ headPtr };
	int count = 1;
	while (tempPtr->getNext() != nullptr) {
		tempPtr = tempPtr->getNext();
		count++;
	}
	return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	// static Node<ItemType>* nodePtr{ headPtr };
	static shared_ptr<Node<ItemType>> nodePtr{ headPtr };
	if (nodePtr != nullptr) {
		nodePtr = nodePtr->getNext();
		return getCurrentSize340RecursiveNoHelper() + 1;
	}
	nodePtr = headPtr;
	return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
	return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
	// static Node<ItemType>* nodePtr{ headPtr };
	static shared_ptr<Node<ItemType>> nodePtr{ headPtr };
	if (nodePtr != nullptr) {
		if (nodePtr->getItem() == anEntry) {
			nodePtr = nodePtr->getNext();
			return getFrequencyOf340RecursiveNoHelper(anEntry) + 1;
		}
		nodePtr = nodePtr->getNext();
		return getFrequencyOf340RecursiveNoHelper(anEntry);
	}
	nodePtr = headPtr;
	return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(shared_ptr<Node<ItemType>> nodePtr) const {
	if (nodePtr != nullptr) {
		return getCurrentSize340RecursiveHelper(nodePtr->getNext()) + 1;
	}
	return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(shared_ptr<Node<ItemType>> nodePtr, const ItemType& anEntry) const {
	if (nodePtr != nullptr) {
		if (anEntry == nodePtr->getItem()) {
			return getFrequencyOf340RecursiveHelper(nodePtr->getNext(), anEntry) + 1;
		}
		return getFrequencyOf340RecursiveHelper(nodePtr->getNext(), anEntry);
	}
	return 0;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	srand(static_cast<unsigned int>(time(NULL)));
	int rNode = rand() % itemCount;
	// Node<ItemType>* tempPtr{ headPtr };
	shared_ptr<Node<ItemType>> tempPtr{ headPtr };
	for (int i = 0; i < rNode; i++) {
		tempPtr = tempPtr->getNext();
	}
	ItemType temp = tempPtr->getItem();
	remove(tempPtr->getItem());
	return temp;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::getMostFrequent() const {
	shared_ptr<Node<ItemType>> curPtr{ headPtr };
	ItemType result = curPtr->getItem();
	int max = 0, eval;
	while (curPtr->getNext() != nullptr) {
		eval = getFrequencyOf(curPtr->getItem());
		if (eval > max) {
			max = eval;
			result = curPtr->getItem();
		}
		curPtr = curPtr->getNext();
	}
	return result;
}

template<typename ItemType>
shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPtrToMostFrequent() {
	shared_ptr<Node<ItemType>> curPtr{ headPtr };
	shared_ptr<Node<ItemType>> resultPtr;
	int max = 0, eval;
	while (curPtr->getNext() != nullptr) {
		eval = getFrequencyOf340RecursiveNoHelper(curPtr->getItem());
		if (eval > max) {
			max = eval;
			resultPtr = curPtr;
		}
		curPtr = curPtr->getNext();
	}
	return resultPtr;
}

template<typename ItemType>
int LinkedBag<ItemType>::removeMostFrequent(shared_ptr<Node<ItemType>> nodePtr) {
	int count = 0;
	const ItemType entry = nodePtr->getItem();
	while (nodePtr->getNext() != nullptr) {
		if (entry == nodePtr->getItem()) {
			remove(entry);
			count++;
		}
		nodePtr = nodePtr->getNext();
	}
	return count;
}

/*
template<typename ItemType>
ItemType LinkedBag<ItemType>::addRandom340() {
	srand(static_cast<unsigned int>(time(NULL)));
	int rNode = rand() % itemCount;
	// Node<ItemType>* tempPtr{ headPtr };
	shared_ptr<Node<ItemType>> tempPtr{ headPtr };
	for (int i = 0; i < rNode; i++) {
		tempPtr = tempPtr->getNext();
	}
	ItemType temp = tempPtr->getItem();
	remove(tempPtr->getItem());
	return temp;
}
*/