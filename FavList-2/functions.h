#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void Load(vector<string>& vector) {
	string line;
	ifstream readFile("W3-shows.txt"); 
	if(readFile.is_open()) {
		while(getline(readFile, line)) {
			vector.push_back(line);
		}
	} else {
		cout << "File could not be read.\n";
	}
}
void Add(vector<string>& vector) {
	cout << "\nWhat show would you like to add?\n\n";
	string input;
	getline(cin, input);

	vector.push_back(input);
	
	cout << "\nHere's your updated list:\n";
	for(int i = 0; i < vector.size(); i++) {
		cout << vector[i] << "\n";
	}
	ofstream writeFile("W3-shows.txt");
	if(writeFile.is_open()) {
		for(int i = 0; i < vector.size(); i++) {
			writeFile << vector[i] << "\n";
		}
	}
}

void Edit(vector<string>& vector) {
	::vector<string>::iterator iter = vector.begin();
	cout << "\nWhat show would you like to edit?\n\n";
	string input;
	getline(cin, input);
	iter = find(vector.begin(), vector.end(), input);
	if(iter != vector.end()) {
		cout << "What would you like to change " << input << " to?\n";
		getline(cin, input);
		*iter = input;
		cout << "\nHere's your updated list:\n";
		sort(vector.begin(), vector.end());
		for(int i = 0; i < vector.size(); i++) {
			cout << i + 1 << ". " << vector[i] << "\n";
		}
		cout << "\n";
		ofstream writeFile("W3-shows.txt");
		if(writeFile.is_open()) {
			for(int i = 0; i < vector.size(); i++) {
				writeFile << vector[i] << "\n";
			}
		}
	} else {
		cout << "Hm. I couldn't find that one, try searching again.\n\n";
	}
}

void Remove(vector<string>& vector) {
	::vector<string>::iterator iter = vector.begin();
	cout << "\nWhat show would you like to remove?\n\n";
	string input;
	getline(cin, input);
	iter = find(vector.begin(), vector.end(), input);
	if(iter != vector.end()) {
		cout << "Okay, " << input << " has been deleted.\n";
		vector.erase(iter);
		iter = vector.begin(); 
		cout << "\nHere's your updated list:\n";
		sort(vector.begin(), vector.end());
		for(int i = 0; i < vector.size(); i++) {
			cout << i + 1 << ". " << vector[i] << "\n";
		}
		cout << "\n";
		ofstream writeFile("W3-shows.txt");
		if(writeFile.is_open()) {
			for(int i = 0; i < vector.size(); i++) {
				writeFile << vector[i] << "\n";
			}
		}
	} else {
		cout << "Hm. I couldn't find that one, try searching again.\n\n";
	}
}

void View(const vector<string>& vector) {
	cout << "\nHere's your list:\n";
	for(int i = 0; i < vector.size(); i++) {
		cout << i + 1 << ". " << vector[i] << "\n";
	}
}

void Quit(const vector<string>& vector) {
	cout << "Before you leave, do you want to Save or Erase your list?\n\n";
	fstream file;
	string input;
	getline(cin, input);
	if(input == "Save" || input == "save") {
		file.close();
		cout << "\nOkay, list saved.\n";
	}
	else if(input == "Erase" || input == "erase") {
		ofstream writeFile("W3-shows.txt");
		writeFile.open("W3-shows.txt");
		if(writeFile.is_open()) {
			writeFile << "";
		}
		writeFile.close();
		cout << "\nYikes, list erased.\n";
	}
}