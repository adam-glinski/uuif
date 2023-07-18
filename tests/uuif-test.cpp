#include "gtest/gtest.h"
#include "framework.h"

using namespace uuif;

TEST(GeneralWidgets, TypeAssignment)
{
    EXPECT_EQ(c_window("TestWindow", area_t(50.f, 50.f, 50.f, 50.f)).type, widget_t::window);
    bool s = false;
    EXPECT_EQ(c_checkbox("TestWindow", &s).type, widget_t::checkbox);

}

TEST(Core, GettingWindows)
{
    auto w = core->add_window("TestWindow", area_t());
    EXPECT_EQ(w, core->get_window("TestWindow")); // By label
    EXPECT_EQ(w, core->get_window(g_hash->compile_time("TestWindow"))); // By id
    // EXPECT_NE(w, core->get_window("OtherWindow"));
    EXPECT_NE(2, 3);
}