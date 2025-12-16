// Test program for CSCI 60 Homework 2; due Tuesday, 04/29/2025
// This program tests each function of the Histogram class.
// Name: vidit agarwal

#include <iostream>
#include "histogram.h"
using namespace std;

int main() {
    // Test 1: File-reading constructor
    Histogram h("data.txt");
    cout << "Histogram from file (data.txt):\n";
    cout << h << endl; // tests operator<<

    // Test 2: Default constructor
    Histogram empty;
    cout << "Empty histogram size: " << empty.size() << "\n\n";

    // Test 3: Function outputs
    cout << "Size: " << h.size() << endl;
    cout << "Min: " << h.min() << endl;
    cout << "Max: " << h.max() << endl;
    cout << "Mode: " << h.mode() << endl;
    cout << "Median: " << h.median() << endl;
    cout << "Mean: " << h.mean() << endl;
    cout << "Variance: " << h.variance() << "\n\n";

    // Test 4: operator[]
    cout << "Count of 2s: " << h[2] << endl;
    cout << "Count of 9s: " << h[9] << "\n\n";

    // Test 5: operator+=
    Histogram h2("data.txt");
    h += h2;
    cout << "After h += h2:\n";
    cout << h;

    return 0;
}
