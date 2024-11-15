#include <uuif/widget.h>
#include <uuif/core.h>
#include <uuif/hashing.hpp>

// TODO: Add some const spacing to the newly added widget
void uuif::c_window::add_widget(std::shared_ptr<c_widget> widget)
{
    auto widget_id = g_hash->compile_time(widget->label.c_str());
    auto insertion = m_children.try_emplace(widget_id, widget);
    auto type_name = widget_type_to_str(widget->type);
    if(insertion.second)
        spdlog::info("added {} [0x{:0x}] to {} [0x{:0x}]", type_name, widget_id,
            widget_type_to_str(this->type), g_hash->compile_time(this->label.c_str()));
    else {
        if(insertion.first !=  m_children.end())
            spdlog::warn("failed to add {} [0x{:0x}]: Widget already exists!", type_name, widget_id);
        else
            spdlog::critical("failed to add {} [0x{:0x}]", type_name, widget_id);
    }
}

uuif::c_window::~c_window()
{
    // TODO: Fix seg fault (the window is already destroyed while trying to call remove_window
    // id_t window_id = g_hash->compile_time(this->label.c_str());
    // core->remove_window(window_id);
}

// TODO: Invert render order? Or implement focus system
void uuif::c_window::draw()
{
    core->get_renderer()->draw_rect_filled(area.x, area.y, area.w, area.h, {30, 30, 30, 255});
    for(auto w : m_children)
        w.second->draw();
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
