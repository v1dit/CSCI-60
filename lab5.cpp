#include <iostream>
using namespace std;

int main(){
  //Draw the memory picture for the code below, up until the next comment
  int * p1, n1=53, *p2, n2=72, *p3;
  
  //Step 1:  Draw a picture of the memory at this point
  p1 = &n1;
  //Step 2:  Draw a picture of the memory at this point
  p2 = &n2;
  //Step 3:  Draw a picture of the memory at this point
  p3 = p1;
  //Step 4:  Draw a picture of the memory at this point
  *p3 = 35;
  //Step 5:  Draw a picture of the memory at this point
  n2 = 21;
  //Step 6:  Draw a picture of the memory at this point
  p1=&n2;
  //Step 7:  Draw a picture of the memory at this point
  //Write down what will be printed by the line of code below
  cout<<"n1= "<<n1<<", n2= "<<n2<<", *p1= "<<*p1<<", *p2= "<<*p2<<", *p3= "<<*p3<<endl;

  int n1=53, n2=72;
  int *p1=&n1, *p2=&n2;
  double n4=6.3, *p4=&n4;
  //which of the following do or don't compile?  Why or why not?
  n4 = n1;//Step 1 runs
  n1 = n4;//Step 2 runs
  p1 = p4;//Step 3 no because diff types
  p2 = &p1;//Step 4 no because diff types
  p4 = &n1;//Step 5 no because diff types
  &n1 = &n2;//Step 6 no because you cannot change the address of something
  *p1 = *p2;//Step 7 runs 
  
  int arr[] = {11, 13, 15, 17};
  int *p=arr, *p3;
  cout<<p<<endl; //address of arr
  cout<<arr<<endl; //address of arr 
  cout<<arr[3]<<endl; //17
  cout<<p[3]<<endl; //17

  p3 = p+3;//move from p by 3 integer spots
  cout<<p3[0]<<endl;//All four of these are accessing the same value in the same spot //17
  cout<<*p3<<endl; //17 
  cout<<*(p+3)<<endl; //17
  cout<<p[3]<<endl; //17
  cout<<endl;
  *(p+3) = 99;
  for(int i=0; i<4; i++){
    cout<<p[i]<<" = "<<*(p+i)<<endl; //11,13,15,99
  }
  cout<<endl;

  int a=1, b=2, c=3, d=4, e=5;
  p=&a;
  for(int i=0; i<4; i++){
    cout<<p[i]<<endl; //1,4,undef, undef
  }
  cout<<endl;

  cout<<endl;
  p=&b;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl; //2, 1,4,undef
  }
  cout<<endl;
  p=&c;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;//3, 2, 1,4
  }
  cout<<endl;
  p=&d;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl;//4,3,2,1
  }
  cout<<endl;
  p=&e;
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl; //4, undef,5,4,3
  }
  cout<<endl;
  int f=6, g=7;
  //If I want to print both the 6 and the 7, should I set p=&f or p=&g?
  for(int i=0; i<10; i++){
    cout<<p[i]<<endl; //2,1,4,undef
  }


void max_avg(int a[], int size, int *max, int *avg) {
   *max = a[0];
   int average = 0;


   for(int i = 0; i < size; i++) {
       if(a[i] > *max) {
           *max = a[i];
       }
       average += a[i];
   }


   average = average / size;
   *avg = average;
}


int main() {
   int a[] = {2, 5, 6, 8, 13};
   int highest, average;
   int *max = &highest, *avg = &average, size = 5;
   max_avg(a, size, max, avg);
   cout << "Max: " << *max << endl << "Average: " << *avg << endl;
}
