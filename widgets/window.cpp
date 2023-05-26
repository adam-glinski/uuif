#include "window.h"
#include "../core/core.h"
#include "../utils/hashing.hpp"

uuif::c_window::~c_window()
{
    id_t window_id = g_hash->compile_time(this->label.c_str());
    core->remove_window(window_id);
}

void uuif::c_window::draw()
{
    return;
}

void uuif::c_window::update()
{
    return;
}