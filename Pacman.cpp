#include "stdafx.h"
#include "Main.h"

int main(int argc, char *argv[])
{
	CMain* cmain = new CMain(800,600);
	cmain->GameLoop();
	delete cmain;
	return 0;
}