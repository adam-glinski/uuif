#include <uuif/widget.h>

namespace uuif {
    const char* widget_type_to_str(widget_t type) {
        switch (type) {
        case widget_t::invalid:
            return "invalid";
        case widget_t::checkbox:
            return "checkbox";
        case widget_t::slider:
            return "slider";
        case widget_t::button:
            return "button";
        case widget_t::combobox:
            return "combobox";
        case widget_t::key_bind:
            return "key_bind";
        case widget_t::tab:
            return "tab";
        case widget_t::window:
            return "window";
        default:
            return "other";
        }
    }
}
