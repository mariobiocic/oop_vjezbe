#include<iostream>
#include<string>

using namespace std;

int pojavljivanje_podstringa(string &primjer, string &podstring) 
{
    int br = 0;
    int duljina = primjer.length();
    int duljina2 = podstring.length();

    for (int i = 0; i <= duljina - duljina2; i++) 
    {
        int j;
        for (j = 0; j < duljina2; j++)
        {
            if (primjer[i + j] != podstring[j])
            {
                break;
            }
        }
        if (j == duljina2)
        {
            br++;
        }
    }
    return br;
}

int main()
{
   string primjer = "Dobar dan, kako ste? Dobar dan, dobro sam.";
   string podstring = "kako";
   int rez = pojavljivanje_podstringa(primjer, podstring);
   cout << "Broj pojavljivanja podstringa je: " << rez << std::endl;
   return 0;
}