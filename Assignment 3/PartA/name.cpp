// name.cpp : name class

#include "name.h"

Name::Name() {}
Name::Name(const string& firstName, const string& lastName)
	: firstName(firstName), lastName(lastName) {}

Name::~Name() {
	cout << "  **** Destructor ********" << endl << "  * Name: " << this->getName() << endl << "  * Object @: " << this << endl << "  ************************" << endl;
}

string Name::getFirstName() const {
	return this->firstName;
}

string Name::getLastName() const {
	return this->lastName;
}

string Name::getName() const {
	return this->firstName + " " + this->lastName;
}

void Name::setName(const string& firstName, const string& lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}