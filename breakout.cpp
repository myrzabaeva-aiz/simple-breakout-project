#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"

#include "raylib.h"

void update()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        game_state = paused_state;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        move_paddle(-paddle_speed);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        move_paddle(paddle_speed);
    }
    move_ball();

    if (!is_ball_inside_level()) {
        lives--;
        PlaySound(lose_sound);

        if (lives <= 0) {
            game_state = game_over_state;
        } else {
            load_level(0);
        }
    } else if (current_level_blocks == 0) {
        load_level(1);
        PlaySound(win_sound);
    }
}

void draw()
{
    draw_level();
    draw_paddle();
    draw_ball();
    draw_ui();
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "Breakout");
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_sounds();

    lives = 3;
    load_level();

    while (!WindowShouldClose()) {

        if (is_music_loaded) {
            UpdateMusicStream(background_music);
        }

        BeginDrawing();

        switch (game_state) {
        case menu_state:
            draw_menu();
            if (IsKeyPressed(KEY_ENTER)) {
                lives = 3;
                load_level(0);
                game_state = in_game_state;
            }
            break;
        case in_game_state:
            draw();
            update();
            break;
        case paused_state:
            draw();
            draw_pause_menu();
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = in_game_state;
            }
            break;
        case victory_state:
            draw_victory_menu();
            if (IsKeyPressed(KEY_ENTER)) {
                lives = 3;
                current_level_index = 0;
                load_level(0);
                game_state = menu_state;
            }
            break;
        case game_over_state:
            draw_game_over_menu();
            if (IsKeyPressed(KEY_ENTER)) {
                lives = 3;
                current_level_index = 0;
                load_level(0);
                game_state = menu_state;
            }
            break;
        }

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}