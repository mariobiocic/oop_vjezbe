#include <iostream>
#include <algorithm>

using namespace std;


template <typename T>
void mySort(T arr[], int size) {
    sort(arr, arr + size);
}


template <>
void mySort<char>(char arr[], int size) {
    sort(arr, arr + size, [](char a, char b) {
        return tolower(a) < tolower(b);
        });
}


template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int nizbr[] = { 5, 2, 8, 1, 3 };
    char nizstr[] = { 'b', 'A', 'c', 'D', 'a' };

    int duljina = sizeof(nizbr) / sizeof(nizbr[0]);
    int duljinastr = sizeof(nizstr) / sizeof(nizstr[0]);

    
    mySort(nizbr, duljina);
    cout << "Sorted intArray: ";
    printArray(nizbr, duljina);

    
    mySort(nizstr, duljinastr);
    cout << "Sorted charArray: ";
    printArray(nizstr, duljinastr);

    return 0;
}