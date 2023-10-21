#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using std::vector;

int main()
{
	int suma=0;
	vector <int> vektor1 = { 234,236,500,311,2,34 };
	sort(vektor1.begin(), vektor1.end());
	int najmanji_element = *min_element(vektor1.begin(), vektor1.end());
	int najveci_element = *max_element(vektor1.begin(), vektor1.end());
	vektor1.insert(find(vektor1.begin(), vektor1.end(), najmanji_element), 0);
	for (int trenutni_broj : vektor1)
	{
		if(trenutni_broj!=najveci_element || trenutni_broj==najveci_element)
		{
			suma += trenutni_broj;
		}
	}

	vektor1.push_back(suma);
	for (int broj : vektor1) {
		std::cout << broj << ' ';
	}

	return 0;
}