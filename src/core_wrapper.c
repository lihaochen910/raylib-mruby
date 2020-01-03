#include <core_wrapper.h>

//================================================================//
// Window-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_init_window ( mrb_state *mrb, mrb_value self ) {
	mrb_int width, height = 0;
	mrb_value title;

	mrb_get_args ( mrb, "iiS", & width, & height, & title );

	//InitWindow(width, height, mrb_str_to_cstr(mrb, title));
	InitWindow ( width, height, RSTRING_PTR( title ) );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_close_window ( mrb_state *mrb, mrb_value self ) {
	CloseWindow ();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_ready ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( IsWindowReady () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_window_should_close ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( WindowShouldClose () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_minimized ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( IsWindowMinimized () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_resized ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( IsWindowResized () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_hidden ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( IsWindowHidden () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_toggle_fullscreen ( mrb_state *mrb, mrb_value self ) {
	ToggleFullscreen ();
	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_unhide_window ( mrb_state *mrb, mrb_value self ) {
	UnhideWindow ();
	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_hide_window ( mrb_state *mrb, mrb_value self ) {
	HideWindow ();
	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_title ( mrb_state *mrb, mrb_value self ) {
	mrb_value title;

	mrb_get_args ( mrb, "S", & title );

	SetWindowTitle ( RSTRING_PTR( title ) );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_position ( mrb_state *mrb, mrb_value self ) {
	mrb_int x, y = 0;

	mrb_get_args ( mrb, "ii", & x, & y );

	SetWindowPosition ( x, y );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_monitor ( mrb_state *mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", & monitor );

	SetWindowMonitor ( monitor );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_min_size ( mrb_state *mrb, mrb_value self ) {
	mrb_int width, height = 0;

	mrb_get_args ( mrb, "ii", & width, & height );

	SetWindowMinSize ( width, height );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_size ( mrb_state *mrb, mrb_value self ) {
	mrb_int width, height = 0;

	mrb_get_args ( mrb, "ii", & width, & height );

	SetWindowSize ( width, height );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_screen_width ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetScreenWidth () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_screen_height ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetScreenHeight () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_count ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetMonitorCount () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_width ( mrb_state* mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", &monitor );

	return mrb_fixnum_value ( GetMonitorWidth ( monitor ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_height ( mrb_state* mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", &monitor );

	return mrb_fixnum_value ( GetMonitorHeight ( monitor ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_physical_width ( mrb_state* mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", &monitor );

	return mrb_fixnum_value ( GetMonitorPhysicalWidth ( monitor ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_physical_height ( mrb_state* mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", &monitor );

	return mrb_fixnum_value ( GetMonitorPhysicalHeight ( monitor ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_monitor_name ( mrb_state* mrb, mrb_value self ) {
	mrb_int monitor = 0;

	mrb_get_args ( mrb, "i", &monitor );

	return mrb_str_new_cstr ( mrb, GetMonitorName ( monitor ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_clipboard_text ( mrb_state* mrb, mrb_value self ) {
	return mrb_str_new_cstr ( mrb, GetClipboardText () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_clipboard_text ( mrb_state* mrb, mrb_value self ) {
	mrb_value text;

	mrb_get_args ( mrb, "s", &text );

	SetClipboardText ( mrb_string_value_cstr ( mrb, &text ) );

	return mrb_nil_value ();
}

//================================================================//
// Cursor-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_show_cursor ( mrb_state *mrb, mrb_value self ) {
	ShowCursor ();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_hide_cursor ( mrb_state *mrb, mrb_value self ) {
	HideCursor ();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_cursor_hidden ( mrb_state *mrb, mrb_value self ) {
	return mrb_bool_value ( IsCursorHidden () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_enable_cursor ( mrb_state *mrb, mrb_value self ) {
	EnableCursor ();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_disable_cursor ( mrb_state *mrb, mrb_value self ) {
	DisableCursor ();

	return self;
}


//================================================================//
// Drawing-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_clear_background ( mrb_state *mrb, mrb_value self ) {
	mrb_float r, g, b, a = 0;

	mrb_get_args ( mrb, "ffff", & r, & g, & b, & a );

	Color bg = { r, g, b, a };

	ClearBackground ( bg );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_begin_drawing ( mrb_state *mrb, mrb_value self ) {
	BeginDrawing ();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_end_drawing ( mrb_state *mrb, mrb_value self ) {
	EndDrawing ();

	return self;
}



//================================================================//
// Timing-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_set_target_fps ( mrb_state *mrb, mrb_value self ) {
	mrb_int fps;

	mrb_get_args ( mrb, "i", & fps );

	SetTargetFPS ( fps );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_fps ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetFPS () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_frame_time ( mrb_state *mrb, mrb_value self ) {
	return mrb_float_value ( mrb, GetFrameTime () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_time ( mrb_state *mrb, mrb_value self ) {
	return mrb_float_value ( mrb, GetTime () );
}



//================================================================//
// Misc. functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_show_logo ( mrb_state *mrb, mrb_value self ) {
	//ShowLogo();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_trace_log_level ( mrb_state *mrb, mrb_value self ) {
	mrb_int logType;

	mrb_get_args ( mrb, "i", &logType );

	SetTraceLogLevel ( logType );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_trace_log_exit ( mrb_state *mrb, mrb_value self ) {
	mrb_int logType;

	mrb_get_args ( mrb, "i", &logType );

	SetTraceLogExit ( logType );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_trace_log ( mrb_state *mrb, mrb_value self ) {
	mrb_int logType;
	mrb_value text;

	mrb_get_args ( mrb, "iS", &logType, &text );

	TraceLog ( logType, RSTRING_PTR( text ) );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_take_screen_shot ( mrb_state *mrb, mrb_value self ) {
	mrb_value filename;

	mrb_get_args ( mrb, "S", & filename );

	TakeScreenshot ( RSTRING_PTR( filename ) );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_random_value ( mrb_state *mrb, mrb_value self ) {
	mrb_int min, max = 0;

	mrb_get_args ( mrb, "ii", & min, & max );

	return mrb_fixnum_value ( GetRandomValue ( min, max ) );
}


//================================================================//
// Input-related functions: keyboard
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_pressed ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsKeyPressed ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_down ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsKeyDown ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_released ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsKeyReleased ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_up ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsKeyUp ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_key_pressed ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetKeyPressed () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_exit_key ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	SetExitKey ( key );

	return self;
}


//================================================================//
// Input-related functions: gamepads
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_available ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad = 0;

	mrb_get_args ( mrb, "i", & gamepad );

	return mrb_bool_value ( IsGamepadAvailable ( gamepad ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_name ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad = 0;
	mrb_value name;

	mrb_get_args ( mrb, "iS", & gamepad, & name );

	return mrb_bool_value ( IsGamepadName ( gamepad, RSTRING_PTR( name ) ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_name ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad = 0;

	mrb_get_args ( mrb, "i", & gamepad );

	return mrb_str_new_cstr ( mrb, GetGamepadName ( gamepad ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_pressed ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad, button = 0;

	mrb_get_args ( mrb, "ii", & gamepad, & button );

	return mrb_bool_value ( IsGamepadButtonPressed ( gamepad, button ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_down ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad, button = 0;

	mrb_get_args ( mrb, "ii", & gamepad, & button );

	return mrb_bool_value ( IsGamepadButtonDown ( gamepad, button ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_released ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad, button = 0;

	mrb_get_args ( mrb, "ii", & gamepad, & button );

	return mrb_bool_value ( IsGamepadButtonReleased ( gamepad, button ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_up ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad, button = 0;

	mrb_get_args ( mrb, "ii", & gamepad, & button );

	return mrb_bool_value ( IsGamepadButtonUp ( gamepad, button ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_button_pressed ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetGamepadButtonPressed () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_axis_count ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad = 0;

	mrb_get_args ( mrb, "i", & gamepad );

	return mrb_fixnum_value ( GetGamepadAxisCount ( gamepad ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_axis_movement ( mrb_state *mrb, mrb_value self ) {
	mrb_int gamepad, axis = 0;

	mrb_get_args ( mrb, "ii", & gamepad, & axis );

	return mrb_float_value ( mrb, GetGamepadAxisMovement ( gamepad, axis ) );
}


//================================================================//
// Input-related functions: mouse
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_pressed ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsMouseButtonPressed ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_down ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsMouseButtonDown ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_released ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsMouseButtonReleased ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_up ( mrb_state *mrb, mrb_value self ) {
	mrb_int key = 0;

	mrb_get_args ( mrb, "i", & key );

	return mrb_bool_value ( IsMouseButtonUp ( key ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_X ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetMouseX () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_Y ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetMouseY () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_position ( mrb_state *mrb, mrb_value self ) {
	Vector2 pos = GetMousePosition ();

	mrb_value posArray = mrb_ary_new ( mrb );

	mrb_ary_push ( mrb, posArray, mrb_float_value ( mrb, pos.x ) );
	mrb_ary_push ( mrb, posArray, mrb_float_value ( mrb, pos.y ) );

	return posArray;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_mouse_position ( mrb_state *mrb, mrb_value self ) {
	mrb_int x, y = 0;

	mrb_get_args ( mrb, "ii", & x, & y );

	SetMousePosition ( x, y );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_wheel_move ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetMouseWheelMove () );
}


//================================================================//
// Input-related functions: touch
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_X ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetTouchX () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_Y ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetTouchY () );
}


//================================================================//
// Gestures-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_gestures_enabled ( mrb_state *mrb, mrb_value self ) {
	mrb_int gestureFlags = 0;

	mrb_get_args ( mrb, "i", & gestureFlags );

	SetGesturesEnabled ( gestureFlags );

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gestures_detected ( mrb_state *mrb, mrb_value self ) {
	mrb_int gesture = 0;

	mrb_get_args ( mrb, "i", & gesture );

	return mrb_bool_value ( IsGestureDetected ( gesture ) );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gestures_detected ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetGestureDetected () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_points_count ( mrb_state *mrb, mrb_value self ) {
	return mrb_fixnum_value ( GetTouchPointsCount () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_hold_duration ( mrb_state *mrb, mrb_value self ) {
	return mrb_float_value ( mrb, GetGestureHoldDuration () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_drag_vector ( mrb_state *mrb, mrb_value self ) {
	mrb_value dragVector = mrb_ary_new ( mrb );

	Vector2 vec = GetGestureDragVector ();

	mrb_ary_push ( mrb, dragVector, mrb_float_value ( mrb, vec.x ) );
	mrb_ary_push ( mrb, dragVector, mrb_float_value ( mrb, vec.y ) );

	return dragVector;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_drag_angle ( mrb_state *mrb, mrb_value self ) {
	return mrb_float_value ( mrb, GetGestureDragAngle () );
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_pinch_vector ( mrb_state *mrb, mrb_value self ) {
	mrb_value pinchVector = mrb_ary_new ( mrb );

	Vector2 vec = GetGesturePinchVector ();

	mrb_ary_push ( mrb, pinchVector, mrb_float_value ( mrb, vec.x ) );
	mrb_ary_push ( mrb, pinchVector, mrb_float_value ( mrb, vec.y ) );

	return pinchVector;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_pinch_angle ( mrb_state *mrb, mrb_value self ) {
	return mrb_float_value ( mrb, GetGesturePinchAngle () );
}

//----------------------------------------------------------------//
void
mrb_raylib_core_init ( mrb_state *mrb, struct RClass *mod_RayLib ) {

	// Window-related functions
	mrb_define_module_function ( mrb, mod_RayLib, "init_window", mrb_init_window, MRB_ARGS_REQ( 3 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "window_should_close", mrb_window_should_close, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "close_window", mrb_close_window, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "is_window_ready", mrb_is_window_ready, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "is_window_minimized", mrb_is_window_minimized, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "is_window_resized", mrb_is_window_resized, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "is_window_hidden", mrb_is_window_hidden, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "toggle_fullscreen", mrb_toggle_fullscreen, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "unhide_window", mrb_unhide_window, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "hide_window", mrb_hide_window, MRB_ARGS_NONE() );

	mrb_define_module_function ( mrb, mod_RayLib, "set_window_title", mrb_set_window_title, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "set_window_position", mrb_set_window_position, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "set_window_monitor", mrb_set_window_monitor, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "set_window_min_size", mrb_set_window_min_size, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "set_window_size", mrb_set_window_size, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_screen_width", mrb_get_screen_width, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_screen_height", mrb_get_screen_height, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_count", mrb_get_monitor_count, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_width", mrb_get_monitor_width, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_height", mrb_get_monitor_height, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_physical_width", mrb_get_monitor_physical_width, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_physical_height", mrb_get_monitor_physical_height, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_monitor_name", mrb_get_monitor_name, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_clipboard_text", mrb_get_clipboard_text, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "set_clipboard_text", mrb_set_clipboard_text, MRB_ARGS_REQ( 1 ) );

	// Cursor-related functions
	mrb_define_module_function ( mrb, mod_RayLib, "show_cursor", mrb_show_cursor, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "hide_cursor", mrb_hide_cursor, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "is_cursor_hidden", mrb_is_cursor_hidden, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "enable_cursor", mrb_enable_cursor, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "disable_cursor", mrb_disable_cursor, MRB_ARGS_NONE() );

	// Drawing-related functions
	mrb_define_module_function ( mrb, mod_RayLib, "clear_background", mrb_clear_background, MRB_ARGS_REQ( 4 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "begin_drawing", mrb_begin_drawing, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "end_drawing", mrb_end_drawing, MRB_ARGS_NONE() );

	// Timing-related functions
	mrb_define_module_function ( mrb, mod_RayLib, "set_target_fps", mrb_set_target_fps, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_fps", mrb_get_fps, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_frame_time", mrb_get_frame_time, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_time", mrb_get_time, MRB_ARGS_NONE() );

//	mrb_define_module_function ( mrb, mod_RayLib, "show_logo", mrb_show_logo, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "set_trace_log_level", mrb_set_trace_log_level, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "set_trace_log_exit", mrb_set_trace_log_exit, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "trace_log", mrb_trace_log, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "take_screen_shot", mrb_take_screen_shot, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_random_value", mrb_get_random_value, MRB_ARGS_REQ( 2 ) );

	//------------------------------------------------------------------------------------
	// Input Handling Functions
	//------------------------------------------------------------------------------------
	mrb_define_module_function ( mrb, mod_RayLib, "is_key_pressed", mrb_is_key_pressed, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_key_down", mrb_is_key_down, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_key_released", mrb_is_key_released, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_key_up", mrb_is_key_up, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_key_pressed", mrb_get_key_pressed, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "set_exit_key", mrb_set_exit_key, MRB_ARGS_REQ( 1 ) );

	mrb_define_module_function ( mrb, mod_RayLib, "is_gamepad_available", mrb_is_gamepad_available, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_gamepad_name", mrb_is_gamepad_name, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gamepad_name", mrb_get_gamepad_name, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_gamepad_pressed", mrb_is_gamepad_pressed, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_gamepad_down", mrb_is_gamepad_down, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_gamepad_released", mrb_is_gamepad_released, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gamepad_button_pressed", mrb_get_gamepad_button_pressed, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gamepad_axis_count", mrb_get_gamepad_axis_count, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gamepad_axis_movement", mrb_get_gamepad_axis_movement, MRB_ARGS_REQ( 2 ) );

	mrb_define_module_function ( mrb, mod_RayLib, "is_mouse_button_pressed", mrb_is_mouse_button_pressed, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_mouse_button_down", mrb_is_mouse_button_down, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_mouse_button_released", mrb_is_mouse_button_released, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_mouse_button_up", mrb_is_mouse_button_up, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_mouse_X", mrb_get_mouse_X, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_mouse_Y", mrb_get_mouse_Y, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_mouse_position", mrb_get_mouse_position, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "set_mouse_position", mrb_set_mouse_position, MRB_ARGS_REQ( 2 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_mouse_wheel_move", mrb_get_mouse_wheel_move, MRB_ARGS_NONE() );

	mrb_define_module_function ( mrb, mod_RayLib, "get_touch_X", mrb_get_touch_X, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_touch_Y", mrb_get_touch_Y, MRB_ARGS_NONE() );

	mrb_define_module_function ( mrb, mod_RayLib, "gestures_enabled", mrb_gestures_enabled, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "is_gestures_detected", mrb_is_gestures_detected, MRB_ARGS_REQ( 1 ) );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gestures_detected", mrb_get_gestures_detected, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_touch_points_count", mrb_get_touch_points_count, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gesture_hold_duration", mrb_get_gesture_hold_duration, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gesture_drag_vector", mrb_get_gesture_drag_vector, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gesture_drag_angle", mrb_get_gesture_drag_angle, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gesture_pinch_vector", mrb_get_gesture_pinch_vector, MRB_ARGS_NONE() );
	mrb_define_module_function ( mrb, mod_RayLib, "get_gesture_pinch_angle", mrb_get_gesture_pinch_angle, MRB_ARGS_NONE() );

}

void
mrb_raylib_core_final ( mrb_state *mrb, struct RClass *mod_RayLib ) {

}
