#include "../lib/app.h"
#include "../lib/Deck.h"

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
void playerHand()
{
    int playersPoints = 0;
    char choice;
    while (playersPoints < 21) {
    Cards newCard = cardSelect(playersPoints);
        playersPoints += newCard.getRank();
        std::cout << "You drew a card with problem: " << newCard.getProblem() << "\n";
        std::cout << "Card value: " << newCard.getRank() << "\n";
        std::cout << "Your total points: " << playersPoints << "\n";
        std::cout << "Do you want another card";
    }

    std::cin >> choice;
    if (choice =='y' || choice == 'Y') {
        playerHand();
    }
    std::cout << "Final Points: " << playersPoints << std::endl;


    if (playersPoints > 21)
        {
        std::cout << "Game Over!";
        }
    if (playersPoints < 21) {
        std::cout << "Player 1 wins!";
    }
}
