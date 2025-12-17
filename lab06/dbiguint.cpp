
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include "dbiguint.h"
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


    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    dbiguint::dbiguint(){
        capacity_ = 1;
        data_ = new unsigned short [capacity_];

        for(int i = 0; i<capacity_;i++){
            data_[i]=0;
        }


    }

    dbiguint::dbiguint(const string & s){
        capacity_ = s.size();
        data_ = new unsigned short [capacity_];

        for(int i = 0; i<capacity_;i++){
            data_[i]= s[s.size()-1-i];
        }
    }


    int dbiguint::size() const {
    return capacity_;
}

    unsigned short dbiguint::operator [](int pos) const{
        if(pos < capacity_){
            return data_[pos];
        }
        return 0;
    }

    void dbiguint::reserve(int newcapacity) {
    if (newcapacity <= capacity_) {
        return;
    }
    
    unsigned short* new_data = new unsigned short[newcapacity];
    
    for (int i = 0; i < capacity_; i++) {
        new_data[i] = data_[i];
    }
    
    for (int i = capacity_; i < newcapacity; i++) {
        new_data[i] = 0;
    }
    
    delete[] data_;
    
    data_ = new_data;
    capacity_ = newcapacity;
}

void dbiguint::operator+=(const dbiguint & b) {
    int max_size = max(size(), b.size()) + 1;  
    if (max_size > capacity_) {
        reserve(max_size);
    }
    int carry = 0;
    for (int i = 0; i < capacity_; i++) {
        int sum = data_[i] + b[i] + carry;
        data_[i] = sum % 10;
        carry = sum / 10;
    }
    int new_size = capacity_;
    while (new_size > 1 && data_[new_size - 1] == 0) {
        new_size--;
    }
    if (new_size < capacity_) {
        unsigned short* new_data = new unsigned short[new_size];
        for (int i = 0; i < new_size; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_size;
    }
}
        
        

    //dbiguint::dbiguint(const dbiguint & b){
   //     return 0;
 //   }

/*

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

*/


