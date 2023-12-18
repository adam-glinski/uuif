#include "core.h"

#include "../util/hashing.hpp"

// NOTE: Do I rlly want to return the object at the end ??
/* TODO: Replace this if with just .try_emplace() or add function overload
(one will parse the object and another will create it and return) */
std::shared_ptr<uuif::c_window> uuif::c_core::add_window(const std::string& title, area_t area)
{

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

    return m_windows.at(window_id);
}

bool uuif::c_core::remove_window(id_t id)
{
    if (auto it_window = m_windows.find(id); it_window != m_windows.end())
    {
        m_windows.erase(id);
    }

    return !m_windows.contains(id);
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(id_t id)
{
    return m_windows.at(id);
}

std::shared_ptr<uuif::c_window> uuif::c_core::get_window(const std::string& title)
{
    return this->get_window(g_hash->compile_time(title.c_str()));
}
