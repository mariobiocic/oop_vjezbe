#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using std::vector;

void uklanjanje(vector <int> &vektor, int indeks)
{
	if (indeks >= 0 && indeks < vektor.size())
	{
		vektor.erase(vektor.begin() + indeks);
	}
}

int main()
{
	vector <int> vektor2 = {234,1,124,-100,67,45};
	int velicina_vektora =vektor2.size() ;
	int element_za_ukloniti;
	cout << "unesi element za ukloniti" << endl;
	cin >> element_za_ukloniti;
	

	uklanjanje(vektor2, element_za_ukloniti);
	cout << "vektor nakon uklanjanja.";

	for (int element : vektor2)
		{
			cout << element << ' ';
		}
	cout << endl;

	return 0;
}