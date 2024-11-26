#pragma once
#include "precompile.h"

struct Problems {
    std::string cardSmallAce[4]{ "10-9","5-4","10/10","100/100" };
    std::string cardTwo[4]{ "1+1","2:1","3-1","1*2" };
    std::string cardThree[4]{ "1+2","75:25","64-61","1*3" };
    std::string cardFour[4]{ "1+3","64:16","20-16","2*2" };
    std::string cardFive[4]{ "2+3","125:25","12-7","2,5*2" };
    std::string cardSix[4]{ "1+5","66:11","8-2","3*2" };
    std::string cardSeven[4]{ "3+4","56:8","14-7","3,5*2" };
    std::string cardEight[4]{ "4+4","32:8","16-8","2*4" };
    std::string cardNine[4]{ "5+4","36:4","19-10","3*3" };
    std::string cardTen[4]{ "8+2","400:40","60-50","1*10" };
    std::string cardJack[4]{ "7+3","300:30","50-40","10*1" };
    std::string cardQueen[4]{ "6+4","200:20","40-30","5*2" };
    std::string cardKing[4]{ "5+5","100:10","30-20","2*5" };
    std::string cardBigAce[4]{ "10+1", "110/10", "9+2", "20-9" };
};

class Cards {
public:
    Cards(int suit, int rank, std::string problem, int points);
    int getRank() { return m_rank; }
    int getSuit() { return m_suit; }
    std::string getProblem() { return m_problem; }

private:
    int m_suit;
    int m_rank;
    std::string m_problem;
    int m_points;
};

class CardTexture {
public:
    CardTexture(std::string path, std::string prob, int posX, int posY);
    Texture cardTexture;
    Image temp;
    std::string problem;
    int x;
    int y;
};

class GameMenu {
public:
	GameMenu();
	void loadResources();
    void gameLogic();
    void userTurn();
    void dealerTurn();
    Cards cardSelect(int& points);
	Texture table;
	Texture hitButton;
	Texture standButton;
	Rectangle hitButtonRec;
	Rectangle standButtonRec;
    std::vector<CardTexture> userTextures;
    std::vector<CardTexture> dealerTextures;
private:
	int dealerPoints = 0;
	int userPoints = 0;
    int dealerPosX = 1285;
    int dealerPosY = 161;
    int userPosX = 1285;
    int userPosY = 721;
    bool isDealerTurn = false;
    bool isUserTurn = true;
    bool canUserPlay = true;
    bool isLMBPressed = false;
    std::vector<Cards> userDeck;
    std::vector<Cards> dealerDeck;
    
};