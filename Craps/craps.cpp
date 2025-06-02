//**************************************************************************
//
// Student name: Moaz Zawra
//
// Student number: 200449085
//
// Dr. Cory Butz
//
// Assignment number: CS 110 Assignment #3
//
// Program name: craps.cpp
//
// Last date modified: June 01, 2025
//
// Problem statement: This C++ program takes in an integer parameter via a void function to generate a random dice roll, returns the sum of the two given rolls, via two added integer parameters, and outputs a message to the user describing the two rolled values and their sum
//
// Input: the randomly generated value of the dice roll
//
// Output: a message to the user describing the two rolled values and their sum
//
// Main algorithm: generate a random dice roll
//                 return the sum of the two given dice rolls
//                 print out a message describing the two rolled values and their sum
//                 based on the results, the user is declared "win" or "lose"
//
// Major variables: SumOfRolls - the sum of the two randomly generated dice rolls
//                  dice1 - the first dice rolled
//                  dice2 - the second dice rolled
//                  diceRoll - the variable assigned to the "GetRoll" void function
//                  diceRoll1 - equals to diceRoll and represents the second randomly generated roll
//****************************************************************************

#include <iostream>
#include <ctime>   /* Header file used for the "rand() function", which is used to generate a random number */
#include <cstdlib> /* Header file used for the "rand() function", which is used to generate a random number */
using namespace std;

// Function prototypes
void GetRoll(int &); // Function using a reference parameter, "passing by reference"
int CalcSum(int, int);
void PrintRoll(int, int, int);

// Start of the main function
int main()
{
    // Set datatypes for variables to be used
    int SumOfRolls;
    int diceRoll1 = 0;
    int diceRoll = diceRoll1;
    int dice1 = 0, dice2 = 0;

    // Set time to 0 (NULL), used for generating a random number
    srand(time(0));

    // Function calls
    GetRoll(diceRoll);
    dice1 = diceRoll;
    GetRoll(diceRoll1);
    dice2 = diceRoll1;
    SumOfRolls = CalcSum(dice1, dice2);
    PrintRoll(dice1, dice2, SumOfRolls);

    // Conditions set for possible outcomes of summing the dice rolls
    if (SumOfRolls == 2 || SumOfRolls == 3 || SumOfRolls == 12)
    {
        cout << "You lose" << endl;
    }

    else if (SumOfRolls == 7 || SumOfRolls == 11)
    {
        cout << "You win" << endl;
    }

    else if (SumOfRolls == 4 || SumOfRolls == 5 || SumOfRolls == 6 || SumOfRolls == 8 || SumOfRolls == 9 || SumOfRolls == 10)
    {
        cout << "Point is " << SumOfRolls << endl;
    }

    /* Initiate a loop to continue the program, rolling the dice using randomly generated numbers, until the player/user is declared "losing" or "winning" */
    while (SumOfRolls == 4 || SumOfRolls == 5 || SumOfRolls == 6 || SumOfRolls == 8 || SumOfRolls == 9 || SumOfRolls == 10)
    {
        GetRoll(diceRoll);
        dice1 = diceRoll;
        GetRoll(diceRoll1);
        dice2 = diceRoll1;
        SumOfRolls = CalcSum(dice1, dice2);
        PrintRoll(dice1, dice2, SumOfRolls);

        if (SumOfRolls == 2 || SumOfRolls == 3 || SumOfRolls == 12)
        {
            cout << "You lose" << endl;
            break;
        }

        else if (SumOfRolls == 7 || SumOfRolls == 11)
        {
            cout << "You win" << endl;
            break;
        }
    }

    cout << "Press Enter to exit...";
    cin.get();
}

// Void function definition, includes one parameter
void GetRoll(int &diceRoll)
{
    // Generate a random number between 1 and 6
    diceRoll = (rand() % 6) + 1;
}

// Function definition, declared as int and includes two parameters
int CalcSum(int dice1, int dice2)
{
    // Sends the sum of the two generated random numbers to its respective function in the main
    int sum = 0;
    sum = dice1 + dice2;
    return sum;
}

// Void function definition, includes three parameters
void PrintRoll(int dice1, int dice2, int Sum)
{
    cout << "You rolled " << dice1 << " + " << dice2 << " = " << Sum << endl;
}
