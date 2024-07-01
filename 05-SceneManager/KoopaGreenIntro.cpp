#include "KoopaGreenIntro.h"
#include "Koopa.h"
void CKoopaGreenIntro::Render()
{
	int aniId = -1;
	if (vx > 0) aniId = ID_ANI_GREEN_WALK_RIGHT;
	else aniId = ID_ANI_GREEN_WALK_LEFT;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}
void CKoopaGreenIntro::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CKoopaGreenIntro::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - 16 / 2;
	t = y - 16 / 2;
	r = l + 16;
	b = t + 16;
}