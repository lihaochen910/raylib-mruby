Raylib::init_window 800, 600, "raylib [core] example - 2d camera"
Raylib::set_target_fps 60

G = 400
PLAYER_JUMP_SPD = 350.0
PLAYER_HOR_SPD = 200.0

class Player
    attr_accessor :position
    attr_accessor :speed
    attr_accessor :can_jump

    def initialize()
        @position = Raylib::Vector2.new
        @speed = 0
        @can_jump = true
    end
end

class EnvItem
    attr_accessor :rect
    attr_accessor :blocking
    attr_accessor :color

    def initialize()
        @rect = Raylib::Rectangle.new
        @blocking = 0
        @color = Raylib::Color.new
    end
end

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

color_red = Raylib::Color.new
color_red.r = 255
color_red.g = 0
color_red.b = 0
color_red.a = 255

color_light_grey = Raylib::Color.new
color_light_grey.r = 200
color_light_grey.g = 200
color_light_grey.b = 200
color_light_grey.a = 255

color_grey = Raylib::Color.new
color_grey.r = 130
color_grey.g = 130
color_grey.b = 130
color_grey.a = 255

init_position = Raylib::Vector2.new
init_position.x = 400
init_position.y = 280

player = Player.new
player.position.x = 400
player.position.y = 280

env_items = []
ei_1 = EnvItem.new
ei_1.rect = Raylib::Rectangle.new
ei_1.rect.x = 0
ei_1.rect.y = 0
ei_1.rect.width = 1000
ei_1.rect.height = 400
ei_1.blocking = 0
ei_1.color = color_light_grey
env_items.push ei_1

camera_offset = Raylib::Vector2.new
camera_offset.x = 800 / 2.0
camera_offset.y = 600 / 2.0
camera = Raylib::Camera2D.new
camera.target = player.position
camera.offset = camera_offset
camera.rotation = 0
camera.zoom = 1.0

ZoomIncrement = 0.125

def update_player( player, env_items, delta )
    if Raylib.is_key_down Raylib::KEY_LEFT
        player.position.x -= PLAYER_HOR_SPD * delta
    end
    if Raylib.is_key_down Raylib::KEY_RIGHT
        player.position.x += PLAYER_HOR_SPD * delta
    end
    if Raylib.is_key_down Raylib::KEY_SPACE
        player.speed = -PLAYER_JUMP_SPD
        player.can_jump = false
    end
end

until Raylib.window_should_close

    delta_time = Raylib.get_frame_time

    update_player player, env_items, delta_time

    camera.zoom += Raylib.get_mouse_wheel_move * 0.05
    camera.zoom = 3.0 if camera.zoom > 3.0
    camera.zoom = 0.25 if camera.zoom < 0.25

    if Raylib.is_key_pressed Raylib::KEY_R
        camera.zoom = 1.0
        player.position = init_position
    end

    wheel = Raylib.get_mouse_wheel_move
    if wheel != 0
        mouse_world_pos = Raylib.get_screen_to_world2d( Raylib.get_mouse_position, camera )
        camera.offset = Raylib.get_mouse_position
        camera.target = mouse_world_pos

        camera.zoom += wheel * ZoomIncrement
        camera.zoom = ZoomIncrement if camera.zoom < ZoomIncrement
    end

    Raylib.begin_drawing

        Raylib.clear_background bg_color

        Raylib.begin_mode2d camera

            player_rect = Raylib::Rectangle.new
            player_rect.x = player.position.x - 20
            player_rect.y = player.position.y - 20
            player_rect.width = 40
            player_rect.height = 40
            Raylib.draw_rectangle_rec player_rect, color_red

        Raylib.end_mode2d

        Raylib.draw_text "Mouse right button drag to move, mouse wheel to zoom", 10, 10, 20, color_white

    Raylib.end_drawing

end

Raylib.close_window
