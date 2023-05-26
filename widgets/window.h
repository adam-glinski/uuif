#pragma once
#include "widget.h"
#include <memory>
#include <unordered_map>
// #include <spdlog/spdlog.h>

namespace uuif
{
    class c_window : public c_widget /*, public std::enable_shared_from_this<c_window>*/
    {
        std::unordered_map<id_t, std::shared_ptr<c_widget>> m_widgets{};

    public:
        c_window(const std::string &title, area_t area)
        {
            this->label = title;
            this->area = area;
        }

        c_window(){};

        ~c_window();

        void draw() override;
        void update() override;
        void disable() override;
    };
}
