#include "image_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Texture struct
//================================================================//

static struct RClass *class_Texture;

typedef struct mrb_raylib_texture_data_t {
	bool is_associated;
	Texture texture;
} mrb_raylib_texture_data_t;

static void
mrb_raylib_texture_data_free ( mrb_state *mrb, void *p ) {
	mrb_raylib_texture_data_t *data = ( mrb_raylib_texture_data_t * ) p;
	if ( NULL != data ) {
		/*if ((NULL != &data->texture) && (false == data->is_associated)) {

		}*/
		mrb_free ( mrb, data );
	}
}

static struct mrb_data_type const mrb_raylib_texture_data_type = {
		"Texture", mrb_raylib_texture_data_free
};

mrb_value
mrb_raylib_texture ( mrb_state *mrb, Texture *texture, bool is_associated ) {
	mrb_raylib_texture_data_t *data =
			( mrb_raylib_texture_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_texture_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	data->is_associated = is_associated;
	data->texture = * texture;
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Texture, & mrb_raylib_texture_data_type, data ) );
}

mrb_value
mrb_raylib_texture_direct ( mrb_state *mrb, Texture const *texture ) {
	mrb_raylib_texture_data_t *data =
			( mrb_raylib_texture_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_texture_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	if ( NULL == texture ) {
		Texture null_texture = { 0 };
		data->texture = null_texture;
		//data->texture->id = NULL;
		//data->texture->width = 0;
		//data->texture->height = 0;
	} else {
		data->texture = * texture;
		data->is_associated = true;
	}
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Texture, & mrb_raylib_texture_data_type, data ) );
}

Texture *
mrb_raylib_texture_get_ptr ( mrb_state *mrb, mrb_value texture ) {
	mrb_raylib_texture_data_t *data;
	if ( mrb_nil_p( texture ) ) {
		return NULL;
	}
	data =
			( mrb_raylib_texture_data_t * ) mrb_data_get_ptr ( mrb, texture, & mrb_raylib_texture_data_type );
	return & data->texture;
}


static mrb_value
mrb_raylib_texture_initialize ( mrb_state *mrb, mrb_value self ) {
	mrb_raylib_texture_data_t *data = DATA_PTR( self );

	if ( NULL == data ) {
		data = mrb_malloc ( mrb, sizeof ( mrb_raylib_texture_data_t ) );
		if ( NULL == data ) {
			mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
		}
		//&data->texture = NULL;
	} else {
		if ( NULL != & data->texture ) {

		}
	}
	Texture texture = { 0 };
	data->texture = texture;
	//if (NULL == &data->texture) {
	//	mrb_free(mrb, data);
	//	//mruby_sdl2_raise_error(mrb);
	//}
	DATA_PTR( self ) = data;
	DATA_TYPE( self ) = & mrb_raylib_texture_data_type;
	return self;
}

static mrb_value
mrb_raylib_texture_id ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_texture_get_ptr ( mrb, self )->id );
}

static mrb_value
mrb_raylib_texture_width ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_texture_get_ptr ( mrb, self )->width );
}

static mrb_value
mrb_raylib_texture_height ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_texture_get_ptr ( mrb, self )->height );
}

static mrb_value
mrb_raylib_texture_mipmaps ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_texture_get_ptr ( mrb, self )->mipmaps );
}

static mrb_value
mrb_raylib_texture_format ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_texture_get_ptr ( mrb, self )->format );
}


void
mrb_raylib_texture_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	class_Texture = mrb_define_class_under ( mrb, mod_RayLib, "Texture", mrb->object_class );
	mrb_define_class_under ( mrb, mod_RayLib, "Texture2D", class_Texture );

	MRB_SET_INSTANCE_TT( class_Texture, MRB_TT_DATA );

	mrb_define_method ( mrb, class_Texture, "initialize", mrb_raylib_texture_initialize, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Texture, "id", mrb_raylib_texture_id, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Texture, "width", mrb_raylib_texture_width, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Texture, "height", mrb_raylib_texture_height, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Texture, "mipmaps", mrb_raylib_texture_mipmaps, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Texture, "format", mrb_raylib_texture_format, MRB_ARGS_NONE() );
}

void
mrb_raylib_texture_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
