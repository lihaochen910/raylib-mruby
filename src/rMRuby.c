#include "rMRuby.h"

#include "image_wrapper.h"
#include "texture_wrapper.h"
#include "render_texture_wrapper.h"
#include "charinfo_wrapper.h"
#include "font_wrapper.h"
#include "wave_wrapper.h"
#include "sound_wrapper.h"
#include "audiostream_wrapper.h"
#include "music_wrapper.h"
#include "shader_wrapper.h"

#include "module_shapes_wrapper.h"
#include "module_texture_wrapper.h"
#include "module_text_wrapper.h"
#include "module_models_wrapper.h"
#include "module_audio_wrapper.h"

//#include "vector2.h"

void
mrb_raylib_module_init(mrb_state *mrb)
{
	mod_RayLib = mrb_define_module(mrb, "RayLib");
	class_RayLibError = mrb_define_class_under(mrb, mod_RayLib, "RayLibError", mrb->eStandardError_class);

	mrb_raylib_gem_init(mrb);

	//================================================================//
	// module: core
	//================================================================//
	mrb_define_module_function(mrb, mod_RayLib, "init_window", mrb_init_window, MRB_ARGS_REQ(3));
	mrb_define_module_function(mrb, mod_RayLib, "close_window", mrb_close_window, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "is_window_ready", mrb_is_window_ready, MRB_ARGS_NONE(1));
	mrb_define_module_function(mrb, mod_RayLib, "window_should_close", mrb_window_should_close, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "is_window_minimized", mrb_is_window_minimized, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "toggle_fullscreen", mrb_toggle_fullscreen, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "set_window_title", mrb_set_window_title, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "set_window_position", mrb_set_window_position, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "set_window_monitor", mrb_set_window_monitor, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "set_window_min_size", mrb_set_window_min_size, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "set_window_size", mrb_set_window_size, MRB_ARGS_REQ(2));

	mrb_define_module_function(mrb, mod_RayLib, "show_cursor", mrb_show_cursor, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "hide_cursor", mrb_hide_cursor, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "is_cursor_hidden", mrb_is_cursor_hidden, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "enable_cursor", mrb_enable_cursor, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "disable_cursor", mrb_disable_cursor, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "clear_background", mrb_clear_background, MRB_ARGS_REQ(4));
	mrb_define_module_function(mrb, mod_RayLib, "begin_drawing", mrb_begin_drawing, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "end_drawing", mrb_end_drawing, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "set_target_fps", mrb_set_target_fps, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_fps", mrb_get_fps, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_frame_time", mrb_get_frame_time, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_time", mrb_get_time, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "show_logo", mrb_show_logo, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "trace_log", mrb_trace_log, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "take_screen_shot", mrb_take_screen_shot, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_random_value", mrb_get_random_value, MRB_ARGS_REQ(2));

	mrb_define_module_function(mrb, mod_RayLib, "is_key_pressed", mrb_is_key_pressed, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_key_down", mrb_is_key_down, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_key_released", mrb_is_key_released, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_key_up", mrb_is_key_up, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_key_pressed", mrb_get_key_pressed, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "set_exit_key", mrb_set_exit_key, MRB_ARGS_REQ(1));

	mrb_define_module_function(mrb, mod_RayLib, "is_gamepad_available", mrb_is_gamepad_available, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_gamepad_name", mrb_is_gamepad_name, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "get_gamepad_name", mrb_get_gamepad_name, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_gamepad_pressed", mrb_is_gamepad_pressed, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "is_gamepad_down", mrb_is_gamepad_down, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "is_gamepad_released", mrb_is_gamepad_released, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "get_gamepad_button_pressed", mrb_get_gamepad_button_pressed, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gamepad_axis_count", mrb_get_gamepad_axis_count, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_gamepad_axis_movement", mrb_get_gamepad_axis_movement, MRB_ARGS_REQ(2));

	mrb_define_module_function(mrb, mod_RayLib, "is_mouse_button_pressed", mrb_is_mouse_button_pressed, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_mouse_button_down", mrb_is_mouse_button_down, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_mouse_button_released", mrb_is_mouse_button_released, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_mouse_button_up", mrb_is_mouse_button_up, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_mouse_X", mrb_get_mouse_X, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_mouse_Y", mrb_get_mouse_Y, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_mouse_position", mrb_get_mouse_position, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "set_mouse_position", mrb_set_mouse_position, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "get_mouse_wheel_move", mrb_get_mouse_wheel_move, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "get_touch_X", mrb_get_touch_X, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_touch_Y", mrb_get_touch_Y, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, mod_RayLib, "gestures_enabled", mrb_gestures_enabled, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_gestures_detected", mrb_is_gestures_detected, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_gestures_detected", mrb_get_gestures_detected, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_touch_points_count", mrb_get_touch_points_count, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gesture_hold_duration", mrb_get_gesture_hold_duration, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gesture_drag_vector", mrb_get_gesture_drag_vector, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gesture_drag_angle", mrb_get_gesture_drag_angle, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gesture_pinch_vector", mrb_get_gesture_pinch_vector, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "get_gesture_pinch_angle", mrb_get_gesture_pinch_angle, MRB_ARGS_NONE());


	//================================================================//
	// module: shapes
	//================================================================//
	mrb_raylib_module_shapes_init(mrb, mod_RayLib);


	//================================================================//
	// module: textures
	//================================================================//
	mrb_raylib_module_texture_init(mrb, mod_RayLib);


	//================================================================//
	// module: text
	//================================================================//
	mrb_raylib_module_text_init(mrb, mod_RayLib);


	//================================================================//
	// module: models
	//================================================================//
	mrb_raylib_module_models_init(mrb, mod_RayLib);

	//================================================================//
	// module: shaders
	//================================================================//
	mrb_raylib_module_shader_init(mrb, mod_RayLib);


	//================================================================//
	// module: audio
	//================================================================//
	mrb_raylib_module_audio_init(mrb, mod_RayLib);
}


void
mrb_raylib_gem_init(mrb_state* mrb)
{
	mrb_raylib_image_init(mrb, mod_RayLib);
	mrb_raylib_texture_init(mrb, mod_RayLib);
	mrb_raylib_render_texture_init(mrb, mod_RayLib);
	mrb_raylib_charinfo_init(mrb, mod_RayLib);
	mrb_raylib_font_init(mrb, mod_RayLib);
	mrb_raylib_wave_init(mrb, mod_RayLib);
	mrb_raylib_sound_init(mrb, mod_RayLib);
	mrb_raylib_audiostream_init(mrb, mod_RayLib);
	//mrb_raylib_music_init(mrb, mod_RayLib);
	mrb_raylib_shader_init(mrb, mod_RayLib);
}

void
mrb_raylib_struct_init(mrb_state* mrb)
{

}

void
mrb_raylib_module_final(mrb_state* mrb)
{

}
