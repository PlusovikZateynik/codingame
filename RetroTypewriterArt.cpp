/*Task Retro Typewriter Art from CodinGame
https://www.codingame.com/ide/puzzle/retro-typewriter-art
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int characterAmountWithAbbrevationCalculate(string& chunk) {
    string characterAmountString = "";
    for (int i = 0; i < chunk.size() - 2; i++) {
        characterAmountString += chunk[i];
    }
    int characterAmountDigit = stoi(characterAmountString);
    return characterAmountDigit;

}

int characterAmountCalculate(string& chunk) {
    string characterAmountString = "";
    for (int i = 0; i < chunk.size() - 1; i++) {
        characterAmountString += chunk[i];
    }
    int characterAmountDigit = stoi(characterAmountString);
    return characterAmountDigit;

}


void drawingChunk(string& chunk) {
    string twoLastSymbols;
    twoLastSymbols += chunk[chunk.size() - 2];
    twoLastSymbols += chunk[chunk.size() - 1];

    if (twoLastSymbols == "sp") {

        for (int i = 0; i < characterAmountWithAbbrevationCalculate(chunk); i++) {
            cout << " ";
        }

    }
    else if (twoLastSymbols == "bS") {

        for (int i = 0; i < characterAmountWithAbbrevationCalculate(chunk); i++) {
            cout << "\\";
        }

    }
    else if (twoLastSymbols == "sQ") {

        for (int i = 0; i < characterAmountWithAbbrevationCalculate(chunk); i++) {
            cout << "'";
        }

    }
    else if (twoLastSymbols == "nl") {

        cout << "\n";


    }
    else {
        for (int i = 0; i < characterAmountCalculate(chunk); i++) {
            cout << chunk[chunk.size() - 1];
        }
    }

}

void parseRecipe(string& recipe) {
    string chunk = "";
    for (int i = 0; i < recipe.size(); i++) {
        if (recipe[i] == ' ') {
            drawingChunk(chunk);
            chunk = "";
        }
        else {
            chunk += recipe[i];
            if (i == recipe.size() - 1) {
                drawingChunk(chunk);
            }
        }
    }
}

int main()
{
    string recipe;
    getline(cin, recipe);

    parseRecipe(recipe);

    return 0;
}


