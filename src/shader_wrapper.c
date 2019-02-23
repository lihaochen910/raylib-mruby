#include "shader_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"

//================================================================//
// Shader struct
//================================================================//

static struct RClass* class_Shader;

typedef struct mrb_raylib_shader_data_t {
	Shader	shader;
} mrb_raylib_shader_data_t;

static void
mrb_raylib_shader_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_shader_data_t* data = (mrb_raylib_shader_data_t*)p;
	if (NULL != data) {
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_shader_data_type = {
  "Shader", mrb_raylib_shader_data_free
};

mrb_value
mrb_raylib_shader(mrb_state* mrb, Shader* shader, bool is_associated)
{
	mrb_raylib_shader_data_t* data =
		(mrb_raylib_shader_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_shader_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->shader = *shader;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Shader, &mrb_raylib_shader_data_type, data));
}

mrb_value
mrb_raylib_shader_direct(mrb_state* mrb, Shader const* shader)
{
	mrb_raylib_shader_data_t* data =
		(mrb_raylib_shader_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_shader_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == shader) {

	}
	else {
		data->shader = *shader;
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Shader, &mrb_raylib_shader_data_type, data));
}

Shader*
mrb_raylib_shader_get_ptr(mrb_state* mrb, mrb_value shader)
{
	mrb_raylib_shader_data_t *data;
	if (mrb_nil_p(shader)) {
		return NULL;
	}
	data =
		(mrb_raylib_shader_data_t*)mrb_data_get_ptr(mrb, shader, &mrb_raylib_shader_data_type);
	return &data->shader;
}


static mrb_value
mrb_raylib_shader_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_shader_data_t *data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_shader_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->shader = { 0 };
	}
	else {

	}
	Shader shader = { 0 };
	data->shader = shader;
	if (NULL == &data->shader) {
		mrb_free(mrb, data);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_shader_data_type;
	return self;
}

static mrb_value
mrb_raylib_shader_get_id(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_shader_get_ptr(mrb, self)->id);
}


void
mrb_raylib_shader_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_Shader = mrb_define_class_under(mrb, mod_RayLib, "Shader", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_Shader, MRB_TT_DATA);

	mrb_define_method(mrb, class_Shader, "initialize", mrb_raylib_shader_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Shader, "id", mrb_raylib_shader_get_id, MRB_ARGS_NONE());
}

void
mrb_raylib_shader_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
