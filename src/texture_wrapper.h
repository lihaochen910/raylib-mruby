#ifndef TEXTURE_WRAPPER_H
#define TEXTURE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_texture_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_texture_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_texture(mrb_state* mrb, Texture* texture, bool is_associated);
extern mrb_value mrb_raylib_texture_direct(mrb_state* mrb, Texture const* texture);

extern Texture* mrb_raylib_texture_get_ptr(mrb_state* mrb, mrb_value texture);


#ifdef __cplusplus
}
#endif

#endif