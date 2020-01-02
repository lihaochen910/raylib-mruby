#include "sound_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Sound struct
//================================================================//

static struct RClass* class_Sound;

typedef struct mrb_raylib_sound_data_t {
	Sound	sound;
} mrb_raylib_sound_data_t;

static void
mrb_raylib_sound_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_sound_data_t* data = (mrb_raylib_sound_data_t*)p;
	if (NULL != data) {
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_sound_data_type = {
  "Sound", mrb_raylib_sound_data_free
};

mrb_value
mrb_raylib_sound(mrb_state* mrb, Sound* sound, bool is_associated)
{
	mrb_raylib_sound_data_t* data =
		(mrb_raylib_sound_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_sound_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->sound = *sound;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Sound, &mrb_raylib_sound_data_type, data));
}

mrb_value
mrb_raylib_sound_direct(mrb_state* mrb, Sound const* sound)
{
	mrb_raylib_sound_data_t* data =
		(mrb_raylib_sound_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_sound_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == sound) {

	}
	else {
		data->sound = *sound;
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Sound, &mrb_raylib_sound_data_type, data));
}

Sound*
mrb_raylib_sound_get_ptr(mrb_state* mrb, mrb_value sound)
{
	mrb_raylib_sound_data_t *data;
	if (mrb_nil_p(sound)) {
		return NULL;
	}
	data =
		(mrb_raylib_sound_data_t*)mrb_data_get_ptr(mrb, sound, &mrb_raylib_sound_data_type);
	return &data->sound;
}


static mrb_value
mrb_raylib_sound_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_sound_data_t* data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_sound_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->sound = { 0 };
	}
	else {

	}
	Sound sound = { 0 };
	data->sound = sound;
	if (NULL == &data->sound) {
		mrb_free(mrb, data);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_sound_data_type;
	return self;
}

//static mrb_value
//mrb_raylib_sound_get_source(mrb_state *mrb, mrb_value self)
//{
//	return mrb_fixnum_value(mrb_raylib_sound_get_ptr(mrb, self)->source);
//}
//
//static mrb_value
//mrb_raylib_sound_get_buffer(mrb_state *mrb, mrb_value self)
//{
//	return mrb_fixnum_value(mrb_raylib_sound_get_ptr(mrb, self)->buffer);
//}
//
//static mrb_value
//mrb_raylib_sound_get_format(mrb_state *mrb, mrb_value self)
//{
//	return mrb_fixnum_value(mrb_raylib_sound_get_ptr(mrb, self)->format);
//}


void
mrb_raylib_sound_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_Sound = mrb_define_class_under(mrb, mod_RayLib, "Sound", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_Sound, MRB_TT_DATA);

	mrb_define_method(mrb, class_Sound, "initialize", mrb_raylib_sound_initialize, MRB_ARGS_NONE());
//	mrb_define_method(mrb, class_Sound, "source", mrb_raylib_sound_get_source, MRB_ARGS_NONE());
//	mrb_define_method(mrb, class_Sound, "buffer", mrb_raylib_sound_get_buffer, MRB_ARGS_NONE());
//	mrb_define_method(mrb, class_Sound, "format", mrb_raylib_sound_get_format, MRB_ARGS_NONE());
}

void
mrb_raylib_sound_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
