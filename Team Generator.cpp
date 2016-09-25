/*

Dinesh Singh
NBA 2K Team Generator
10/15/2014

*/

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

vector<string> getPlayers() {
	vector<string> playerList;
	while (true) {
		cout << "Enter a player's name: ";
		string playerName;
		cin >> playerName;
		if (playerName == "Done") {
			return playerList;
		}
		cout << "Player added to the pool. If finished, enter 'Done'." << endl;
		playerList.push_back(playerName);
	}
}

void generateTeams(vector<string>& playerList) {

	vector<string> teamOne;
	vector<string> teamTwo;
	vector<int> indexCount;

	for (string player : playerList) {
		int index = rand() % playerList.size();
		while (find(indexCount.begin(), indexCount.end(), index) != indexCount.end()) {
			index = rand() % playerList.size();
		}
		indexCount.push_back(index);
		if (teamOne.size() == teamTwo.size()) {
			teamOne.push_back(playerList[index]);
		}
		else {
			teamTwo.push_back(playerList[index]);
		}
	}

	cout << endl;
	cout << "=======================================================================" << endl;
	cout << "=======================================================================" << endl;
	cout << endl;

	cout << "Squad One: ";
	for (string s : teamOne) {
		cout << s << " ";
	}
	cout << endl;
	
	cout << "Squad Two: ";
	for (string s : teamTwo) {
		cout << s << " ";
	}
	cout << endl;
	cout << endl;
}

void displayArt() {
	ifstream basketballFile;
	basketballFile.open("ballislife.txt");
	if (!basketballFile) {
		cerr << "Error opening the file.\n" << endl;
		exit(1);
	}
	string lines = "";
	while (basketballFile) {
		string tempString;
		getline(basketballFile, tempString);
		tempString += "\n";
		lines += tempString;
	}
	cout << lines;
}

int main() {
	vector<string> playerList;
	playerList = getPlayers();
	generateTeams(playerList);
	displayArt();
	system("pause");
}