#pragma once
#include "GameObject.h"
#include "Animations.h"
#include "Animation.h"

#define BOOMBRICK_BBOX_WIDTH 16
#define BOOMBRICK_BBOX_HEIGHT 16
#define ID_ANI_BOOMBRICK 10001

#define BOOMBRICK_COIN 1
#define BOOMBRICK_NOT_COIN 2

class CBoomBrick : public CGameObject
{
protected:
	int model;
public:
	CBoomBrick(float x, float y, int model) : CGameObject(x, y)
	{
		this->model = model;
	}
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};