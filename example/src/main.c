#include <string.h>
#include <raylib.h>
#include <fsearch.h>

int main()
{
    char array[20][20] = {
        "lorem",
        "ipsum",
        "dolor",
        "sit",
        "amet",
        "consectetur",
        "adipiscing",
        "elit",
        "proin",
        "velit",
        "purus",
        "iaculis",
        "a magna",
        "vel",
        "sollicitudin",
        "aliquet",
        "mauris",
        "phasellus",
        "interdum",
        "nibh",
    };

    char search[1024];
    memset(search, '\0', sizeof(search));
    
    size_t search_i = 0;

    int selected[20];
    memset(selected, 1, sizeof(selected));

    InitWindow(400, 600, "example");

    while (!WindowShouldClose()) {
        int key = GetCharPressed();

        while (key > 0) {
            if (key >= 32 && key <= 125 && search_i <= 1023) {
                search[search_i] = (char)key;
                search_i++;
            }
            
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && search_i > 0) {
            search[--search_i] = '\0';
        }
        
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < 20; i++) {
            if (selected[i]) DrawText(array[i], 20, 20 + i * 20, 20, RAYWHITE);
        }

        DrawText("search:", 20, 480, 20, RAYWHITE);
        DrawText(search, 20, 500, 20, RAYWHITE);
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}