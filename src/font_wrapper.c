#include "font_wrapper.h"
#include "texture_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Font struct
//================================================================//

static struct RClass* class_Font;

typedef struct mrb_raylib_font_data_t {
	Font	font;
} mrb_raylib_font_data_t;

static void
mrb_raylib_font_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_font_data_t* data = (mrb_raylib_font_data_t*)p;
	if (NULL != data) {
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_font_data_type = {
  "Font", mrb_raylib_font_data_free
};

mrb_value
mrb_raylib_font(mrb_state* mrb, Font* font, bool is_associated)
{
	mrb_raylib_font_data_t* data =
		(mrb_raylib_font_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_font_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->font = *font;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Font, &mrb_raylib_font_data_type, data));
}

mrb_value
mrb_raylib_font_direct(mrb_state* mrb, Font const* font)
{
	mrb_raylib_font_data_t* data =
		(mrb_raylib_font_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_font_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == font) {

	}
	else {
		data->font = *font;
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Font, &mrb_raylib_font_data_type, data));
}

Font*
mrb_raylib_font_get_ptr(mrb_state* mrb, mrb_value font)
{
	mrb_raylib_font_data_t *data;
	if (mrb_nil_p(font)) {
		return NULL;
	}
	data =
		(mrb_raylib_font_data_t*)mrb_data_get_ptr(mrb, font, &mrb_raylib_font_data_type);
	return &data->font;
}


static mrb_value
mrb_raylib_font_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_font_data_t *data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_font_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->font = { 0 };
	}
	else {

	}
	Font font = { 0 };
	data->font = font;
	if (NULL == &data->font) {
		mrb_free(mrb, data);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_font_data_type;
	return self;
}

static mrb_value
mrb_raylib_font_texture(mrb_state *mrb, mrb_value self)
{
	return mrb_raylib_texture_direct(mrb, &mrb_raylib_font_get_ptr(mrb, self)->texture);
}

static mrb_value
mrb_raylib_font_base_size(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_font_get_ptr(mrb, self)->baseSize);
}

static mrb_value
mrb_raylib_font_chars_count(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_font_get_ptr(mrb, self)->charsCount);
}


void
mrb_raylib_font_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_Font = mrb_define_class_under(mrb, mod_RayLib, "Font", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_Font, MRB_TT_DATA);

	mrb_define_method(mrb, class_Font, "initialize", mrb_raylib_font_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Font, "texture", mrb_raylib_font_texture, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Font, "base_size", mrb_raylib_font_base_size, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Font, "chars_count", mrb_raylib_font_chars_count, MRB_ARGS_NONE());
}

void
mrb_raylib_font_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
