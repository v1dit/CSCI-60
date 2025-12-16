/*
 * CSCI 60 — Lab 1
 * File: syntax.cpp
 * Author: (student submission)
 *
 * Purpose:
 *   Simple miles-per-gallon (MPG) calculator used in an introductory
 *   programming lab. The program prompts for miles driven and gallons
 *   of gasoline used, then prints the integer division result (miles/gallons).
 *
 * Main functions:
 *   - main(): reads two integer values from standard input and prints
 *     the integer result of dividing miles by gallons. No error handling
 *     (e.g., division by zero) is performed in this simple lab submission.
 */

#include <iostream>
using namespace std;

int main()
{
    // Prompt for miles driven (integer)
    cout << "amount of miles" << endl;
    int n;
    cin >> n;
    
    // Prompt for gallons used (integer)
    cout << "amount of gallons" << endl;
    int b;
    cin >> b;

    // Print integer division result (fractional part truncated)
    cout << n / b << endl;

    return 0;
}
