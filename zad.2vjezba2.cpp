#include<iostream>

using namespace std;


int &element_niza_uvecan_za_jedan(int niz[], int zeljeni_indeks)
{
    return niz[zeljeni_indeks];
}

int main()
{
    int niz[] = { 23, 4, 5, 67, 56, 13 };
    int velicina = sizeof(niz) / sizeof(niz[0]);
    int zeljeni_indeks;
    cout << "unesite indeks zeljenog elementa: "<<endl;
    cin >> zeljeni_indeks;

    if (zeljeni_indeks < 0 || zeljeni_indeks >= velicina)
    {
        cout << "nemoguc izbor, zeljeni indeks nije u nizu." << endl;
    }
    else
    {
        int &ref_element = element_niza_uvecan_za_jedan(niz, zeljeni_indeks);
        ref_element = ref_element + 1;
        cout << "novi element: " << niz[zeljeni_indeks] << endl;
    }

    return 0;
}