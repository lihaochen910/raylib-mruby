#ifndef CORE_WRAPPER_H
#define CORE_WRAPPER_H

#include <raylib.h>
#include <mruby.h>
#include <mruby/string.h>
#include <mruby/array.h>

//================================================================//
// Window-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_init_window(mrb_state *mrb, mrb_value self)
{
	mrb_int width, height = 0;
	mrb_value title;

	mrb_get_args(mrb, "iiS", &width, &height, &title);

	//InitWindow(width, height, mrb_str_to_cstr(mrb, title));
	InitWindow(width, height, RSTRING_PTR(title));

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_close_window(mrb_state *mrb, mrb_value self)
{
	CloseWindow();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_ready(mrb_state *mrb, mrb_value self)
{
	return mrb_bool_value(IsWindowReady());
}

//----------------------------------------------------------------//
static mrb_value
mrb_window_should_close(mrb_state *mrb, mrb_value self)
{
	return mrb_bool_value(WindowShouldClose());
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_window_minimized(mrb_state *mrb, mrb_value self)
{
	return mrb_bool_value(IsWindowMinimized());
}

//----------------------------------------------------------------//
static mrb_value
mrb_toggle_fullscreen(mrb_state *mrb, mrb_value self)
{
	ToggleFullscreen();
	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_title(mrb_state *mrb, mrb_value self)
{
	mrb_value title;

	mrb_get_args(mrb, "S", &title);

	SetWindowTitle(RSTRING_PTR(title));

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_position(mrb_state *mrb, mrb_value self)
{
	mrb_int x, y = 0;

	mrb_get_args(mrb, "ii", &x, &y);

	SetWindowPosition(x, y);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_monitor(mrb_state *mrb, mrb_value self)
{
	mrb_int monitor = 0;

	mrb_get_args(mrb, "i", &monitor);

	SetWindowMonitor(monitor);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_min_size(mrb_state *mrb, mrb_value self)
{
	mrb_int width, height = 0;

	mrb_get_args(mrb, "ii", &width, &height);

	SetWindowMinSize(width, height);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_window_size(mrb_state *mrb, mrb_value self)
{
	mrb_int width, height = 0;

	mrb_get_args(mrb, "ii", &width, &height);

	SetWindowSize(width, height);

	return self;
}


//================================================================//
// Cursor-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_show_cursor(mrb_state *mrb, mrb_value self)
{
	ShowCursor();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_hide_cursor(mrb_state *mrb, mrb_value self)
{
	HideCursor();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_cursor_hidden(mrb_state *mrb, mrb_value self)
{
	return mrb_bool_value(IsCursorHidden());
}

//----------------------------------------------------------------//
static mrb_value
mrb_enable_cursor(mrb_state *mrb, mrb_value self)
{
	EnableCursor();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_disable_cursor(mrb_state *mrb, mrb_value self)
{
	DisableCursor();

	return self;
}


//================================================================//
// Drawing-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_clear_background(mrb_state *mrb, mrb_value self)
{
	mrb_float r, g, b, a = 0;

	mrb_get_args(mrb, "ffff", &r, &g, &b, &a);

	Color bg = { r, g, b, a };

	ClearBackground(bg);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_begin_drawing(mrb_state *mrb, mrb_value self)
{
	BeginDrawing();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_end_drawing(mrb_state *mrb, mrb_value self)
{
	EndDrawing();

	return self;
}



//================================================================//
// Timing-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_set_target_fps(mrb_state *mrb, mrb_value self)
{
	mrb_int fps;

	mrb_get_args(mrb, "i", &fps);

	SetTargetFPS(fps);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_fps(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetFPS());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_frame_time(mrb_state *mrb, mrb_value self)
{
	return mrb_float_value(mrb, GetFrameTime());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_time(mrb_state *mrb, mrb_value self)
{
	return mrb_float_value(mrb, GetTime());
}



//================================================================//
// Misc. functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_show_logo(mrb_state *mrb, mrb_value self)
{
	//ShowLogo();

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_trace_log(mrb_state *mrb, mrb_value self)
{
	mrb_int logType;
	mrb_value text;

	mrb_get_args(mrb, "iS", &logType, &text);

	TraceLog(logType, RSTRING_PTR(text));

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_take_screen_shot(mrb_state *mrb, mrb_value self)
{
	mrb_value filename;

	mrb_get_args(mrb, "S", &filename);

	TakeScreenshot(RSTRING_PTR(filename));

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_random_value(mrb_state *mrb, mrb_value self)
{
	mrb_int min, max = 0;

	mrb_get_args(mrb, "ii", &min, &max);

	return mrb_fixnum_value(GetRandomValue(min, max));
}


//================================================================//
// Input-related functions: keyboard
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_pressed(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsKeyPressed(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_down(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsKeyDown(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_released(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsKeyReleased(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_key_up(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsKeyUp(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_key_pressed(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetKeyPressed());
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_exit_key(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	SetExitKey(key);

	return self;
}


//================================================================//
// Input-related functions: gamepads
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_available(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad = 0;

	mrb_get_args(mrb, "i", &gamepad);

	return mrb_bool_value(IsGamepadAvailable(gamepad));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_name(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad = 0;
	mrb_value name;

	mrb_get_args(mrb, "iS", &gamepad, &name);

	return mrb_bool_value(IsGamepadName(gamepad, RSTRING_PTR(name)));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_name(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad = 0;

	mrb_get_args(mrb, "i", &gamepad);

	return mrb_str_new_cstr(mrb, GetGamepadName(gamepad));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_pressed(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad, button = 0;

	mrb_get_args(mrb, "ii", &gamepad, &button);

	return mrb_bool_value(IsGamepadButtonPressed(gamepad, button));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_down(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad, button = 0;

	mrb_get_args(mrb, "ii", &gamepad, &button);

	return mrb_bool_value(IsGamepadButtonDown(gamepad, button));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_released(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad, button = 0;

	mrb_get_args(mrb, "ii", &gamepad, &button);

	return mrb_bool_value(IsGamepadButtonReleased(gamepad, button));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gamepad_up(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad, button = 0;

	mrb_get_args(mrb, "ii", &gamepad, &button);

	return mrb_bool_value(IsGamepadButtonUp(gamepad, button));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_button_pressed(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetGamepadButtonPressed());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_axis_count(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad = 0;

	mrb_get_args(mrb, "i", &gamepad);

	return mrb_fixnum_value(GetGamepadAxisCount(gamepad));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gamepad_axis_movement(mrb_state *mrb, mrb_value self)
{
	mrb_int gamepad, axis = 0;

	mrb_get_args(mrb, "ii", &gamepad, &axis);

	return mrb_float_value(mrb, GetGamepadAxisMovement(gamepad, axis));
}


//================================================================//
// Input-related functions: mouse
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_pressed(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsMouseButtonPressed(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_down(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsMouseButtonDown(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_released(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsMouseButtonReleased(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_mouse_button_up(mrb_state *mrb, mrb_value self)
{
	mrb_int key = 0;

	mrb_get_args(mrb, "i", &key);

	return mrb_bool_value(IsMouseButtonUp(key));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_X(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetMouseX());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_Y(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetMouseY());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_position(mrb_state *mrb, mrb_value self)
{
	Vector2 pos = GetMousePosition();

	mrb_value posArray = mrb_ary_new(mrb);

	mrb_ary_push(mrb, posArray, mrb_float_value(mrb, pos.x));
	mrb_ary_push(mrb, posArray, mrb_float_value(mrb, pos.y));

	return posArray;
}

//----------------------------------------------------------------//
static mrb_value
mrb_set_mouse_position(mrb_state *mrb, mrb_value self)
{
	mrb_int x, y = 0;

	mrb_get_args(mrb, "ii", &x, &y);

	SetMousePosition(x, y);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_mouse_wheel_move(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetMouseWheelMove());
}


//================================================================//
// Input-related functions: touch
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_X(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetTouchX());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_Y(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetTouchY());
}


//================================================================//
// Gestures-related functions
//================================================================//

//----------------------------------------------------------------//
static mrb_value
mrb_gestures_enabled(mrb_state *mrb, mrb_value self)
{
	mrb_int gestureFlags = 0;

	mrb_get_args(mrb, "i", &gestureFlags);

	SetGesturesEnabled(gestureFlags);

	return self;
}

//----------------------------------------------------------------//
static mrb_value
mrb_is_gestures_detected(mrb_state *mrb, mrb_value self)
{
	mrb_int gesture = 0;

	mrb_get_args(mrb, "i", &gesture);

	return mrb_bool_value(IsGestureDetected(gesture));
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gestures_detected(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetGestureDetected());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_touch_points_count(mrb_state *mrb, mrb_value self)
{
	return mrb_fixnum_value(GetTouchPointsCount());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_hold_duration(mrb_state *mrb, mrb_value self)
{
	return mrb_float_value(mrb, GetGestureHoldDuration());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_drag_vector(mrb_state *mrb, mrb_value self)
{
	mrb_value dragVector = mrb_ary_new(mrb);

	Vector2 vec = GetGestureDragVector();

	mrb_ary_push(mrb, dragVector, mrb_float_value(mrb, vec.x));
	mrb_ary_push(mrb, dragVector, mrb_float_value(mrb, vec.y));

	return dragVector;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_drag_angle(mrb_state *mrb, mrb_value self)
{
	return mrb_float_value(mrb, GetGestureDragAngle());
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_pinch_vector(mrb_state *mrb, mrb_value self)
{
	mrb_value pinchVector = mrb_ary_new(mrb);

	Vector2 vec = GetGesturePinchVector();

	mrb_ary_push(mrb, pinchVector, mrb_float_value(mrb, vec.x));
	mrb_ary_push(mrb, pinchVector, mrb_float_value(mrb, vec.y));

	return pinchVector;
}

//----------------------------------------------------------------//
static mrb_value
mrb_get_gesture_pinch_angle(mrb_state *mrb, mrb_value self)
{
	return mrb_float_value(mrb, GetGesturePinchAngle());
}

#endif