/**
 * File:   liquid_flow.h
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

#ifndef TK_LIQUID_FLOW_H
#define TK_LIQUID_FLOW_H

#include "base/widget.h"

BEGIN_C_DECLS
/**
 * @class liquid_flow_t
 * @parent widget_t
 * @annotation ["scriptable","design","widget"]
 * 液体流动控件
 * 在xml中使用"liquid\_flow"标签创建控件。如：
 *
 * ```xml
 * <!-- ui -->
 * <liquid_flow name="flow2" vertical="false" forward="true" running="true" style="hor" 
 *     image="flow_hor" head_image="right" tail_image="left"/>
 *
 * ```
 *
 * 可用通过style来设置控件的显示风格，如字体的大小和颜色等等。如：
 * 
 * ```xml
 * <!-- style -->
 * <liquid_flow>
 *   <style name="default" font_size="32">
 *     <normal text_color="black" />
 *   </style>
 * </liquid_flow>
 * ```
 */
typedef struct _liquid_flow_t {
  widget_t widget;

  /**
   * @property {bool_t} running
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否在运行。
   */
  bool_t running;

  /**
   * @property {bool_t} forward
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否前向流动(水平时向右，垂直时向下)。
   */
  bool_t forward;

  /**
   * @property {bool_t} vertical
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否垂直方向。
   */
  bool_t vertical;

  /**
   * @property {char*} image
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 图片。
   */
  char* image;

  /**
   * @property {char*} head_image
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 头部图片。
   */
  char* head_image;

  /**
   * @property {char*} tail_image
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 尾部图片。
   */
  char* tail_image;

  /**
   * @property {uint32_t} update_delta
   * @annotation ["readable"]
   * 每次移动的增量。
   */
  uint32_t update_delta;

  /**
   * @property {uint32_t} update_interval
   * @annotation ["readable"]
   * 定时更新的间隔。
   */
  uint32_t update_interval;

  /*private*/
  uint64_t offset;
  uint32_t timer_id;
} liquid_flow_t;

/**
 * @method liquid_flow_create
 * @annotation ["constructor", "scriptable"]
 * 创建liquid_flow对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} liquid_flow对象。
 */
widget_t* liquid_flow_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method liquid_flow_cast
 * 转换为liquid_flow对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget liquid_flow对象。
 *
 * @return {widget_t*} liquid_flow对象。
 */
widget_t* liquid_flow_cast(widget_t* widget);

/**
 * @method liquid_flow_set_running
 * 设置 是否在运行。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} running 是否在运行。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_running(widget_t* widget, bool_t running);

/**
 * @method liquid_flow_set_forward
 * 设置 是否前向流动(水平时向右，垂直时向下)。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} forward 是否前向流动(水平时向右，垂直时向下)。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_forward(widget_t* widget, bool_t forward);

/**
 * @method liquid_flow_set_vertical
 * 设置 是否垂直方向。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} vertical 是否垂直方向。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_vertical(widget_t* widget, bool_t vertical);

/**
 * @method liquid_flow_set_image
 * 设置 图片。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {const char*} image 图片。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_image(widget_t* widget, const char* image);

/**
 * @method liquid_flow_set_head_image
 * 设置 头部图片。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {const char*} head_image 头部图片。
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_head_image(widget_t* widget, const char* head_image);

/**
 * @method liquid_flow_set_tail_image
 * 设置 尾部图片。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {const char*} tail_image 尾部图片。
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_tail_image(widget_t* widget, const char* tail_image);

/**
 * @method liquid_flow_set_update_delta
 * 设置 每次移动的增量。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint32_t} update_delta 每次移动的增量。
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_update_delta(widget_t* widget, uint32_t update_delta);

/**
 * @method liquid_flow_set_update_interval
 * 设置 定时更新的间隔。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint32_t} update_interval 定时更新的间隔。
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t liquid_flow_set_update_interval(widget_t* widget, uint32_t update_interval);

#define LIQUID_FLOW_PROP_RUNNING "running"
#define LIQUID_FLOW_PROP_FORWARD "forward"
#define LIQUID_FLOW_PROP_VERTICAL "vertical"
#define LIQUID_FLOW_PROP_IMAGE "image"
#define LIQUID_FLOW_PROP_HEAD_IMAGE "head_image"
#define LIQUID_FLOW_PROP_TAIL_IMAGE "tail_image"
#define LIQUID_FLOW_PROP_UPDATE_DELTA "update_delta"
#define LIQUID_FLOW_PROP_UPDATE_INTERVAL "update_interval"

#define WIDGET_TYPE_LIQUID_FLOW "liquid_flow"

#define LIQUID_FLOW(widget) ((liquid_flow_t*)(liquid_flow_cast(WIDGET(widget))))

/*public for subclass and runtime type check*/
TK_EXTERN_VTABLE(liquid_flow);

END_C_DECLS

#endif /*TK_LIQUID_FLOW_H*/
