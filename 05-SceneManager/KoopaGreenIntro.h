#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "Game.h"

class CKoopaGreenIntro :public CGameObject
{
	int typespeed;//0 la cham 1 la nhanh
public:
	CKoopaGreenIntro(float x, float y,float typespeed) : CGameObject(x, y)
	{
		this->typespeed = typespeed;
		vx = 0;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	void SetVx(float vx)
	{
		this->vx = vx;
	}
	int Gettypespeed()
	{
		return this->typespeed;
	}
};
