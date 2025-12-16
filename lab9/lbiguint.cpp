#include "lbiguint.h"
#include <string>
#include <iostream>
using namespace std;



node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

int lbiguint::size() const {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        ++count;
        current = current->link();
    }
    return count;
}

int lbiguint::operator[](int pos) const {
    int index = 0;
    node* current = head;
    while (current != nullptr && index < pos) {
        current = current->link();
        ++index;
    }
    return (current != nullptr) ? current->data() : 0;
}

lbiguint::lbiguint(const lbiguint & b) {
    if (b.head == nullptr) {
        head = tail = new node(0, nullptr);
        return;
    }

    head = new node(b.head->data(), nullptr);
    node* curr_new = head;
    const node* curr_old = b.head->link();

    while (curr_old != nullptr) {
        curr_new->set_link(new node(curr_old->data(), nullptr));
        curr_new = curr_new->link();
        curr_old = curr_old->link();
    }

    tail = curr_new;
}

void lbiguint::operator=(const lbiguint & b) {
    if (this == &b) return; // self-assignment check

    // Delete old list
    while (head != nullptr) {
        node* temp = head;
        head = head->link();
        delete temp;
    }

    // Copy new list
    if (b.head == nullptr) {
        head = tail = new node(0, nullptr);
        return;
    }

    head = new node(b.head->data(), nullptr);
    node* curr_new = head;
    const node* curr_old = b.head->link();

    while (curr_old != nullptr) {
        curr_new->set_link(new node(curr_old->data(), nullptr));
        curr_new = curr_new->link();
        curr_old = curr_old->link();
    }

    tail = curr_new;
}

lbiguint::lbiguint(const std::string &s) {
    head = nullptr;
    tail = nullptr;
    
    int start = 0;
    while (start < s.size() && s[start] == '0') {
        ++start;
    }

    if (start == s.size()) {
        head = tail = new node(0, nullptr);
        return;
    }

    for (int i = s.size() - 1; i >= start; --i) {
        if (isdigit(s[i])) {
            int digit = s[i] - '0';
            if (!head) {
                head = tail = new node(digit, nullptr);
            } else {
                head = new node(digit, head);
            }
        }
    }
}

ostream & operator<<(ostream & out, const lbiguint & b) {
    if (!b.head) {
        out << '0';
        return out;
    }

    string digits;
    const node *current = b.head;
    while (current) {
        digits.insert(digits.begin(), current->data() + '0');
        current = current->link();
    }

    out << digits;
    return out;
}

int main() {
    lbiguint num1("123456");
    cout << "num1: " << num1 << endl;
    cout << "Size: " << num1.size() << endl;

    for (int i = 0; i < num1.size(); ++i) {
        cout << "num1[" << i << "] = " << num1[i] << endl;
    }

    lbiguint num2 = num1;
    cout << "num2 (copy of num1): " << num2 << endl;

    lbiguint num3("999");
    num3 = num1;
    cout << "num3 (assigned from num1): " << num3 << endl;

    return 0;
}


   