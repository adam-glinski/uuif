#pragma once
#include <memory>
#include <string>

#include "../data_types.h"

// TODO: Add save() and load()
namespace uuif
{
    class c_widget : public std::enable_shared_from_this<c_widget>
    {
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void disable() {}

        void adjust_area(const area_t area)
        {
            this->area = original_area;
            this->area = area;
        }

        void adjust_posistion(const vector_2d pos)
        {
            this->area.x += pos.x;
            this->area.y += pos.y;
        }

        area_t area{}, original_area{};
        std::string label{"base_widget"};
        std::shared_ptr<c_widget> parent{};
        widget_t type{widget_t::invalid};
    };
}
