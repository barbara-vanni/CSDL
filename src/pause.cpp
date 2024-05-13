#include "raylib.h"
#include <iostream>
#include <chrono>
#include <thread>

// Pause the game for 2 seconds


void pauseGame()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}