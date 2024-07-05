#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "Game.h"

class CInvisibleBlock :public CGameObject
{
	float ax, ay;
	bool ReBack;
public:
	CInvisibleBlock(float x, float y) : CGameObject(x, y)
	{
		vy = 0.7/2;
		ax = 0;
		ay = 0;
		ReBack = 0;
	}
	void ReSetReBack()
	{
		this->ReBack = 0;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsCollidable() { return 1; };
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	void SetX(float x)
	{
		this->x = x;
	}
	void SetY(float y)
	{
		this->y = y;
	}
	bool GetReBack()
	{
		return this->ReBack;
	}
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithPlatForm(LPCOLLISIONEVENT e);
};
