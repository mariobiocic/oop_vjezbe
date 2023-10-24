#include<iostream>
#include"zad.1vjezba3(header).hpp"
#include<vector>
using namespace std;
using std::vector;

int main()
{
	vector<int> vektor;
	int a;
	cout << "unesi zeljeni broj elemenata: " << endl;
	cin >> a;

	broj_elemenata(vektor,a);
	cout << "Vektor nakon unosenja svih elemenata (nakon broja elemenata)" << endl;
	ispis(vektor);

	int c, d;
	int t;
	cout << "Unesite donju granicu intervala: ";
	cin >> c;
	cout << "Unesite gornju granicu intervala: ";
	cin >> d;
	if (c > d)
	{
		t = c;
		c = d;
		d = t;
	}

	interval(vektor, c, d);
	cout << "Vektor nakon granica intervala (drugog unosa): " << endl;
	ispis(vektor);

}