#include "../lib/app.h"

void app() {
    InitWindow(1920 , 1080, "BlackJack");
    update();
    CloseWindow();
}
void update() {
    while(!WindowShouldClose()) {
        display();
    }
}
void display() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, 1920, 1080, WHITE);
    EndDrawing();
}