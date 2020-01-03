#include "module_text_wrapper.h"
#include "font_wrapper.h"
#include "image_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"

//================================================================//
// module: text
//================================================================//

//----------------------------------------------------------------//
/**	@ruby	LoadFont
	@text	Load font from file into GPU memory (VRAM)

	@in		String file Path
	@out	Font font
*/
static mrb_value
mrb_raylib_module_text_load_font ( mrb_state *mrb, mrb_value self ) {
	mrb_value fileName;

	mrb_get_args ( mrb, "S", & fileName );

	Font font = LoadFont ( RSTRING_PTR( fileName ) );

	return mrb_raylib_font_direct ( mrb, & font );
}

//----------------------------------------------------------------//
/**	@ruby	GetFontDefault
	@text	Get the default Font

	@out	Font font
*/
static mrb_value
mrb_raylib_module_text_get_font_default ( mrb_state *mrb, mrb_value self ) {
	Font font = GetFontDefault ();

	return mrb_raylib_font_direct ( mrb, & font );
}

//----------------------------------------------------------------//
/**	@ruby	UnloadFont
	@text	Unload Font from GPU memory (VRAM)

	@in		Font font
*/
static mrb_value
mrb_raylib_module_text_unload_font ( mrb_state *mrb, mrb_value self ) {
	mrb_value font;

	mrb_get_args ( mrb, "o", & font );

	UnloadFont ( * mrb_raylib_font_get_ptr ( mrb, font ) );

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawFPS
	@text	Shows current FPS

	@in		Fixnum posX
	@in		Fixnum posY
*/
static mrb_value
mrb_raylib_module_text_draw_fps ( mrb_state *mrb, mrb_value self ) {
	mrb_int posX, posY = 0;

	mrb_get_args ( mrb, "ii", & posX, & posY );

	DrawFPS ( posX, posY );

	return self;
}


//----------------------------------------------------------------//
/**	@ruby	DrawText
	@text	Draw text (using default font)

	@in		String text
	@in		Fixnum posX
	@in		Fixnum posY
	@in		Fixnum fontSize
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_raylib_module_text_draw_text ( mrb_state *mrb, mrb_value self ) {
	mrb_value text;
	mrb_int posX, posY = 0;
	mrb_int fontSize = 0;
	mrb_float r, g, b, a = 0;

	mrb_get_args ( mrb, "Siiiffff", & text, & posX, & posY, & fontSize, & r, & g, & b, & a );

	Color color = { r, g, b, a };

	DrawText ( RSTRING_PTR( text ), posX, posY, fontSize, color );

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawTextEx
	@text	Draw text using font and additional parameters

	@in		Font font
	@in		String text
	@in		Fixnum posX
	@in		Fixnum posY
	@in		Fixnum fontSize
	@in		Fixnum spacing
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_raylib_module_text_draw_text_ex ( mrb_state *mrb, mrb_value self ) {
	mrb_value font;
	mrb_value text;
	mrb_float posX, posY = 0;
	mrb_float fontSize = 0;
	mrb_float spacing = 0;
	mrb_float r, g, b, a = 0;

	mrb_get_args ( mrb, "oSffffffff", & font, & text, & posX, & posY, & fontSize, & spacing, & r, & g, & b, & a );

	Vector2 position = { posX, posY };
	Color tint = { r, g, b, a };

	DrawTextEx ( * mrb_raylib_font_get_ptr ( mrb, font ), RSTRING_PTR( text ), position, fontSize, spacing, tint );

	return self;
}

void
mrb_raylib_module_text_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	// Font loading/unloading functions
	mrb_define_module_function ( mrb, mod_RayLib, "get_font_default", mrb_raylib_module_text_get_font_default, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "load_font", mrb_raylib_module_text_load_font, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "unload_font", mrb_raylib_module_text_unload_font, MRB_ARGS_REQ( 1 ) );

	// Text drawing functions
	mrb_define_module_function ( mrb, mod_RayLib, "draw_fps", mrb_raylib_module_text_draw_fps, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "draw_text", mrb_raylib_module_text_draw_text, MRB_ARGS_REQ( 8 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "draw_text_ex", mrb_raylib_module_text_draw_text_ex, MRB_ARGS_REQ( 10 ) );

	// TODO: Text misc. functions

}

void
mrb_raylib_module_text_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
