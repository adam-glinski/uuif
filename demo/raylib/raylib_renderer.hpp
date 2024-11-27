#include <uuif/renderer.h>
#include <raylib.h>

#define UUIF_COL_TO_RL(col) (Color){col.r, col.g, col.b, col.a}

class c_raylib_renderer : public uuif::i_renderer {
        void draw_line(int x, int y, int w, int h, uuif::color_t color) override {
            DrawLine(x, y, x + w, y + h, UUIF_COL_TO_RL(color));
        }
        void draw_rect_ex(int x, int y, int w, int h, uuif::color_t color, float thickness) override {
            DrawRectangleLinesEx({static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h)}, thickness, UUIF_COL_TO_RL(color));
        }
        void draw_rect_filled(int x, int y, int w, int h, uuif::color_t color) override {
            DrawRectangle(x, y, x + w, y + h, UUIF_COL_TO_RL(color));
        }
};
