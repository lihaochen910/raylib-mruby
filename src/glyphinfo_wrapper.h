#ifndef GLYPHINFO_WRAPPER_H
#define GLYPHINFO_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_glyphinfo_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_glyphinfo_final ( mrb_state *mrb, struct RClass *mod_RayLib );

extern mrb_value mrb_raylib_glyphinfo ( mrb_state *mrb, GlyphInfo *glyphinfo, bool is_associated );
extern mrb_value mrb_raylib_glyphinfo_direct ( mrb_state *mrb, GlyphInfo const *glyphinfo );
extern GlyphInfo *mrb_raylib_glyphinfo_get_ptr ( mrb_state *mrb, mrb_value glyphinfo );


#ifdef __cplusplus
}
#endif

#endif