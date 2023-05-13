#include "core.h"

#include "../utils/hashing.hpp"

std::shared_ptr<uuif::c_window> uuif::c_core::add_window(std::string title, position_t position, dimension_t size)
{
    id_t window_id = g_hash->compile_time(title.c_str());
    if (auto it_window = m_windows.find(window_id); it_window == m_windows.end()) {
        auto temp = std::make_shared<c_window>(title, position, size);
        m_windows.try_emplace(window_id, temp);
        it_window = m_windows.find(window_id);
    }

    return m_windows.at(window_id);
}

bool uuif::c_core::remove_window(id_t id)
{
    if (auto it_window = m_windows.find(id); it_window != m_windows.end())
    {
        m_windows.erase(id);
    }

    return !m_windows.contains(id) ? true : false;
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(id_t id)
{
    return m_windows.at(id);
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(std::string title)
{
    return this->get_window(g_hash->compile_time(title.c_str()));
}
