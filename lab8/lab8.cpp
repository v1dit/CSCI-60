//template function

/*

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
int count_exact(T a[], int size, T find) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] == find) { // supports ==
            count += 1;
        }
    }
    return count;
}

template <typename T>
T frequent(T a[], size_t size) {
    assert(size <= 50); // Ensure size is 50 or less
    T most_frequent = a[0];
    int max_count = 0;

    for (size_t i = 0; i < size; i++) {
        int count = 0;
        for (size_t j = 0; j < size; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_frequent = a[i];
        }
    }
    return most_frequent;
}



int main() {
    int a[] = {1,2,5,4,5,10,5,8,9,10};
    int size = 10;
    cout<< count_exact(a, size, 10) << endl;

    string s[] = {"apple", "banana", "apple", "cherry", "apple"};
    int ssize = 5;
    cout<< count_exact(s, ssize, string("apple")) << endl;

     cout << frequent(s, ssize) << endl;
    return 0;
}

*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <typename T>
class NPoint {
private:
    T arr[10];      
    int dimension;

public:
    NPoint();                            
    NPoint(int dim);                      
    NPoint(int dim, const T input[]);     
    T get(int i) const;                  
    int size() const;                    
    void print() const;                  
    NPoint<T>& operator=(const NPoint<T>& rhs); 
};

template <typename T>
NPoint<T>::NPoint() {
    dimension = 0;
}

template <typename T>
NPoint<T>::NPoint(int dim) {
    assert(dim <= 10);
    dimension = dim;
    for (int i = 0; i < dimension; i++) {
        arr[i] = T(); 
    }
}

template <typename T>
NPoint<T>::NPoint(int dim, const T input[]) {
    assert(dim <= 10);
    dimension = dim;
    for (int i = 0; i < dimension; i++) {
        arr[i] = input[i];
    }
}


template <typename T>
T NPoint<T>::get(int i) const {
    assert(i >= 0 && i < dimension);
    return arr[i];
}

template <typename T>
int NPoint<T>::size() const {
    return dimension;
}

template <typename T>
void NPoint<T>::print() const {
    for (int i = 0; i < dimension; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
NPoint<T>& NPoint<T>::operator=(const NPoint<T>& rhs) {
    if (this == &rhs) return *this;
    dimension = rhs.size();
    for (int i = 0; i < dimension; i++) {
        arr[i] = rhs.get(i);
    }
    return *this;
}