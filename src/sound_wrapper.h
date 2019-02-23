#ifndef SOUND_WRAPPER_H
#define SOUND_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_sound_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_sound_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_sound(mrb_state* mrb, Sound* sound, bool is_associated);
extern mrb_value mrb_raylib_sound_direct(mrb_state* mrb, Sound const* sound);

extern Sound* mrb_raylib_sound_get_ptr(mrb_state* mrb, mrb_value sound);


#ifdef __cplusplus
}
#endif

#endif