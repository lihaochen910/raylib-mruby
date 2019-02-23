#ifdef RAYLIB_MUSIC

#include "music_wrapper.h"
#include "audiostream_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Music struct
//================================================================//

static struct RClass* class_Music;

typedef struct mrb_raylib_music_data_t {
	Music	music;
} mrb_raylib_music_data_t;

static void
mrb_raylib_music_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_music_data_t* data = (mrb_raylib_music_data_t*)p;
	if (NULL != data) {
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_music_data_type = {
  "Music", mrb_raylib_music_data_free
};

mrb_value
mrb_raylib_music(mrb_state* mrb, Music music, bool is_associated)
{
	mrb_raylib_music_data_t* data =
		(mrb_raylib_music_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_music_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->music = music;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Music, &mrb_raylib_music_data_type, data));
}

mrb_value
mrb_raylib_music_direct(mrb_state* mrb, Music const music)
{
	mrb_raylib_music_data_t* data =
		(mrb_raylib_music_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_music_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == music) {

	}
	else {
		data->music = music;
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_Music, &mrb_raylib_music_data_type, data));
}

Music
mrb_raylib_music_get_ptr(mrb_state* mrb, mrb_value music)
{
	mrb_raylib_music_data_t *data;
	if (mrb_nil_p(music)) {
		return NULL;
	}
	data =
		(mrb_raylib_music_data_t*)mrb_data_get_ptr(mrb, music, &mrb_raylib_music_data_type);
	return data->music;
}


static mrb_value
mrb_raylib_music_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_music_data_t* data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_music_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->music = { 0 };
	}
	else {

	}
	Music music = { 0 };
	data->music = music;
	if (NULL == &data->music) {
		mrb_free(mrb, data);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_music_data_type;
	return self;
}

static mrb_value
mrb_raylib_music_get_ctx_type(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_music_get_ptr(mrb, self)->ctxType);
}

static mrb_value
mrb_raylib_music_get_stream(mrb_state *mrb, mrb_value self)
{
	return mrb_raylib_audiostream_direct(mrb, &mrb_raylib_music_get_ptr(mrb, self)->stream);
}

static mrb_value
mrb_raylib_music_get_loop_count(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_music_get_ptr(mrb, self)->loopCount);
}

static mrb_value
mrb_raylib_music_get_total_samples(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_music_get_ptr(mrb, self)->totalSamples);
}

static mrb_value
mrb_raylib_music_get_samples_left(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_music_get_ptr(mrb, self)->samplesLeft);
}


void
mrb_raylib_music_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_Music = mrb_define_class_under(mrb, mod_RayLib, "Music", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_Music, MRB_TT_DATA);

	mrb_define_method(mrb, class_Music, "initialize", mrb_raylib_music_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Music, "ctx_type", mrb_raylib_music_get_ctx_type, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Music, "stream", mrb_raylib_music_get_stream, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Music, "loop_count", mrb_raylib_music_get_loop_count, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Music, "total_samples", mrb_raylib_music_get_total_samples, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_Music, "samples_left", mrb_raylib_music_get_samples_left, MRB_ARGS_NONE());

	int arena_size = mrb_gc_arena_save(mrb);
	mrb_define_const(mrb, class_Music, "MUSIC_AUDIO_OGG", mrb_fixnum_value(0));
	mrb_define_const(mrb, class_Music, "MUSIC_AUDIO_FLAC", mrb_fixnum_value(1));
	mrb_define_const(mrb, class_Music, "MUSIC_AUDIO_MP3", mrb_fixnum_value(2));
	mrb_define_const(mrb, class_Music, "MUSIC_MODULE_XM", mrb_fixnum_value(3));
	mrb_define_const(mrb, class_Music, "MUSIC_MODULE_MOD", mrb_fixnum_value(4));
	mrb_gc_arena_restore(mrb, arena_size);
}

void
mrb_raylib_music_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}

#endif