
#include <iostream>
#include "Owner.hpp"

using namespace std;

int main() {
    VirtualPet pet1("Maks", "Dog", 5, 8, true);
    VirtualPet pet2("Azriel", "Cat", 3, 7, true);

    Owner owner1("Ivan");
    owner1.addPet(pet1);
    owner1.addPet(pet2);

    Owner owner2 = owner1;

    cout << "Interacting with pets for owner 1:" << endl;
    int happinessOwner1 = owner1.interactWithPets(2);
    cout << "Total happiness for owner 1: " << happinessOwner1 << endl;

    cout << "Interacting with pets for owner 2:" << endl;
    int happinessOwner2 = owner2.interactWithPets(2);
    cout << "Total happiness for owner 2: " << happinessOwner2 << endl;

    const Owner& happiestOwner = (happinessOwner1 > happinessOwner2) ? owner1 : owner2;

    cout << "The owner with the happiest pet is: " << happiestOwner.getName() << endl;

    return 0;
}
