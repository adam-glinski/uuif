#pragma once
#include <memory>
#include <unordered_map>
#include "widget.h"
// #include <spdlog/spdlog.h>

namespace uuif
{
    class c_window : public c_widget , public std::enable_shared_from_this<c_window>
    {
        std::unordered_map<id_t, std::shared_ptr<c_widget>> m_children{};
        bool m_enabled{true}, m_clicked{false}, m_should_drag{false};
        vector_2d m_drag_offset{0, 0};
        std::shared_ptr<c_window> m_selected_tab{nullptr};

    public:
        c_window(const std::string &title, area_t area)
        {
            this->label = title;
            this->area = area;
            this->type = widget_t::window;
        }

        bool is_enabled() { return m_enabled; }
        void set_enabled(bool status) { m_enabled = status; }

        void add_widget(std::shared_ptr<c_widget> widget);

        //c_window() =;
        ~c_window();
        void draw() override;
        void update() override;
    };
}
