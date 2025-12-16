#include <iostream>
using namespace std;

/*
int isPrime(int num){
	for(int i=2; i<num; i++)
	{
		if(num%i==0)
			return false;
	}
	return true;
}

int main(){
	cout<<"enter a number: "<< endl;
	int num;
	cin>>num;
	if(isPrime(num))
		cout<<"prime"<<endl;
	else
		cout<<"not prime"<<endl;

	return 0;
	
}


int main(){
	for(int i=0;i<5;i++){
		for(int j=3;j>0;j--)
			cout<<i*j<< " ";
	}

	return 0;

}

*/

void maxAvg(double& a,double& m)
{
	double count = 0;
	double total = 0;

	cout<< "enter positive numbers, enter -1 to end"<<endl;
	double val;
	cin>>val;
	while(val!=-1)
	{
		if(val>m)
			m = val;
		total = total + val;
		count = count + 1;
		cout<<"Please enter a value, or -1 when you're done."<<endl;
        cin>>val;
	}

	a = total/count;
}

int main(){
	double a;
	double m;
	maxAvg(a,m);
	cout<<"average:"<<a<<" max: "<<m<<endl;

	return 0;
}


