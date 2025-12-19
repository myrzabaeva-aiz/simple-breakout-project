#include "assets.h"
#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    wall_texture = LoadTexture("data/images/wall.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/block.png");
    paddle_texture = LoadTexture("data/images/paddle.png");
    ball_sprite = load_sprite("data/images/ball/ball", ".png", 8, true, 10);
}

void unload_textures()
{
    UnloadTexture(wall_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(paddle_texture);
    unload_sprite(ball_sprite);
}

void load_sounds()
{
    InitAudioDevice();
    win_sound = LoadSound("data/sounds/win.wav");
    lose_sound = LoadSound("data/sounds/lose.wav");


    if (FileExists("data/music/09.mp3")) {
        background_music = LoadMusicStream("data/music/09.mp3");
        PlayMusicStream(background_music);
        SetMusicVolume(background_music, 0.5f);
        is_music_loaded = true;
    }
}

void unload_sounds()
{
    UnloadSound(win_sound);
    UnloadSound(lose_sound);

    if (is_music_loaded) {
        UnloadMusicStream(background_music);
    }

    CloseAudioDevice();
}