#ifndef WEATHERSTATION_CHARACTERS_H
#define WEATHERSTATION_CHARACTERS_H

#include <map>
#include <array>
#include <vector>


class Character {
public:
    typedef std::pair<short int , short int> IPixelPos;
    typedef std::vector<IPixelPos> IPixelPosVector;

    Character(char character, short int width, IPixelPosVector * posMap);
    short int getWidth() const;
    char getCharacter() const;
    IPixelPosVector* getPosMap();

private:
    char character{};
    short int width{};
    IPixelPosVector* posMap{};
};

#endif //WEATHERSTATION_CHARACTERS_H
