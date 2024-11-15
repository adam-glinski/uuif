#pragma once
#include "data_types.h"

namespace uuif{
/*
    class c_renderer : public c_singleton<c_renderer> {
        using draw_line_p = std::add_pointer<void(int, int, int, int, float, color_t)>;

        using draw_rect_p = std::add_pointer_t<void(int, int, int, int, color_t, int)>;
        using draw_circle_p = std::add_pointer_t<void(int, int, float, color_t)>;

        using draw_filled_rect_p = std::add_pointer_t<void(int, int, int, int, color_t, int)>;
        using draw_filled_circle_p = std::add_pointer_t<void(int, int, float, color_t)>;
    };

   auto inline auto g_renderer = c_renderer::get();
*/

    class i_renderer {
    public:
        virtual void draw_line(int, int, int, int, color_t) = 0;
        virtual void draw_rect(int, int, int, int, color_t) = 0;
        virtual void draw_rect_filled(int, int, int, int, color_t) = 0;

        //virtual ~i_renderer() = 0;
    };
}
