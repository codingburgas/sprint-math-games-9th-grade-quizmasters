#include "../lib/Deck.h"

Cards::Cards(int suit,int rank,std::string problem) {
    m_suit=suit;
    m_rank=rank;
    m_problem=problem;
}
Cards cardSelect(int points)
{
    int cardPoints;

    Problems problems;
    std::random_device rd;
    std::uniform_int_distribution<int> cardDist(1, 13);
    std::uniform_int_distribution<int> problemDist(0, 3);
    int randomCard = cardDist(rd);
    int randomProblemIndex = problemDist(rd);
    std::string selectedProblem;
    switch (randomCard) {
        case 1:
            if(points > 10)
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
    }
}

