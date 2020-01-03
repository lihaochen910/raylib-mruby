#include "module_models_wrapper.h"
#include "font_wrapper.h"
#include "image_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"

//================================================================//
// module: models
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_draw_ray ( mrb_state *mrb, mrb_value self ) {
	mrb_float p0, p1, p2;
	mrb_float d0, d1, d2;
	mrb_float r, g, b, a = 0;

	mrb_get_args ( mrb, "ffffffffff", & p0, & p1, & p2, & d0, & d1, & d2, & r, & g, & b, & a );

	Vector3 pos = { p0, p1, p2 };
	Vector3 dir = { d0, d1, d2 };
	Ray ray = { pos, dir };
	Color color = { r, g, b, a };

	DrawRay ( ray, color );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_grid ( mrb_state *mrb, mrb_value self ) {
	mrb_int slices;
	mrb_float spacing;

	mrb_get_args ( mrb, "if", & slices, & spacing );

	DrawGrid ( slices, spacing );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_cube_v ( mrb_state *mrb, mrb_value self ) {
	mrb_float p0, p1, p2;
	mrb_float s0, s1, s2;
	mrb_float r, g, b, a = 0;

	mrb_get_args ( mrb, "ffffffffff", & p0, & p1, & p2, & s0, & s1, & s2, & r, & g, & b, & a );

	Vector3 pos = { p0, p1, p2 };
	Vector3 size = { s0, s1, s2 };
	Color color = { r, g, b, a };

	DrawCubeV ( pos, size, color );

	return self;
}


void
mrb_raylib_module_models_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	// Basic geometric 3D shapes drawing functions
	mrb_define_module_function ( mrb, mod_RayLib, "draw_ray", mrb_draw_ray, MRB_ARGS_REQ( 10 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "draw_grid", mrb_draw_grid, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "draw_cube_v", mrb_draw_cube_v, MRB_ARGS_REQ( 10 ) );
}

void
mrb_raylib_module_models_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
