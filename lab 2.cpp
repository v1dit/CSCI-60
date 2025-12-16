#include <iostream>
using namespace std;

int main(){
	cout<<"enter a number: "<< endl;
	int num;
	cin<<num;


	bool check = true;

	for(int i=2; i<num; i++){
		if(num%i==0)
			check = false;
			break;
	}
	if(check==true)
		cout<<"not prime"<<endl;
	else
		cout<<"prime"<<endl;
	}

}
