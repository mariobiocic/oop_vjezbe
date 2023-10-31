#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include<algorithm>
using namespace std;
using std::vector;

string pig_latin()
{
	string recenica1 = "What time is it?";
	string recenica2 = "Dobar dan. Kako ste?";
	string recenica3 = "A to sam naucio, a ti? ";
	string recenica4 = "How do you do?";
	vector<string> vektor1;

	vektor1.push_back(recenica1);
	vektor1.push_back(recenica2);
	vektor1.push_back(recenica3);
	vektor1.push_back(recenica4);

	int slucajni_indeks = rand() % vektor1.size();

	string odabrana_recenica = vektor1[slucajni_indeks];
	string samoglasnici = "aeiouAEIOU";
	string nova_recenica = "";

	string rijec;
	for (char slovo: odabrana_recenica)
	{
		if (isalpha(slovo))
		{
			rijec += slovo;
		}
		else 
		{
			if (!rijec.empty())
			{
				if (samoglasnici.find(rijec[0]) != string::npos)
				{
					rijec += "hay";
					nova_recenica += rijec + slovo;
				}
				else
				{
					int prvi_suglasnik = rijec.find_first_of(samoglasnici);
					string prvi_dio = rijec.substr(0, prvi_suglasnik);
					rijec.erase(0, prvi_suglasnik);
					nova_recenica += rijec + prvi_dio + "ay" + slovo;
				}
				rijec = "";
			}
			else
			{
				nova_recenica += slovo;
			}
		}
	}

	return nova_recenica;

	
}

int main()
{
	string rez;
	rez= pig_latin();
	cout << rez << endl;
	return 0;
}