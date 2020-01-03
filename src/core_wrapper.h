#ifndef CORE_WRAPPER_H
#define CORE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>
#include <mruby/string.h>
#include <mruby/array.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mrb_raylib_core_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_core_final ( mrb_state *mrb, struct RClass *mod_RayLib );

#ifdef __cplusplus
}
#endif

#endif
