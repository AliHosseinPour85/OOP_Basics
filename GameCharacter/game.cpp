#include "game.hpp"

void Game::addCharacter(const Character& character) {
    characters.push_back(character);
}

void Game::displayGameCharacters() const {
    for (const auto& character : characters) {
        character.displayCharacter();
        std::cout << "------------------" << std::endl ;
    }
}