#include "Sprite.h"
using namespace std;

CSprite::CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == NULL)
	{
		cout << "Couldn't load " << FilePath.c_str() << endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	X_pos = x;
	Y_pos = y;
	Origin_X = 0;
	Origin_Y = 0;
	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
	crop.x = 0;
	crop.y = 0;
	crop.w = img_width;
	crop.h = img_height;
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
}

void CSprite::Draw()
{
	SDL_RenderCopy(renderer, image, &crop, &rect);
}

void CSprite::SetX(int X)
{
	X_pos = X;
	rect.x = int(X_pos-Origin_X);
}

void CSprite::SetY(int Y)
{
	Y_pos = Y;
	rect.y = int(Y_pos-Origin_Y);
}


void CSprite::SetPosition(int X, int Y)
{
	X_pos = X;
	rect.x = int(X_pos-Origin_X);
	Y_pos = Y;
	rect.y = int(Y_pos-Origin_Y);
}

int CSprite::GetX()
{
	return X_pos;
}

int CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrigin(int X, int Y)
{
	Origin_X= X;
	Origin_Y= Y;
	SetPosition(GetX(), GetY());
}

void CSprite::SetWidth(int W)
{
	rect.w = W;
}

void CSprite::SetHeight(int H)
{
	rect.h = H;
}

int CSprite::GetWidth()
{
	return rect.w;
}

int CSprite::GetHeight()
{
	return rect.h;
}
