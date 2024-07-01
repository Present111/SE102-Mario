#pragma once
#include "GameObject.h"
#include "Game.h"
#include "Animation.h"
#include "Animations.h"
#include "IntroScene.h"
#define ID_ANI_BACK	40070

class CBack : public CGameObject
{
public:
	CBack(float x, float y) :CGameObject(x, y)
	{
		vy = -0.06;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnNoCollision(DWORD dt) {
		y += vy * dt;
	}
};

