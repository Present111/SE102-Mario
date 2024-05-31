#include "InvisibleBlock.h"

void CInvisibleBlock::Render()
{
	RenderBoundingBox();
}

void CInvisibleBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - INVISIBLE_BLOCK_BBOX_WIDTH / 2;
	t = y - INVISIBLE_BLOCK_BBOX_HEIGHT / 2;
	r = l + INVISIBLE_BLOCK_BBOX_WIDTH;
	b = t + INVISIBLE_BLOCK_BBOX_HEIGHT;
}