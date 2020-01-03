#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif


extern void mrb_raylib_image_init ( mrb_state *mrb, struct RClass *mod_RayLib );
extern void mrb_raylib_image_final ( mrb_state *mrb, struct RClass *mod_RayLib );

extern mrb_value mrb_raylib_image ( mrb_state *mrb, Image *image, bool is_associated );
extern mrb_value mrb_raylib_image_direct ( mrb_state *mrb, Image const *image );
extern Image *mrb_raylib_image_get_ptr ( mrb_state *mrb, mrb_value image );


#ifdef __cplusplus
}
#endif

#endif