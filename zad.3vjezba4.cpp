#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::vector;
using namespace std;

void naopako_sortiranje(int broj_stringova)
{
	vector<string> vektor_stringova;
	for (int i = 0;i < broj_stringova;i++)
	{
		string element;
		cout << "unesite string: " << endl;
		cin >> element;
		vektor_stringova.push_back(element);
	}

	for (string &clan : vektor_stringova)
	{
		reverse(clan.begin(), clan.end());
	}

	sort(vektor_stringova.begin(), vektor_stringova.end());
	
	for (int j = 0;j < broj_stringova;j++)
	{
		cout << vektor_stringova[j] << ' ';
	}
}

int main()
{

	int broj_stringova;
	cout << "koliko stringova zelite unijeti: " << endl;
	cin >> broj_stringova;
	naopako_sortiranje(broj_stringova);
	return 0;
}