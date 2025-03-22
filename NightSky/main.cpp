#include "sky.hpp"
#include <raylib.h>

int main() {
    const int screenWidth = 1080;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Night Sky");

    Sky sky;
    sky.addStar(Star(100, 200, 0.8, YELLOW));
    sky.addStar(Star(1400, 300, 1.0, WHITE));
    sky.addStar(Star(700, 100, 0.5, ORANGE));

    while (!WindowShouldClose()) {
        BeginDrawing();

        sky.render();

        EndDrawing();
    }

    CloseWindow();

    sky.display();

    return 0;
}