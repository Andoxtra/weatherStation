#include "CharTable.h"

CharTable::CharTable() {
    for (ICharData& charInfo : charData){
        char character = std::get<0>(charInfo);
        short int width = std::get<1>(charInfo);
        Character::IPixelPosVector* posMap = &std::get<2>(charInfo);
        allChars.push_back(new Character(character, width, posMap));
    }
}

Character* CharTable::getCharacterObject(char character){
    for(Character* charObject : allChars){
        if(charObject->getCharacter() == character){
            return charObject;
        }
    }
    return nullptr;
}
