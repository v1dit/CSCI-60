// Implementation starter file for CSCI 60 Homework 2; due Tuesday, 04/29/2025
// Comment functions below; list any collaborators and write your name here

#include "histogram.h"

// Default constructor initializes all counts to 0
Histogram::Histogram() {
    for (size_t i = 0; i <= MAX; i++) {
        counts[i] = 0; // no values seen yet
    }
}

// File-reading constructor reads integers from a file and updates counts
Histogram::Histogram(string filename) {
    for (size_t i = 0; i <= MAX; i++) {
        counts[i] = 0; // initialize all counts to 0 first
    }

    ifstream in(filename); // open the input file
    int val;
    while (in >> val) { // read each value
        if (val >= 0 && val <= MAX) {
            counts[val]++; // increment the count for that value
        }
    }

    in.close(); // close the file after reading
}

// operator+= adds the counts from another histogram to this one
Histogram& Histogram::operator+=(const Histogram& rhs) {
    for (size_t i = 0; i <= MAX; i++) {
        counts[i] += rhs.counts[i]; // add each count from rhs
    }
    return *this; // return the updated object 
}

// operator[] returns the count of a specific value
size_t Histogram::operator[](size_t i) const {
    if (i <= MAX) {
        return counts[i]; // return count if in range
    }
    return 0; // otherwise, return 0
}

// size() returns the total number of values in the histogram
size_t Histogram::size() const {
    size_t count = 0;
    for (size_t i = 0; i <= MAX; i++) {
        count += counts[i]; // sum all the counts
    }
    return count; // total count
}

// min() returns the smallest value that has a positive count
size_t Histogram::min() const {
    for (size_t i = 0; i <= MAX; i++) {
        if (counts[i] > 0) {
            return i; // first non-zero count found
        }
    }
    return MAX + 1; // if histogram is empty
}

// max() returns the largest value that has a positive count
size_t Histogram::max() const {
    for (int i = MAX; i >= 0; i--) {
        if (counts[i] > 0) {
            return i; // last non-zero count found
        }
    }
    return MAX + 1; // if histogram is empty
}

// mode() returns the value with the highest count
size_t Histogram::mode() const {
    size_t maxCount = 0;
    size_t leader = MAX + 1; // default to MAX+1

    for (size_t i = 0; i <= MAX; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i]; // update max count
            leader = i;           // track current mode
        }
    }

    return leader; // value with highest frequency
}

// median() returns the middle value (50th percentile)
size_t Histogram::median() const {
    size_t total = size(); // total number of values in the histogram
    if (total == 0) return MAX + 1; // histogram is empty

    size_t runningCount = 0; // how many we have seen
    size_t mid = total / 2; // the middle point 

    for (size_t i = 0; i <= MAX; i++) { // loop through array
        runningCount += counts[i]; // track of which value we are on
        if (runningCount > mid) { // check if we've reached the middle
            return i; // return the median value
        }
    }

    return MAX + 1; // should never reach here if total > 0
}

// mean() returns the average of all values in the histogram
double Histogram::mean() const {
    size_t total = size();
    if (total == 0) return 0.0; // avoid divide by zero

    size_t sum = 0;
    for (size_t i = 0; i <= MAX; i++) {
        sum += counts[i] * i; // add value * frequency
    }

    return (double)sum / total;  // convert to double for accurate division
}

// variance() returns the variance (spread from the mean)
double Histogram::variance() const {
    size_t total = size();
    if (total == 0) return 0.0; // avoid division by zero

    double meanVal = mean(); // compute the mean
    double sum = 0.0;

    for (size_t i = 0; i <= MAX; i++) {
        double diff = i - meanVal; // difference from the mean
        sum += counts[i] * diff * diff; // add squared difference * frequency
    }

    return sum / total; // divide by total for variance
}

// operator<< prints the histogram to an output stream
ostream& operator<<(ostream& out, const Histogram& h) {
    size_t start = h.min(); // get first value with positive count
    size_t end = h.max();   // get last value with positive count

    for (size_t i = start; i <= end; i++) {
        size_t count = h[i]; // number of times i appeared
        if (count > 0) {
            out << i << ": " << string(count, '*') << endl; // print line of stars
        }
    }

    return out; 
}
