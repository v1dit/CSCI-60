#include <iostream>
using namespace std;

class Rational{
private:
	int numer, denom;
public:
	Rational() {
        numer = 0;
        denom = 1;

}

struct Rational {
    int numer, denom;

    // Default constructor (fixed missing closing brace)
    Rational() {
        numer = 0;
        denom = 1;
    } // Added closing brace here

    // Parameterized constructor
    Rational(int n, int d) {
        cout << "Rational constructor is called" << endl;
        numer = n;
        denom = d;
    }
};

    Rational r1(2, 3); // Uses parameterized constructor
    cout << "r1: " << r1.numer << " / " << r1.denom << endl;

    r1.numer = 4;
	cout << "r1: " << r1.numer << " / " << r1.denom << endl;




    Rational r2; // Uses default constructor
    cout << "r2: " << r2.numer << " / " << r2.denom << endl;

    return 0;
}
