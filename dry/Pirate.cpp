
#include "Pirate.h"

const char *const devilFruitNames[] = {
    "Gum Gum",
    "Smoke Smoke",
    "Flame Flame",
    "Rumble Rumble",
    "String String",
    "Ice Ice",
    "None"};

Pirate::Pirate(const string &name, const int &bounty, DEVIL_FRUIT devilFruit) : name(name), bounty(bounty), devilFruit(devilFruit) {}

void Pirate::setName(const string &name)
{
    this->name = name;
}

void Pirate::setDevilFruit(DEVIL_FRUIT devilFruit)
{
    this->devilFruit = devilFruit;
}

std::string Pirate::getName()
{
    return this->name;
}

void Pirate::setBounty(const int &bounty)
{
    this->bounty = bounty;
}
int Pirate::getBounty()
{
    return this->bounty;
}

std::ostream &operator<<(std::ostream &os, const Pirate &pirate)
{
    os << pirate.name << " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")" << " Bounty: " << pirate.bounty << std::endl;
    return os;
}

DEVIL_FRUIT Pirate::getDevilFruit()
{
    return this->devilFruit;
}
