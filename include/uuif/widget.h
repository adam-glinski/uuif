#pragma once
#include <memory>
#include <string>
#include <spdlog/spdlog.h>
#include "data_types.h"
#include "hashing.hpp"

// TODO: Add save() and load()
namespace uuif {
    const char* widget_type_to_str(widget_t type);

    class c_widget : public std::enable_shared_from_this<c_widget> {
        public:
            area_t area{}, original_area{};
            std::string label{"base_widget"};
        std::shared_ptr<c_widget> parent{};
        widget_t type{widget_t::invalid};

        c_widget(const std::string& title, const widget_t type) {
            this->label = title;
            this->type = type;
            spdlog::info("created new {} [0x{:x}]", widget_type_to_str(type), g_hash->compile_time(title.c_str()));
        }

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void disable() {}

        void adjust_area(const area_t area) {
            this->area = original_area;
            this->area = area;
        }

        void adjust_posistion(const vector_2d pos) {
            this->area.x += pos.x;
            this->area.y += pos.y;
        }

    };
}
