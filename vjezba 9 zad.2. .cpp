#include <iostream>
#include <set>

using namespace std;

template <typename T>
class MojSkup {
private:
    set<T> elementi;

public:
    
    void dodajElement(const T& element)
    {
        elementi.insert(element);
    }

  
    void izbaciElement(const T& element) 
    {
        elementi.erase(element);
    }

    
    bool sadrzi(const T& element) const 
    {
        return elementi.find(element) != elementi.end();
    }
};

int main() {
    MojSkup<int> intSkup;
    intSkup.dodajElement(1);
    intSkup.dodajElement(2);
    intSkup.dodajElement(3);

    cout << "Sadrzi 2: " << intSkup.sadrzi(2) << endl;
    cout << "Sadrzi 4: " << intSkup.sadrzi(4) << endl;

    intSkup.izbaciElement(2);

    cout << "Sadrzi 2: " << intSkup.sadrzi(2) << endl;

    MojSkup<string> stringSkup;
    stringSkup.dodajElement("jabuka");
    stringSkup.dodajElement("banana");

    cout << "Sadrzi 'jabuka': " << stringSkup.sadrzi("jabuka") << endl;
    cout << "Sadrzi 'naranca': " << stringSkup.sadrzi("naranca") << endl;

    return 0;
}
