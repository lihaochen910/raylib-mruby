#ifndef RMRUBY_H
#define RMRUBY_H

#include <mruby.h>
#include "core_wrapper.h"

#ifdef __cplusplus
	#define RMRUBY_API extern "C"
#else
	#define RMRUBY_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

RMRUBY_API struct RClass *mod_RayLib;
RMRUBY_API struct RClass *class_RayLibError;

RMRUBY_API void mrb_raylib_module_init(mrb_state *mrb);
RMRUBY_API void mrb_raylib_struct_init(mrb_state *mrb);
RMRUBY_API void mrb_raylib_gem_init(mrb_state *mrb);
RMRUBY_API void mrb_raylib_module_final(mrb_state *mrb);

#ifdef __cplusplus
}
#endif

#endif