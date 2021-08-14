#include "raylib.h"

int main() {

    // Window params
    const int WINDOW_WIDTH{1280};
    const int WINDOW_HEIGHT{960};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dapper Dasher");
    int frameCounter{ 0 };
    SetTargetFPS(60);

    // rectangle
    const int width{ 50 };
    const int height { 80 };

    int posX{ (WINDOW_HEIGHT / 2) - (width / 2) }; // Center on X
    int posY{ WINDOW_HEIGHT - height }; // bottom

    // physics
    float velocityY { 0.0 };
    bool isInAir {}; // empty braces means false

    // sprite
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec{ 0.0, 0.0, (float)scarfy.width / 6, (float)scarfy.height };  // 6 sprites in texture
    Vector2 scarfyPos{ posX, WINDOW_HEIGHT - scarfy.height};
    int spriteIndex{ 0 };

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);


        // check if we're in the air
        // isInAir = (scarfyPos.y < (WINDOW_HEIGHT - height));
        isInAir = (scarfyPos.y < (WINDOW_HEIGHT - scarfy.height));

        // choose a sprite from the texture
        // there are two aspects here: 1) how frequently to update? 2) which frame to choose?
        if (frameCounter % 6 == 0) // ten times a second (@ 60 fps)
        {
            // Animate, unless we're in the air
            // Cycle through 6 indexes
            if (!isInAir)
            {
                scarfyRec.x = (spriteIndex % 6) * (scarfy.width / 6);
                spriteIndex++;
            }
        }
        
        if (isInAir) {
            // apply gravity
            velocityY += (24.0 / 60);
        }
        else
        {
            // We're on the ground, so zero out our velocity
            velocityY = 0.0;
        } 
        
        // DrawRectangle(posX, posY, width, height, BLUE);

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocityY += -12.0;            
        }

        // apply velocities
        // posY += (int)velocityY;
        scarfyPos.y += (int)velocityY;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        frameCounter++;
        EndDrawing();

    }
    CloseWindow();




}