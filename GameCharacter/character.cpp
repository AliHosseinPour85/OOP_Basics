#include "character.hpp"
#include <iostream>

Character::Character(const std::string &name, int health, int power)
{
    Name = name;
    while ( health <= 0 )
    {
        std::cerr << "Enter a Health more than 0 !!!";
        std::cin >> health;
    } 
    while ( power <= 0 )
    {
        std::cerr << "Enter a Power more than 0 !!!";
        std::cin >> power;
    }  
    Health = health;
    Power = power;

}

void Character::addSkill(const std::string &skillName, int level)
{
    SkillNames.push_back(skillName);
    while ( level <= 0 )
    {
        std::cerr << "Enter a Level more than 0 !!!";
        std::cin >> level;        
    } 
    SkillLevels.push_back(level);
}

void Character::displayCharacter() const
{
    std::cout << "Name: " << Name << "\nHealth: " << Health << "\nPower: " << Power << "\nSkills:\n";
    for (size_t i = 0; i < SkillNames.size(); i++)
    {
        std::cout << "- " << SkillNames[i] << ": Level " << SkillLevels[i] << "\n";
    }
}
