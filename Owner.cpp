
#include "Owner.hpp"
#include <iostream>
#include <random>

Owner::Owner(const string& name) : name(name) {}

void Owner::addPet(const VirtualPet& pet) {
    pets.push_back(pet);
}

int Owner::interactWithPets(int numInteractions) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 2);

    int totalHappiness = 0;

    for (auto& pet : pets) {
        for (int i = 0; i < numInteractions; ++i) {
            int action = dis(gen);
            switch (action) {
            case 0:
                pet.eat();
                break;
            case 1:
                pet.sleep();
                break;
            case 2:
                pet.play();
                break;
            default:
                break;
            }
        }
        totalHappiness += pet.getHappiness();
    }

    return totalHappiness;
}

const string& Owner::getName() const {
    return name;
}

Owner::Owner(const Owner& other) : name(other.name), pets(other.pets) {}
