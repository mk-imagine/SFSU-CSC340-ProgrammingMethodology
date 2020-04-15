/*
	@author Mark Kim

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

const static string file = "Data.CS.SFSU.txt";  // could be placed in init() function, but is more visible here
const static string nullValue = "**000**";
const static string error = "<2nd argument must be a part of speech or \"distinct\">";
set<string> partsOfSpeech;
multimap<string, vector<string>> d;
list<string> output;

// change entire string to lower case
void tolowercase(string& s) {
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{
		s[i] = tolower(s[i]);
	}
}

// parse text and return in vector
vector<string> parseText(const string& s, const string& delim) {
	vector<string> result;
	auto start = 0;
	auto end = s.find(delim);
	while (end != string::npos) {
		result.push_back(s.substr(start, end - start));
		start = end + delim.length();
		end = s.find(delim, start);
	}
	result.push_back(s.substr(start, s.length()));
	return result;
}

// initialize data structure
void init() {
	string line;
	fstream ioFile;
	cout << "! Opening data file... ./" << file << endl;
	ioFile.open(file, ios::in);
	if (!ioFile) {
		cout << "ERROR: Unable to open file.";
		return;
	}
	cout << "! Loading data..." << endl;
	while (getline(ioFile, line)) {
		vector<string> firstParse = parseText(line, "|");
		for (vector<string>::iterator itr = firstParse.begin() + 1; itr != firstParse.end(); ++itr) {
			vector<string> secondParse = parseText(*itr, " -=>> ");
			partsOfSpeech.insert(secondParse[0]);
			d.emplace(firstParse[0], secondParse);
		}
	}
	cout << "! Loading completed...\n! Closing data file... ./" << file << "\n\n----- DICTIONARY 340 C++ -----\n\n";
}

// display entire dictionary used for testing data structure
void showDictionary() {
	for (multimap<string, vector<string>>::iterator itr = d.begin(); itr != d.end(); ++itr) {
		cout << (*itr).first << " [" << (*itr).second[0] << "] : " << (*itr).second[1] << endl;
	}
}

// display results
void showOutput(list<string> sv) {
	cout << "       |\n";
	for (list<string>::iterator itr = sv.begin(); itr != sv.end(); ++itr) {
		cout << "\t" << *itr << endl;
	}
	cout << "       |\n";
}

// capitalize words accordingly
string outputCapitalization(const string& s) {
	string result = s;
	if (result.find("csc") == 0) {
		for (int i = 0; i < 3; i++) {
			result[i] = toupper(result[i]);
		}
	}
	else {
		result[0] = toupper(result[0]);
	}
	return result;
}

// query dictionary
void query(const string& keyword, const string& partOfSpeech, const bool& distinct) {
	for (multimap<string, vector<string>>::iterator itr = d.begin(); itr != d.end(); ++itr) {
		string k = (*itr).first;
		string p = (*itr).second[0];
		string d = (*itr).second[1];
		string o = outputCapitalization(k) + " [" + p + "] : " + d;
		if (keyword.compare(k) == 0 && partOfSpeech.compare(nullValue) == 0) {
			output.push_back(o);
		}
		else if (keyword.compare(k) == 0 && partOfSpeech.compare(p) == 0) {
			output.push_back(o);
		}
	}
	if (output.size() == 0) {
		output.push_back("<Not found>");
	}
	output.sort();
	if (distinct) {
		output.unique();
	}
}

// user session to recieve input and call queries
void runUserSession() {
	while (true) {
		string input;
		cout << "Search: ";
		getline(cin, input);
		tolowercase(input);
		vector<string> searchParams = parseText(input, " ");
		if (searchParams[0].compare("!q") == 0) {
			break;
		}
		switch (searchParams.size()) {
		case 1:
			query(searchParams[0], nullValue, false);
			break;
		case 2:
			if (partsOfSpeech.find(searchParams[1]) != partsOfSpeech.end()) {
				query(searchParams[0], searchParams[1], false);
			}
			else if (searchParams[1].compare("distinct") == 0) {
				query(searchParams[0], nullValue, true);
			}
			else {
				output.push_back(error);
			}
			break;
		case 3:
			if (partsOfSpeech.find(searchParams[1]) != partsOfSpeech.end() && searchParams[2].compare("distinct") == 0) {
				query(searchParams[0], searchParams[1], true);
			}
			else {
				output.push_back(error);
			}
			break;
		default:
			output.push_back("Too many parameters. Please enter 3 parameters at most. Thank you.\n");
			break;
		}
		showOutput(output);
		output.clear();
	}
}

int main() {
	init();
	runUserSession();
	cout << "\n-----THANK YOU-----" << endl;
	return 0;
}