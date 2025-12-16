// Implementation starter file for CSCI 60 Homework 4; due Thursday 05/15/25
// List any collaborators and write your name here

#include "parity.h" // Do NOT add any additional libraries/namespaces!

Parity::Parity(int* a, size_t n) : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { //2 arg const that intializes everything to empty and inerst values from an input array while taking in size and array
    for (size_t i = 0; i < n; ++i) {
        insert(a[i]); // inserts values from the input arrya
    }
}

void Parity::insert(int val) {
    if (val % 2 == 0) {
        // Determine capacity and resize if needed
        size_t capacity = ((nEven_ + CAP - 1) / CAP) * CAP;
        if (nEven_ == capacity) {
            int* new_evens = new int[capacity + CAP];
            for (size_t i = 0; i < nEven_; ++i)
                new_evens[i] = evens_[i];
            delete[] evens_;
            evens_ = new_evens;
        }

        // Find insert position
        size_t pos = 0;
        while (pos < nEven_ && evens_[pos] <= val)
            ++pos;

        // Shift elements to the right
        for (size_t i = nEven_; i > pos; --i)
            evens_[i] = evens_[i - 1];

        // Insert value
        evens_[pos] = val;
        ++nEven_;
    } else {
        size_t capacity = ((nOdd_ + CAP - 1) / CAP) * CAP;
        if (nOdd_ == capacity) {
            int* new_odds = new int[capacity + CAP];
            for (size_t i = 0; i < nOdd_; ++i)
                new_odds[i] = odds_[i];
            delete[] odds_;
            odds_ = new_odds;
        }

        size_t pos = 0;
        while (pos < nOdd_ && odds_[pos] <= val)
            ++pos;

        for (size_t i = nOdd_; i > pos; --i)
            odds_[i] = odds_[i - 1];

        odds_[pos] = val;
        ++nOdd_;
    }
}


int Parity::min() const { //find min of the array
    int smallest = INT_MAX; //sets as smallest
    for (size_t i = 0; i < nEven_; ++i) { //loops thru array
        if (evens_[i] < smallest) { 
            smallest = evens_[i];
        } // if smaller than smallest it becomes smallest
    }
    for (size_t i = 0; i < nOdd_; ++i) {
        if (odds_[i] < smallest) {
            smallest = odds_[i];
        } // same thing for odds
    }
    return smallest;
}


int Parity::max() const {
    int largest = INT_MIN; //sets as largest
    for (size_t i = 0; i < nEven_; ++i) { //loops thru array
        if (evens_[i] > largest) {
            largest = evens_[i];
        } // if larger than largest it becomes largest
    }
    for (size_t i = 0; i < nOdd_; ++i) {
        if (odds_[i] > largest) {
            largest = odds_[i];
        } // same for odds
    }
    return largest;
}

bool Parity::odd() const { //checks if it is odd or not
    return (nOdd_ % 2 == 1); //if modding it is 1, it is odd, if not its false (even)
}

ostream& operator <<(ostream& out, const Parity& p) {
    out << "E:"; // first writes "e" for evens
    for (size_t i = 0; i < p.nEven_; ++i) {
        out << " " << p.evens_[i];
    } 
    out << endl; // loops through and prints each even number

    out << "O:"; // writes "o" for odds
    for (size_t i = 0; i < p.nOdd_; ++i) {
        out << " " << p.odds_[i];
    }
    out << endl; // loops through and prints each odd number 

    return out;
}


Parity::~Parity() {
    delete[] evens_;
    delete[] odds_;
}



Parity::Parity(const Parity& rhs) {
    nEven_ = rhs.nEven_;
    nOdd_ = rhs.nOdd_;

    size_t evenCap = ((nEven_ + CAP - 1) / CAP) * CAP;
    size_t oddCap = ((nOdd_ + CAP - 1) / CAP) * CAP;

    evens_ = new int[evenCap];
    odds_ = new int[oddCap];

    for (size_t i = 0; i < nEven_; ++i)
        evens_[i] = rhs.evens_[i];
    for (size_t i = 0; i < nOdd_; ++i)
        odds_[i] = rhs.odds_[i];
}

Parity& Parity::operator=(const Parity& rhs) {
    if (this != &rhs) {
        // Free current memory
        delete[] evens_;
        delete[] odds_;

        // Copy counts
        nEven_ = rhs.nEven_;
        nOdd_ = rhs.nOdd_;

        // Allocate new memory
        size_t evenCap = ((nEven_ + CAP - 1) / CAP) * CAP;
        size_t oddCap = ((nOdd_ + CAP - 1) / CAP) * CAP;

        evens_ = new int[evenCap];
        odds_ = new int[oddCap];

        // Deep copy values
        for (size_t i = 0; i < nEven_; ++i)
            evens_[i] = rhs.evens_[i];
        for (size_t i = 0; i < nOdd_; ++i)
            odds_[i] = rhs.odds_[i];
    }
    return *this;
}


size_t Parity::remove(int val) {
    bool is_even = (val % 2 == 0);
    int* &arr = is_even ? evens_ : odds_;
    size_t &size = is_even ? nEven_ : nOdd_;

    size_t write = 0, count = 0;

    for (size_t read = 0; read < size; ++read) {
        if (arr[read] != val) {
            arr[write++] = arr[read];
        } else {
            ++count;
        }
    }

    size = write;

    // Resize downward if necessary
    size_t capacity = ((size + CAP - 1) / CAP) * CAP;
    int* new_arr = new int[capacity];
    for (size_t i = 0; i < size; ++i)
        new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;

    return count;
}




