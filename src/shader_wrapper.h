#ifndef SHADER_WRAPPER_H
#define SHADER_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_shader_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_shader_final ( mrb_state *mrb, struct RClass *mod_RayLib );

extern mrb_value mrb_raylib_shader ( mrb_state *mrb, Shader *shader, bool is_associated );
extern mrb_value mrb_raylib_shader_direct ( mrb_state *mrb, Shader const *shader );

extern Shader *mrb_raylib_shader_get_ptr ( mrb_state *mrb, mrb_value shader );


#ifdef __cplusplus
}
#endif

#endif