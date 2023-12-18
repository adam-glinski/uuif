#pragma once
#include <type_traits>

#include "../util/singleton.hpp"
#include "../data_types.h"

namespace uuif{
    class c_renderer : public c_singleton<c_renderer> {
        using draw_rect_p = std::add_pointer_t<void(int, int, int, int, color_t)>;
    };

    inline auto g_renderer = c_renderer::get();
}