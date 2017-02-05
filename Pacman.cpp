#include "stdafx.h"
#include "Main.h"
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
	int xscreen = GetSystemMetrics(SM_CXSCREEN);
	int yscreen = GetSystemMetrics(SM_CYSCREEN);
	CMain* cmain = new CMain(xscreen,yscreen);
	cmain->GameLoop();
	delete cmain;
	return 0;
}