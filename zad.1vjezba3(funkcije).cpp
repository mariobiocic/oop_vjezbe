#include<iostream>
#include"zad.1vjezba3(header).hpp"
using namespace std;
#include<vector>

void broj_elemenata(vector<int> &vektor, int br_el)
{
	int broj;
	for (int i = 0;i < br_el;i++)
	{
		cin >> broj;
		vektor.push_back(broj);
	}
}

void interval(vector<int> &vektor, int donja_granica, int gornja_granica)
{
	int broj;
	while (true)
	{
		cout << "unesite broj: ";
		cin >> broj;
		if (broj<donja_granica || broj>gornja_granica)
		{
			break;
		}
		vektor.push_back(broj);
	}
}

void ispis(vector<int>& vektor)
{
	for (int element : vektor)
	{
		cout << element<<' ';
	}
}
