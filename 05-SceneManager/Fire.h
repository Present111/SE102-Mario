#pragma once
#include "GameObject.h"
#define FIRE_BBOX_WIDTH	8
#define FIRE_BBOX_HEIGHT 8

#define FIRE_SPEED_X	0.2f
#define FIRE_SPEED_Y	0.05f

#define FIRE_GRAVITY 0.0006f;
#define FIRE_JUMP 0.15f;

#define ID_ANI_FIRE_RIGHT		71
#define ID_ANI_FIRE_LEFT		72	

class CFire :public CGameObject
{
protected:
	float ax, ay;

	virtual int IsCollidable() { return 1; }

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e);
public:
	CFire(float bx, float by);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
	}
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int IsBlocking() { return 0; }

	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

};
