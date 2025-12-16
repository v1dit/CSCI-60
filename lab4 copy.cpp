
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
private:
    int arr[];
public: 

    static const int CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint() {data_[CAPACITY] =0;}


    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(string s);

    unsigned short operator[](int pos){
        if(pos < CAPACITY)
            return data_[pos];
        return 0;
    }


    // CONSTANT MEMBER FUNCTIONS

    // pre: none
    // post: returns the digit at position pos
    //          0 is the least significant (units) position


    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(biguint b) ;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry if any
    void operator += (biguint b){

        int temp;
        for(int i=0;i<CAPACITY;i++){
            data_[i] += b[i];
            temp =  data_[i] + b[i];


            if(temp > 9){
                data_[i+1] += 1
                data_[i] -= 10
            }
        }

    }
    // pre: this is > b, since unsigned
    // post: b is subtracted to this biguint; ignore last borrow if any
    void operator -= (biguint b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + ( biguint b1,  biguint b2);
biguint operator - ( biguint b1,  biguint b2);

bool operator < ( biguint b1,  biguint b2);
bool operator <= ( biguint b1,  biguint b2);
bool operator != ( biguint b1,  biguint b2);
bool operator == ( biguint b1,  biguint b2);
bool operator >= ( biguint b1,  biguint b2);
bool operator > ( biguint b1,  biguint b2);
std::ostream& operator <<(std::ostream& out,  biguint b);

biguint::biguint()
{
    for(int i;i< CAPACITY;i++)
    {
        data_[i] = 0;
    }
}
    
biguint::biguint(string s){
    int len=s.length();
    int num;
    char ch;

    for(int i;i< s.length();i++){
        ch = s[len-1-i];
        num = ch - '0';
        data_[i] = num;
    }
}

int main(){

  biguint b1("1472");
  cout << b1[0] << endl;


}

