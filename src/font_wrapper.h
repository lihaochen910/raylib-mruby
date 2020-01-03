#ifndef FONT_WRAPPER_H
#define FONT_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_font_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_font_final ( mrb_state *mrb, struct RClass *mod_RayLib );

extern mrb_value mrb_raylib_font ( mrb_state *mrb, Font *font, bool is_associated );
extern mrb_value mrb_raylib_font_direct ( mrb_state *mrb, Font const *font );
extern Font *mrb_raylib_font_get_ptr ( mrb_state *mrb, mrb_value font );


#ifdef __cplusplus
}
#endif

#endif