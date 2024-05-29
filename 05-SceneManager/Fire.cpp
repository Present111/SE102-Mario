#include "Fire.h"
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Animation.h"
#include "PlantEnemy.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Pipe.h"
#include "Map.h"
CFire::CFire(float bx, float by)
{
	ay = FIRE_GRAVITY;
	ax = 0;
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	y = by;
	vy = FIRE_SPEED_Y;


	if (mario->GetNx() > 0) {
		x = bx + MARIO_BIG_BBOX_WIDTH;
		vx = FIRE_SPEED_X;
	}
	else
	{
		x = bx - MARIO_BIG_BBOX_WIDTH;
		vx = -FIRE_SPEED_X;
	}
}
void CFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CFire::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	int aniId = 0;
	if (vx > 0)
		aniId = ID_ANI_FIRE_RIGHT;
	else
		aniId = ID_ANI_FIRE_LEFT;
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}
void CFire::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + FIRE_BBOX_WIDTH;
	b = y + FIRE_BBOX_HEIGHT;
}

void CFire::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (e->obj->IsItem()) return;
	if (dynamic_cast<CFire*>(e->obj)) return;
	if (e->obj->IsPlatform() || e->obj->IsBlocking() || !e->obj->IsEnemy()) {
		if (e->nx != 0) {
			isDeleted = true;
			//vx = -vx;
		}
		else if (e->ny < 0) {
			vy = -FIRE_JUMP;
		}
		return;
	}

	if (dynamic_cast<CGoomba*>(e->obj)) OnCollisionWithGoomba(e);
	else if (dynamic_cast<CKoopa*>(e->obj)) OnCollisionWithKoopa(e);
	else if (dynamic_cast<CPlantEnemy*>(e->obj)) OnCollisionWithPlantEnemy(e);
}

void CFire::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	goomba->SetState(GOOMBA_STATE_DIE_UPSIDE);
}

void CFire::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	koopa->SetState(KOOPA_STATE_DEAD_UPSIDE);
}

void CFire::OnCollisionWithPlantEnemy(LPCOLLISIONEVENT e) {
	isDeleted = true;
	CPlantEnemy* plant = dynamic_cast<CPlantEnemy*>(e->obj);
	plant->SetState(PLANT_STATE_DEATH);
}