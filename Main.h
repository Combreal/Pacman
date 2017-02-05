#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();
private:
	bool quit;
	int ScreenWidth;
	int ScreenHeight;
	CSDL_Setup* csdl_setup;
	CSprite* BG;
};

