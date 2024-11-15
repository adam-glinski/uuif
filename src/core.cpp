#include <uuif/core.h>
#include <uuif/focus_manager.h>
#include <spdlog/spdlog.h>
#include <uuif/hashing.hpp>

// NOTE: Do I rlly want to return the object at the end ??
/* TODO: Replace this if with just .try_emplace() or add function overload
(one will parse the object and another will create it and return) */
std::shared_ptr<uuif::c_window> uuif::c_core::add_window(const std::string& title, area_t area) {
    id_t window_id = g_hash->compile_time(title.c_str());
    /*
    if (auto it_window = m_windows.find(window_id); it_window == m_windows.end())
    {
        auto temp = std::make_shared<c_window>(title, area);
        m_windows.try_emplace(window_id, temp);
        it_window = m_windows.find(window_id);
    }
    */
    m_windows.try_emplace(window_id, std::make_shared<c_window>(title, area));
    auto created_window = m_windows.at(window_id);

    if(!focus_manager->get_focused())
        focus_manager->set_focused(created_window);

    return created_window;
}

bool uuif::c_core::remove_window(id_t id) {
    if (auto it_window = m_windows.find(id); it_window != m_windows.end()) {
        m_windows.erase(id);
    }

    return !m_windows.contains(id);
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(id_t id) {
    return m_windows.at(id);
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(const std::string& title) {
    return this->get_window(g_hash->compile_time(title.c_str()));
}

void uuif::c_core::init(i_renderer* renderer) {
    m_renderer = renderer;
    if(!m_renderer)
        spdlog::error("Failed to create renderer!!!");

}

uuif::i_renderer* uuif::c_core::get_renderer() {
    if(!m_renderer)
        spdlog::error("c_core::get_renderer(): Failed to get renderer!");
    return m_renderer;
}
