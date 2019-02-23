#ifdef RAYLIB_MUSIC

#ifndef MUSIC_WRAPPER_H
#define MUSIC_WRAPPER_H

#include <raylib.h>
//#include <raudio.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_music_init(mrb_state* mrb, struct RClass* mod_RayLib);
extern void mrb_raylib_music_final(mrb_state* mrb, struct RClass* mod_RayLib);

extern mrb_value mrb_raylib_music(mrb_state* mrb, Music music, bool is_associated);
extern mrb_value mrb_raylib_music_direct(mrb_state* mrb, Music const music);

extern Music mrb_raylib_music_get_ptr(mrb_state* mrb, mrb_value music);


#ifdef __cplusplus
}
#endif

#endif

#endif