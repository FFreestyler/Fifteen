#pragma once
#include <SFML\Config.hpp>

using namespace sf;

const int field = 4;
const int fieldarr = 4 * 4;
const int bone = 120;
const int fieldsize = 500;

enum class motion { Left = 0, Right = 1, Up = 2, Down = 3 };

class Bone 
{
protected:
	int Bones[fieldarr];
	int emptybones;

};