#include <uuif/checkbox.h>
#include <uuif/core.h>

void uuif::c_checkbox::draw() {
    uuif::core->get_renderer()->draw_rect_filled(this->parent->area.x + area.x, this->parent->area.y + area.y, area.w, area.h, {60, 60, 60, 255});
}

void uuif::c_checkbox::update() {

}
