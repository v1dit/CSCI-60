#include <iostream>
using namespace std;


int main()
{
  int arr[] = {11, 13, 15, 17};
  int *p=arr, *p3;
  cout<<p<<endl;
  cout<<arr<<endl;
  cout<<arr[3]<<endl;
  cout<<p[3]<<endl;

  p3 = p+3;//move from p by 3 integer spots
  cout<<p3[0]<<endl;//All four of these are accessing the same value in the same spot
  cout<<*p3<<endl;
  cout<<*(p+3)<<endl;
  cout<<p[3]<<endl;
  cout<<endl;
  *(p+3) = 99;
  for(int i=0; i<4; i++){
    cout<<p[i]<<" = "<<*(p+i)<<endl;
  }
  cout<<endl;

  int a=1, b=2, c=3, d=4, e=5;
  p=&a;
  for(int i=0; i<4; i++){
    cout<<p[i]<<endl;
  }
  cout<<endl;

  cout<<endl;
  p=&b;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;
  }
  cout<<endl;
  p=&c;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;
  }
  cout<<endl;
  p=&d;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;
  }
  cout<<endl;
  p=&e;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;
  }
  cout<<endl;
  int f=6, g=7;
  //If I want to print both the 6 and the 7, should I set p=&f or p=&g?
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;
  }
return 0;
}
