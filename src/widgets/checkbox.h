#pragma once
#include "widget.h"

namespace uuif {
class c_checkbox : public c_widget {
    bool *m_status;
    // area_t m_clickable_area;
    public:
    c_checkbox(const char *label, bool *status) {
        this->label = label;
        this->m_status = status;
        this->type = widget_t::checkbox;
    }

    void draw() override;
    void update() override;
};
} // namespace uuif
