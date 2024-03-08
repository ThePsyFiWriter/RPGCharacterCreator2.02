#include <iostream>
#include <string>
#include <random>

// Function to generate a random number in a given range
int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Represents a character with name, race, class, and ability scores
struct Character {
    std::string name;
    std::string race;
    std::string characterClass;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int strBonus;
    int dexBonus;
    int conBonus;
    int intBonus;
    int wisBonus;
    int chaBonus;
};

// Represents a race with a name and ability score bonuses
struct Race {
    std::string name;
    int strBonus;
    int dexBonus;
    int conBonus;
    int intBonus;
    int wisBonus;
    int chaBonus;
};

int main() {
    // Sumerian text in ASCII art
    std::cout << R"(
   _____ _ _           _   _      _ _       
  / ____(_) |         | | (_)    | | |      
 | |  __ _| |__  _   _| |_ _  ___| | |_ ___ 
 | | |_ | | '_ \| | | | __| |/ __| | __/ _ \
 | |__| | | |_) | |_| | |_| | (__| | ||  __/
  \_____|_|_.__/ \__,_|\__|_|\___|_|\__\___|
                                            
)";

    // Define races and their bonuses
    std::vector<Race> races = {
        {"Human", 1, 1, 1, 1, 1, 1},
        {"Elf", 0, 2, 0, 0, 0, 0},
        {"Dwarf", 2, 0, 2, 0, 0, 0},
        {"Halfling", 0, 2, 1, 0, 0, 0}
    };

    Character character;

    // Get user input for character creation
    std::cout << "Enter character name: ";
    std::getline(std::cin, character.name);

    // Select race
    std::cout << "Choose a race (Human, Elf, Dwarf, Halfling): ";
    std::getline(std::cin, character.race);

    // Find the selected race and apply ability score bonuses
    for (const auto& race : races) {
        if (race.name == character.race) {
            character.strBonus = race.strBonus;
            character.dexBonus = race.dexBonus;
            character.conBonus = race.conBonus;
            character.intBonus = race.intBonus;
            character.wisBonus = race.wisBonus;
            character.chaBonus = race.chaBonus;
            character.strength = getRandomNumber(8, 15) + race.strBonus;
            character.dexterity = getRandomNumber(8, 15) + race.dexBonus;
            character.constitution = getRandomNumber(8, 15) + race.conBonus;
            character.intelligence = getRandomNumber(8, 15) + race.intBonus;
            character.wisdom = getRandomNumber(8, 15) + race.wisBonus;
            character.charisma = getRandomNumber(8, 15) + race.chaBonus;
            break;
        }
    }

    // Select class
    std::cout << "Choose a class (Fighter, Wizard, Rogue, Cleric): ";
    std::getline(std::cin, character.characterClass);

    // Display the character's final details
    std::cout << "\nFinal Character Details:\n";
    std::cout << "Name: " << character.name << "\n";
    std::cout << "Race: " << character.race << " (";
    std::cout << "Str Bonus: " << character.strBonus << ", ";
    std::cout << "Dex Bonus: " << character.dexBonus << ", ";
    std::cout << "Con Bonus: " << character.conBonus << ", ";
    std::cout << "Int Bonus: " << character.intBonus << ", ";
    std::cout << "Wis Bonus: " << character.wisBonus << ", ";
    std::cout << "Cha Bonus: " << character.chaBonus << ")\n";
    std::cout << "Class: " << character.characterClass << "\n";
    std::cout << "Strength: " << character.strength << "\n";
    std::cout << "Dexterity: " << character.dexterity << "\n";
    std::cout << "Constitution: " << character.constitution << "\n";
    std::cout << "Intelligence: " << character.intelligence << "\n";
    std::cout << "Wisdom: " << character.wisdom << "\n";
    std::cout << "Charisma: " << character.charisma << "\n";

    return 0;
}
