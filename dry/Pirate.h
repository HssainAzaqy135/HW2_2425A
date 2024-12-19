
#pragma once

#include <iostream>

using std::string;

class Pirate
{
private:
    string name;
    int bounty;

public:
    Pirate() : name(""), bounty(0) {} // To fix compilation error
    Pirate(const string &name, const int &bounty) : name(name), bounty(bounty) {}
    Pirate(const string &name);

    ~Pirate() = default;

    void setName(const string &name);
    void setBounty(const int &bounty);
    int getBounty();
    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
