#include "gtest/gtest.h"
#include "framework.h"

using namespace uuif;

TEST(GeneralWidgets, TypeAssignment)
{
    EXPECT_EQ(c_window("TestWindow", area_t(50.f, 50.f, 50.f, 50.f)).type, widget_t::window);
    bool s = false;
    EXPECT_EQ(c_checkbox("TestWindow", &s).type, widget_t::checkbox);

}