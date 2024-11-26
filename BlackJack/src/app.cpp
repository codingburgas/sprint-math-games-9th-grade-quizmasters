#include "app.h"


App::App() {
    InitWindow(1920, 1080, "BlackJack");
    SetTargetFPS(60);
    mainMenu.loadResources();
    gameMenu.loadResources();
    update();
    CloseWindow();
}
void App::update() {
    while (!WindowShouldClose()) {
        appLogic();
        display();
    }
}

void App::appLogic() {
    if (pages.mainMenu) {
        if (CheckCollisionPointRec(GetMousePosition(), mainMenu.startButtonRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            pages.mainMenu = 0;
            pages.game = 1;
        }
        return;
    }
    if (pages.game) {
        gameMenu.gameLogic();
    }
}

void App::display() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (pages.mainMenu) {
        drawMainMenu();
    }
    if (pages.game) {
        drawGame();
    }
    EndDrawing();
}

void App::drawMainMenu() {
    DrawTexture(mainMenu.background, 0, 0, WHITE);
    DrawTexture(mainMenu.startButton, 660, 600, WHITE);
    DrawTexture(mainMenu.title, 360, 0, WHITE);
}

void App::drawGame() {
    DrawTexture(gameMenu.table, 0, 0, WHITE);
    DrawTexture(gameMenu.hitButton, 1450, 550, WHITE);
    DrawTexture(gameMenu.standButton, 1620, 550, WHITE);
    for (size_t i = 0;i < gameMenu.userTextures.size();i++) {
        DrawTexture(gameMenu.userTextures[i].cardTexture, gameMenu.userTextures[i].x, gameMenu.userTextures[i].y, WHITE);
        DrawText(gameMenu.userTextures[i].problem.c_str(), gameMenu.userTextures[i].x + 50, gameMenu.userTextures[i].y + 80, 20, BLACK);
    }
    for (size_t i = 0;i < gameMenu.dealerTextures.size();i++) {
        DrawTexture(gameMenu.dealerTextures[i].cardTexture, gameMenu.dealerTextures[i].x, gameMenu.dealerTextures[i].y, WHITE);
        DrawText(gameMenu.dealerTextures[i].problem.c_str(), gameMenu.dealerTextures[i].x + 50, gameMenu.dealerTextures[i].y + 80, 20, BLACK);
    }
}