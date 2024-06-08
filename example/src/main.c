#include <string.h>
#include <raylib.h>
#include <fsearch.h>
#include <stdio.h>

#define CUTOFF 3

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

    int searchv[20];
    memset(searchv, 0, sizeof(searchv));

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
            memset(search, '\0', sizeof(search));
            search_i = 0;
        }

        // if search is not empty
        if (search[0] != '\0') {
            for (size_t i = 0; i < 20; i++) {
                searchv[i] = fsearch(array[i], search);
                selected[i] = searchv[i] < CUTOFF;
            }
        } else memset(selected, 1, sizeof(selected));
        
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < 20; i++) {
            Color col = selected[i] ? RAYWHITE : GRAY;

            DrawText(array[i], 20, 20 + i * 20, 20, col);

            // if has searched
            if (search[0] != '\0') {
                char searchvstr[5];
                sprintf(searchvstr, "%d", searchv[i]);

                DrawText(searchvstr, 300, 20 + i * 20, 20, RAYWHITE);
            }
        }

        DrawText("search:", 20, 480, 20, RAYWHITE);
        DrawText(search, 20, 500, 20, RAYWHITE);
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}