#include "module_texture_wrapper.h"
#include "texture_wrapper.h"
#include "image_wrapper.h"
#include "render_texture_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// module: textures
//================================================================//

//----------------------------------------------------------------//
/**	@ruby	LoadImage
	@text	Load image from file into CPU memory (RAM)

	@in		String file Path
	@out	Image image
*/
static mrb_value
mrb_raylib_module_texture_load_image(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;

	mrb_get_args(mrb, "S", &fileName);

	Image image = LoadImage(RSTRING_PTR(fileName));

	return mrb_raylib_image_direct(mrb, &image);
}

//----------------------------------------------------------------//
/**	@ruby	ExportImage
	@text	Export image as a PNG file

	@in		String file Path
*/
static mrb_value
mrb_raylib_module_texture_export_image(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;
	mrb_value image;

	mrb_get_args(mrb, "So", &image, &fileName);

	ExportImage(*mrb_raylib_image_get_ptr(mrb, image), RSTRING_PTR(fileName));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	LoadTexture
	@text	Load texture from file into GPU memory (VRAM)

	@in		String file Path
	@out	Texture texture
*/
static mrb_value
mrb_raylib_module_texture_load_texture(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;

	mrb_get_args(mrb, "S", &fileName);

	Texture texture = LoadTexture(RSTRING_PTR(fileName));

	return mrb_raylib_texture_direct(mrb, &texture);
}

//----------------------------------------------------------------//
/**	@ruby	LoadTextureFromImage
	@text	Load texture from file into GPU memory (VRAM)

	@in		Image image
	@out	Texture texture
*/
static mrb_value
mrb_raylib_module_texture_load_texture_from_image(mrb_state* mrb, mrb_value self)
{
	mrb_value image;

	mrb_get_args(mrb, "o", &image);

	Texture texture = LoadTextureFromImage(*mrb_raylib_image_get_ptr(mrb, image));

	return mrb_raylib_texture_direct(mrb, &texture);
}

//----------------------------------------------------------------//
/**	@ruby	LoadRenderTexture
	@text	Load texture for rendering (framebuffer)

	@in		Fixnum width
	@in		Fixnum height
	@out	RenderTexture2D framebuffer
*/
static mrb_value
mrb_raylib_module_texture_load_render_texture(mrb_state* mrb, mrb_value self)
{
	mrb_int width, height;

	mrb_get_args(mrb, "ii", &width, &height);

	RenderTexture2D render_texture = LoadRenderTexture(width, height);

	return mrb_raylib_render_texture_direct(mrb, &render_texture);
}

//----------------------------------------------------------------//
/**	@ruby	UnloadImage
	@text	Unload image from CPU memory (RAM)

	@in		Image image
*/
static mrb_value
mrb_raylib_module_texture_unload_image(mrb_state* mrb, mrb_value self)
{
	mrb_value image;

	mrb_get_args(mrb, "o", &image);

	UnloadImage(*mrb_raylib_image_get_ptr(mrb, image));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	UnloadTexture
	@text	Unload texture from GPU memory (VRAM)

	@in		Texture texture
*/
static mrb_value
mrb_raylib_module_texture_unload_texture(mrb_state* mrb, mrb_value self)
{
	mrb_value texture;

	mrb_get_args(mrb, "o", &texture);

	UnloadTexture(*mrb_raylib_texture_get_ptr(mrb, texture));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	UnloadRenderTexture
	@text	Unload render texture from GPU memory (VRAM)

	@in		RenderTexture render texture
*/
static mrb_value
mrb_raylib_module_texture_unload_render_texture(mrb_state* mrb, mrb_value self)
{
	mrb_value render_texture;

	mrb_get_args(mrb, "o", &render_texture);

	UnloadRenderTexture(*mrb_raylib_render_texture_get_ptr(mrb, render_texture));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	GetTextureData
	@text	Get pixel data from GPU texture and return an Image

	@in		Texture2D texture
	@out	Image image
*/
static mrb_value
mrb_raylib_module_texture_get_texture_data(mrb_state* mrb, mrb_value self)
{
	mrb_value texture2d;

	mrb_get_args(mrb, "o", &texture2d);

	Image image = GetTextureData(*mrb_raylib_texture_get_ptr(mrb, texture2d));

	return mrb_raylib_image_direct(mrb, &image);
}

//----------------------------------------------------------------//
/**	@ruby	DrawTexture
	@text	Draw a Texture2D

	@in		Texture2D texture
	@in		Fixnum posX
	@in		Fixnum posY
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_raylib_module_texture_draw_texture(mrb_state* mrb, mrb_value self)
{
	mrb_value texture2d;
	mrb_int posX, posY;
	mrb_float r, g, b, a;

	mrb_get_args(mrb, "oiiffff", &texture2d, &posX, &posY, &r, &g, &b, &a);

	Color tint = { r, g, b, a };

	DrawTexture(*mrb_raylib_texture_get_ptr(mrb, texture2d), posX, posY, tint);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawTextureEx
	@text	Draw a Texture2D with extended parameters

	@in		Texture2D texture
	@in		Fixnum posX
	@in		Fixnum posY
	@in		Float rotation
	@in		Float scale
	@in		Fixnum r
	@in		Fixnum g
	@in		Fixnum b
	@in		Fixnum a
*/
static mrb_value
mrb_raylib_module_texture_draw_texture_ex(mrb_state* mrb, mrb_value self)
{
	mrb_value texture2d;
	mrb_int posX, posY;
	mrb_float rotation, scale;
	mrb_float r, g, b, a;

	mrb_get_args(mrb, "oiiffffff", &texture2d, &posX, &posY, &rotation, &scale, &r, &g, &b, &a);

	Vector2 position = { posX, posY };
	Color tint = { r, g, b, a };

	DrawTextureEx(*mrb_raylib_texture_get_ptr(mrb, texture2d), position, rotation, scale, tint);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawTextureRec
	@text	Draw a part of a texture defined by a rectangle

	@in		Texture2D texture
	@in		Float sourceRecX
	@in		Float sourceRecY
	@in		Float sourceRecWidth
	@in		Float sourceRecHeight
	@in		Fixnum posX
	@in		Fixnum posY
	@in		Fixnum r
	@in		Fixnum g
	@in		Fixnum b
	@in		Fixnum a
*/
static mrb_value
mrb_raylib_module_texture_draw_texture_rec(mrb_state* mrb, mrb_value self)
{
	mrb_value texture2d;
	mrb_float sourceRecX, sourceRecY, sourceRecWidth, sourceRecHeight;
	mrb_int posX, posY;
	mrb_float r, g, b, a;

	mrb_get_args(mrb, "offffiiffff", &texture2d, &sourceRecX, &sourceRecY, &sourceRecWidth, &sourceRecHeight, &posX, &posY, &r, &g, &b, &a);

	Rectangle sourceRec = { sourceRecX, sourceRecY, sourceRecWidth, sourceRecHeight };
	Vector2 position = { posX, posY };
	Color tint = { r, g, b, a };

	DrawTextureRec(*mrb_raylib_texture_get_ptr(mrb, texture2d), sourceRec, position, tint);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawTexturePro
	@text	Draw a part of a texture defined by a rectangle with 'pro' parameters

	@in		Texture2D texture
	@in		Float sourceRecX
	@in		Float sourceRecY
	@in		Float sourceRecWidth
	@in		Float sourceRecHeight
	@in		Float destRecX
	@in		Float destRecY
	@in		Float destRecWidth
	@in		Float destRecHeight
	@in		Fixnum originX
	@in		Fixnum originY
	@in		Fixnum rotation
	@in		Fixnum r
	@in		Fixnum g
	@in		Fixnum b
	@in		Fixnum a
*/
static mrb_value
mrb_raylib_module_texture_draw_texture_pro(mrb_state* mrb, mrb_value self)
{
	mrb_value texture2d;
	mrb_float sourceRecX, sourceRecY, sourceRecWidth, sourceRecHeight;
	mrb_float destRecX, destRecY, destRecWidth, destRecHeight;
	mrb_int originX, originY;
	mrb_float rotation;
	mrb_float r, g, b, a;

	mrb_get_args(mrb, "offffiiffff", &texture2d, 
		&sourceRecX, &sourceRecY, &sourceRecWidth, &sourceRecHeight,
		&destRecX, &destRecY, &destRecWidth, &destRecHeight,
		&originX, &originY, &rotation, &r, &g, &b, &a);

	Rectangle sourceRec = { sourceRecX, sourceRecY, sourceRecWidth, sourceRecHeight };
	Rectangle destRec = { destRecX, destRecY, destRecWidth, destRecHeight };
	Vector2 origin = { originX, originY };
	Color tint = { r, g, b, a };

	DrawTexturePro(*mrb_raylib_texture_get_ptr(mrb, texture2d), sourceRec, destRec, origin, rotation, tint);

	return self;
}


void
mrb_raylib_module_texture_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	// Image/Texture2D data loading/unloading/saving functions
	mrb_define_module_function(mrb, mod_RayLib, "load_image", mrb_raylib_module_texture_load_image, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "export_image", mrb_raylib_module_texture_export_image, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "load_texture", mrb_raylib_module_texture_load_texture, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "load_texture_from_image", mrb_raylib_module_texture_load_texture_from_image, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "load_render_texture", mrb_raylib_module_texture_load_render_texture, MRB_ARGS_REQ(1));

	mrb_define_module_function(mrb, mod_RayLib, "unload_image", mrb_raylib_module_texture_unload_image, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "unload_texture", mrb_raylib_module_texture_unload_texture, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "unload_render_texture", mrb_raylib_module_texture_unload_render_texture, MRB_ARGS_REQ(1));

	mrb_define_module_function(mrb, mod_RayLib, "get_texture_data", mrb_raylib_module_texture_get_texture_data, MRB_ARGS_REQ(1));

	// TODO: Image manipulation functions

	// TODO: Image generation functions

	// TODO: Texture2D configuration functions

	// Texture2D drawing functions
	mrb_define_module_function(mrb, mod_RayLib, "draw_texture", mrb_raylib_module_texture_draw_texture, MRB_ARGS_REQ(7));
	mrb_define_module_function(mrb, mod_RayLib, "draw_texture_ex", mrb_raylib_module_texture_draw_texture_ex, MRB_ARGS_REQ(9));
	mrb_define_module_function(mrb, mod_RayLib, "draw_texture_rec", mrb_raylib_module_texture_draw_texture_rec, MRB_ARGS_REQ(11));
	mrb_define_module_function(mrb, mod_RayLib, "draw_texture_pro", mrb_raylib_module_texture_draw_texture_pro, MRB_ARGS_REQ(16));
}

void
mrb_raylib_module_texture_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
