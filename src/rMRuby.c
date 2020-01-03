#include "rMRuby.h"

#include "core_wrapper.h"
#include "image_wrapper.h"
#include "texture_wrapper.h"
#include "render_texture_wrapper.h"
#include "charinfo_wrapper.h"
#include "font_wrapper.h"
#include "wave_wrapper.h"
#include "sound_wrapper.h"
#include "audiostream_wrapper.h"
#include "music_wrapper.h"
#include "shader_wrapper.h"

#include "module_shapes_wrapper.h"
#include "module_texture_wrapper.h"
#include "module_text_wrapper.h"
#include "module_models_wrapper.h"
#include "module_audio_wrapper.h"

RMRUBY_API struct RClass *mod_RayLib;
RMRUBY_API struct RClass *class_RayLibError;

void
mrb_raylib_module_init ( mrb_state *mrb ) {

	mod_RayLib = mrb_define_module ( mrb, "Raylib" );
	class_RayLibError = mrb_define_class_under ( mrb, mod_RayLib, "RaylibError", mrb->eStandardError_class );

	//================================================================//
	// module: raylib struct
	//================================================================//
	mrb_raylib_gem_init ( mrb );

	//================================================================//
	// module: core
	//================================================================//
	mrb_raylib_core_init ( mrb, mod_RayLib );


	//================================================================//
	// module: shapes
	//================================================================//
	mrb_raylib_module_shapes_init ( mrb, mod_RayLib );


	//================================================================//
	// module: textures
	//================================================================//
	mrb_raylib_module_texture_init ( mrb, mod_RayLib );


	//================================================================//
	// module: text
	//================================================================//
	mrb_raylib_module_text_init ( mrb, mod_RayLib );


	//================================================================//
	// module: models
	//================================================================//
	mrb_raylib_module_models_init ( mrb, mod_RayLib );


	//================================================================//
	// module: shaders
	//================================================================//
	mrb_raylib_module_shader_init ( mrb, mod_RayLib );


	//================================================================//
	// module: audio
	//================================================================//
	mrb_raylib_module_audio_init ( mrb, mod_RayLib );
}


void
mrb_raylib_gem_init ( mrb_state *mrb ) {
	mrb_raylib_image_init ( mrb, mod_RayLib );
	mrb_raylib_texture_init ( mrb, mod_RayLib );
	mrb_raylib_render_texture_init ( mrb, mod_RayLib );
	mrb_raylib_charinfo_init ( mrb, mod_RayLib );
	mrb_raylib_font_init ( mrb, mod_RayLib );
	mrb_raylib_wave_init ( mrb, mod_RayLib );
	mrb_raylib_sound_init ( mrb, mod_RayLib );
	mrb_raylib_audiostream_init ( mrb, mod_RayLib );
	//mrb_raylib_music_init(mrb, mod_RayLib);
	mrb_raylib_shader_init ( mrb, mod_RayLib );
}

void
mrb_raylib_struct_init ( mrb_state *mrb ) {

}

void
mrb_raylib_module_final ( mrb_state *mrb ) {

}
