#include "raylib.h"
#include <iostream>
#include <chrono>
#include <thread>

void pauseGame()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}