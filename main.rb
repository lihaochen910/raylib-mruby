
Raylib::init_window 800, 600, "Window"
Raylib::set_target_fps 60

until Raylib::window_should_close

    Raylib::begin_drawing

    Raylib::clear_background 1,0,0,1
    Raylib::draw_text( "Congrats! You created your first window!", 190, 200, 20, 1,1,1,1 )

    Raylib::end_drawing

end

Raylib::close_window
