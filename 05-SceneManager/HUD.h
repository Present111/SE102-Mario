#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Mario.h"

#define FONT_BBOX_WIDTH	8
#define DEFAULT_TIME	300
#define ID_ANI_HUD 30000
#define ID_ANI_BLACK_RECTANGEL 30001
class CHUD
{
protected:
	float x, y;
public:
	CHUD(float x, float y);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};