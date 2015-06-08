#if !defined(GLOBALS_H)

#include <string>

#include "Constants.h"

#include "SFML/System.hpp"

class game;

namespace Global
{
    global_variable game* Game;
    global_variable HWND Window;

    // Game loop variables
    global_variable double UpdatesPerSecond = 60.0;
    global_variable sf::Time FrameTime = sf::seconds(1.0/UpdatesPerSecond);
    global_variable uint16 MaxFrameSkip = 10;

    std::string ImagePath = "w:/build/fg/img/";

    bool32 DebugMode = false;
}

#define GLOBALS_H
#endif