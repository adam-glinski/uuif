#include "core/core.h"
#include <spdlog/spdlog.h>

int main() {
    auto example_window = uuif::core->add_window("example window", {0, 0, 500, 600});
    spdlog::info("Welcome to spdlog!");
    return 0;
}