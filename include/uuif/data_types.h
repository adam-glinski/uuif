#pragma once
// #include <cstdio>

namespace uuif
{
    // using id_t = uint32_t;
    using id_t = int;

    struct area_t
    {
        int x{}, y{}, w{}, h{};
    };

    struct vector_2d
    {
        int x{}, y{};
        vector_2d(int x, int y) : x(x), y(y) {}
    };

    enum class widget_t
    {
        invalid = -1,
        checkbox,
        slider,
        button,
        combobox,
        key_bind,
        tab,
        window
    };

    struct color_t
    {
        int r{}, g{}, b{}, a{};
    };

}
