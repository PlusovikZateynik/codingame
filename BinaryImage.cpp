/*Task Binary image from CodinGame
* https://www.codingame.com/ide/puzzle/binary-image
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool checkRowLength(std::vector<std::vector<int>>& integerStore) {
	int length = 0;

	for (int i = 0; i < integerStore[0].size(); i++) {
		length += integerStore[0][i];
	}

	for (int i = 1; i < integerStore.size(); i++) {
		int rowLength = 0;
		for (int k = 0; k < integerStore[i].size(); k++) {
			rowLength += integerStore[i][k];
		}
		if (length != rowLength) return false;
	}

	return true;
}


void PrintBinaryImage(std::vector<std::vector<int>>& integerStore) {
	for (auto& row : integerStore) {
		char symbol = '.';
		int index = 0;
		if (row[0] == 0) {
			symbol = 'O';
			index = 1;
		}
		for (int i = index; i < row.size(); i++) {
			for (int k = 0; k < row[i]; k++) {
				std::cout << symbol;
			}
			if (symbol == 'O') {
				symbol = '.';
			}
			else {
				symbol = 'O';
			}
		}
		std::cout << std::endl;
	}
}


std::vector<int> ParseDigitRow(std::string& row) {
	std::vector<int> digitStore;
	std::string digitSymbol = "";
	for (int i = 0; i < row.size(); i++) {
		if (row[i] == ' ') {
			digitStore.push_back(stoi(digitSymbol));
			digitSymbol = "";
		}
		else {
			digitSymbol += row[i];
		}

		if (i == row.size() - 1 && digitSymbol != "") {
			digitStore.push_back(stoi(digitSymbol));
		}
	}


	return digitStore;
}

int main()
{
	int h;
	cin >> h; cin.ignore();

	int length = 0;
	int rowLength = 0;
	vector<vector<int>> integerStore;
	for (int i = 0; i < h; i++) {
		string row;
		getline(cin, row);
		integerStore.push_back(ParseDigitRow(row));
	}

	if (checkRowLength(integerStore)) {
		PrintBinaryImage(integerStore);
	}
	else {
		cout << "INVALID";
	}

	return 0;
}