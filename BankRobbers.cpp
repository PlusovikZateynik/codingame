/*Task Bank Robbers from CodinGame
https://www.codingame.com/ide/puzzle/bank-robbers
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calculateHeistTime(vector<int>& combinationCompose) {

    int totalCharactersAmount = combinationCompose[0];
    int digitAmount = combinationCompose[1];
    int vowelsAmount = totalCharactersAmount - digitAmount;

    int heistTime = (pow(10, digitAmount) * pow(5, vowelsAmount));

    return heistTime;
}

int checkMinIndexTime(vector<int>& robberList) {
    int minValue = robberList[0];
    int minIndex = 0;

    for (int i = 1; i < robberList.size(); i++) {
        if (minValue > robberList[i]) {
            minValue = robberList[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void setRobberTime(vector<int>& robberList, int& minIndex, int& newTimeValue) {
    robberList[minIndex] += newTimeValue;
}

int checkMaxRobberTime(vector<int>& robberList) {

    auto iterator = max_element(begin(robberList), end(robberList));

    int maxRobberTimeIndex = distance(robberList.begin(), iterator);
    return robberList[maxRobberTimeIndex];
}


int main()
{
    int r;
    cin >> r; cin.ignore();
    int v;
    cin >> v; cin.ignore();

    vector<vector<int>> combinationCompose;
    vector<int> robberList;

    for (int i = 0; i < r; i++) {
        robberList.push_back({});
    }

    for (int i = 0; i < v; i++) {
        combinationCompose.push_back({});
        int c;
        int n;
        cin >> c >> n; cin.ignore();
        combinationCompose[i].push_back(c);
        combinationCompose[i].push_back(n);
    }

    for (int i = 0; i < combinationCompose.size(); i++) {
        int newTimeValue = calculateHeistTime(combinationCompose[i]);
        int minTimeIndex = checkMinIndexTime(robberList);

        setRobberTime(robberList, minTimeIndex, newTimeValue);

    }

    cout << checkMaxRobberTime(robberList) << endl;

    return 0;
}