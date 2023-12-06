
#ifndef VIRTUALPET_HPP
#define VIRTUALPET_HPP

#include <string>
using namespace std;

class VirtualPet {
public:
    VirtualPet(const string& name, const string& type, int hungerPoints, int happinessPoints, bool isAwake);

   
    void eat();
    void sleep();
    void play();

    
    const string& getName() const;
    const string& getType() const;
    int getHunger() const;
    int getHappiness() const;
    bool isAwake() const;

private:
    string name;
    string type;
    int hungerPoints;
    int happinessPoints;
    bool awake;
};

#endif
