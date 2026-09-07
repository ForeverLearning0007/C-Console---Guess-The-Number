/***************************************************************************************************************************************
 Name:      Forever Learning
 Date:      09.07.2026
 Purpose:   This program will be a game where you must guess the number
            
            in VS Code using mingw you must:
                    g++ main.cpp -o main -lwinmm && start cmd /K "main"
            to link the Multi-Media Library to our program
 **************************************************************************************************************************************/


#include <iostream>
#include <random>
//So emojis can be shown in the console
#ifdef _WIN32
#include <windows.h>
#endif


using namespace std;


int main()
{
    // Windows-specific setup to allow UTF-8 printing in the terminal
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif


    // 1. Obtain a random seed from the hardware
    std::random_device rd;

    // 2. Initialize the standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());

    // 3. Define the distribution range [1, 10] (inclusive)
    std::uniform_int_distribution<int> distrib(1, 10);

    // 4. Generate the random number
    int number = distrib(gen);

    // 5. Print the result to the console
    // std::cout << "Random number between 1 and 10: " << number << std::endl;

    bool isRunning = true;
    int guess = 0;
    int attempts = 0;

    cout << "========================================" << endl;
    cout << "    Welcome to the Number Guessing Game! " << endl;
    cout << "========================================" << endl;
    cout << "I have selected a secret number between 1 and 10." << endl;
    cout << "Can you guess what it is?\n" << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number)
        {
            cout << "❌ Too high! Try guessing a lower number.\n" << endl;
        }
        else if (guess < number) 
        {
            cout << "❌ Too low! Try guessing a higher number.\n" << endl;
        }
        else
        {
            cout << "\n 🎉 Congratulations! You got it!" << endl;
            cout << "The secret number was: " << number << endl;
            cout << "It took you " << attempts << " attempts to win the game! 🏆" << endl;
        }


    } while (guess != number);

    cout << "========================================" << endl;
    cout << "Thank you for playing! Have a great day!" << endl;
    cout << "========================================" << endl;
    

    return 0;
}
