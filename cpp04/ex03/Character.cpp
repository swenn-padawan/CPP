
#include "Character.hpp"

Character::Character(){
	name = "default name";
	for (int i = 0; i < 4; i++){
		inventory[i] = nullptr;
	}
}

Character::Character(std::string const & _name){
	this->name = _name;
	for (int i = 0; i < 4; i++){
		inventory[i] = nullptr;
	}
	
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i] != NULL) {
                delete inventory[i];
            }
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string Character::getName() const {
    return (this->name);
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        inventory[idx]->use(target);
    }
}
