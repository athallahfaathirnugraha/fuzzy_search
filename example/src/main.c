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

    int selected[20];
    memset(selected, 1, sizeof(selected));

    InitWindow(400, 600, "example");

    while (!WindowShouldClose()) {
        BeginDrawing();

        for (size_t i = 0; i < 20; i++) {
            if (selected[i]) DrawText(array[i], 20, 20 + i * 20, 20, RAYWHITE);
        }
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}