#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define INVISIBLE_BLOCK_WIDTH 16
#define INVISIBLE_BLOCK_BBOX_WIDTH 16
#define INVISIBLE_BLOCK_BBOX_HEIGHT 16

class CInvisibleBlock : public CGameObject {
public:
	CInvisibleBlock(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 1; };

};
