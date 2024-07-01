#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "Game.h"

class CKoopaGreenIntro :public CGameObject
{
public:
	CKoopaGreenIntro(float x, float y) : CGameObject(x, y)
	{
		vx = 0.05;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
};
