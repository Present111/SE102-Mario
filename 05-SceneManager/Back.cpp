#include "Back.h"

void CBack::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BACK)->Render(x, y);
	//RenderBoundingBox();
}

void CBack::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

}
void CBack::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}