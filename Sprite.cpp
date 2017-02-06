#include "Sprite.h"
using namespace std;


CSprite::CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *passed_CameraX, float *passed_CameraY, CCollisionRectangle passed_CollisionRect)
{
	CollisionRect = passed_CollisionRect;
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == NULL)
	{
		cout << "couldn't load " << FilePath.c_str() << endl;
	}
	CollisionImage = NULL;
	CollisionImage = IMG_LoadTexture(renderer, "data/debug/CollisionBox.png");
	if (CollisionImage == NULL)
	{
		cout << "couldn't load CollisionImage" << endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	X_pos = (float)x;
	Y_pos = (float)y;
	Origin_X = 0;
	Origin_Y = 0;
	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
	crop.x = 0;
	crop.y = 0;
	crop.w = img_width; //400; //img_width;
	crop.h = img_height; //415;//img_height;
	//CurrentFrame = 0;
	CameraX = passed_CameraX;
	CameraY = passed_CameraY;
	Camera.x = rect.x + static_cast<int>(*CameraX);
	Camera.y = rect.y + static_cast<int>(*CameraY);
	Camera.w = rect.w;
	Camera.h = rect.h;
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(image);
}

void CSprite::Draw()
{
	Camera.x = rect.x + static_cast<int>(*CameraX);
	Camera.y = rect.y + static_cast<int>(*CameraY);
	CollisionRect.SetX(rect.x + static_cast<int>(*CameraX));
	CollisionRect.SetY(rect.y + static_cast<int>(*CameraY));
	SDL_RenderCopy(renderer, image, &crop, &Camera);
	//SDL_RenderCopy(renderer, CollisionImage, NULL, &CollisionRect.GetRectangle());// pour le debug des collisionboxies
}

void CSprite::DrawSteady()
{
	Camera.x = rect.x + static_cast<int>(*CameraX);
	Camera.y = rect.y + static_cast<int>(*CameraY);
	//SDL_RenderCopy(renderer, CollisionImage, &crop, &rect);
	SDL_RenderCopy(renderer, CollisionImage, NULL, &CollisionRect.GetRectangle());
}

bool CSprite::isColliding(CCollisionRectangle theCollider)
{
	return !(CollisionRect.GetRectangle().x + CollisionRect.GetRectangle().w < theCollider.GetRectangle().x || CollisionRect.GetRectangle().y + CollisionRect.GetRectangle().h < theCollider.GetRectangle().y || CollisionRect.GetRectangle().x > theCollider.GetRectangle().x + theCollider.GetRectangle().w || CollisionRect.GetRectangle().y > theCollider.GetRectangle().y + theCollider.GetRectangle().h); //check si il y a collision sur un des quatres coins
}

/*void CSprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed)
{
	if(animationDelay+Speed < SDL_GetTicks())
	{
		if (EndFrame <= CurrentFrame)
			CurrentFrame = BeginFrame;
		else
			CurrentFrame++;
		crop.x = CurrentFrame*(img_width/2);
		crop.y = Row*(img_height/2);
		crop.w = img_width/2;
		crop.h = img_height/2;
		animationDelay = SDL_GetTicks();
	}
}*/

void CSprite::ImageDirection(int Pillar, int Line)
{
	crop.x = Pillar*(img_width/2);
	crop.y = Line*(img_height/2);
	crop.w = img_width/2;
	crop.h = img_height/2;
}

void CSprite::SetX(float X)
{
	X_pos = X;
	rect.x = int(X_pos-Origin_X);
}

void CSprite::SetY(float Y)
{
	Y_pos = Y;
	rect.y = int(Y_pos-Origin_Y);
}

void CSprite::SetPosition(float X, float Y)
{
	X_pos = X;
	rect.x = int(X_pos-Origin_X);
	Y_pos = Y;
	rect.y = int(Y_pos-Origin_Y);
}

float CSprite::GetX()
{
	return X_pos;
}

float CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrigin(float X, float Y)
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

void CSprite::TimerCrop(int Pillar)
{
	crop.x = Pillar*(6);
	crop.w = 6;
	crop.h = img_height;
}