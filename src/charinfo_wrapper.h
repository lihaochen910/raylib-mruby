#ifndef CHARINFO_WRAPPER_H
#define CHARINFO_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_charinfo_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_charinfo_final ( mrb_state *mrb, struct RClass *mod_RayLib );

extern mrb_value mrb_raylib_charinfo ( mrb_state *mrb, GlyphInfo *charinfo, bool is_associated );
extern mrb_value mrb_raylib_charinfo_direct ( mrb_state *mrb, GlyphInfo const *charinfo );
extern GlyphInfo *mrb_raylib_charinfo_get_ptr ( mrb_state *mrb, mrb_value charinfo );


#ifdef __cplusplus
}
#endif

#endif