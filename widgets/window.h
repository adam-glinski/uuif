#include "widget.h"
#include <memory>
#include <unordered_map>
//#include <spdlog/spdlog.h>

namespace uuif
{
    class c_window : public c_widget/*, public std::enable_shared_from_this<c_window>*/ {
        std::unordered_map <id_t, std::shared_ptr<c_widget>> m_widgets{};
    public:
        c_window(std::string const& title, position_t position, dimension_t size) {
            set_label(title);
            set_position(position);
            set_size(size);
        }

        c_window() {};

        ~c_window();

        void draw() override;
        void update() override;
        void input() override;

    };
}
