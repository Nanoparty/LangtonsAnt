#pragma once

#include "Global.h"
#include "Ant.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

using namespace std;

std::vector<Ant> ants;

array<array<unsigned char, MAP_HEIGHT>, MAP_WIDTH> buffer;

