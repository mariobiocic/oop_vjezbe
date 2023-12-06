
#include "VirtualPet.hpp"
#include <iostream>

using namespace std;

VirtualPet::VirtualPet(const string& name, const string& type, int hungerPoints, int happinessPoints, bool isAwake)
    : name(name), type(type), hungerPoints(hungerPoints), happinessPoints(happinessPoints), awake(isAwake) {}

void VirtualPet::eat() 
{
    cout << name << " is eating." << endl;
    hungerPoints -= 2;
    happinessPoints += 1;
}

void VirtualPet::sleep() 
{
    cout << name << " is sleeping." << endl;
    hungerPoints += 1;
    happinessPoints += 2;
    awake = false;
}

void VirtualPet::play() 
{
    cout << name << " is playing." << endl;
    hungerPoints += 2;
    happinessPoints += 2;
}

const string& VirtualPet::getName() const
{
    return name;
}

const std::string& VirtualPet::getType() const
{
    return type;
}

int VirtualPet::getHunger() const
{
    return hungerPoints;
}

int VirtualPet::getHappiness() const 
{
    return happinessPoints;
}

bool VirtualPet::isAwake() const 
{
    return awake;
}
