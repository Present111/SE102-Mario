#pragma once
#include "GameObject.h"

#define ID_ANI_FLOWER 11003
#define FL_BBOX_WIDTH 10
#define FL_BBOX_HEIGHT 16
class CFlowerFire :	public CGameObject
{
	float ay;
	float firstYPosition;
public:
	CFlowerFire(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsCollidable() { return 1; }
	virtual void OnNoCollision(DWORD dt);
	int IsBlocking() { return 0; }
};

