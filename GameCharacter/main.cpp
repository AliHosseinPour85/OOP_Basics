#include "game.hpp"
#include <iostream>

int main() {
    Game game;

    Character One("Solider1", 100, 75);
    One.addSkill("Sword", 10);
    One.addSkill("Defense", 8);

    game.addCharacter(One);
    
    Character Two("Solider2", 80, 90);
    Two.addSkill("spear", 9);
    Two.addSkill("Defense", 7);

    game.addCharacter(Two);

    return 0;
}