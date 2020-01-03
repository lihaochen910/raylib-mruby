#include "image_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// Image struct
//================================================================//

static struct RClass *class_Image;

typedef struct mrb_raylib_image_data_t {
	bool is_associated;
	Image image;
} mrb_raylib_image_data_t;

static void
mrb_raylib_image_data_free ( mrb_state *mrb, void *p ) {
	mrb_raylib_image_data_t *data = ( mrb_raylib_image_data_t * ) p;
	if ( NULL != data ) {
		/*if ((NULL != data->image) && (false == data->is_associated)) {

		}*/
		mrb_free ( mrb, data );
	}
}

static struct mrb_data_type const mrb_raylib_image_data_type = {
		"Image", mrb_raylib_image_data_free
};

mrb_value
mrb_raylib_image ( mrb_state *mrb, Image *image, bool is_associated ) {
	mrb_raylib_image_data_t *data =
			( mrb_raylib_image_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_image_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	data->is_associated = is_associated;
	data->image = * image;
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Image, & mrb_raylib_image_data_type, data ) );
}

mrb_value
mrb_raylib_image_direct ( mrb_state *mrb, Image const *image ) {
	mrb_raylib_image_data_t *data =
			( mrb_raylib_image_data_t * ) mrb_malloc ( mrb, sizeof ( mrb_raylib_image_data_t ) );
	if ( NULL == data ) {
		mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
	}
	if ( NULL == image ) {
		/*data->image->data = NULL;
		data->image->width = 0;
		data->image->height = 0;
		data->image->mipmaps = 0;
		data->image->format = 0;*/
	} else {
		data->image = * image;
		/*data->image->data = image->data;
		data->image->width = image->width;
		data->image->height = image->height;
		data->image->mipmaps = image->mipmaps;
		data->image->format = image->format;*/
	}
	return mrb_obj_value ( Data_Wrap_Struct( mrb, class_Image, & mrb_raylib_image_data_type, data ) );
}

Image *
mrb_raylib_image_get_ptr ( mrb_state *mrb, mrb_value image ) {
	mrb_raylib_image_data_t *data;
	if ( mrb_nil_p( image ) ) {
		return NULL;
	}
	data =
			( mrb_raylib_image_data_t * ) mrb_data_get_ptr ( mrb, image, & mrb_raylib_image_data_type );
	return & data->image;
}


static mrb_value
mrb_raylib_image_initialize ( mrb_state *mrb, mrb_value self ) {
	mrb_raylib_image_data_t *data = DATA_PTR( self );

	if ( NULL == data ) {
		data = mrb_malloc ( mrb, sizeof ( mrb_raylib_image_data_t ) );
		if ( NULL == data ) {
			mrb_raise ( mrb, E_RUNTIME_ERROR, "insufficient memory." );
		}
		//data->image = { 0 };
	} else {
		if ( NULL != & data->image ) {

		}
	}
	Image image = { 0 };
	data->image = image;
	if ( NULL == & data->image ) {
		mrb_free ( mrb, data );
		//mruby_sdl2_raise_error(mrb);
	}
	DATA_PTR( self ) = data;
	DATA_TYPE( self ) = & mrb_raylib_image_data_type;
	return self;
}

static mrb_value
mrb_raylib_image_width ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_image_get_ptr ( mrb, self )->width );
}

static mrb_value
mrb_raylib_image_height ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_image_get_ptr ( mrb, self )->height );
}

static mrb_value
mrb_raylib_image_mipmaps ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_image_get_ptr ( mrb, self )->mipmaps );
}

static mrb_value
mrb_raylib_image_format ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( mrb_raylib_image_get_ptr ( mrb, self )->format );
}


void
mrb_raylib_image_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {
	class_Image = mrb_define_class_under ( mrb, mod_RayLib, "Image", mrb->object_class );

	MRB_SET_INSTANCE_TT( class_Image, MRB_TT_DATA );

	mrb_define_method ( mrb, class_Image, "initialize", mrb_raylib_image_initialize, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Image, "width", mrb_raylib_image_width, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Image, "height", mrb_raylib_image_width, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Image, "mipmaps", mrb_raylib_image_mipmaps, MRB_ARGS_NONE() );
	mrb_define_method ( mrb, class_Image, "format", mrb_raylib_image_format, MRB_ARGS_NONE() );
}

void
mrb_raylib_image_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
