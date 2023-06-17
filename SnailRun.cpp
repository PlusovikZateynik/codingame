#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void parseRow(string& row, map<int, vector<int>>& snailCoordinates, vector<vector<int>>& destinationStore, int& height) {
    for (int i = 0; i < row.size(); i++) {
        stringstream str;
        str << row[i];
        int index;
        str >> index;
        if (isdigit(row[i])) snailCoordinates[index] = { i, height };
        if (row[i] == '#') destinationStore.push_back({ i, height });
    }
}


int calculateShortestPath(int& snailNumber, int& snailSpeed, map<int, vector<int>>& snailCoordinates,
    vector<vector<int>>& destinationStore) {
    int shortestPath = 0;
    for (int i = 0; i < destinationStore.size(); i++) {
        shortestPath = (abs(destinationStore[i][0] - snailCoordinates[snailNumber + 1][0]) +
            abs(destinationStore[i][1] - snailCoordinates[snailNumber + 1][1])) / snailSpeed;
    }
    return shortestPath;
}

int main()
{
    int number_snails;
    cin >> number_snails; cin.ignore();
    vector<int> snailSpeedStore;
    map<int, vector<int>> snailCoordinates;
    vector<vector<int>> destinationStore;

    for (int i = 0; i < number_snails; i++) {
        int speed_snail;
        cin >> speed_snail; cin.ignore();
        snailSpeedStore.push_back(speed_snail);
    }
    int map_height;
    cin >> map_height; cin.ignore();
    int map_width;
    cin >> map_width; cin.ignore();
    for (int i = 0; i < map_height; i++) {
        string row;
        getline(cin, row);
        parseRow(row, snailCoordinates, destinationStore, i);
    }

    int index = 0;
    int winnerPath = calculateShortestPath(index, snailSpeedStore[0], snailCoordinates, destinationStore);

    for (int i = 1; i < number_snails; i++) {
        int path = calculateShortestPath(i, snailSpeedStore[i], snailCoordinates, destinationStore);
        if (path < winnerPath) {
            winnerPath = path; index = i;
        }
    }

    cout << index + 1 << endl;
}