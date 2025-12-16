//define a simple class -- Rational
//compile: g++ Rational.cpp -std=c++11
//Tiantian Chen, Monday, April 14, 2025

#include <iostream>
using namespace std;

class Rational{
private: //cannot be accessed except by the member functions
    int numer, denom;

public:
    //0-arg constructor-->default constructor
    Rational(){
        // cout << "0-arg constructor is called" << endl;
        numer = 0;
        denom = 1;
    }

    //2-arg constructor
    //no return type; same name as my structure name
    Rational(int n, int d){
        // cout << "2-arg constructor is called" << endl;
        numer = n;
        denom = d;
    }

    //two getters/accessors--> access the values of 
    //private member variables
    int getNumer() const{ return numer; }
    int getDenom() const{ return denom; }

    //two setters/mutators--> change values of 
    //private member variables
    void setNumer(int n){ numer = n; }
    void setDenom(int d){ denom = d; }

    //overload * as a member function
    void operator *=(Rational rhs){
        numer = numer * rhs.numer;//numer *= rhs.numer;
        denom = denom * rhs.denom;
    }
    //overload []
    

    //EXERCISE: overload +=, -= as a member function
    void operator +=(Rational rhs){
        numer = (numer*rhs.denom) + (rhs.numer*denom);
        denom = denom*rhs.denom;
    }

    void operator -=(Rational rhs){
    numer = (numer*rhs.denom) - (rhs.numer*denom);
    denom = denom*rhs.denom;
    
    }

};

//overload * as a non-memeber (treat left and right equally)
Rational operator *(const Rational& lhs, const Rational& rhs){
    int numerNew = lhs.getNumer()*rhs.getNumer();
    int denomNew = lhs.getDenom()*rhs.getDenom();
    return Rational(numerNew, denomNew);
}

//overload + as a non-memeber (treat left and right equally)
Rational operator *(const Rational& lhs, const Rational& rhs){
    int numerNew = (lhs.getNumer()*rhs.getDenom())+(rhs.getNumer()*lhs.getDenom());
    int denomNew = lhs.getDenom()*rhs.getDenom();
    return Rational(numerNew, denomNew);


//overload << (can only be overloaded as a non-member)
//return as reference for chain output


int main(){

    //test for 2-arg constructor
    Rational r1(2, 3);
    // cout<<"r1: "<<r1.numer<<"/"<<r1.denom<<endl; //didn't work since numer and denom are private
    cout<<"r1: "<<r1.getNumer()<<"/"<<r1.getDenom()<<endl;

    // r1.setNumer(4);
    // cout<<"r1: "<<r1.getNumer()<<"/"<<r1.getDenom()<<endl;

    //test for 0-arg constructor
    Rational r2; //call the 0-arg constructor
    cout<<"r2: "<<r2.getNumer()<<"/"<<r2.getDenom()<<endl;
    
    //test for setters
    r2.setNumer(1);
    r2.setDenom(4);
    cout<<"r2: "<<r2.getNumer()<<"/"<<r2.getDenom()<<endl;

    //test for *= overloading
    r1 *= r2;
    cout<<"r1: "<<r1.getNumer()<<"/"<<r1.getDenom()<<endl;
    cout<<"r2: "<<r2.getNumer()<<"/"<<r2.getDenom()<<endl;

    //#1: test for * overloading
    // cout<<"test for * overloading\n";
    // Rational r3 = r1 * r2;
    // cout<<"r3: "<<r3.getNumer()<<"/"<<r3.getDenom()<<endl;
    
    //#2: overload <<
    // cout << "test for << overloading\n";
    // cout << "r3: " << r3; //cannot do this to output an object without overloading
    // cout << endl;

    //#3: overload []
    // cout << "test for [] overloading\n";
    // cout << "r3 numerator: " << r3[0] << endl;  //cannot do this now. need overload []
    // cout << "r3 denominator: " << r3[1] << endl;

    //EXERCISE: test for += overloading
    // cout << "test for += overloading\n";
    // r3 += r1;
    // cout<<"r3: "<<r3.getNumer()<<"/"<<r3.getDenom()<<endl;
    
    //EXERCISE: test for + overloading
    // cout << "test for + overloading\n";
    // r3 = r1 + r2;
    // cout<<"r3: "<<r3.getNumer()<<"/"<<r3.getDenom()<<endl;
    
    return 0;
}

//Elements of a class: member variables and member functions

//Difference between structure and class: class separates
//its definition into two parts: private and public parts,
//which makes class an abstract data type (users who
//use the class don’t know the details of how the 
//variables and operations are implemented.) 

//Public members: can be referenced by name anyplace.
//Private data: cannot be referenced by name except
//within member functions definitions of the class.

//Constructor: initiliation of member variables
//no return type; same name as struct/class name;

//Can different functions have same name?
//Yes, as long as they have different parameter lists

//Functions are distinghuished by their function signatures,
//which include function name and parameter list (parameter
//types and order)

// when a binary operator is overloaded as a member function,
// there is only one parameter, not two. The calling object 
// serves as the 1st parameter. When it is overloaded as a 
//non-member function, there are two paramters.




