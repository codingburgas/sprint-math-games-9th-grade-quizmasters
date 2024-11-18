#pragma once
#include "../lib/precompile.h"

struct Problems{
    std::string CardTwo[4] {"1+1","2:1","3-1","1*2"};
    std::string CardThree[4] {"1+2","75:25","64-61","1*3"};
    std::string CardFour[4] {"1+3","64:16","20-16","2*2"};
    std::string CardFive[4] {"2+3","125:25","12-7","2,5*2"};
    std::string CardSix[4] {"1+5","66:11","8-2","3*2"};
    std::string CardSeven[4] {"3+4","56:8","14-7","3,5*2"};
    std::string CardEight[4] {"4+4","32:8","16-8","2*4"};
    std::string CardNine[4] {"5+4","36:4","19-10","3*3"};
    std::string CardTen[4] {"8+2","400:40","60-50","1*10"};
    std::string CardJack[4] {"7+3","300:30","50-40","10*1"};
    std::string CardQueen[4] {"6+4","200:20","40-30","5*2"};
    std::string CardKing[4] {"5+5","100:10","30-20","2*5"};
};

class Cards {
public:
    Cards(int suit,int rank,std::string problem);

private:
    int m_suit;
    int m_rank;
    std::string m_problem;

};