#include <iostream>

using namespace std;

struct Matrica {

	float** element;
	int redovi;
	int stupci;

};

void unos_matrice(Matrica &matrica)
{
	cout << "unesi broj redova (m): " << endl;
	cin >> matrica.redovi;
	cout << "unesi broj stupaca (n): " << endl;
	cin >> matrica.stupci;

	matrica.element = new float* [matrica.redovi];
	for (int i = 0; i < matrica.redovi; i++)
	{
		matrica.element[i] = new float[matrica.stupci];
	}

	cout << "unesite elemente matrice:" << endl;
	for (int i = 0; i < matrica.redovi; i++)
	{
		for (int j = 0; j < matrica.stupci; j++)
		{
			cin >> matrica.element[i][j];
		}
	}
}

void generiraj_matricu(Matrica &matrica, float a, float b)
{
	cout << "unesite broj redova (m): ";
	cin >> matrica.redovi;
	cout << "unesite broj stupaca (n): ";
	cin >> matrica.stupci;

	matrica.element = new float* [matrica.redovi];
	for (int i = 0; i < matrica.redovi; i++) 
	{
		matrica.element[i] = new float[matrica.stupci];
	}

	for (int i = 0; i < matrica.redovi; i++) {
		for (int j = 0; j < matrica.stupci; j++) {
			matrica.element[i][j] = a + static_cast<float>(rand()) / RAND_MAX * (b - a);
		}
	}
}


Matrica zbrajanje_matrica(Matrica &matrica1, Matrica &matrica2) 
{
	Matrica rezultat;
	rezultat.redovi = matrica1.redovi;
	rezultat.stupci = matrica1.stupci;

	rezultat.element = new float* [rezultat.redovi];
	for (int i = 0; i < rezultat.redovi; i++) {
		rezultat.element[i] = new float[rezultat.stupci];
		for (int j = 0; j < rezultat.stupci; j++) {
			rezultat.element[i][j] = matrica1.element[i][j] + matrica2.element[i][j];
		}
	}

	return rezultat;
}

Matrica oduzimanje_matrica(Matrica &matrica1, Matrica &matrica2) 
{
	Matrica rezultat;
	rezultat.redovi = matrica1.redovi;
	rezultat.stupci = matrica1.stupci;

	rezultat.element = new float* [rezultat.redovi];
	for (int i = 0; i < rezultat.redovi; i++) 
	{
		rezultat.element[i] = new float[rezultat.stupci];
		for (int j = 0; j < rezultat.stupci; j++) 
		{
			rezultat.element[i][j] = matrica1.element[i][j] - matrica2.element[i][j];
		}
	}

	return rezultat;
}

Matrica mnozenje_matrica(Matrica &matrica1, Matrica &matrica2)
{
	Matrica rezultat;
	rezultat.redovi = matrica1.redovi;
	rezultat.stupci = matrica2.stupci;

	rezultat.element = new float* [rezultat.redovi];
	for (int i = 0; i < rezultat.redovi; i++)
	{
		rezultat.element[i] = new float[rezultat.stupci];
		for (int j = 0; j < rezultat.stupci; j++)
		{
			rezultat.element[i][j] = 0.0;
			for (int k = 0; k < matrica1.stupci; k++)
			{
				rezultat.element[i][j] += matrica1.element[i][k] * matrica2.element[k][j];
			}
		}
	}

	return rezultat;
}

Matrica transponiranje_matrice(Matrica &matrica)
{
	Matrica rezultat;
	rezultat.redovi = matrica.stupci;
	rezultat.stupci = matrica.redovi;

	rezultat.element = new float* [rezultat.redovi];
	for (int i = 0; i < rezultat.redovi; i++) {
		rezultat.element[i] = new float[rezultat.stupci];
		for (int j = 0; j < rezultat.stupci; j++) {
			rezultat.element[i][j] = matrica.element[j][i];
		}
	}

	return rezultat;
}

void ispis_matrice(Matrica &matrica) 
{

	for (int i = 0; i < matrica.redovi; i++)
	{
		for (int j = 0; j < matrica.stupci; j++)
		{
			cout << matrica.element[i][j];
		}
		cout << endl;
	}
}

void brisanje_matrice(Matrica &matrica)
{
	for (int i = 0; i < matrica.redovi; i++)
	{
		delete[] matrica.element[i];
	}
	delete[] matrica.element;
}

int main()
{ 
	Matrica matrica1;
	Matrica matrica2;

	cout << "unos prve matrice: " << endl;
	unos_matrice(matrica1);

	float a, b, t;
	cout << "unesi prvu granicu: " << endl;
	cin >> a;
	cout << "unesi drugu granicu: " << endl;
	cin >> b;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	cout << "generiranje druge matrice " << endl;
	generiraj_matricu(matrica2,a,b);
	cout << "prva matrica:" << endl;
	ispis_matrice(matrica1);

	cout << "druga matrica: " << endl;
	ispis_matrice(matrica2);

	cout << "transponiranje prve matrice: " << endl;
	Matrica transponirana_matrica = transponiranje_matrice(matrica1);
	ispis_matrice(transponirana_matrica);

	cout << "rezultat zbrajanja matrica je: " << endl;
	Matrica rezultat_zbroj = zbrajanje_matrica(matrica1, matrica2);
	ispis_matrice(rezultat_zbroj);

	cout << "rezultat oduzimanja matrica je: " << endl;
	Matrica rezultat_razlika = oduzimanje_matrica(matrica1, matrica2);
	ispis_matrice(rezultat_razlika);

	brisanje_matrice(matrica1);
	brisanje_matrice(matrica2);

	return 0;
}