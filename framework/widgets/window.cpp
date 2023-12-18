#include "window.h"
#include "../core/core.h"
#include "../util/hashing.hpp"

void uuif::c_window::add_widget(std::shared_ptr<c_widget> widget)
{
    auto widget_id = g_hash->compile_time(widget->label.c_str());
    m_children.try_emplace(widget_id, widget);
}

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

// TODO
// void uuif::c_window::save()
// {
//     for (auto w : m_children)
//         w.second->
// }