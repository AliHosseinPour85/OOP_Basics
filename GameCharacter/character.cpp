#include "character.hpp"
#include <iostream>

Character::Character(const std::string &name, int health, int power)
{
    Name = name;
    Health = health;
    Power = power;

}

void Character::addSkill(const std::string &skillName, int level)
{
    SkillNames.push_back(skillName);
    SkillLevels.push_back(level);
}

