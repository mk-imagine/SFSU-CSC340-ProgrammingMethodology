// name.h : header file for name class

#pragma once
#include <iostream>
using namespace std;

class Name {

public:
	Name();
	Name(const string &, const string &);

	~Name();

	string getFirstName() const;
	string getLastName() const;
	string getName() const;
	void setName(const string&, const string&);

private:
	string firstName{ "N/A" };
	string lastName{ "N/A" };

};