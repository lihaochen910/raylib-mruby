#ifndef RENDER_TEXTURE_WRAPPER_H
#define RENDER_TEXTURE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_render_texture_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_render_texture_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_render_texture(mrb_state* mrb, RenderTexture* render_texture, bool is_associated);
extern mrb_value mrb_raylib_render_texture_direct(mrb_state* mrb, RenderTexture const* render_texture);

extern RenderTexture* mrb_raylib_render_texture_get_ptr(mrb_state* mrb, mrb_value render_texture);


#ifdef __cplusplus
}
#endif

#endif