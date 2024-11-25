#pragma once
#include "deck.h"
#include "mainMenu.h"


class App {
public:
	App();
	void update();
	void display();
	void playerHand();
	MainMenu mainMenu;

};
