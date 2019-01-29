//
// Created by Egri Zoltán on 2019. 01. 29..
//

#include "pokemon.h"

Pokemon::Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst)
{
    _name = name;
    _type = type;
    _effectiveAgainst = effectiveAgainst;
}

bool Pokemon::isEffectiveAgainst(Pokemon anotherPokemon)
{
    return _effectiveAgainst == anotherPokemon._type;
}