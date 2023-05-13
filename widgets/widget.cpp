#include "widget.h"

void uuif::c_widget::set_size(dimension_t size)
{
    m_size = size;
}

uuif::dimension_t uuif::c_widget::get_size()
{
    return m_size;
}

void uuif::c_widget::set_position(position_t position)
{
    m_position = position;
}

uuif::position_t uuif::c_widget::get_position()
{
    return m_position;
}

void uuif::c_widget::set_label(std::string label)
{
    m_label = std::move(label);
}

std::string uuif::c_widget::get_label()
{
    return m_label;
}

void uuif::c_widget::set_parent(std::shared_ptr<c_widget> widget)
{
    m_parent = std::move(widget);
}

std::shared_ptr<uuif::c_widget> uuif::c_widget::get_parent()
{
    return m_parent;
}

