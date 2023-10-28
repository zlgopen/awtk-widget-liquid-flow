﻿/**
 * File:   liquid_flow_register.h
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

#ifndef TK_LIQUID_FLOW_REGISTER_H
#define TK_LIQUID_FLOW_REGISTER_H

#include "base/widget.h"

BEGIN_C_DECLS

/**
 * @method  liquid_flow_register
 * 注册控件。
 *
 * @annotation ["global"]
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_register(void);

/**
 * @method  liquid_flow_supported_render_mode
 * 获取支持的渲染模式。
 *
 * @annotation ["global"]
 *
 * @return {const char*} 返回渲染模式。
 */
const char* liquid_flow_supported_render_mode(void);

END_C_DECLS

#endif /*TK_LIQUID_FLOW_REGISTER_H*/
