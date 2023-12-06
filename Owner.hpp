#ifndef OWNER_HPP
#define OWNER_HPP

#include "VirtualPet.hpp"
#include <vector>

using namespace std;

class Owner
{
public:
    Owner(const std::string& name);

    
    void addPet(const VirtualPet& pet);
    int interactWithPets();  

    
    const string& getName() const;

   
    Owner(const Owner& other);

private:
    string name;
    vector<VirtualPet> pets;
};

#endif