#pragma once
#include "GameObject.h"

#define FIRE_BBOX_WIDTH_PLANT 9
#define FIRE_BBOX_HEIGHT_PLANT 9

#define FIRE_SPEED_X_PLANT 0.06f
#define FIRE_SPEED_Y_PLANT 0.06f

#define ADJUST_VECTOR_Y 30

#define CHANGE_DIRECTION 30
#define TIME_FIRE_DELETE 10000

#define ID_ANI_FIRE_RIGHT 71
#define ID_ANI_FIRE_LEFT 72

class CFireFromPlant :public CGameObject
{
protected:
	ULONGLONG start_deleted;
	virtual int IsCollidable() { return 1; }

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
