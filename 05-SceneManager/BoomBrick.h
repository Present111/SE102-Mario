#pragma once
#include "GameObject.h"
#include "Animations.h"
#include "Animation.h"
#include "Platform.h"
#include"Game.h"
#include"PlayScene.h"

#define BOOMBRICK_BBOX_WIDTH 16
#define BOOMBRICK_BBOX_HEIGHT 16
#define ID_ANI_BOOMBRICK 10001

#define BOOMBRICK_COIN 1

#define BRICK_STATE_DELETE 100
#define BRICK_STATE_GOLD 200

class CBoomBrick : public CGameObject
{
	CPlatform* platform;
	bool isBreak = false;
	bool isGold = false;
	bool isUseButton = false;
	bool isStopLoop = false;
protected:
	int model;
public:
	CBoomBrick(float x, float y, int model) : CGameObject(x, y) {
		this->model = model;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
};