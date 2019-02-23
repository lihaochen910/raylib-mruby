#include "module_shapes_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"

//================================================================//
// module: shapes
//================================================================//

//----------------------------------------------------------------//
/**	@ruby	DrawPixel
	@text	Draw a pixel

	@in		Fixnum posX
	@in		Fixnum posY
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_pixel(mrb_state *mrb, mrb_value self)
{
	mrb_int posX, posY;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiffff", &posX, &posY, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawPixel(posX, posY, color);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawLine
	@text	Draw a line

	@in		Fixnum startPosX
	@in		Fixnum startPosY
	@in		Fixnum endPosX
	@in		Fixnum endPosY
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_line(mrb_state *mrb, mrb_value self)
{
	mrb_int startPosX, startPosY;
	mrb_int endPosX, endPosY;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiiffff", &startPosX, &startPosY, &endPosX, &endPosY, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawLine(startPosX, startPosY, endPosX, endPosY, color);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawLineEx
	@text	Draw a line defining thickness

	@in		Fixnum startPosX
	@in		Fixnum startPosY
	@in		Fixnum endPosX
	@in		Fixnum endPosY
	@in		Float thick
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_line_ex(mrb_state *mrb, mrb_value self)
{
	mrb_int startPosX, startPosY;
	mrb_int endPosX, endPosY;
	mrb_float thick;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiifffff", &startPosX, &startPosY, &endPosX, &endPosY, &thick, &r, &g, &b, &a);

	Vector2 startPos = { startPosX, startPosY };
	Vector2 endPos = { endPosX, endPosY };
	Color color = { r, g, b, a };

	DrawLineEx(startPos, endPos, thick, color);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawLineBezier
	@text	Draw a line using cubic-bezier curves in-out

	@in		Fixnum startPosX
	@in		Fixnum startPosY
	@in		Fixnum endPosX
	@in		Fixnum endPosY
	@in		Float thick
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_line_bezier(mrb_state *mrb, mrb_value self)
{
	mrb_int startPosX, startPosY;
	mrb_int endPosX, endPosY;
	mrb_float thick;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiifffff", &startPosX, &startPosY, &endPosX, &endPosY, &thick, &r, &g, &b, &a);

	Vector2 startPos = { startPosX, startPosY };
	Vector2 endPos = { endPosX, endPosY };
	Color color = { r, g, b, a };

	DrawLineBezier(startPos, endPos, thick, color);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawCircle
	@text	Draw a color-filled circle

	@in		Fixnum startPosX
	@in		Fixnum startPosY
	@in		Float radius
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_circle(mrb_state *mrb, mrb_value self)
{
	mrb_int centerX, centerY;
	mrb_float radius;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iifffff", &centerX, &centerY, &radius, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawCircle(centerX, centerY, radius, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_circle_gradient(mrb_state *mrb, mrb_value self)
{
	mrb_int centerX, centerY;
	mrb_float radius;
	mrb_float r0, g0, b0, a0 = 0;
	mrb_float r1, g1, b1, a1 = 0;

	mrb_get_args(mrb, "iifffffffff", &centerX, &centerY, &radius,
		&r0, &g0, &b0, &a0,
		&r1, &g1, &b1, &a1);

	Color color1 = { r0, g0, b0, a0 };
	Color color2 = { r1, g1, b1, a1 };

	DrawCircleGradient(centerX, centerY, radius, color1, color2);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	DrawCircleLines
	@text	Draw circle outline

	@in		Fixnum centerX
	@in		Fixnum centerY
	@in		Float radius
	@in		Float r
	@in		Float g
	@in		Float b
	@in		Float a
*/
static mrb_value
mrb_draw_circle_lines(mrb_state *mrb, mrb_value self)
{
	mrb_int centerX, centerY;
	mrb_float radius;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iifffff", &centerX, &centerY, &radius, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawCircleLines(centerX, centerY, radius, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_rectangle(mrb_state *mrb, mrb_value self)
{
	mrb_int posX, posY;
	mrb_int width, height;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiiffff", &posX, &posY, &width, &height, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawRectangle(posX, posY, width, height, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_rectangle_lines(mrb_state *mrb, mrb_value self)
{
	mrb_int posX, posY;
	mrb_int width, height;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiiffff", &posX, &posY, &width, &height, &r, &g, &b, &a);

	Color color = { r, g, b, a };

	DrawRectangleLines(posX, posY, width, height, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_rectangle_lines_ex(mrb_state *mrb, mrb_value self)
{
	mrb_int posX, posY;
	mrb_int width, height;
	mrb_int lineThick;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "iiiiiffff", &posX, &posY, &width, &height, &lineThick, &r, &g, &b, &a);

	Rectangle rec = { posX, posY, width, height };
	Color color = { r, g, b, a };

	DrawRectangleLinesEx(rec, lineThick, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_triangle(mrb_state *mrb, mrb_value self)
{
	mrb_float v1X, v1Y;
	mrb_float v2X, v2Y;
	mrb_float v3X, v3Y;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "ffffffffff", &v1X, &v1Y, &v2X, &v2Y, &v3X, &v3Y, &r, &g, &b, &a);

	Vector2 v1 = { v1X, v1Y };
	Vector2 v2 = { v2X, v2Y };
	Vector2 v3 = { v3X, v3Y };
	Color color = { r, g, b, a };

	DrawTriangle(v1, v2, v3, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_triangle_lines(mrb_state *mrb, mrb_value self)
{
	mrb_float v1X, v1Y;
	mrb_float v2X, v2Y;
	mrb_float v3X, v3Y;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "ffffffffff", &v1X, &v1Y, &v2X, &v2Y, &v3X, &v3X, &r, &g, &b, &a);

	Vector2 v1 = { v1X, v1Y };
	Vector2 v2 = { v2X, v2Y };
	Vector2 v3 = { v3X, v3Y };
	Color color = { r, g, b, a };

	DrawTriangleLines(v1, v2, v3, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_draw_poly(mrb_state *mrb, mrb_value self)
{
	mrb_float centerX, centerY;
	mrb_int sides;
	mrb_float radius;
	mrb_float rotation;
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "ffiffffff", &centerX, &centerY,
		&sides, &radius, &rotation,
		&r, &g, &b, &a);

	Vector2 center = { centerX, centerY };
	Color color = { r, g, b, a };

	DrawPoly(center, sides, radius, rotation, color);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_check_collision_recs(mrb_state *mrb, mrb_value self)
{
	mrb_float posX1, posY1, width1, height1;
	mrb_float posX2, posY2, width2, height2;

	mrb_get_args(mrb, "ffffffff",
		&posX1, &posY1, &width1, &height1,
		&posX2, &posY2, &width2, &height2);

	Rectangle rec1 = { posX1, posY1, width1, height1 };
	Rectangle rec2 = { posX2, posY2, width2, height2 };

	return mrb_bool_value(CheckCollisionRecs(rec1, rec2));
}

//----------------------------------------------------------------//
static mrb_value
mrb_check_collision_circles(mrb_state *mrb, mrb_value self)
{
	mrb_float x1, y1;
	mrb_float radius1;
	mrb_float x2, y2;
	mrb_float radius2;

	mrb_get_args(mrb, "ffffff",
		&x1, &y1, &radius1,
		&x2, &y2, &radius2);

	Vector2 center1 = { x1, y1 };
	Vector2 center2 = { x2, y2 };

	return mrb_bool_value(CheckCollisionCircles(center1, radius1, center2, radius2));
}

//----------------------------------------------------------------//
static mrb_value
mrb_check_collision_circles_rec(mrb_state *mrb, mrb_value self)
{
	mrb_float x1, y1;
	mrb_float radius;
	mrb_float x2, y2, width, height;

	mrb_get_args(mrb, "fffffff",
		&x1, &y1, &radius,
		&x2, &y2, &width, &height);

	Vector2 center = { x1, y1 };
	Rectangle rect = { x2, y2, width, height };

	return mrb_bool_value(CheckCollisionCircleRec(center, radius, rect));
}

//----------------------------------------------------------------//
static mrb_value
mrb_check_collision_point_rec(mrb_state *mrb, mrb_value self)
{
	mrb_float x1, y1;
	mrb_float x2, y2, width, height;

	mrb_get_args(mrb, "ffffff",
		&x1, &y1,
		&x2, &y2, &width, &height);

	Vector2 point = { x1, y1 };
	Rectangle rect = { x2, y2, width, height };

	return mrb_bool_value(CheckCollisionPointRec(point, rect));
}

//----------------------------------------------------------------//
static mrb_value
mrb_check_collision_point_circle(mrb_state *mrb, mrb_value self)
{
	mrb_float x1, y1;
	mrb_float x2, y2;
	mrb_float radius;

	mrb_get_args(mrb, "fffff",
		&x1, &y1,
		&x2, &y2, &radius);

	Vector2 point = { x1, y1 };
	Vector2 center = { x2, y2 };

	return mrb_bool_value(CheckCollisionPointCircle(point, center, radius));
}


void
mrb_raylib_module_shapes_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	// Basic shapes drawing functions
	mrb_define_module_function(mrb, mod_RayLib, "draw_pixel", mrb_draw_pixel, MRB_ARGS_REQ(6));
	mrb_define_module_function(mrb, mod_RayLib, "draw_line", mrb_draw_line, MRB_ARGS_REQ(8));
	mrb_define_module_function(mrb, mod_RayLib, "draw_line_ex", mrb_draw_line_ex, MRB_ARGS_REQ(9));
	mrb_define_module_function(mrb, mod_RayLib, "draw_line_bezier", mrb_draw_line_bezier, MRB_ARGS_REQ(9));
	mrb_define_module_function(mrb, mod_RayLib, "draw_circle", mrb_draw_circle, MRB_ARGS_REQ(7));
	mrb_define_module_function(mrb, mod_RayLib, "draw_circle_gradient", mrb_draw_circle_gradient, MRB_ARGS_REQ(11));
	mrb_define_module_function(mrb, mod_RayLib, "draw_circle_lines", mrb_draw_circle_lines, MRB_ARGS_REQ(7));
	mrb_define_module_function(mrb, mod_RayLib, "draw_rectangle", mrb_draw_rectangle, MRB_ARGS_REQ(8));
	mrb_define_module_function(mrb, mod_RayLib, "draw_rectangle_lines", mrb_draw_rectangle_lines, MRB_ARGS_REQ(8));
	mrb_define_module_function(mrb, mod_RayLib, "draw_rectangle_lines_ex", mrb_draw_rectangle_lines_ex, MRB_ARGS_REQ(9));
	mrb_define_module_function(mrb, mod_RayLib, "draw_triangle", mrb_draw_triangle, MRB_ARGS_REQ(10));
	mrb_define_module_function(mrb, mod_RayLib, "draw_triangle_lines", mrb_draw_triangle_lines, MRB_ARGS_REQ(10));
	mrb_define_module_function(mrb, mod_RayLib, "draw_poly", mrb_draw_poly, MRB_ARGS_REQ(9));

	// Basic shapes collision detection functions
	mrb_define_module_function(mrb, mod_RayLib, "check_collision_recs", mrb_check_collision_recs, MRB_ARGS_REQ(8));
	mrb_define_module_function(mrb, mod_RayLib, "check_collision_circles", mrb_check_collision_circles, MRB_ARGS_REQ(6));
	mrb_define_module_function(mrb, mod_RayLib, "check_collision_circles_rec", mrb_check_collision_circles_rec, MRB_ARGS_REQ(7));
	mrb_define_module_function(mrb, mod_RayLib, "check_collision_point_rec", mrb_check_collision_point_rec, MRB_ARGS_REQ(6));
	mrb_define_module_function(mrb, mod_RayLib, "check_collision_point_circle", mrb_check_collision_point_circle, MRB_ARGS_REQ(5));

}

void
mrb_raylib_module_shapes_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
