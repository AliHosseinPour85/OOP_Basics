#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <vector>
#include <iostream>

class Character {
private:
    std::string Name;
    int Health;
    int Power;

    std::vector<std::string> SkillNames;
    std::vector<int> SkillLevels;

public:
    Character(const std::string& name, int health, int power);
    void addSkill(const std::string& skillName, int level);
    void displayCharacter() const;
};

#endif