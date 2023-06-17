/* Task Next car license plate from CodinGame
* https://www.codingame.com/ide/puzzle/next-car-license-plate
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>


using namespace std;

vector<string> parseLicensePlate(string& licensePlate) {
    vector<string> parsedLicensePlateStore;

    string licensePlatePart = "";

    for (int i = 0; i <= licensePlate.size(); i++) {
        if (licensePlate[i] == '-' || i == licensePlate.size()) {
            parsedLicensePlateStore.push_back(licensePlatePart);
            licensePlatePart = "";
        }
        else {
            licensePlatePart += licensePlate[i];
        }
    }

    return parsedLicensePlateStore;
}

void printPlate(vector<int> platePartStore, map<int, char>& licenseAlphabet) {
    cout << licenseAlphabet[platePartStore[0]] << licenseAlphabet[platePartStore[1]] << "-" << setw(3) << std::setfill('0') <<
        platePartStore[4] << "-" << licenseAlphabet[platePartStore[2]] << licenseAlphabet[platePartStore[3]] << endl;
}


vector<int> calculatePlate(vector<string>& licenseCarPlateStore, int& numberOfCars, map<char, int>& licenseAlphabet) {
    int middlePart = (numberOfCars + stoi(licenseCarPlateStore[1])) % 999;
    vector<int> platePartStore = { licenseAlphabet[licenseCarPlateStore[0][0]], licenseAlphabet[licenseCarPlateStore[0][1]],
        licenseAlphabet[licenseCarPlateStore[2][0]], licenseAlphabet[licenseCarPlateStore[2][1]], middlePart };
    if (numberOfCars + stoi(licenseCarPlateStore[1]) == 999) {
        platePartStore[4] = 999;
        return platePartStore;
    }

    int totalNumber = (numberOfCars + stoi(licenseCarPlateStore[1])) / 999;

    int firstRegister = totalNumber / pow(26, 3);
    totalNumber = totalNumber % (26 * 26 * 26);

    int secondRegister = totalNumber / pow(26, 2);
    totalNumber = totalNumber % (26 * 26);

    int thirdRegister = totalNumber / 26;
    int fourthRegister = totalNumber % 26;

    if ((licenseAlphabet[licenseCarPlateStore[2][1]] + fourthRegister) > 26) {
        thirdRegister++;
        fourthRegister -= 26;
    }

    if ((licenseAlphabet[licenseCarPlateStore[2][0]] + thirdRegister) > 26) {
        secondRegister++;
        thirdRegister -= 26;
    }

    if ((licenseAlphabet[licenseCarPlateStore[0][1]] + secondRegister) > 26) {
        firstRegister++;
        secondRegister -= 26;
    }


    platePartStore[0] += firstRegister;
    platePartStore[1] += secondRegister;
    platePartStore[2] += thirdRegister;
    platePartStore[3] += fourthRegister;
    platePartStore[4] = middlePart;

    return platePartStore;

}

int main()
{
    string x;
    getline(cin, x);
    int n;
    cin >> n; cin.ignore();

    map<char, int> firstLicenseAlphabet;
    map<int, char> secondLicenseAlphabet;

    for (int i = 1; i <= 26; i++) {
        int number = 64 + i;
        char letter = char(number);
        firstLicenseAlphabet[letter] = i;
        secondLicenseAlphabet[i] = letter;
    }

    vector<string> licenseCarPlateStore = parseLicensePlate(x);


    printPlate(calculatePlate(licenseCarPlateStore, n, firstLicenseAlphabet), secondLicenseAlphabet);

    return 0;
}