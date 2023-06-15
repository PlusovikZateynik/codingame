/*Task from CodinGame
Body weight is a girl's secret
https://www.codingame.com/ide/puzzle/body-weight-is-a-girls-secret
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CheckedDigitStore(int& firstDigit, int& secondDigit, int& thirdDigit, int& sum) {
    vector<int> checkedDigitStore;
    if (abs(firstDigit - sum) % 2 == 0) {
        checkedDigitStore.push_back(firstDigit);
    }
    if (abs(secondDigit - sum) % 2 == 0 && secondDigit != firstDigit) {
        checkedDigitStore.push_back(secondDigit);
    }
    if (abs(thirdDigit - sum) % 2 == 0 && thirdDigit != secondDigit && thirdDigit != firstDigit) {
        checkedDigitStore.push_back(thirdDigit);
    }
    return checkedDigitStore;
}

vector<int> MakeMeasurementStore(vector<int>& weightStore, int& digit, int& sum) {
    vector<int> girlSecretWeight = { 0, 0, 0, 0, 0 };

    girlSecretWeight[4] = abs(digit - sum) / 2;
    girlSecretWeight[3] = weightStore[9] - girlSecretWeight[4];
    girlSecretWeight[2] = weightStore[8] - girlSecretWeight[4];
    girlSecretWeight[0] = weightStore[1] - girlSecretWeight[2];
    girlSecretWeight[1] = weightStore[0] - girlSecretWeight[0];

    return girlSecretWeight;
}

void PrintCorrectWeight(vector<vector<int>>& measurementStore, vector<int>& weightStore) {
    vector <vector<int>> measurementVariants;
    for (int i = 0; i < measurementStore.size(); i++) {
        vector<int> measurements;
        for (int k = 0; k < measurementStore[i].size() - 1; k++) {
            for (int m = k + 1; m < measurementStore[i].size(); m++) {
                int sum = measurementStore[i][k] + measurementStore[i][m];
                measurements.push_back(sum);
            }
        }
        std::sort(measurements.begin(), measurements.end());
        measurementVariants.push_back(measurements);
    }

    for (int i = 0; i < measurementVariants.size(); i++) {
        if (measurementVariants[i] == weightStore) {
            for (int k = 0; k < measurementStore[i].size(); k++) {
                cout << measurementStore[i][k];
                if (k != measurementStore[i].size() - 1) cout << " ";
            }
        }
    }
}


int main()
{
    vector<int> weightStore;
    vector<vector<int>> measurementStore;

    for (int i = 0; i < 10; i++) {
        int w;
        cin >> w; cin.ignore();
        weightStore.push_back(w);
    }

    int sum = weightStore[8] + weightStore[9];

    vector<int> checkedDigitStore = CheckedDigitStore(weightStore[5], weightStore[6], weightStore[7], sum);

    for (int i = 0; i < checkedDigitStore.size(); i++) {
        measurementStore.push_back(MakeMeasurementStore(weightStore, checkedDigitStore[i], sum));
    }

    PrintCorrectWeight(measurementStore, weightStore);

    return 0;
}

