#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"


class Game {
private:
    std::vector<Character> characters;

public:
    void addCharacter(const Character& character);
    void displayGameCharacters() const;

};

#endif