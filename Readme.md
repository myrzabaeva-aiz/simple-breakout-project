# Simple Breakout

A classic Breakout arcade game clone written in C++ using the Raylib graphics library.

## Features

* **Core Gameplay:** Classic mechanics with paddle, ball, and destructive blocks.
* **5 Unique Levels:** Includes custom levels like "Pyramid", "Tunnels", and "Final Boss Wall".
* **Lives System:** The player starts with 3 lives. Losing all lives triggers a Game Over screen.
* **Audio:** Includes background music (`09.mp3`) and sound effects for winning/losing.
* **Game States:**
    * Menu Screen
    * Gameplay
    * Pause Screen (ESC)
    * Victory Screen (with animation)
    * Game Over Screen

## Controls

* **Left Arrow / A**: Move Paddle Left
* **Right Arrow / D**: Move Paddle Right
* **Space**: Launch Ball
* **Enter**: Start Game / Restart after Game Over
* **ESC**: Pause / Resume Game

## How to Compile & Run

1.  Open the project in CLion.
2.  Ensure the **Working Directory** in Run Configurations is set to `$ProjectFileDir$`. This is critical for loading assets (images, music) correctly.
3.  Build and Run the `breakout` target.

## Assets Structure

* `data/images/`: Sprites and textures.
* `data/sounds/`: Sound effects.
* `data/music/`: Background music (`09.mp3`).
* `data/fonts/`: Game fonts.