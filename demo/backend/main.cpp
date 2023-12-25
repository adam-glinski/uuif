#include <util/hashing.hpp>

#include "core/core.h"
#include <spdlog/spdlog.h>

int main() {
    spdlog::set_level(spdlog::level::trace);

    auto example_window = uuif::core->add_window("example window", {0, 0, 500, 600});
    static bool value = true;
    auto example_checkbox = std::make_shared<uuif::c_checkbox>("example checkbox", &value);
    example_window->add_widget(example_checkbox);
    example_window->add_widget(example_checkbox);
    // spdlog::trace("Created window \"{}\" [0x{:0x}]", example_window->label, uuif::g_hash->compile_time(example_window->label.c_str()));
    return 0;
}
