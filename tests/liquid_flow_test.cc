#include "liquid_flow/liquid_flow.h"
#include "gtest/gtest.h"

TEST(liquid_flow, basic) {
  value_t v;
  widget_t* w = liquid_flow_create(NULL, 10, 20, 30, 40);

  widget_destroy(w);
}
