#pragma once
#include <memory>
#include <unordered_map>
#include <spdlog/spdlog.h>

#include "widget.h"

// IDEA: Add another class named "container"
namespace uuif {
    class c_window : public c_widget, public std::enable_shared_from_this<c_window> {
        std::unordered_map<id_t, std::shared_ptr<c_widget>> m_children{};
        std::shared_ptr<c_window> m_selected_tab{nullptr};
        // TODO: Move to c_widget
        bool m_enabled{true}, m_clicked{false}, m_should_drag{false};
        vector_2d m_drag_offset{0, 0};

    public:
        c_window(const std::string& title, area_t area): c_widget(title, widget_t::window) {
            this->area = area;
            // this->label = title;
            // this->type = widget_t::window;
        }

        bool is_enabled() { return m_enabled; }
        void set_enabled(bool status) { m_enabled = status; }

        void add_widget(std::shared_ptr<c_widget> widget);

        bool operator==(const c_window& window) const {
            return this->type == window.type && this->label == window.label;
        }

        //c_window() =;
        ~c_window();

        void draw() override;

        void update() override;
    };
}
