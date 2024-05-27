#pragma once
#include "GameObject.h"

#define FIRE_BBOX_WIDTH 9
#define FIRE_BBOX_HEIGHT 9

#define FIRE_SPEED_X 0.06f
#define FIRE_SPEED_Y 0.06f

#define ADJUST_VECTOR_Y 30

#define CHANGE_DIRECTION 30
#define TIME_FIRE_DELETE 4000

#define ID_ANI_FIRE_RIGHT 71
#define ID_ANI_FIRE_LEFT 72

class CFireFromPlant :public CGameObject
{
	ULONGLONG start_deleted;
public:
	CFireFromPlant(float bx, float by, bool up, bool right);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
