#include "module_shaders_wrapper.h"
#include "shader_wrapper.h"
#include "texture_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"

//================================================================//
// module: shaders
//================================================================//

//----------------------------------------------------------------//
/**	@ruby	LoadShader
	@text	Load a custom shader and bind default locations

	@in		String vertext shader file name
	@in		String fragment shader file name
	@out	Shader shader
*/
static mrb_value
mrb_raylib_module_shader_load_shader(mrb_state* mrb, mrb_value self)
{
	mrb_value vsFileName;
	mrb_value fsFileName;

	mrb_get_args(mrb, "SS", &vsFileName, &fsFileName);

	Shader shader = LoadShader(RSTRING_PTR(vsFileName), RSTRING_PTR(fsFileName));

	return mrb_raylib_shader_direct(mrb, &shader);
}

//----------------------------------------------------------------//
/**	@ruby	LoadShaderCode
	@text	Load shader from code strings and bind default locations

	@in		String vertext shader file name
	@in		String fragment shader file name
	@out	Shader shader
*/
static mrb_value
mrb_raylib_module_shader_load_shader_code(mrb_state* mrb, mrb_value self)
{
	mrb_value vsCode;
	mrb_value fsCode;

	mrb_get_args(mrb, "SS", &vsCode, &fsCode);

	Shader shader = LoadShaderCode(RSTRING_PTR(vsCode), RSTRING_PTR(fsCode));

	return mrb_raylib_shader_direct(mrb, &shader);
}

//----------------------------------------------------------------//
/**	@ruby	UnloadShader
	@text	Unload a custom shader from memory

	@in		Shader shader
*/
static mrb_value
mrb_raylib_module_shader_unload_shader(mrb_state* mrb, mrb_value self)
{
	mrb_value shader;

	mrb_get_args(mrb, "o", &shader);

	UnloadShader(*mrb_raylib_shader_get_ptr(mrb, shader));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	GetShaderDefault
	@text	Get default shader

	@out	Shader shader
*/
static mrb_value
mrb_raylib_module_shader_get_shader_default(mrb_state* mrb, mrb_value self)
{
	Shader shader = GetShaderDefault();

	return mrb_raylib_shader_direct(mrb, &shader);
}

//----------------------------------------------------------------//
/**	@ruby	GetTextureDefault
	@text	Get default texture

	@out	Texture2D texture
*/
static mrb_value
mrb_raylib_module_shader_get_texture_default(mrb_state* mrb, mrb_value self)
{
	Texture2D texture = GetTextureDefault();

	return mrb_raylib_texture_direct(mrb, &texture);
}

//----------------------------------------------------------------//
/**	@ruby	GetShaderLocation
	@text	Get shader uniform location

	@in		Shader shader
	@in		String uniformName
	@out	Fixnum location
*/
static mrb_value
mrb_raylib_module_shader_get_shader_location(mrb_state* mrb, mrb_value self)
{
	mrb_value shader;
	mrb_value uniformName;

	mrb_get_args(mrb, "oS", &shader, &uniformName);

	return mrb_fixnum_value(GetShaderLocation(*mrb_raylib_shader_get_ptr(mrb, shader), RSTRING_PTR(uniformName)));
}

//----------------------------------------------------------------//
/**	@ruby	BeginShaderMode
	@text	Begin custom shader drawing

	@in		Shader shader
*/
static mrb_value
mrb_raylib_module_shader_begin_shader_mode(mrb_state* mrb, mrb_value self)
{
	mrb_value shader;

	mrb_get_args(mrb, "o", &shader);

	BeginShaderMode(*mrb_raylib_shader_get_ptr(mrb, shader));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	EndShaderMode
	@text	End custom shader drawing (use default shader)
*/
static mrb_value
mrb_raylib_module_shader_end_shader_mode(mrb_state* mrb, mrb_value self)
{
	EndShaderMode();

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	BeginShaderMode
	@text	Begin blending mode (alpha, additive, multiplied)

	@in		Fixnum blend mode
*/
static mrb_value
mrb_raylib_module_shader_begin_blend_mode(mrb_state* mrb, mrb_value self)
{
	mrb_int blend_mode;

	mrb_get_args(mrb, "i", &blend_mode);

	BeginBlendMode(blend_mode);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	EndBlendMode
	@text	End blending mode (reset to default: alpha blending)
*/
static mrb_value
mrb_raylib_module_shader_end_blend_mode(mrb_state* mrb, mrb_value self)
{
	EndBlendMode();

	return self;
}



void
mrb_raylib_module_shader_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	// Shader loading/unloading functions
	mrb_define_module_function(mrb, mod_RayLib, "load_shader", mrb_raylib_module_shader_load_shader, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "load_shader_code", mrb_raylib_module_shader_load_shader_code, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "unload_shader", mrb_raylib_module_shader_unload_shader, MRB_ARGS_REQ(1));

	mrb_define_module_function(mrb, mod_RayLib, "get_shader_default", mrb_raylib_module_shader_get_shader_default, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_texture_default", mrb_raylib_module_shader_get_texture_default, MRB_ARGS_NONE());

	// Shader access functions
	mrb_define_module_function(mrb, mod_RayLib, "get_shader_location", mrb_raylib_module_shader_get_shader_location, MRB_ARGS_REQ(2));

	// Shading beegin/end functions
	mrb_define_module_function(mrb, mod_RayLib, "begin_shader_mode", mrb_raylib_module_shader_begin_shader_mode, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "end_shader_mode", mrb_raylib_module_shader_end_shader_mode, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "begin_blend_mode", mrb_raylib_module_shader_begin_blend_mode, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "end_blend_mode", mrb_raylib_module_shader_end_blend_mode, MRB_ARGS_NONE());

	// TODO: VR control functions
}

void
mrb_raylib_module_shader_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
