#include "mainMenu.h"

MainMenu::MainMenu() {
	loadResources();
}
void MainMenu::loadResources() {
	BackgroundImage = LoadImage("../assets/MainMenu-Background.png");
	background = LoadTextureFromImage(BackgroundImage);
}