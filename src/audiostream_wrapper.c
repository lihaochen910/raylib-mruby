#include "audiostream_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// AudioStream struct
//================================================================//

static struct RClass *class_AudioStream;

typedef struct mrb_raylib_audiostream_data_t {
	AudioStream audiostream;
} mrb_raylib_audiostream_data_t;

static void
mrb_raylib_audiostream_data_free ( mrb_state *mrb, void *p ) {
	mrb_raylib_audiostream_data_t *data = (mrb_raylib_audiostream_data_t *) p;
	if ( NULL != data ) {
		mrb_free ( mrb, data );
	}
}

static struct mrb_data_type const mrb_raylib_audiostream_data_type = {
		"AudioStream", mrb_raylib_audiostream_data_free
};

mrb_value
mrb_raylib_audiostream ( mrb_state *mrb, AudioStream *audiostream, bool is_associated ) {
	mrb_raylib_audiostream_data_t *data =
			(mrb_raylib_audiostream_data_t *) mrb_malloc ( mrb, sizeof ( mrb_raylib_audiostream_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	data->audiostream = *audiostream;
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_AudioStream, &mrb_raylib_audiostream_data_type, data ) );
}

mrb_value
mrb_raylib_audiostream_direct ( mrb_state *mrb, AudioStream const *audiostream ) {
	mrb_raylib_audiostream_data_t *data =
			(mrb_raylib_audiostream_data_t *) mrb_malloc ( mrb, sizeof ( mrb_raylib_audiostream_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	if ( NULL == audiostream ) {

	} else {
		data->audiostream = *audiostream;
	}
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_AudioStream, &mrb_raylib_audiostream_data_type, data ) );
}

AudioStream *
mrb_raylib_audiostream_get_ptr ( mrb_state *mrb, mrb_value audiostream ) {
	mrb_raylib_audiostream_data_t *data;
	if ( mrb_nil_p( audiostream ) ) {
		return NULL;
	}
	data =
			(mrb_raylib_audiostream_data_t *) mrb_data_get_ptr ( mrb, audiostream, &mrb_raylib_audiostream_data_type );
	return &data->audiostream;
}


static mrb_value
mrb_raylib_audiostream_initialize ( mrb_state *mrb, mrb_value self ) {
	mrb_raylib_audiostream_data_t *data = DATA_PTR( self );

	if ( NULL == data ) {
		data = mrb_malloc ( mrb, sizeof ( mrb_raylib_audiostream_data_t ) );
		if ( NULL == data ) {
			mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
		}
		//data->audiostream = { 0 };
	} else {

	}
	AudioStream audiostream = { 0 };
	data->audiostream = audiostream;
	if ( NULL == &data->audiostream ) {
		mrb_free ( mrb, data );
	}
	DATA_PTR( self ) = data;
	DATA_TYPE( self ) = &mrb_raylib_audiostream_data_type;
	return self;
}

static mrb_value
mrb_raylib_audiostream_get_sample_rate ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_audiostream_get_ptr ( mrb, self )->sampleRate );
}

static mrb_value
mrb_raylib_audiostream_get_sample_size ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_audiostream_get_ptr ( mrb, self )->sampleSize );
}

static mrb_value
mrb_raylib_audiostream_get_channels ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_audiostream_get_ptr ( mrb, self )->channels );
}

//static mrb_value
//mrb_raylib_audiostream_get_format(mrb_state *mrb, mrb_value self)
//{
//	return mrb_fixnum_value(mrb_raylib_audiostream_get_ptr(mrb, self)->format);
//}

//static mrb_value
//mrb_raylib_audiostream_get_source(mrb_state *mrb, mrb_value self)
//{
//	return mrb_fixnum_value(mrb_raylib_audiostream_get_ptr(mrb, self)->source);
//}


void
mrb_raylib_audiostream_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	class_AudioStream = mrb_define_class_under ( mrb, mod_RayLib, "AudioStream", mrb->object_class );

	MRB_SET_INSTANCE_TT( class_AudioStream, MRB_TT_DATA );

	mrb_define_method ( mrb, class_AudioStream, "initialize", mrb_raylib_audiostream_initialize, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_AudioStream, "sample_rate", mrb_raylib_audiostream_get_sample_rate, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_AudioStream, "sample_size", mrb_raylib_audiostream_get_sample_size, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_AudioStream, "channels", mrb_raylib_audiostream_get_channels, MRB_ARGS_NONE() );
//	mrb_define_method(mrb, class_AudioStream, "format", mrb_raylib_audiostream_get_format, MRB_ARGS_NONE());
//	mrb_define_method(mrb, class_AudioStream, "source", mrb_raylib_audiostream_get_source, MRB_ARGS_NONE());
}

void
mrb_raylib_audiostream_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
