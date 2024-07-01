#include "Back.h"
#include "FontIntro.h"
#include "debug.h"
#include "IntroScene.h"

void CBack::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BACK)->Render(x, y);
	//RenderBoundingBox();
}

void CBack::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CIntroScene* scene = (CIntroScene*)CGame::GetInstance()->GetCurrentScene();
	//DebugOutTitle(L"y vy %f %f", y, vy);
	if (y < -100)
	{
		y = -100;
		vy = 0;
		CFontIntro* font = new CFontIntro();
		scene->AddObject(font);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CBack::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}