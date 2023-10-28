/**
 * File:   liquid_flow.c
 * Author: AWTK Develop Team
 * Brief:  液体流动控件
 *
 * Copyright (c) 2023 - 2023 Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2023-10-28 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "liquid_flow_register.h"
#include "base/widget_factory.h"
#include "liquid_flow/liquid_flow.h"

ret_t liquid_flow_register(void) {
  return widget_factory_register(widget_factory(), WIDGET_TYPE_LIQUID_FLOW, liquid_flow_create);
}

const char* liquid_flow_supported_render_mode(void) {
  return "OpenGL|AGGE-BGR565|AGGE-BGRA8888|AGGE-MONO";
}
