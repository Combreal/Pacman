#include "StdAfx.h"
#include "CollisionRectangle.h"
#pragma once
class CSprite
{
public:
	CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *passed_CameraX, float *passed_CameraY, CCollisionRectangle passed_CollisionRect);
	~CSprite(void);
	void Draw();
	void DrawSteady();
	void SetX(float X);
	void SetY(float Y);
	void SetPosition(float X, float Y);
	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();
	void SetWidth(int W);
	void SetHeight(int H);
	void SetOrigin(float X, float Y);
	//void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);
	void ImageDirection(int Pillar, int Line);
	void TimerCrop(int Pillar);
	bool isColliding(CCollisionRectangle theCollider);
	CCollisionRectangle GetCollisionRect() { return CollisionRect;}
private:
	CCollisionRectangle CollisionRect;
	SDL_Rect Camera;
	float *CameraX;
	float *CameraY;
	float Origin_X;
	float Origin_Y;
	float X_pos;
	float Y_pos;
	int animationDelay;
	SDL_Texture* image;
	SDL_Texture* CollisionImage;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Renderer* renderer;
	int img_width;
	int img_height;
	int CurrentFrame;
};

