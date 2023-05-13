#pragma once
#include "../utils/singleton.hpp"
#include "../data_types.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace uuif {
    class c_window;
    class c_core : public c_singleton <c_core>
    {
        std::unordered_map <id_t, std::shared_ptr<c_window>> m_windows{};
    public:
        std::shared_ptr<c_window> add_window(std::string title, position_t position, dimension_t size);
        bool remove_window(id_t id);
        std::shared_ptr<c_window> get_window(id_t id);
        std::shared_ptr<c_window> get_window(std::string title);
    };

    inline const auto core = c_core::get();
}
