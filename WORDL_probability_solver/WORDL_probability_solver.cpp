// WORDL_probability_solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//purpose: write a program that feeds in English dictionary and then solves WORDL by giving the user probability distributions based on current Knowledge Base
//date: 3-11-2024
//date modified: 3-11-2024

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Specifying the file path
    string filePath = "C:\\Users\\demet\\Documents\\GitHub\\WORDL_solver\\English (American).dic";

    // Creating an ifstream object to open the file
    ifstream file(filePath);

    // A vector to store each processed line
    vector<string> English_Dictionary;

    // A vector to keep track of all guesses
    vector<string> guesses;

    // Check if the file was successfully opened
    if (file.is_open()) {
        string line;

        // Reading each line from the file
        while (getline(file, line)) {
            size_t slashPos = line.find('/');
            if (slashPos != string::npos) {
                line = line.substr(0, slashPos);
            }
            English_Dictionary.push_back(line);
        }

        file.close(); // Close the file

        cout << "File read successfully. " << English_Dictionary.size() << " words processed." << endl;

        srand(static_cast<unsigned int>(time(0))); // Seeding the random number generator

        if (!English_Dictionary.empty()) {
            int randomIndex = rand() % English_Dictionary.size();
            string WORDL_of_the_day = English_Dictionary[randomIndex];

            // Inform the user of the number of letters in the WORDL of the day
            cout << "WORDL of the day has " << WORDL_of_the_day.length() << " letters. Please enter a guess of exactly this length." << endl;

            string userGuess;
            bool wordGuessed = false;

            // Keep track of user's correct character positions
            string guessFeedback(WORDL_of_the_day.length(), '_');

            while (!wordGuessed) {
                cout << "Guess the word: " << guessFeedback << "\nEnter a guess: ";
                cin >> userGuess;

                // Ensure user guess is of correct length
                if (userGuess.length() != WORDL_of_the_day.length()) {
                    cout << "Please enter a word of exactly " << WORDL_of_the_day.length() << " letters." << endl;
                    continue; // Skip the rest of the loop and prompt for input again
                }

                // Add the guess to the guess history
                guesses.push_back(userGuess);

                // Check if the user's guess is correct
                if (userGuess == WORDL_of_the_day) {
                    wordGuessed = true;
                    cout << "Congratulations! You've guessed the WORDL of the day correctly: " << WORDL_of_the_day << endl;
                }
                else {
                    // Provide feedback on correct character positions
                    for (size_t i = 0; i < WORDL_of_the_day.length(); ++i) {
                        if (userGuess[i] == WORDL_of_the_day[i]) {
                            guessFeedback[i] = WORDL_of_the_day[i];
                        }
                    }
                    cout << "Not quite right. Here's what you've got correct so far: " << guessFeedback << endl;
                }

                // Optionally, show the guess history
                cout << "Your guess history: ";
                for (const auto& guess : guesses) {
                    cout << guess << " ";
                }
                cout << endl;
            }

        }
        else {
            cout << "The dictionary is empty. Unable to select a WORDL of the day." << endl;
        }

    }
    else {
        cout << "Failed to open file. Please check if the file exists and the path is correct." << endl;
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
