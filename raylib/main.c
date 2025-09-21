
#include "raylib.h"
typedef struct CardSheet {

  Texture2D tex;
  int sheetW, sheetH;
  int cardW, cardH;
  int padX, padY;
  int paddX, paddY;
  int cols, row;
};
// Program main entry point
int main(void) {
  const int screenWidth = 1920;
  const int screenHeight = 1080;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");

  // Image Loading

  Texture2D cardsTex = LoadTexture("./assets/CuteCards.png");

  // On draw:
  Rectangle src = {0, 0, 100, 144};     // which tile to take
  Rectangle dst = {200, 200, 100, 144}; // where on screen
  Vector2 origin = {0, 0};

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) {

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTexturePro(cardsTex, src, dst, origin, 0, WHITE);

    EndDrawing();
  }
  CloseWindow(); // Close window and OpenGL context

  return 0;
}
