#include <iostream>
#include <vector>
#include <algorithm>
#include "zad.1vjezba3(header).hpp"
using namespace std;
using std::vector;


int main()
{
	vector<int> vektor1;
	vector<int> vektor2;
	vector<int> rez;

	int br;
	cout << "unesi broj elemenata: " << endl;
	cin >> br;
	broj_elemenata(vektor1, br);

	int dg, gg;
	int t;
	cout << "unesi donju granicu: " << endl;
	cin >> dg;
	cout << "unesi gornju granicu: " << endl;
	cin >> gg;

	if (dg > gg)
	{
		t = dg;
		dg = gg;
		gg = t;
	}

	interval(vektor2, dg, gg);

	sort(vektor1.begin(), vektor1.end());
	sort(vektor2.begin(), vektor2.end());

	set_difference(vektor1.begin(), vektor1.end(),
		vektor2.begin(), vektor2.end(), back_inserter(rez));

	cout << "elementi koji nisu u drugom vektoru: " << endl;
	ispis(rez);
}

