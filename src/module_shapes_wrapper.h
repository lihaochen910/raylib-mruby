﻿#ifndef MODULE_SHAPES_WRAPPER_H
#define MODULE_SHAPES_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_module_shapes_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_module_shapes_final ( mrb_state *mrb, struct RClass *mod_RayLib );


#ifdef __cplusplus
}
#endif

#endif
