#include "window.h"
#include "../core/core.h"
#include "../util/hashing.hpp"

void uuif::c_window::add_widget(std::shared_ptr<c_widget> widget)
{
    auto widget_id = g_hash->compile_time(widget->label.c_str());
    auto insertion = m_children.try_emplace(widget_id, widget);
    auto type_name = magic_enum::enum_name(widget->type);
    if(insertion.second)
        spdlog::info("added {} [0x{:0x}] to {} [0x{:0x}]", type_name, widget_id,
            magic_enum::enum_name(this->type), g_hash->compile_time(this->label.c_str()));
    else {
        if(insertion.first !=  m_children.end())
            spdlog::warn("failed to add {} [0x{:0x}]: Widget already exists!", type_name, widget_id);
        else
            spdlog::critical("failed to add {} [0x{:0x}]", type_name, widget_id);
    }
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