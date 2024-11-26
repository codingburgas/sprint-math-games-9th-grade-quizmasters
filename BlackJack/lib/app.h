#pragma once
#include "mainMenu.h"
#include "gameMenu.h"

struct Pages {
	bool mainMenu = 1;
	bool game = 0;
};

class App {
public:
	App();
	void update();
	void appLogic();
	void display();
	void drawMainMenu();
	void drawGame();
	MainMenu mainMenu;
	GameMenu gameMenu;
	Pages pages;
};
