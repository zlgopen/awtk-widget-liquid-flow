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
#include "liquid_flow.h"

ret_t liquid_flow_on_timer(const timer_info_t* info) {
  widget_t* widget = WIDGET(info->ctx);
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);

  liquid_flow->offset += liquid_flow->update_delta;
  widget_invalidate(widget, NULL);

  return RET_REPEAT;
}

ret_t liquid_flow_set_running(widget_t* widget, bool_t running) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  if (running == liquid_flow->running) {
    return RET_OK;
  }

  if (!running) {
    widget_remove_timer(widget, liquid_flow->timer_id);
  } else {
    liquid_flow->timer_id =
        widget_add_timer(widget, liquid_flow_on_timer, liquid_flow->update_interval);
  }

  liquid_flow->running = running;

  return RET_OK;
}

ret_t liquid_flow_set_forward(widget_t* widget, bool_t forward) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->forward = forward;

  return RET_OK;
}

ret_t liquid_flow_set_vertical(widget_t* widget, bool_t vertical) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->vertical = vertical;

  return RET_OK;
}

ret_t liquid_flow_set_image(widget_t* widget, const char* image) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->image = tk_str_copy(liquid_flow->image, image);

  return RET_OK;
}

ret_t liquid_flow_set_head_image(widget_t* widget, const char* head_image) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->head_image = tk_str_copy(liquid_flow->head_image, head_image);

  return RET_OK;
}

ret_t liquid_flow_set_tail_image(widget_t* widget, const char* tail_image) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->tail_image = tk_str_copy(liquid_flow->tail_image, tail_image);

  return RET_OK;
}

ret_t liquid_flow_set_update_delta(widget_t* widget, uint32_t update_delta) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->update_delta = update_delta;

  return RET_OK;
}

ret_t liquid_flow_set_update_interval(widget_t* widget, uint32_t update_interval) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow->update_interval = update_interval;

  return RET_OK;
}

static ret_t liquid_flow_get_prop(widget_t* widget, const char* name, value_t* v) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(LIQUID_FLOW_PROP_RUNNING, name)) {
    value_set_bool(v, liquid_flow->running);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_FORWARD, name)) {
    value_set_bool(v, liquid_flow->forward);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_VERTICAL, name)) {
    value_set_bool(v, liquid_flow->vertical);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_IMAGE, name)) {
    value_set_str(v, liquid_flow->image);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_HEAD_IMAGE, name)) {
    value_set_str(v, liquid_flow->head_image);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_TAIL_IMAGE, name)) {
    value_set_str(v, liquid_flow->tail_image);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_UPDATE_DELTA, name)) {
    value_set_uint32(v, liquid_flow->update_delta);
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_UPDATE_INTERVAL, name)) {
    value_set_uint32(v, liquid_flow->update_interval);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t liquid_flow_set_prop(widget_t* widget, const char* name, const value_t* v) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(LIQUID_FLOW_PROP_RUNNING, name)) {
    liquid_flow_set_running(widget, value_bool(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_FORWARD, name)) {
    liquid_flow_set_forward(widget, value_bool(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_VERTICAL, name)) {
    liquid_flow_set_vertical(widget, value_bool(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_IMAGE, name)) {
    liquid_flow_set_image(widget, value_str(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_HEAD_IMAGE, name)) {
    liquid_flow_set_head_image(widget, value_str(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_TAIL_IMAGE, name)) {
    liquid_flow_set_tail_image(widget, value_str(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_UPDATE_DELTA, name)) {
    liquid_flow_set_update_delta(widget, value_uint32(v));
    return RET_OK;
  } else if (tk_str_eq(LIQUID_FLOW_PROP_UPDATE_INTERVAL, name)) {
    liquid_flow_set_update_interval(widget, value_uint32(v));
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t liquid_flow_on_destroy(widget_t* widget) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && liquid_flow != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(liquid_flow->image);
  TKMEM_FREE(liquid_flow->head_image);
  TKMEM_FREE(liquid_flow->tail_image);

  return RET_OK;
}

static ret_t liquid_flow_draw_vertical_backward(widget_t* widget, canvas_t* c, bitmap_t* image) {
  int32_t x = 0;
  int32_t w = 0;
  int32_t h = 0;
  int32_t sy = 0;
  int32_t dy = 0;
  rect_t src;
  rect_t dst;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  w = image->w;
  x = widget->w / 2 - image->w / 2;
  sy = liquid_flow->offset % image->h;

  while (dy < widget->h) {
    h = tk_min_int(image->h - sy, widget->h - dy);

    src = rect_init(0, sy, w, h);
    dst = rect_init(x, dy, w, h);

    canvas_draw_image(c, image, &src, &dst);
    sy = 0;
    dy += h;
  }

  return RET_OK;
}

static ret_t liquid_flow_draw_vertical_forward(widget_t* widget, canvas_t* c, bitmap_t* image) {
  int32_t y = 0;
  int32_t x = 0;
  int32_t w = 0;
  int32_t h = 0;
  int32_t sh = 0;
  rect_t src;
  rect_t dst;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  w = image->w;
  x = widget->w / 2 - image->w / 2;
  sh = image->h - liquid_flow->offset % image->h;
  y = widget->h;

  while (y > 0) {
    h = tk_min_int(sh, y);
    src = rect_init(0, 0, w, h);
    dst = rect_init(x, y - h, w, h);

    if (y < sh) {
      /*空间不够，显示下半部分*/
      src.y = image->h - h;
    }
    canvas_draw_image(c, image, &src, &dst);
    y -= h;
    sh = image->h;
  }

  return RET_OK;
}

static ret_t liquid_flow_draw_horizontal_forward(widget_t* widget, canvas_t* c, bitmap_t* image) {
  int32_t y = 0;
  int32_t x = 0;
  int32_t w = 0;
  int32_t h = 0;
  int32_t sw = 0;
  rect_t src;
  rect_t dst;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  h = image->h;
  y = widget->h / 2 - image->h / 2;
  sw = image->w - liquid_flow->offset % image->w;
  x = widget->w;

  while (x > 0) {
    w = tk_min_int(sw, x);
    src = rect_init(0, 0, w, h);
    dst = rect_init(x - w, y, w, h);

    if (x < sw) {
      /*空间不够，显示右边部分*/
      src.x = image->w - w;
    }
    canvas_draw_image(c, image, &src, &dst);
    x -= w;
    sw = image->w;
  }

  return RET_OK;
}

static ret_t liquid_flow_draw_horizontal_backward(widget_t* widget, canvas_t* c, bitmap_t* image) {
  int32_t y = 0;
  int32_t w = 0;
  int32_t h = 0;
  int32_t sx = 0;
  int32_t dx = 0;
  rect_t src;
  rect_t dst;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  h = image->h;
  y = widget->h / 2 - image->h / 2;
  sx = liquid_flow->offset % image->w;

  while (dx < widget->w) {
    w = tk_min_int(image->w - sx, widget->w - dx);

    src = rect_init(sx, 0, w, h);
    dst = rect_init(dx, y, w, h);

    canvas_draw_image(c, image, &src, &dst);
    sx = 0;
    dx += w;
  }

  return RET_OK;
}

static ret_t liquid_flow_draw_left_image(widget_t* widget, canvas_t* c, bitmap_t* image) {
  rect_t src;
  rect_t dst;
  double scale = 0;
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  scale = 1.0 * widget->h / image->h;
  src = rect_init(0, 0, image->w, image->h);
  dst = rect_init(0, 0, image->w * scale, widget->h);
  canvas_draw_image(c, image, &src, &dst);

  return RET_OK;
}

static ret_t liquid_flow_draw_right_image(widget_t* widget, canvas_t* c, bitmap_t* image) {
  rect_t src;
  rect_t dst;
  double scale = 0;
  int32_t w = 0;
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  scale = 1.0 * widget->h / image->h;
  src = rect_init(0, 0, image->w, image->h);
  w = image->w * scale;
  dst = rect_init(widget->w - w, 0, w, widget->h);
  canvas_draw_image(c, image, &src, &dst);

  return RET_OK;
}

static ret_t liquid_flow_draw_top_image(widget_t* widget, canvas_t* c, bitmap_t* image) {
  rect_t src;
  rect_t dst;
  double scale = 0;
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  scale = 1.0 * widget->w / image->w;
  src = rect_init(0, 0, image->w, image->h);
  dst = rect_init(0, 0, widget->w, image->h * scale);
  canvas_draw_image(c, image, &src, &dst);

  return RET_OK;
}

static ret_t liquid_flow_draw_bottom_image(widget_t* widget, canvas_t* c, bitmap_t* image) {
  rect_t src;
  rect_t dst;
  double scale = 0;
  int32_t h = 0 ;
  return_value_if_fail(widget != NULL && c != NULL && image != NULL, RET_BAD_PARAMS);

  scale = 1.0 * widget->w / image->w;
  src = rect_init(0, 0, image->w, image->h);
  h = image->h * scale;
  dst = rect_init(0, widget->h - h, widget->w, h);
  canvas_draw_image(c, image, &src, &dst);

  return RET_OK;
}

static ret_t liquid_flow_draw_head_tail_image(widget_t* widget, canvas_t* c) {
  bitmap_t image;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && c != NULL && liquid_flow != NULL, RET_BAD_PARAMS);

  if (liquid_flow->head_image != NULL) {
    if (widget_load_image(widget, liquid_flow->head_image, &image) == RET_OK) {
      if (liquid_flow->vertical) {
        if (liquid_flow->forward) {
          liquid_flow_draw_bottom_image(widget, c, &image);
        } else {
          liquid_flow_draw_top_image(widget, c, &image);
        }
      } else {
        if (liquid_flow->forward) {
          liquid_flow_draw_right_image(widget, c, &image);
        } else {
          liquid_flow_draw_left_image(widget, c, &image);
        }
      }
    }
  }

  if (liquid_flow->tail_image != NULL) {
    if (widget_load_image(widget, liquid_flow->tail_image, &image) == RET_OK) {
      if (liquid_flow->vertical) {
        if (liquid_flow->forward) {
          liquid_flow_draw_top_image(widget, c, &image);
        } else {
          liquid_flow_draw_bottom_image(widget, c, &image);
        }
      } else {
        if (liquid_flow->forward) {
          liquid_flow_draw_left_image(widget, c, &image);
        } else {
          liquid_flow_draw_right_image(widget, c, &image);
        }
      }
    }
  }

  return RET_OK;
}

static ret_t liquid_flow_draw_image(widget_t* widget, canvas_t* c) {
  bitmap_t image;
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && liquid_flow != NULL, RET_BAD_PARAMS);

  if (liquid_flow->image == NULL) {
    return RET_OK;
  }

  if (widget_load_image(widget, liquid_flow->image, &image) != RET_OK) {
    return RET_OK;
  }

  if (liquid_flow->vertical) {
    if (liquid_flow->forward) {
      liquid_flow_draw_vertical_forward(widget, c, &image);
    } else {
      liquid_flow_draw_vertical_backward(widget, c, &image);
    }
  } else {
    if (liquid_flow->forward) {
      liquid_flow_draw_horizontal_forward(widget, c, &image);
    } else {
      liquid_flow_draw_horizontal_backward(widget, c, &image);
    }
  }

  return RET_OK;
}

static ret_t liquid_flow_on_paint_self(widget_t* widget, canvas_t* c) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && liquid_flow != NULL, RET_BAD_PARAMS);

  liquid_flow_draw_image(widget, c);
  liquid_flow_draw_head_tail_image(widget, c);

  return RET_OK;
}

static ret_t liquid_flow_on_event(widget_t* widget, event_t* e) {
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(widget != NULL && liquid_flow != NULL, RET_BAD_PARAMS);

  (void)liquid_flow;

  return RET_OK;
}

const char* s_liquid_flow_properties[] = {LIQUID_FLOW_PROP_RUNNING, LIQUID_FLOW_PROP_FORWARD,
                                          LIQUID_FLOW_PROP_VERTICAL, LIQUID_FLOW_PROP_IMAGE, NULL};

TK_DECL_VTABLE(liquid_flow) = {.size = sizeof(liquid_flow_t),
                               .type = WIDGET_TYPE_LIQUID_FLOW,
                               .clone_properties = s_liquid_flow_properties,
                               .persistent_properties = s_liquid_flow_properties,
                               .parent = TK_PARENT_VTABLE(widget),
                               .create = liquid_flow_create,
                               .on_paint_self = liquid_flow_on_paint_self,
                               .set_prop = liquid_flow_set_prop,
                               .get_prop = liquid_flow_get_prop,
                               .on_event = liquid_flow_on_event,
                               .on_destroy = liquid_flow_on_destroy};

widget_t* liquid_flow_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  widget_t* widget = widget_create(parent, TK_REF_VTABLE(liquid_flow), x, y, w, h);
  liquid_flow_t* liquid_flow = LIQUID_FLOW(widget);
  return_value_if_fail(liquid_flow != NULL, NULL);

  liquid_flow->running = FALSE;
  liquid_flow->forward = TRUE;
  liquid_flow->vertical = FALSE;
  liquid_flow->update_delta = 10;
  liquid_flow->update_interval = 30;

  return widget;
}

widget_t* liquid_flow_cast(widget_t* widget) {
  return_value_if_fail(WIDGET_IS_INSTANCE_OF(widget, liquid_flow), NULL);

  return widget;
}
