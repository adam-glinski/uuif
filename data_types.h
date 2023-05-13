#pragma once
#include <cstdio>

namespace uuif
{
    //using id_t = uint32_t;
    using id_t = int;

	struct position_t {
	    int x{}, y{};
	};
	
	struct dimension_t {
	    float width{}, height{};
	};

    const enum class widget_t {
        unknown = -1,
        base = 0,
        window
    };
}
