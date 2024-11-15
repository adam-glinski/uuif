#include <uuif/focus_manager.h>
#include "uuif/hashing.hpp"
#include "uuif/widget.h"
#include <spdlog/spdlog.h>

void uuif::c_focus_manager::set_focused(std::shared_ptr<uuif::c_widget> widget) {
    m_focused = widget;
    spdlog::info("changing focus to {} [0x{:0x}]", 
            widget_type_to_str(widget->type), g_hash->compile_time(widget->label.c_str()));
}

std::shared_ptr<uuif::c_widget> uuif::c_focus_manager::get_focused() {
    return m_focused;
}

bool uuif::c_focus_manager::is_focused(std::shared_ptr<uuif::c_widget> widget) {
    return widget == m_focused;
}
