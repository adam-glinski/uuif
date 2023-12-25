#pragma once
#include <memory>
#include <string>
#include <spdlog/spdlog.h>
#include <magic_enum.hpp>
#include <util/hashing.hpp>

#include "../data_types.h"

// TODO: Add save() and load()
namespace uuif {
    class c_widget : public std::enable_shared_from_this<c_widget> {
    public:
        virtual void draw() = 0;

        virtual void update() = 0;

        virtual void disable() {
        }

        void adjust_area(const area_t area) {
            this->area = original_area;
            this->area = area;
        }

        void adjust_posistion(const vector_2d pos) {
            this->area.x += pos.x;
            this->area.y += pos.y;
        }

        c_widget(const std::string& title, const widget_t type) {
            this->label = title;
            this->type = type;
            spdlog::info("created new {} [0x{:x}]", magic_enum::enum_name(type),g_hash->compile_time(title.c_str()));
        }

        area_t area{}, original_area{};
        std::string label{"base_widget"};
        std::shared_ptr<c_widget> parent{};
        widget_t type{widget_t::invalid};
    };
}
