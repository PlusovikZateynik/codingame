/*
* Task Mountain Map from CodinGame
* https://www.codingame.com/ide/puzzle/mountain-map
*/

#include <iostream>
#include <string>
#include <vector>

std::string GenerateMountainsSubString(int& mountainHeight, int& lineNumber, bool& isNewLine) {
    std::string mountainSubString = "";
    if (mountainHeight < lineNumber) {
        if (isNewLine) return "";
        for (int i = 0; i < (mountainHeight * 2); ++i) {
            mountainSubString += " ";
        }
    }
    else {
        for (int i = 0; i < lineNumber - 1; ++i) {
            mountainSubString += " ";
        }
        mountainSubString += "/";
        for (int i = 0; i < (mountainHeight - lineNumber) * 2; ++i) {
            mountainSubString += " ";
        }
        mountainSubString += "\\";
        if (!isNewLine) {
            for (int i = 0; i < lineNumber - 1; ++i) {
                mountainSubString += " ";
            }
        }
    }
    return mountainSubString;
}

void PrintMountains(std::vector<int>& mountainsHeightStore, int maxHeight) {
    for (int i = maxHeight; i > 0; --i) {
        std::string mountainLine = "";
        for (int k = 0; k < mountainsHeightStore.size(); ++k) {
            bool isNewLine = true;
            if (k < mountainsHeightStore.size() - 1) {
                for (int n = k + 1; n < mountainsHeightStore.size(); ++n) {
                    if (mountainsHeightStore[n] >= i) {
                        isNewLine = false;
                        break;
                    }
                }
            }

            mountainLine += GenerateMountainsSubString(mountainsHeightStore[k], i, isNewLine);
        }
        std::cout << mountainLine << std::endl;
    }
}

int main()
{
    int mountainsNumber; // the number of mountains
    std::cin >> mountainsNumber; std::cin.ignore();

    std::vector<int> mountainsHeightStore;
    int maxHeight = 1;

    for (int i = 0; i < mountainsNumber; ++i) {
        int height; // height of the mountain
        std::cin >> height; std::cin.ignore();
        mountainsHeightStore.push_back(height);
        if (maxHeight < height) maxHeight = height;
    }

    PrintMountains(mountainsHeightStore, maxHeight);

    return 0;
}


