#include "FireFromPlant.h"
#include "Mario.h"
#include "PlayScene.h"
#include "Animation.h"
#include "PlantEnemy.h"
#include "Map.h"
CFireFromPlant::CFireFromPlant(float bx, float by, bool up, bool right)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	if (up)
	{
		y = by;
		vy = -abs((mario->GetY() - GetY())) / ADJUST_VECTOR_Y * FIRE_SPEED_Y;
	}
	else
	{
		y = by + FIRE_BBOX_HEIGHT;
		vy = abs((mario->GetY() - GetY()) - CHANGE_DIRECTION) / ADJUST_VECTOR_Y * FIRE_SPEED_Y;
	}


	if (right)
	{
		x = bx + PLANT_BBOX_WIDTH;
		vx = FIRE_SPEED_X;
	}
	else
	{
		x = bx - FIRE_BBOX_WIDTH;
		vx = -FIRE_SPEED_X;
	}
	start_deleted = GetTickCount64();
}
void CFireFromPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - start_deleted > TIME_FIRE_DELETE) {
		isDeleted = true;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CFireFromPlant::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	int aniId = 0;
	if (vx > 0)
		aniId = ID_ANI_FIRE_RIGHT;
	else
		aniId = ID_ANI_FIRE_LEFT;
	animations->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}
void CFireFromPlant::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + FIRE_BBOX_WIDTH;
	b = y + FIRE_BBOX_HEIGHT;
}
void CFireFromPlant::OnCollisionWith(LPCOLLISIONEVENT e) {


}