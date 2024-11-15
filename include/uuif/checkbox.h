#pragma once
#include "widget.h"

namespace uuif {
class c_checkbox : public c_widget {
    bool *m_status;
    // area_t m_clickable_area;
    public:
    c_checkbox(const char *label, bool *status): c_widget(label, widget_t::checkbox) {
        this->m_status = status;
        this->area = {10, 10, 50, 25};
    }

    void draw() override;
    void update() override;
};
} // namespace uuif
