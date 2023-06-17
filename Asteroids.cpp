/* Task Asteroids from CodinGame
https://www.codingame.com/ide/puzzle/asteroids
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int w;
    int h;
    int t1;
    int t2;
    int t3;
    cin >> w >> h >> t1 >> t2 >> t3; cin.ignore();

    map<char, vector<int>> asteroidsDataStoreForFirstPicture;
    map<char, vector<int>> asteroidsDataStoreForSecondPicture;
    map<char, vector<int>> asteroidsDataStoreForThirdPicture;

    vector<char> thirdPictureAsteroidsName;
    vector<vector<int>> thirdPictureAsteroidsCoordinates;

    float astetoidSpeedXT3;
    float astetoidSpeedYT3;


    for (int i = 0; i < h; i++) {
        string firstPictureRow;
        string secondPictureRow;
        cin >> firstPictureRow >> secondPictureRow; cin.ignore();

        for (int k = 0; k < firstPictureRow.size(); k++) {
            if (isalpha(firstPictureRow[k])) {
                asteroidsDataStoreForFirstPicture[firstPictureRow[k]].push_back(k + 1);
                asteroidsDataStoreForFirstPicture[firstPictureRow[k]].push_back(i + 1);
            }
        }

        for (int k = 0; k < secondPictureRow.size(); k++) {
            if (isalpha(secondPictureRow[k])) {
                asteroidsDataStoreForSecondPicture[secondPictureRow[k]].push_back(k + 1);
                asteroidsDataStoreForSecondPicture[secondPictureRow[k]].push_back(i + 1);
            }
        }
    }

    for (const auto& [key, value] : asteroidsDataStoreForFirstPicture) {
        int x3;
        int y3;

        astetoidSpeedXT3 = (float(asteroidsDataStoreForSecondPicture[key][0]) - float(asteroidsDataStoreForFirstPicture[key][0])) / float(t2 - t1);
        astetoidSpeedYT3 = (float(asteroidsDataStoreForSecondPicture[key][1]) - float(asteroidsDataStoreForFirstPicture[key][1])) / float(t2 - t1);
        if (astetoidSpeedXT3 == 0) {
            x3 = asteroidsDataStoreForSecondPicture[key][0];
        }
        else {
            x3 = int(float(asteroidsDataStoreForSecondPicture[key][0]) + float(t3 - t2) * astetoidSpeedXT3);
        }

        if (astetoidSpeedYT3 == 0) {
            y3 = asteroidsDataStoreForSecondPicture[key][1];
        }
        else {
            y3 = int(float(asteroidsDataStoreForSecondPicture[key][1]) + float(t3 - t2) * astetoidSpeedYT3);
        }
        asteroidsDataStoreForThirdPicture[key].push_back(x3);
        asteroidsDataStoreForThirdPicture[key].push_back(y3);
    }

    for (const auto& [key, value] : asteroidsDataStoreForThirdPicture) {
        thirdPictureAsteroidsName.push_back(key);
        thirdPictureAsteroidsCoordinates.push_back(value);
    }

    for (int i = 0; i < thirdPictureAsteroidsCoordinates.size(); i++) {
        for (int k = i + 1; k < thirdPictureAsteroidsCoordinates.size(); k++) {
            if (thirdPictureAsteroidsCoordinates[i] == thirdPictureAsteroidsCoordinates[k]) {
                asteroidsDataStoreForThirdPicture.erase(thirdPictureAsteroidsName[k]);
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int k = 1; k <= w; k++) {
            bool flag = true;
            for (const auto& [key, value] : asteroidsDataStoreForThirdPicture) {
                if (asteroidsDataStoreForThirdPicture[key][0] == k && asteroidsDataStoreForThirdPicture[key][1] == i) {
                    cout << key;
                    flag = false;
                }
            }
            if (flag) cout << ".";
        }
        cout << endl;
    }

}