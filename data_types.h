#pragma once
#include <cstdio>

namespace uuif
{
    // using id_t = uint32_t;
    using id_t = int;

    struct area_t
    {
        float x{}, y{}, w{}, h{};
    };

    struct vector_2d
    {
        float x{}, y{};
        vector_2d(float x, float y) : x(x), y(y) {}
    };

    const enum class widget_t {
        invalid = -1,
        checkbox,
        slider,
        button,
        combobox,
        key_bind,
        tab
    };
}
