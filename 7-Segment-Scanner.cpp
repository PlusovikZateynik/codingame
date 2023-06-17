/* Task 7-segment scanner from CodinGame
* https://www.codingame.com/ide/puzzle/7-segment-scanner
*/


#include <iostream>
#include <string>
#include <vector>

int DefineDigitForResultOutput(std::string& digitFirstLine, std::string& digitSecondLine,
    std::string& digitThirdLine) {
    if (digitSecondLine == "| |") {
        return 0;
    }
    else if (digitThirdLine == "|_ ") {
        return 2;
    }
    else if (digitFirstLine == "   ") {
        if (digitSecondLine == "  |") {
            return 1;
        }
        if (digitSecondLine == "|_|") {
            return 4;
        }
    }
    else if (digitThirdLine == " _|") {
        if (digitSecondLine == " _|") {
            return 3;
        }
        if (digitSecondLine == "|_ ") {
            return 5;
        }
        if (digitSecondLine == "|_|") {
            return 9;
        }
    }
    else if (digitThirdLine == "|_|") {
        if (digitSecondLine == "|_ ") {
            return 6;
        }
        if (digitSecondLine == "|_|") {
            return 8;
        }
    }
    return 7;
}

std::vector<int> ParseUserInput(std::string& line_1, std::string& line_2, std::string& line_3) {
    std::vector<int> digitOutputStore;
    int flag = 0;
    std::string digitFirstLine = "";
    std::string digitSecondLine = "";
    std::string digitThirdLine = "";
    for (int index = 0; index < line_1.size(); ++index) {
        ++flag;
        digitFirstLine += line_1[index];
        digitSecondLine += line_2[index];
        digitThirdLine += line_3[index];
        if (flag % 3 == 0) {
            int digitResult = DefineDigitForResultOutput(digitFirstLine, digitSecondLine,
                digitThirdLine);
            digitOutputStore.push_back(digitResult);
            digitFirstLine = "";
            digitSecondLine = "";
            digitThirdLine = "";
        }
    }
    return digitOutputStore;
}

void printResult(std::vector<int>& resultOutputStore) {
    for (int index = 0; index < resultOutputStore.size(); ++index) {
        std::cout << resultOutputStore[index];
    }
}

int main() {

    std::string line_1;
    getline(std::cin, line_1);
    std::string line_2;
    getline(std::cin, line_2);
    std::string line_3;
    getline(std::cin, line_3);

    std::vector<int> resultOutputStore;
    resultOutputStore = ParseUserInput(line_1, line_2, line_3);

    printResult(resultOutputStore);

    return 0;
}
