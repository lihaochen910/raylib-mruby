#include "glyphinfo_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// GlyphInfo struct
//================================================================//

static struct RClass *class_GlyphInfo;

typedef struct mrb_raylib_glyphinfo_data_t {
	GlyphInfo glyphinfo;
} mrb_raylib_glyphinfo_data_t;

static void
mrb_raylib_glyphinfo_data_free ( mrb_state *mrb, void *p ) {
	mrb_raylib_glyphinfo_data_t *data = ( mrb_raylib_glyphinfo_data_t * ) p;
	if ( NULL != data ) {
		mrb_free ( mrb, data );
	}
}

static struct mrb_data_type const mrb_raylib_glyphinfo_data_type = {
		"GlyphInfo", mrb_raylib_glyphinfo_data_free
};

mrb_value
mrb_raylib_glyphinfo ( mrb_state *mrb, GlyphInfo *glyphinfo, bool is_associated ) {
	mrb_raylib_glyphinfo_data_t *data =
			( mrb_raylib_glyphinfo_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_glyphinfo_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	data->glyphinfo = * glyphinfo;
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_GlyphInfo, & mrb_raylib_glyphinfo_data_type, data ) );
}

mrb_value
mrb_raylib_glyphinfo_direct ( mrb_state *mrb, GlyphInfo const *glyphinfo ) {
	mrb_raylib_glyphinfo_data_t *data =
			( mrb_raylib_glyphinfo_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_glyphinfo_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	if ( NULL == glyphinfo ) {

	} else {
		data->glyphinfo = * glyphinfo;
	}
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_GlyphInfo, & mrb_raylib_glyphinfo_data_type, data ) );
}

GlyphInfo *
mrb_raylib_glyphinfo_get_ptr ( mrb_state *mrb, mrb_value glyphinfo ) {
	mrb_raylib_glyphinfo_data_t *data;
	if ( mrb_nil_p( glyphinfo ) ) {
		return NULL;
	}
	data =
			( mrb_raylib_glyphinfo_data_t * ) mrb_data_get_ptr ( mrb, glyphinfo, & mrb_raylib_glyphinfo_data_type );
	return & data->glyphinfo;
}


static mrb_value
mrb_raylib_glyphinfo_initialize ( mrb_state *mrb, mrb_value self ) {
	mrb_raylib_glyphinfo_data_t *data = DATA_PTR( self );

	if ( NULL == data ) {
		data = mrb_malloc ( mrb, sizeof ( mrb_raylib_glyphinfo_data_t ) );
		if ( NULL == data ) {
			mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
		}
		//data->glyphinfo = { 0 };
	} else {

	}
	GlyphInfo glyphinfo = { 0 };
	data->glyphinfo = glyphinfo;
	if ( NULL == & data->glyphinfo ) {
		mrb_free ( mrb, data );
	}
	DATA_PTR( self ) = data;
	DATA_TYPE( self ) = & mrb_raylib_glyphinfo_data_type;
	return self;
}

static mrb_value
mrb_raylib_glyphinfo_value ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_glyphinfo_get_ptr ( mrb, self )->value );
}

static mrb_value
mrb_raylib_glyphinfo_offset_x ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_glyphinfo_get_ptr ( mrb, self )->offsetX );
}

static mrb_value
mrb_raylib_glyphinfo_offset_y ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_glyphinfo_get_ptr ( mrb, self )->offsetY );
}

static mrb_value
mrb_raylib_glyphinfo_advance_x ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_glyphinfo_get_ptr ( mrb, self )->advanceX );
}


void
mrb_raylib_glyphinfo_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	class_GlyphInfo = mrb_define_class_under ( mrb, mod_RayLib, "GlyphInfo", mrb->object_class );

	MRB_SET_INSTANCE_TT( class_GlyphInfo, MRB_TT_DATA );

	mrb_define_method ( mrb, class_GlyphInfo, "initialize", mrb_raylib_glyphinfo_initialize, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_GlyphInfo, "value", mrb_raylib_glyphinfo_value, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_GlyphInfo, "offsetX", mrb_raylib_glyphinfo_offset_x, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_GlyphInfo, "offsetY", mrb_raylib_glyphinfo_offset_y, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_GlyphInfo, "advanceX", mrb_raylib_glyphinfo_advance_x, MRB_ARGS_NONE() );
}

void
mrb_raylib_glyphinfo_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
