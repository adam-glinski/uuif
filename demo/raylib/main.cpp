#include "raylib.h"
#include "raylib_renderer.hpp"
#include "uuif/core.h"


int main(int argc, char **argv) {
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    constexpr int FPS = 60;
    InitWindow(WIDTH, HEIGHT, "UUIF - raylib demo");
    SetTargetFPS(FPS);

    c_raylib_renderer *rend = new c_raylib_renderer();
    uuif::core->init(rend);

    auto main_win = uuif::core->add_window("Main window", {10, 10, 200, 200});

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground({50, 150, 160, 255});
            main_win->draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
