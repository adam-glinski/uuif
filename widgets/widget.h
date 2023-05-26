#pragma once
#include <memory>
#include <string>

#include "../data_types.h"

namespace uuif
{
    class c_widget : public std::enable_shared_from_this<c_widget>
    {
    private:
        position_t m_position{};
        dimension_t m_size{};
        std::string m_label{};
        std::shared_ptr<c_widget> m_parent{};
        widget_t m_type = widget_t::base;

    public:
        void set_size(dimension_t size);
        dimension_t get_size();

        void set_position(position_t position);
        position_t get_position();

        void set_label(std::string label);
        std::string get_label();

        void set_parent(std::shared_ptr<c_widget> widget);
        std::shared_ptr<c_widget> get_parent();

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void input() = 0;

        // for hashmap
    };
}
