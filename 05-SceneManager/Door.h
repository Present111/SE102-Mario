#pragma once
#include "GameObject.h"

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Game.h"
#include "PlayScene.h"

#define ID_ANI_DOOR_START 25010
#define ID_ANI_DOOR_1 25011
#define ID_ANI_DOOR_2 25012
#define ID_ANI_DOOR_3 25013
#define ID_ANI_DOOR_4 25014
#define ID_ANI_DOOR_5 25015
#define ID_ANI_DOOR_6 25016
#define DOOR_BBOX_WIDTH 16
#define DOOR_BBOX_HEIGHT 16

#define DOOR_WORLD_START 1
#define DOOR_WORLD_1_1 3
#define DOOR_WORLD_1_2 4
#define DOOR_WORLD_1_3 5
#define DOOR_WORLD_1_4 6
#define DOOR_WORLD_1_5 7
#define DOOR_WORLD_1_6 8


class CDoor :
	public CGameObject
{
private:
	int model;
	int idScene;

	bool allowLeft;
	bool allowTop;
	bool allowRight;
	bool allowBottom;
public:
	CDoor(float x, float y, int model, bool allowLeft, bool allowTop, bool allowRight, bool allowBottom) : CGameObject(x, y) {
		this->model = model;
		this->idScene = ID_SCENE_WORLD_1_1;// dat nhu vay la vi chi ton tai world 1-1
		this->allowLeft = allowLeft;
		this->allowTop = allowTop;
		this->allowRight = allowRight;
		this->allowBottom = allowBottom;
	}
	void Render();
	void Update(DWORD dt) {}
	int GetIdScene() { return idScene; }
	bool GetAllowLeft() { return allowLeft; }
	bool GetAllowTop() { return allowTop; }
	bool GetAllowRight() { return allowRight; }
	bool GetAllowBottom() { return allowBottom; }
	virtual int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};


