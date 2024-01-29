Raylib::init_window 800, 600, "raylib [core] example - 2d camera mouse zoom"
Raylib::set_target_fps 60

puts "check Raylib.begin_mode2d:"
puts Raylib.method_defined? :window_should_close
puts Raylib.method_defined? :begin_mode2d

bg_color = Raylib::Color.new
bg_color.r = 0
bg_color.g = 0
bg_color.b = 0
bg_color.a = 255

color_white = Raylib::Color.new
color_white.r = 255
color_white.g = 255
color_white.b = 255
color_white.a = 255

color_yellow = Raylib::Color.new
color_yellow.r = 253
color_yellow.g = 249
color_yellow.b = 0
color_yellow.a = 255

camera = Raylib::Camera2D.new
camera.zoom = 1.0

ZoomIncrement = 0.125

until Raylib::window_should_close

    if Raylib::is_mouse_button_down Raylib::MOUSE_BUTTON_RIGHT
        delta = Raylib::get_mouse_delta()
        vt = Raylib::Vector2.new
        vt.x = camera.target.x + delta.x
        vt.y = camera.target.y + delta.y
        camera.target = vt
    end

    wheel = Raylib::get_mouse_wheel_move
    if wheel != 0
        mouse_world_pos = Raylib::get_screen_to_world2d( Raylib::get_mouse_position, camera )
        camera.offset = Raylib::get_mouse_position
        camera.target = mouse_world_pos

        camera.zoom += wheel * ZoomIncrement
        camera.zoom = ZoomIncrement if camera.zoom < ZoomIncrement
    end

    Raylib::begin_drawing

    Raylib::clear_background bg_color
    # Raylib::draw_text( "Congrats! You created your first window!", 190, 200, 20, color_white )

        Raylib::begin_mode2d camera

            Raylib::draw_grid 100, 50
            Raylib::draw_circle 100, 100, 50, color_yellow

        Raylib::end_mode2d

        Raylib::draw_text "Mouse right button drag to move, mouse wheel to zoom", 10, 10, 20, color_white

    Raylib::end_drawing

end

Raylib::close_window
