#include<iostream>
#include<string>
using namespace std;



void ispravka(string &recenica)
{	
	for (int i=0;i<recenica.length();i++)
		if (recenica[i]=='.' || recenica[i] == '!' || recenica[i] == '?' || recenica[i] == ':' || recenica[i] == '(' || recenica[i] == ')' || recenica[i] == ',' || recenica[i] == ';' || recenica[i] == '"' || recenica[i] == '\'' || recenica[i] == '-')
		{
			while (i > 0 && recenica[i - 1] == ' ')
			{
				recenica.erase(i - 1, 1);
				i--;
			}
			if (i < recenica.length()-1 && recenica[i + 1] != ' ') 
			{
				recenica.insert(i + 1, " ");
				i++;
			}
		}
		
}

int main()
{
	string recenica;
	cout << "Unesi neku recenicu: " << endl;
	getline(cin, recenica);
	ispravka(recenica);
	cout << recenica << endl;

	return 0;
}