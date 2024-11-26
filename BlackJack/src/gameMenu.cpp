#include "gameMenu.h"

Cards::Cards(int suit, int rank, std::string problem, int points) {
	m_suit = suit;
	m_rank = rank;
	m_problem = problem;
	m_points = points;
}

CardTexture::CardTexture(std::string path, std::string prob, int posX, int posY) {
    cardTexture = LoadTexture(path.c_str());
    temp = LoadImageFromTexture(cardTexture);
    ImageResize(&temp, 150, 200);
    cardTexture = LoadTextureFromImage(temp);
    UnloadImage(temp);
    problem = prob;
    x = posX;
    y = posY;
}

Cards GameMenu::cardSelect(int& points)
{
    int cardPoints = 0;
    Problems problems;
    std::random_device rd;
    std::uniform_int_distribution<int> cardDist(1, 13);
    std::uniform_int_distribution<int> suitDist(1, 4);
    std::uniform_int_distribution<int> problemDist(0, 3);
    int randomCard = cardDist(rd);
    int randomProblemIndex = problemDist(rd);
    std::string selectedProblem;
    switch (randomCard) {
    case 1:
        if (points > 10)
        {
            selectedProblem = problems.cardSmallAce[randomProblemIndex];
            cardPoints = 1;
        }
        else
        {
            selectedProblem = problems.cardBigAce[randomProblemIndex];
            cardPoints = 11;
        }
        break;
    case 2: selectedProblem = problems.cardTwo[randomProblemIndex]; cardPoints = 2;
        break;
    case 3: selectedProblem = problems.cardThree[randomProblemIndex]; cardPoints = 3;
        break;
    case 4: selectedProblem = problems.cardFour[randomProblemIndex]; cardPoints = 4;
        break;
    case 5: selectedProblem = problems.cardFive[randomProblemIndex]; cardPoints = 5;
        break;
    case 6: selectedProblem = problems.cardSix[randomProblemIndex]; cardPoints = 6;
        break;
    case 7: selectedProblem = problems.cardSeven[randomProblemIndex]; cardPoints = 7;
        break;
    case 8: selectedProblem = problems.cardEight[randomProblemIndex]; cardPoints = 8;
        break;
    case 9: selectedProblem = problems.cardNine[randomProblemIndex]; cardPoints = 9;
        break;
    case 10: selectedProblem = problems.cardTen[randomProblemIndex]; cardPoints = 10;
        break;
    case 11: selectedProblem = problems.cardJack[randomProblemIndex]; cardPoints = 10;
        break;
    case 12: selectedProblem = problems.cardQueen[randomProblemIndex]; cardPoints = 10;
        break;
    case 13: selectedProblem = problems.cardKing[randomProblemIndex]; cardPoints = 10;
        break;
    }
    Cards card(suitDist(rd), randomCard, selectedProblem, cardPoints);
    points += cardPoints;
    return card;
}

GameMenu::GameMenu() {
	hitButtonRec.x = 1450;
	hitButtonRec.y = 550;
	hitButtonRec.width = 150;
	hitButtonRec.height = 150;

	standButtonRec.x = 1620;
	standButtonRec.y = 550;
	standButtonRec.width = 150;
	standButtonRec.height = 150;
}

void GameMenu::loadResources() {
	table = LoadTexture("././assets/BlackJackTable.png");
	hitButton = LoadTexture("././assets/HITbutton.png");
	standButton = LoadTexture("././assets/STANDbutton.png");
}

void GameMenu::gameLogic() {
    if (isUserTurn && canUserPlay) {
        userTurn();
    }
    if (isDealerTurn) {
        dealerTurn();
    }
}

void GameMenu::userTurn() {
    if (userDeck.size() < 2) {
        userDeck.push_back(cardSelect(userPoints));
        std::string path = "././assets/";
        switch (userDeck[userDeck.size() - 1].getSuit()) {
        case 1: path += "Diamonds.png"; break;
        case 2: path += "Spades.png"; break;
        case 3: path += "Hearts.png"; break;
        case 4: path += "Clubs.png"; break;
        }
        userTextures.push_back(CardTexture(path, userDeck[userDeck.size() - 1].getProblem(), userPosX, userPosY));
        userPosX -= 175;
        isDealerTurn = true;
        isUserTurn = false;
        return;
    }
    if (userDeck.size() < 5) {
        if (CheckCollisionPointRec(GetMousePosition(), hitButtonRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !isLMBPressed) {
            isLMBPressed = true;
            std::cout << "hit" << std::endl;
            userDeck.push_back(cardSelect(userPoints));
            std::string path = "././assets/";
            switch (userDeck[userDeck.size() - 1].getSuit()) {
            case 1: path += "Diamonds.png"; break;
            case 2: path += "Spades.png"; break;
            case 3: path += "Hearts.png"; break;
            case 4: path += "Clubs.png"; break;
            }
            userTextures.push_back(CardTexture(path, userDeck[userDeck.size() - 1].getProblem(), userPosX, userPosY));
            userPosX -= 175;
            isDealerTurn = true;
            isUserTurn = false;
            return;
        }
        isLMBPressed = false;
        if (CheckCollisionPointRec(GetMousePosition(), standButtonRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            canUserPlay = false;
            isDealerTurn = true;
            isUserTurn = false;
            return;
        }
    }
    isDealerTurn = true;
    isUserTurn = false;
    canUserPlay = false;
}

void GameMenu::dealerTurn() {
    if (dealerDeck.size() < 2) {
        dealerDeck.push_back(cardSelect(userPoints));
        std::string path = "././assets/";
        switch (dealerDeck[dealerDeck.size() - 1].getSuit()) {
        case 1: path += "Diamonds.png"; break;
        case 2: path += "Spades.png"; break;
        case 3: path += "Hearts.png"; break;
        case 4: path += "Clubs.png"; break;
        }
        dealerTextures.push_back(CardTexture(path, dealerDeck[dealerDeck.size() - 1].getProblem(), dealerPosX, dealerPosY));
        dealerPosX -= 175;
        isDealerTurn = false;
        isUserTurn = true;
        return;
    }
}