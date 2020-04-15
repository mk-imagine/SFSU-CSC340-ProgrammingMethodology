// ptrtester.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Tests pointers and smart pointers

#include "name.h"

void pauseTest();
void checkStatus(const Name* name, string s, bool e);
void rawPtr_Test();
void smartPtr_RT_Test();
void smartPtr_Deletion_Test();
void uniquePtrConversion();
void weakPtrTest();

int main()
{
	rawPtr_Test();
	pauseTest();
	smartPtr_RT_Test();
	pauseTest();
	smartPtr_Deletion_Test();
	pauseTest();
	uniquePtrConversion();
	pauseTest();
	weakPtrTest();

}

// pause for enter
void pauseTest() {
	cout << "\n****** PRESS ENTER TO CONTINUE ******" << endl;
	cin.get();
}

// raw pointer status
void checkStatus(const Name* name, string s, bool e) {
	cout << "\nStatus of " << s << " pointer" << endl;
	cout << "  obj type       : " << typeid(*name).name() << endl;
	if (e) {
		cout << "  obj name       : " << (*name).getName() << endl;
	}
	else {
		cout << "  obj name       : object does not exist" << endl;
	}
	cout << "  object address : " << addressof(*name) << endl;
	cout << "  pointer address: " << &name << endl;
}

// unique pointer status
void checkStatus(const unique_ptr<Name>& name, string s, bool e) {
	cout << "\nStatus of " << s << " pointer" << endl;
	cout << "  obj type       : " << typeid(*name).name() << endl;
	if (e) {
		cout << "  obj name       : " << (*name).getName() << endl;
	}
	else {
		cout << "  obj name       : object does not exist" << endl;
	}
	cout << "  object address : " << addressof(*name) << endl;
	cout << "  pointer address: " << &name << endl;
}

// shared pointer status
void checkStatus(const shared_ptr<Name>& name, string s, bool e) {
	cout << "\nStatus of " << s << " pointer" << endl;
	cout << "  obj type         : " << typeid(*name).name() << endl;
	if (e) {
		cout << "  obj name         : " << (*name).getName() << endl;
	}
	else {
		cout << "  obj name         : object does not exist" << endl;
	}
	cout << "  object address   : " << addressof(*name) << endl;
	cout << "  pointer address  : " << &name << endl;
	cout << "  pointer use count: " << name.use_count() << endl;
}

// weak pointer status -- no object info available with weak pointer
void checkStatus(const weak_ptr<Name>& name, string s) {
	cout << "\nStatus of " << s << " pointer" << endl;
	cout << "  pointer address  : " << &name << endl;
	cout << "  pointer use count: " << name.use_count() << endl;
	cout << "  " + s + "stale/dangling? " + (name.expired() ? "YES" : "NO") << endl;
}

/******************************************
   PART A.1 - Raw Pointer Test
   Deleting the same memory twice
 ******************************************/

void rawPtr_Test() {
	cout << "\nPART A.1: RAW POINTER FUNCTION CALL" << endl;
	 // raw pointer to Name object
	string s{ "\"stitch\"" };
	string a{ "\"angel\"" };
	cout << "Creating " << s << " object and assigning to " << s << " pointer" << endl;
	Name* stitch{ new Name{ "Stitch", "626" } };
	bool fs = true;					// flag object's freestore status true
	checkStatus(stitch, s, fs);

	// raw pointer to same Name object
	cout << "\nAssigning " << s << " object to " << a << " pointer" << endl;
	Name* angel{ stitch };			// same memory address as stitch pointer
	checkStatus(angel, a, fs);

	// delete stitch pointer
	cout << "\nDeleting " << s << " pointer" << endl;
	delete stitch;					// object's memory returned to freestore
	fs = false;						// flag object's freestore status false

	checkStatus(stitch, s, fs);		// notice that object typeid still returns class Name
	checkStatus(angel, a, fs);

	// delete angel pointer
	// delete angel;				// CRASH! Corrupts freestore

	cout << "\nFUNCTION END" << endl;
}

/******************************************
   PART A.2 - Smart Pointer RT Stack Test
 ******************************************/

void smartPtr_RT_Test() {
	cout << "\nPART A.2: SMART POINTER FUNCTION CALL -- RUNTIME STACK" << endl;
	string a{ "\"lilo\"" };
	cout << "Creating " << a << " object and assigning to " << a << " unique pointer" << endl;
	unique_ptr<Name> lilo{ make_unique<Name>("Lilo", "Pelekai") };
	checkStatus(lilo, a, true);
	cout << "\nFUNCTION END" << endl;
}

/******************************************
   PART A.3 - Smart Pointer Deletion Test
 ******************************************/

void smartPtr_Deletion_Test() {
	cout << "\nPART A.3: SMART POINTER FUNCTION CALL -- OBJECT DELETION" << endl;
	string a{ "\"nani\"" };
	cout << "Creating " << a << " object and assigning to " << a << " unique pointer" << endl;
	unique_ptr<Name> nani{ make_unique<Name>("Nani", "Pelekai") };
	checkStatus(nani, a, true);
	cout << "\nResetting " << a << " unique pointer" << endl;
	nani.reset();
	checkStatus(nani, a, false);
	cout << "\nFUNCTION END" << endl;
}

/******************************************
   PART A.4 - Unique Pointer Conversion Test
 ******************************************/

void uniquePtrConversion() {
	cout << "\nPART A.4: UNIQUE TO SHARED POINTER CONVERSION FUNCTION CALL" << endl;
	string a{ "\"jumba_unique\"" };
	string b{ "\"jumba_shared\"" };
	string c{ "\"jumba2_shared\"" };
	string d{ "\"jumba\"" };
	cout << "Creating " << d << " object and assigning to " << a << " unique pointer" << endl;
	unique_ptr<Name> jumba_unique{ make_unique<Name>("Jumba", "Jookiba") };
	checkStatus(jumba_unique, a, true);
	cout << "\nCONVERTING " << a << " pointer to " << b << " pointer..." << endl;
	shared_ptr<Name> jumba_shared{ move(jumba_unique) };
	checkStatus(jumba_unique, a, false);
	checkStatus(jumba_shared, b, true);
	cout << "\nAssigning " << d << " object to " << c << " pointer" << endl;
	shared_ptr<Name> jumba2_shared{ jumba_shared };
	checkStatus(jumba_shared, b, true);
	checkStatus(jumba2_shared, c, true);
	cout << "\nFUNCTION END" << endl;
}

/******************************************
   PART A.5 - Weak Pointers that can Dangle
 ******************************************/

void weakPtrTest() {
	cout << "\nPART A.5: WEAK POINTERS LIKE POINTERS THAT DANGLE TEST" << endl;
	string a{ "\"wendell_shared\"" };
	string b{ "\"wendell_weak\"" };
	shared_ptr<Name> wendell_shared{ make_shared<Name>("Wendell", "Pleakley") };
	weak_ptr<Name> wendell_weak{ wendell_shared };
	checkStatus(wendell_shared, a, true);
	checkStatus(wendell_weak, b);
	wendell_shared.reset();
	checkStatus(wendell_shared, a, false);
	checkStatus(wendell_weak, b);
	cout << "\nFUNCTION END" << endl;
}