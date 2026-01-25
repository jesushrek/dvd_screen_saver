#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{
    int screenWidth = 800;
    int screenHeight = 600;

    int logoWidth = 192;
    int logoHeight = 113;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    Vector2 position = { (float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 velocity = { 1.0, -1.0 };

    InitWindow(screenWidth, screenHeight, "Dvd-Logo");
    SetTargetFPS(144);

    Image image = LoadImage("asset/logo.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    Color colorList[] = { WHITE, GREEN, BLUE, RED, PURPLE, YELLOW, ORANGE, SKYBLUE };
    Color scolor = WHITE;

    while(!WindowShouldClose())
    { 
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        bool hit = false;

        position.x += velocity.x;
        position.y += velocity.y;

        if( position.x <= 0 || position.x >= (screenWidth - logoWidth))
        {
            velocity.x *= -1;
            hit = true;
        }
        if( position.y <= 0 || position.y >= (screenHeight - logoHeight))
        {
            velocity.y *= -1;
            hit = true;
        }

        if(hit)
            scolor = colorList[ rand() % (sizeof(colorList) / sizeof(*colorList)) ];

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(texture, position.x, position.y, scolor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
