#ifndef MODULE_AUDIO_WRAPPER_H
#define MODULE_AUDIO_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


	extern void mrb_raylib_module_audio_init(mrb_state* mrb, struct RClass* mod_RayLib);
	extern void mrb_raylib_module_audio_final(mrb_state* mrb, struct RClass* mod_RayLib);


#ifdef __cplusplus
}
#endif

#endif
