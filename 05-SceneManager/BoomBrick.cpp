#include "BoomBrick.h"

void CBoomBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BOOMBRICK)->Render(x, y);
	//RenderBoundingBox();
}

void CBoomBrick::Update(DWORD dt)
{

}

void CBoomBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BOOMBRICK_BBOX_WIDTH / 2;
	t = y - BOOMBRICK_BBOX_HEIGHT / 2;
	r = l + BOOMBRICK_BBOX_WIDTH;
	b = t + BOOMBRICK_BBOX_HEIGHT;
}