//	Node.h
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include <iostream>
using namespace std;

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
class Node {
public:
	Node();
	Node(const ItemType&);

	// Node(const ItemType&, Node<ItemType>*);
	Node(const ItemType&, shared_ptr<Node<ItemType>>);

	~Node();

	void setItem(const ItemType&);

	// void setNext(Node<ItemType>*);
	void setNext(shared_ptr<Node<ItemType>>);

	ItemType getItem() const;

	// Node<ItemType>* getNext() const;
	shared_ptr<Node<ItemType>> getNext() const;

private:
	ItemType        item;			 // A data item

	// Node<ItemType>* next{ nullptr }; // Pointer to next node
	shared_ptr<Node<ItemType>> next{ nullptr };
};