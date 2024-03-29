#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "../util/singleton.hpp"
#include "../data_types.h"

#include "../widgets/widget.h"
#include "../widgets/window.h"
#include "../widgets/checkbox.h"

namespace uuif
{
    class c_core : public c_singleton<c_core>
    {
        std::unordered_map<id_t, std::shared_ptr<c_window>> m_windows{};

    public:
        std::shared_ptr<c_window> add_window(const std::string& title, area_t area);
        bool remove_window(id_t id);
        std::shared_ptr<c_window> get_window(id_t id);
        std::shared_ptr<c_window> get_window(const std::string& title);

        void init();
    };

    inline const auto core = c_core::get();
}
