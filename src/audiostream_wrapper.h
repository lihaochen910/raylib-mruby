#ifndef AUDIOSTREAM_WRAPPER_H
#define AUDIOSTREAM_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_audiostream_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_audiostream_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_audiostream(mrb_state* mrb, AudioStream* audiostream, bool is_associated);
extern mrb_value mrb_raylib_audiostream_direct(mrb_state* mrb, AudioStream const* audiostream);

extern AudioStream* mrb_raylib_audiostream_get_ptr(mrb_state* mrb, mrb_value audiostream);


#ifdef __cplusplus
}
#endif

#endif