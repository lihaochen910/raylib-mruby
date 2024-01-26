puts Raylib::VERSION

Raylib::init_window 800, 600, "Window"
Raylib::set_target_fps 60

bg_color = Raylib::Color.new
bg_color.r = 1
bg_color.g = 0
bg_color.b = 0
bg_color.a = 1

until Raylib::window_should_close

    Raylib::begin_drawing

    Raylib::clear_background bg_color
    Raylib::draw_text( "Congrats! You created your first window!", 190, 200, 20, 1,1,1,1 )

    Raylib::end_drawing

end

Raylib::close_window
