#include <iostream>

using namespace std;

void najveci_i_najmanji(int niz[], int velicina, int& ref_najveci, int& ref_najmanji)
{
    int najveci = niz[0];
    int najmanji = niz[0];
    ref_najveci = najveci;
    ref_najmanji = najmanji;
    int i;
    for (i = 0; i < velicina; i++)
    {
        if (niz[i] > ref_najveci)
        {
            ref_najveci = niz[i];
        }
        if (niz[i] < ref_najmanji)
        {
            ref_najmanji = niz[i];
        }
    }
}

int main()
{
    int velicina;

    cout << "unesite broj clanova niza: ";
    cin >> velicina;
    if (velicina <=0)
    {
        cout << "nemoguc broj clanova niza";
    }
    int* niz = new int[velicina];
    cout << "unesite clanove niza" << endl;
    for (int i = 0; i < velicina; i++)
    {
        cin >> niz[i];
    }

    int ref_najveci;
    int ref_najmanji;

    najveci_i_najmanji(niz, velicina, ref_najveci, ref_najmanji);
    cout << "najveci broj iz niza: " << ref_najveci << endl;
    cout << "najmanji broj iz niza: " << ref_najmanji;

    delete[] niz;
    return 0;
}