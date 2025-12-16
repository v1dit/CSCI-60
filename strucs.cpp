#include <iostream>
using namespace std;

struct Student {
    string name;
    double gpa;
    int age;
};

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

int main() {
    Student s1;
    s1.name = "john";
    s1.gpa = 3.8;
    s1.age = 20;
    cout << "Student name is " << s1.name << ", GPA is " << s1.gpa << ", and they are " << s1.age << " years old." << endl;

    Rational r1(2, 3); // Uses parameterized constructor
    cout << "r1: " << r1.numer << " / " << r1.denom << endl;

    r1.numer = 4;
	cout << "r1: " << r1.numer << " / " << r1.denom << endl;




    Rational r2; // Uses default constructor
    cout << "r2: " << r2.numer << " / " << r2.denom << endl;

    return 0;
}
