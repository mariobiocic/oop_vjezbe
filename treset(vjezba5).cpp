#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Karta
{
    string broj;
    string zog;

public:
    Karta(string broj, string zog) : broj(broj), zog(zog) {}

    string dohvatiBroj() const { return broj; }
    string dohvatiZog() const { return zog; }

    bool operator==(const Karta& other) const
    {
        return (broj == other.broj && zog == other.zog);
    }
};

class Mac
{
public:
    vector<Karta> karte;

    Mac()
    {
        stvori_karte();
        promijesaj_karte();
    }

    void stvori_karte()
    {
        vector<string> brojevi = { "1","2","3","4","5","6","7","11","12","13" };
        vector<string> zogovi = { "Bastoni", "Kupe", "Spade", "Dinari" };

        for (string& zog : zogovi)
        {
            for (string& broj : brojevi)
            {
                Karta novaKarta(broj, zog);
                karte.push_back(novaKarta);
            }
        }
    }

    void promijesaj_karte()
    {
        srand(static_cast<unsigned>(time(0)));  
        int n = karte.size();
        for (int i = n - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            swap(karte[i], karte[j]);
        }
    }

    vector<vector<Karta>> podijeli_karte(int broj_igraca)
    {
        vector<vector<Karta>> ruke(broj_igraca);

        for (int i = 0; i < karte.size(); ++i)
        {
            int indeks_igraca = i % broj_igraca;
            ruke[indeks_igraca].push_back(karte[i]);
        }

        return ruke;
    }
};

class Igrac
{
    string ime;
    vector<Karta> kombinacija_karata;
    int bodovi;

public:
    Igrac(string ime) : ime(ime), bodovi(0) {}

    string dohvatiIme() const { return ime; }

    void dodaj_karte(const vector<Karta>& karte)
    {
        kombinacija_karata = karte;
    }

    int provjeri_akuzu()
    {
        int bod = 0;

        int brojac_3 = 0;
        int brojac_2 = 0;
        int brojac_as = 0;
        string zog_3, zog_2, zog_as;

        for (const Karta& karta : kombinacija_karata)
        {
            if (karta.dohvatiBroj() == "3")
            {
                brojac_3++;
                zog_3 = karta.dohvatiZog();
            }
            else if (karta.dohvatiBroj() == "2")
            {
                brojac_2++;
                zog_2 = karta.dohvatiZog();
            }
            else if (karta.dohvatiBroj() == "1")
            {
                brojac_as++;
                zog_as = karta.dohvatiZog();
            }
        }

        if (brojac_3 >= 1 && brojac_2 >= 1 && brojac_as >= 1 && zog_3 == zog_2 && zog_2 == zog_as)
        {
            cout << "Igrac " << ime << " ima tricu, dvicu i asa istog zoga. Dobiva 3 boda." << endl;
            bod += 3;
        }

        if (brojac_3 == 3)
        {
            cout << "Igrac " << ime << " ima tri trice. Dobiva 3 boda." << endl;
            bod += 3;
        }
        if (brojac_3 == 4)
        {
            cout << "Igrac " << ime << " ima cetiri trice. Dobiva 4 boda." << endl;
            bod += 4;
        }
        if (brojac_2 == 3)
        {
            cout << "Igrac " << ime << " ima tri dvice. Dobiva 3 boda." << endl;
            bod += 3;
        }
        if (brojac_2 == 4)
        {
            cout << "Igrac " << ime << " ima cetiri dvice. Dobiva 4 boda." << endl;
            bod += 4;
        }
        if (brojac_as == 3)
        {
            cout << "Igrac " << ime << " ima tri asa. Dobiva 3 boda." << endl;
            bod += 3;
        }
        if (brojac_as == 4)
        {
            cout << "Igrac " << ime << " ima cetiri asa. Dobiva 4 boda." << endl;
            bod += 4;
        }

        return bod;
    }

    void ispisi_karte()
    {
        cout << "Igrac " << ime << " ima sljedece karte:" << endl;
        for (const Karta& karta : kombinacija_karata)
        {
            cout << karta.dohvatiBroj() << " " << karta.dohvatiZog() << endl;
        }
    }
};

int main()
{
    int broj_igraca;
    cout << "Unesite broj igraca (2 ili 4): ";
    cin >> broj_igraca;

    if (broj_igraca != 2 && broj_igraca != 4)
    {
        cout << "Neispravan broj igraca." << endl;
        return -1;
    }

    vector<string> ime_igraca;
    for (int i = 0; i < broj_igraca; i++)
    {
        string ime;
        cout << "Unesi ime igraca: " << endl;
        cin >> ime;
        ime_igraca.push_back(ime);
    }

    Mac mac;

    vector<vector<Karta>> karte_igraca = mac.podijeli_karte(broj_igraca);

    vector<Igrac> igraci;
    for (int i = 0; i < broj_igraca; i++)
    {
        Igrac novi_igrac(ime_igraca[i]);
        novi_igrac.dodaj_karte(karte_igraca[i]);
        igraci.push_back(novi_igrac);
    }

    for (auto& igrac : igraci)
    {
        int bodovi = igrac.provjeri_akuzu();
        cout << "Igrac " << igrac.dohvatiIme() << " ima " << bodovi << " bodova iz akuzacije." << endl;
        igrac.ispisi_karte();
    }

    return 0;
}
