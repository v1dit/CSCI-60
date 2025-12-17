#include "parity.h"

int main() {
    int a[] = {2, 3, 4, 5, 6};

    cout << "Creating p1:\n";
    Parity p1(a, 5); // should call insert 5 times

    cout << "\nCopying p1 to p2:\n";
    Parity p2 = p1;  // should call copy constructor

    cout << "\nAssigning p1 to p3:\n";
    Parity p3;
    p3 = p1;         // should call assignment operator

    cout << "\nExiting main...\n";
    return 0;        // should call destructor 3 times (p3, p2, p1)
}
