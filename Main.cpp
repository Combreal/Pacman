#include "stdafx.h"
#include "Main.h"
using namespace std;

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	CameraX = 0;
	CameraY = 0;
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;
	pause = false;
	MouseX, MouseY = 0;
	csdl_setup = new CSDL_Setup(&quit, passed_ScreenWidth, passed_ScreenHeight);
	BG = new CSprite(csdl_setup->GetRenderer(), "data/background/worlda.png", 0, 0, passed_ScreenWidth, passed_ScreenHeight, &CameraX, &CameraY, CCollisionRectangle(0, 0, 0, 0));
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete BG;
}

void CMain::GameLoop()
{
	while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		csdl_setup->Begin();
		BG->Draw();
		csdl_setup->End();
	}
}