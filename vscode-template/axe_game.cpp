#include "raylib.h"

int main()
{

    const int WIDTH { 1900 };
    const int HEIGHT { 1200 };

    InitWindow(WIDTH, HEIGHT, "Hello World Window");
    
    // Circle
    const int CIRCLE_RADIUS = 64;
    int circle_x{ WIDTH / 2 };
    int circle_y{ HEIGHT / 2 };
    Color circle_color = BLUE;
    
    // Rectangle (axe)
    int rectangle_x{ 300 };
    int rectangle_y{ 0 };
    int rectangle_width{ 50 };
    int rectangle_height{ 50 };
    Color rectangle_color = RED;
    
    SetTargetFPS(60);
    int moveStep = 10;
    int direction = moveStep;

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);

        /*
        CIRCLE
        */
        DrawCircle(circle_x, circle_y, CIRCLE_RADIUS, circle_color);

        // Stay in bounds
        if (IsKeyDown(KEY_W) && (circle_y > CIRCLE_RADIUS + 1)) { circle_y -= moveStep; } // Up
        if (IsKeyDown(KEY_S) && (circle_y < (HEIGHT - CIRCLE_RADIUS))) { circle_y += moveStep; } // Down
        if (IsKeyDown(KEY_A) && (circle_x > CIRCLE_RADIUS)) { circle_x -= moveStep; } // Left
        if (IsKeyDown(KEY_D) && (circle_x < (WIDTH - CIRCLE_RADIUS))) { circle_x += moveStep; } // Right
        
        /*
        AXE
        */
        DrawRectangle(rectangle_x, rectangle_y, rectangle_width, rectangle_height, rectangle_color);
        
        // Move the axe down
        rectangle_y += direction;

        // If we've hit the top or bottom, reverse direction
        if (rectangle_y > (HEIGHT - rectangle_height) || rectangle_y <= 0) { direction = -direction; }
        
        EndDrawing();


    }
}