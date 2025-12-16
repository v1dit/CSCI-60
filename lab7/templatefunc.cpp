//template function
// Tiantian Chen, W7W, 05/14/2025

#include <iostream>
using namespace std;


//Interchanges the values of var1 and var2.
// void swapValues(int& var1, int& var2);
// void swapValues2(char& var1, char& var2);
// void swapValues3(double& var1, double& var2);

//template prefix (need to be included before both function declaration and definition)
template <typename T>
void swapValues(T& var1, T& var2);

//EXERCISE: Transform the following maximal function 
//as a template function so that it can also be used to
//find and return the largest value in double/char array
//What will be the requirement of type T in this case?
template <typename T>
T maximal(T arr[], int size);

int main(){
    int integer1 = 1, integer2 = 2;
    cout << "Original integer values are: "
         << integer1 << " " << integer2 << endl;
    swapValues(integer1, integer2);
    cout << "Swapped integer values are: "
         << integer1 << " " << integer2 << endl;


    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character values are: "
         << symbol1 << " " << symbol2 << endl;
    swapValues(symbol1, symbol2);
    cout << "Swapped character values are: "
         << symbol1 << " " << symbol2 << endl;


    double doubleV1 = 1.3, doubleV2 = 2.2;
    cout << "Original double values are: "
         << doubleV1 << " " << doubleV2 << endl;
    swapValues(doubleV1, doubleV2);
    cout << "Swapped double values are: "
         << doubleV1 << " " << doubleV2 << endl;

    int a[] = {1, 8, 3, 4};
    cout << "maximal(a, 4): " << maximal(a, 4) << endl;
    
    double b[] = {1.5, 4.5, 9.1};
    cout << "maximal(b, 4): " << maximal(b, 3) << endl;
    
    return 0;
}

//REQUIREMENT for type T: assignment operator needs to be defined for type T
template <typename T>
void swapValues(T& var1, T& var2){
    T temp;

    temp = var1;
    var1 = var2;
    var2 = temp;
}

//swap values of two ints
// void swapValues(int& var1, int& var2){
//     int temp;

//     temp = var1;
//     var1 = var2;
//     var2 = temp;
// }


//swap values of two chars
// void swapValues2(char& var1, char& var2){
//     char temp;

//     temp = var1;
//     var1 = var2;
//     var2 = temp;
// }

//swap values of two chars
// void swapValues3(double& var1, double& var2){
//     double temp;

//     temp = var1;
//     var1 = var2;
//     var2 = temp;
// }

//template prefix for template function (appear in both declaration and definition)
//requirement for type T:



//EXERCISE: Transform the following maximal function 
//as a template fucntion so that it can also be used to
//find and return the largest value in double/char array

// int maximal(int arr[], int size)
// {
//     int max=arr[0];
//     for(int i=1; i<size; i++){
//         if(arr[i]>max)
//         max=arr[i];
//     }
//     return max;
// }

template <typename T>
T maximal(T arr[], int size)
{
    T max=arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}






