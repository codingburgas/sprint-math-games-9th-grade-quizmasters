#pragma once
#include "precompile.h"

class MainMenu {
public:
	MainMenu();
	Texture background;
	Texture startButton;
	Texture title;
	Rectangle startButtonRec;
	void loadResources();
};
