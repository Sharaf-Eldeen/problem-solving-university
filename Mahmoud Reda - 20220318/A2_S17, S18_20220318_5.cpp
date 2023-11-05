// File: Q5.cpp
// Purpose: program that manages a list of up to 10 players and their high scores
// Author: Mahmoud Reda
// Section: S17, S18
// ID: 20220318
// TA: Rana Abdelkader‏
// Date: 5 Nov 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
};

bool comparePlayers(const Player& a, const Player& b) {
    return a.score > b.score;
}

int main() {
    vector<Player> playerList;
    const int maxPlayers = 10;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a new player and score\n";
        cout << "2. Print top 10 players and scores\n";
        cout << "3. Find player's highest score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
        }

        switch (choice) {
            case 1: {
                Player newPlayer;
                cout << "Enter player's name: ";
                cin >> newPlayer.name;
                cout << "Enter player's score: ";
                cin >> newPlayer.score;

                playerList.push_back(newPlayer);
                sort(playerList.begin(), playerList.end(), comparePlayers);

                if (playerList.size() > maxPlayers) {
                    playerList.pop_back();
                }
                break;
            }
            case 2: {
                cout << "Top 10 players and scores:\n";
                int count = min(static_cast<int>(playerList.size()), maxPlayers);
                for (int i = 0; i < count; i++) {
                    cout << playerList[i].name << " " << playerList[i].score << "\n";
                }
                break;
            }
            case 3: {
                string playerName;
                cout << "Enter player's name to find the highest score: ";
                cin >> playerName;
                int highestScore = -1;
                for (const Player& player : playerList) {
                    if (player.name == playerName) {
                        highestScore = max(highestScore, player.score);
                    }
                }
                if (highestScore == -1) {
                    cout << "Player not found in the top 10 or hasn't been input.\n";
                } else {
                    cout << playerName << "'s highest score is " << highestScore << "\n";
                }
                break;
            }
            case 4: {
                cout << "Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        }
    }

    return 0;
}
