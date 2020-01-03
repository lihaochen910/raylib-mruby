#include "wave_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Wave struct
//================================================================//

static struct RClass *class_Wave;

typedef struct mrb_raylib_wave_data_t {
	Wave wave;
} mrb_raylib_wave_data_t;

static void
mrb_raylib_wave_data_free ( mrb_state *mrb, void *p ) {
	mrb_raylib_wave_data_t *data = ( mrb_raylib_wave_data_t * ) p;
	if ( NULL != data ) {
		mrb_free ( mrb, data );
	}
}

static struct mrb_data_type const mrb_raylib_wave_data_type = {
		"Wave", mrb_raylib_wave_data_free
};

mrb_value
mrb_raylib_wave ( mrb_state *mrb, Wave *wave, bool is_associated ) {
	mrb_raylib_wave_data_t *data =
			( mrb_raylib_wave_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_wave_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	data->wave = * wave;
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Wave, & mrb_raylib_wave_data_type, data ) );
}

mrb_value
mrb_raylib_wave_direct ( mrb_state *mrb, Wave const *wave ) {
	mrb_raylib_wave_data_t *data =
			( mrb_raylib_wave_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_wave_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	if ( NULL == wave ) {

	} else {
		data->wave = * wave;
	}
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Wave, & mrb_raylib_wave_data_type, data ) );
}

Wave *
mrb_raylib_wave_get_ptr ( mrb_state *mrb, mrb_value wave ) {
	mrb_raylib_wave_data_t *data;
	if ( mrb_nil_p( wave ) ) {
		return NULL;
	}
	data =
			( mrb_raylib_wave_data_t * ) mrb_data_get_ptr ( mrb, wave, & mrb_raylib_wave_data_type );
	return & data->wave;
}


static mrb_value
mrb_raylib_wave_initialize ( mrb_state *mrb, mrb_value self ) {
	mrb_raylib_wave_data_t *data = DATA_PTR( self );

	if ( NULL == data ) {
		data = mrb_malloc ( mrb, sizeof ( mrb_raylib_wave_data_t ) );
		if ( NULL == data ) {
			mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
		}
		//data->wave = { 0 };
	} else {

	}
	Wave wave = { 0 };
	data->wave = wave;
	if ( NULL == & data->wave ) {
		mrb_free ( mrb, data );
	}
	DATA_PTR( self ) = data;
	DATA_TYPE( self ) = & mrb_raylib_wave_data_type;
	return self;
}

static mrb_value
mrb_raylib_wave_get_sample_count ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_wave_get_ptr ( mrb, self )->sampleCount );
}

static mrb_value
mrb_raylib_wave_get_sample_rate ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_wave_get_ptr ( mrb, self )->sampleRate );
}

static mrb_value
mrb_raylib_wave_get_sample_size ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_wave_get_ptr ( mrb, self )->sampleSize );
}

static mrb_value
mrb_raylib_wave_get_channels ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_wave_get_ptr ( mrb, self )->channels );
}


void
mrb_raylib_wave_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	class_Wave = mrb_define_class_under ( mrb, mod_RayLib, "Wave", mrb->object_class );

	MRB_SET_INSTANCE_TT( class_Wave, MRB_TT_DATA );

	mrb_define_method ( mrb, class_Wave, "initialize", mrb_raylib_wave_initialize, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Wave, "sample_count", mrb_raylib_wave_get_sample_count, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Wave, "sample_rate", mrb_raylib_wave_get_sample_rate, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Wave, "sample_size", mrb_raylib_wave_get_sample_size, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Wave, "channels", mrb_raylib_wave_get_channels, MRB_ARGS_NONE() );
}

void
mrb_raylib_wave_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
