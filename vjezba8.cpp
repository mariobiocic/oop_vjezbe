#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Neprijatelj
{
protected:
    string ime;
    int health;
    int steta;

public:
    Neprijatelj(const string& ime, int zdravlje, int steta)
        : ime(ime), health(zdravlje), steta(steta) {
        if (zdravlje < 0 || steta < 0) {
            throw invalid_argument("Zdravlje i steta moraju biti pozitivni.");
        }
    }

    virtual void napad() const = 0;

    virtual void prikaziInfo() const = 0;
};

class Boss : public Neprijatelj {
private:
    string oruzje;

public:
    Boss(const string& ime, int zdravlje, int steta, const string& oruzje)
        : Neprijatelj(ime, zdravlje, steta), oruzje(oruzje) {
        if (oruzje.empty()) {
            throw invalid_argument("Oruzje ne moze biti prazno.");
        }
    }

    void napad() const override
    {
        cout << ime << " napada s oruzjem " << oruzje << " i nanosi " << steta << " stete.\n";
    }

    void prikaziInfo() const override 
    {
        cout << "Boss: " << ime << ", Zdravlje: " << health << ", steta: " << steta << ", Oruzje: " << oruzje << "\n";
    }
};

class Èudovište : public Neprijatelj {
private:
    string sposobnost;

public:
    Èudovište(const string& ime, int zdravlje, int steta, const string& sposobnost)
        : Neprijatelj(ime, zdravlje, steta), sposobnost(sposobnost) 
    {
        if (sposobnost.empty()) {
            throw invalid_argument("Sposobnost ne moze biti prazna.");
        }
    }

    void napad() const override
    {
        cout << ime << " napada s posebnom sposobnoscu: " << sposobnost << " i nanosi " << steta << " stete.\n";
    }

    void prikaziInfo() const override 
    {
        cout << "Cudoviste: " << ime << ", Zdravlje: " << health << ", Steta: " << steta << ", Sposobnost: " << sposobnost << "\n";
    }
};

int main()
{
    vector<Neprijatelj*> neprijatelji;

    try {
        neprijatelji.push_back(new Èudovište("Goblin", 50, 10, "Koplje"));
        neprijatelji.push_back(new Boss("Zmaj", 100, 20, "Riganje Vatre"));
        neprijatelji.push_back(new Boss("Tarantula", -5, 15, "Otrov"));  
    }
    catch (const invalid_argument& e) {
        cerr << "Greska: " << e.what() << endl;
    }

    for (const auto& neprijatelj : neprijatelji)
    {
        neprijatelj->prikaziInfo();
        neprijatelj->napad();
        cout << "\n";
        delete neprijatelj;
    }

    return 0;
}