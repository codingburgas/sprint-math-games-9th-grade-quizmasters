#include "mainMenu.h"

MainMenu::MainMenu() {
	startButtonRec.x = 660;
	startButtonRec.y = 600;
	startButtonRec.width = 600;
	startButtonRec.height = 300;
}
void MainMenu::loadResources() {
	background = LoadTexture("././assets/MainMenu-Background.png");
	startButton = LoadTexture("././assets/Start_button.png");
	title = LoadTexture("././assets/title.png");
}	