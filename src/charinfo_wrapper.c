#include "charinfo_wrapper.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mruby/variable.h"

//================================================================//
// CharInfo struct
//================================================================//

static struct RClass* class_CharInfo;

typedef struct mrb_raylib_charinfo_data_t {
	CharInfo	charinfo;
} mrb_raylib_charinfo_data_t;

static void
mrb_raylib_charinfo_data_free(mrb_state *mrb, void *p)
{
	mrb_raylib_charinfo_data_t* data = (mrb_raylib_charinfo_data_t*)p;
	if (NULL != data) {
		mrb_free(mrb, data);
	}
}

static struct mrb_data_type const mrb_raylib_charinfo_data_type = {
  "CharInfo", mrb_raylib_charinfo_data_free
};

mrb_value
mrb_raylib_charinfo(mrb_state* mrb, CharInfo* charinfo, bool is_associated)
{
	mrb_raylib_charinfo_data_t* data =
		(mrb_raylib_charinfo_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_charinfo_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	data->charinfo = *charinfo;
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_CharInfo, &mrb_raylib_charinfo_data_type, data));
}

mrb_value
mrb_raylib_charinfo_direct(mrb_state* mrb, CharInfo const* charinfo)
{
	mrb_raylib_charinfo_data_t* data =
		(mrb_raylib_charinfo_data_t*)mrb_malloc(mrb, sizeof(mrb_raylib_charinfo_data_t));
	if (NULL == data) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
	}
	if (NULL == charinfo) {

	}
	else {
		data->charinfo = *charinfo;
	}
	return mrb_obj_value(Data_Wrap_Struct(mrb, class_CharInfo, &mrb_raylib_charinfo_data_type, data));
}

CharInfo*
mrb_raylib_charinfo_get_ptr(mrb_state* mrb, mrb_value charinfo)
{
	mrb_raylib_charinfo_data_t *data;
	if (mrb_nil_p(charinfo)) {
		return NULL;
	}
	data =
		(mrb_raylib_charinfo_data_t*)mrb_data_get_ptr(mrb, charinfo, &mrb_raylib_charinfo_data_type);
	return &data->charinfo;
}


static mrb_value
mrb_raylib_charinfo_initialize(mrb_state *mrb, mrb_value self)
{
	mrb_raylib_charinfo_data_t *data = DATA_PTR(self);

	if (NULL == data) {
		data = mrb_malloc(mrb, sizeof(mrb_raylib_charinfo_data_t));
		if (NULL == data) {
			mrb_raise(mrb, E_RUNTIME_ERROR, "insufficient memory.");
		}
		//data->charinfo = { 0 };
	}
	else {

	}
	CharInfo charinfo = { 0 };
	data->charinfo = charinfo;
	if (NULL == &data->charinfo) {
		mrb_free(mrb, data);
	}
	DATA_PTR(self) = data;
	DATA_TYPE(self) = &mrb_raylib_charinfo_data_type;
	return self;
}

static mrb_value
mrb_raylib_charinfo_value(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_charinfo_get_ptr(mrb, self)->value);
}

static mrb_value
mrb_raylib_charinfo_offset_x(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_charinfo_get_ptr(mrb, self)->offsetX);
}

static mrb_value
mrb_raylib_charinfo_offset_y(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_charinfo_get_ptr(mrb, self)->offsetY);
}

static mrb_value
mrb_raylib_charinfo_advance_x(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(mrb_raylib_charinfo_get_ptr(mrb, self)->advanceX);
}


void
mrb_raylib_charinfo_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	class_CharInfo = mrb_define_class_under(mrb, mod_RayLib, "CharInfo", mrb->object_class);

	MRB_SET_INSTANCE_TT(class_CharInfo, MRB_TT_DATA);

	mrb_define_method(mrb, class_CharInfo, "initialize", mrb_raylib_charinfo_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_CharInfo, "value", mrb_raylib_charinfo_value, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_CharInfo, "offsetX", mrb_raylib_charinfo_offset_x, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_CharInfo, "offsetY", mrb_raylib_charinfo_offset_y, MRB_ARGS_NONE());
	mrb_define_method(mrb, class_CharInfo, "advanceX", mrb_raylib_charinfo_advance_x, MRB_ARGS_NONE());
}

void
mrb_raylib_charinfo_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
