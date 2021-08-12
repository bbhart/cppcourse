#include "raylib.h"

int main()
{

    const int WIDTH{1900};
    const int HEIGHT{1200};

    InitWindow(WIDTH, HEIGHT, "Hello World Window");
    
    // Circle
    const int CIRCLE_RADIUS{25};
    int circle_x{WIDTH / 2};
    int circle_y{HEIGHT / 2};
    Color circle_color{BLUE};

    // Rectangle (axe)
    const int AXE_LENGTH{50};
    int axe_x{300};
    int axe_y{0};
    int axe_width{50};
    int axe_height{50};
    Color axe_color{RED};
    
    SetTargetFPS(60);
    int moveStep{10};
    int direction{moveStep};
    bool collisionWithAxe{false};

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);

        /*
        CIRCLE
        */
        DrawCircle(circle_x, circle_y, CIRCLE_RADIUS, circle_color);

        if (collisionWithAxe) {
            DrawText("Game over!", 400, 200, 90, RED);
        }
        else // No collision, play the game
        {

            // Stay in bounds
            if (IsKeyDown(KEY_W) && (circle_y > CIRCLE_RADIUS + 1)) {circle_y -= moveStep;} // Up
            if (IsKeyDown(KEY_S) && (circle_y < (HEIGHT - CIRCLE_RADIUS))) {circle_y += moveStep;} // Down
            if (IsKeyDown(KEY_A) && (circle_x > CIRCLE_RADIUS)) {circle_x -= moveStep;} // Left
            if (IsKeyDown(KEY_D) && (circle_x < (WIDTH - CIRCLE_RADIUS))) {circle_x += moveStep;} // Right

            // Circle edges
            int l_circle_x{circle_x - CIRCLE_RADIUS};
            int r_circle_x{circle_x + CIRCLE_RADIUS};
            int u_circle_y{circle_y - CIRCLE_RADIUS};
            int b_circle_y{circle_y + CIRCLE_RADIUS};

            /*
            AXE
            */
            DrawRectangle(axe_x, axe_y, AXE_LENGTH, AXE_LENGTH, axe_color);
            
            // Move the axe down
            axe_y += direction;

            // If we've hit the top or bottom, reverse direction
            if (axe_y > (HEIGHT - axe_height) || axe_y <= 0) {direction = -direction;}

            // Axe edges
            int l_axe_x{axe_x};
            int r_axe_x{axe_y + AXE_LENGTH};
            int u_axe_y{axe_y};
            int b_axe_y{axe_y + AXE_LENGTH};

            /*
            Collision Detection
            */
            if ((b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (l_axe_x <= r_circle_x) &&
                r_axe_x >= l_circle_x) 
            {
                // Game over
                collisionWithAxe = true;
            }

            
   
            



        }

        EndDrawing();


   }
}
