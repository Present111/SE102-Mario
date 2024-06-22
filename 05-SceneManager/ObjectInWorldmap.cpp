#include "ObjectInWorldMap.h"
#include "Grass.h"

void CObjectInWorldMap::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_GRASS)->Render(x, y);
	//RenderBoundingBox();
}

void CObjectInWorldMap::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - OBJECT_BBOX_WIDTH / 2;
	t = y - OBJECT_BBOX_HEIGHT / 2;
	r = l + OBJECT_BBOX_WIDTH;
	b = t + OBJECT_BBOX_HEIGHT;
}