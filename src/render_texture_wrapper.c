#include "image_wrapper.h"
#include "texture_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Texture struct
//================================================================//

static struct RClass* class_RenderTexture;

typedef struct mrb_raylib_render_texture_data_t {
	bool				is_associated;
	RenderTexture		render_texture;
} mrb_raylib_render_texture_data_t;

static void
mrb_raylib_render_texture_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_render_texture_data_t* data = (mrb_raylib_render_texture_data_t*)p;
	if (NULL != data) {
		/*if ((NULL != data->render_texture) && (false == data->is_associated)) {

		}*/
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_render_texture_data_type = {
  "RenderTexture", mrb_raylib_render_texture_data_free
};

mrb_value
mrb_raylib_render_texture(mrb_state* mrb, RenderTexture* render_texture, bool is_associated)
{
	mrb_raylib_render_texture_data_t* data =
		(mrb_raylib_render_texture_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_render_texture_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->is_associated = is_associated;
	data->render_texture = *render_texture;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_RenderTexture, &mrb_raylib_render_texture_data_type, data));
}

mrb_value
mrb_raylib_render_texture_direct(mrb_state *mrb, RenderTexture const* render_texture)
{
	mrb_raylib_render_texture_data_t* data =
		(mrb_raylib_render_texture_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_render_texture_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == render_texture) {
		//data->render_texture->id = NULL;
	}
	else {
		data->render_texture = *render_texture;
		/*data->render_texture->id = render_texture->id;
		data->render_texture->texture = render_texture->texture;
		data->render_texture->depth = render_texture->depth;*/
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_RenderTexture, &mrb_raylib_render_texture_data_type, data));
}

RenderTexture*
mrb_raylib_render_texture_get_ptr(mrb_state* mrb, mrb_value render_texture)
{
	mrb_raylib_render_texture_data_t *data;
	if (mrb_nil_p(render_texture)) {
		return NULL;
	}
	data =
		(mrb_raylib_render_texture_data_t*)mrb_data_get_ptr(mrb, render_texture, &mrb_raylib_render_texture_data_type);
	return &data->render_texture;
}


static mrb_value
mrb_raylib_render_texture_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_render_texture_data_t *data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_render_texture_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->render_texture = NULL;
	}
	else {
		/*if (NULL != data->render_texture) {

		}*/
	}
	RenderTexture render_texture = { 0 };
	data->render_texture = render_texture;
	if (NULL == &data->render_texture) {
		mrb_free(mrb, data);
		//mruby_sdl2_raise_error(mrb);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_render_texture_data_type;
	return self;
}

static mrb_value
mrb_raylib_render_texture_id(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_render_texture_get_ptr(mrb, self)->id);
}

static mrb_value
mrb_raylib_render_texture_get_texture(mrb_state *mrb, mrb_value self)
{
	return mrb_raylib_texture_direct(mrb, &mrb_raylib_render_texture_get_ptr(mrb, self)->texture);
}

static mrb_value
mrb_raylib_render_texture_get_depth(mrb_state *mrb, mrb_value self)
{
	return mrb_raylib_texture_direct(mrb, &mrb_raylib_render_texture_get_ptr(mrb, self)->depth);
}


void
mrb_raylib_render_texture_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_RenderTexture = mrb_define_class_under(mrb, mod_RayLib, "RenderTexture", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_RenderTexture, MRB_TT_DATA);

	mrb_define_method(mrb, class_RenderTexture, "initialize", mrb_raylib_render_texture_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_RenderTexture, "id", mrb_raylib_render_texture_id, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_RenderTexture, "texture", mrb_raylib_render_texture_get_texture, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_RenderTexture, "depth", mrb_raylib_render_texture_get_depth, MRB_ARGS_NONE());
}

void
mrb_raylib_render_texture_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
