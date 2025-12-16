#include <iostream>
#include <string)

class Bank
{
public:
	string name;
	int balance;
};

int main(){
	Bank account1;
	account1.name = "vidit";
	account1.balance = 3000;

	cout<<account1.name<<"has"<<account1.balance<<"dollars"<<endl;

	return 0;
}