#include <uuif/core.h>
#include <uuif/checkbox.h>
#include <uuif/focus_manager.h>

int main() {
    auto example_window = uuif::core->add_window("example window", {0, 0, 500, 600});
    bool value = true;
    auto example_checkbox = std::make_shared<uuif::c_checkbox>("example checkbox", &value);
    example_window->add_widget(example_checkbox);
    example_window->add_widget(example_checkbox);
    uuif::focus_manager->set_focused(example_checkbox);

    return 0;
}
