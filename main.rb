
Raylib::init_window 800, 600, "Window"
Raylib::set_target_fps 60

bg_color = Raylib::Color.new
bg_color.r = 0
bg_color.g = 0
bg_color.b = 0
bg_color.a = 255

color_white = Raylib::Color.new
color_white.r = 255
color_white.g = 109
color_white.b = 194
color_white.a = 255

until Raylib::window_should_close

    Raylib::begin_drawing

    Raylib::clear_background bg_color
    Raylib::draw_text( "Congrats! You created your first window!", 190, 200, 20, color_white )

    Raylib::end_drawing

end

Raylib::close_window
