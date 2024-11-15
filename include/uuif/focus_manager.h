#pragma once
#include "singleton.hpp"
#include "widget.h"

namespace uuif {
    // Manages which widget should be rendered last
    class c_focus_manager : public uuif::c_singleton<c_focus_manager> {
        std::shared_ptr<c_widget> m_focused{};
        public:

        void set_focused(std::shared_ptr<c_widget> widget);
        std::shared_ptr<c_widget> get_focused();
        bool is_focused(std::shared_ptr<c_widget> widget);
    };
    inline const auto focus_manager = c_focus_manager::get();
}
