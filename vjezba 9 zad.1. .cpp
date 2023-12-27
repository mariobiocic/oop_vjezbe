#include <iostream>
#include <string>
using namespace std;

template <typename T>
const T& my_min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

int main()
{
    int broj1, broj2;
    string rijec1, rijec2;

    cout << "Unesi prvi broj: ";
    cin >> broj1;
    cout << "Unesi drugi broj: ";
    cin >> broj2;

    cout << "Unesi prvu rijec: ";
    cin >> rijec1;
    cout << "Unesi drugu rijec: ";
    cin >> rijec2;

    cout << "Min od brojeva: " << my_min(broj1, broj2) << endl;
    cout << "Min od stringova: " << my_min(rijec1, rijec2) << endl;

    return 0;
}
