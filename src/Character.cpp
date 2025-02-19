#include "Character.h"

Character::Character(char newCharacter, short int newWidth, IPixelPosVector* newPosMap) {
    character = newCharacter;
    width = newWidth;
    posMap = newPosMap;
}

short int Character::getWidth() const{
    return width;
}

char Character::getCharacter() const{
    return character;
}

Character::IPixelPosVector* Character::getPosMap(){
    return posMap;
}
