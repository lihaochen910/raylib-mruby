#ifndef WAVE_WRAPPER_H
#define WAVE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_wave_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_wave_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_wave(mrb_state* mrb, Wave* wave, bool is_associated);
extern mrb_value mrb_raylib_wave_direct(mrb_state* mrb, Wave const* wave);

extern Wave* mrb_raylib_wave_get_ptr(mrb_state* mrb, mrb_value wave);


#ifdef __cplusplus
}
#endif

#endif