﻿#include "PlantEnemy.h"
#include "GameObject.h"
#include "Mario.h"
#include "PlayScene.h"
#include "FireFromPlant.h"
#include "Goomba.h"
CPlantEnemy::CPlantEnemy(float x, float y, int model) : CGameObject(x, y)
{
	this->model = model;
	startY = y;
	minY = startY - PLANT_BBOX_HEIGHT;
	SetState(PLANT_STATE_UP);
}

void CPlantEnemy::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if (state == PLANT_STATE_DEATH) return;
	left = x - PLANT_BBOX_WIDTH / 2;
	top = y - PLANT_BBOX_HEIGHT / 2+4;
	right = left + PLANT_BBOX_WIDTH;
	bottom = top + PLANT_BBOX_HEIGHT;
}
void CPlantEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!checkObjectInCamera(this)) return;
	/*
	ULONGLONG time_out_pipe;
	ULONGLONG time_shoot;
	ULONGLONG time_down_pipe;
	*/
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (IsMarioOnPipe()) {
		// Không cho cây ăn thịt trồi lên nếu Mario đứng trên ống
		if (isUpping) {
			SetState(PLANT_STATE_DOWN);
		}
	}
	
	if (isUpping) {
		if (y > minY) {
			vy = -PLANT_SPEED_UP_DOWN;
		}
		else {
			time_shoot = GetTickCount64();
			vy = 0;
			y = minY;
			if (GetTickCount64() - time_out_pipe > TIME_OUT_PIPE) {
				SetState(PLANT_STATE_DOWN);
			}
			else {
				if (!isShoot) {
					if (GetTickCount64() - time_shoot < TIME_SHOOT) {
						isShoot = true;
						/*
						CGoomba* goomba = new CGoomba(x, y, GOOMBA_WING);
						scene->AddObject(goomba);
							int PositionYWithMario(); //1 if mario on top plant, -1 if mario underplant
							int PositionXWithMario(); //1 if mario left to plant, -1 if mario right to plant
						*/
						bool isOnTop = false, isLeft = false;
						if (PositionXWithMario() == 1) {
							isOnTop = true;
						}
						if (PositionYWithMario() == 1) {
							isLeft = true;
						}
						if (isOnTop && isLeft)
						{
							CFireFromPlant* fire = new CFireFromPlant(x, y, isLeft, !isOnTop);
							scene->AddObject(fire);
						}
						else if (isOnTop && !isLeft) {
							CFireFromPlant* fire = new CFireFromPlant(x, y, isLeft, !isOnTop);
							scene->AddObject(fire);
						}
						else if (!isOnTop && !isLeft) {
							CFireFromPlant* fire = new CFireFromPlant(x, y, isLeft, !isOnTop);
							scene->AddObject(fire);
						}
						else if (!isOnTop && isLeft) {
							CFireFromPlant* fire = new CFireFromPlant(x, y, isLeft, !isOnTop);
							scene->AddObject(fire);
						}
						// code phan ban dan
					}
				}
			}
		}
	}
	else if (isDowning) {
		if (y < startY + 2) {
			vy = PLANT_SPEED_UP_DOWN;
		}
		else {
			vy = 0;
			y = startY + 2;
			if (GetTickCount64() - time_down_pipe > TIME_DOWN_PIPE) {
				SetState(PLANT_STATE_UP);
			}
		}
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CPlantEnemy::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny > 0)
	{
		vy = 0;
	}
}
bool CPlantEnemy::IsMarioOnPipe() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	float marioLeft, marioTop, marioRight, marioBottom;
	mario->GetBoundingBox(marioLeft, marioTop, marioRight, marioBottom);

	float plantLeft, plantTop, plantRight, plantBottom;
	GetBoundingBox(plantLeft, plantTop, plantRight, plantBottom);

	return (marioBottom <= plantTop && marioBottom > plantTop - 5 && marioRight > plantLeft && marioLeft < plantRight);
}
int CPlantEnemy::PositionXWithMario() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetX() < GetX()) //mario left, plant right
	{
		return 1;
	}
	else return -1;
}

void CPlantEnemy::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

int CPlantEnemy::PositionYWithMario() {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (mario->GetY() < GetY()) //mario top, plant under
	{
		return 1;
	}
	else return -1;
}

void CPlantEnemy::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	if (model == PLANT_SHOOT) {
		if (PositionXWithMario() == 1 && PositionYWithMario() == -1)
			if (!isShoot) aniId = ID_ANI_PLANT_LEFT_UNDER_NOT_SHOOT;
			else aniId = ID_ANI_PLANT_LEFT_UNDER_SHOOT;
		else if (PositionXWithMario() == 1 && PositionYWithMario() == 1)
			if (!isShoot) aniId = ID_ANI_PLANT_LEFT_TOP_NOT_SHOOT;
			else aniId = ID_ANI_PLANT_LEFT_TOP_SHOOT;
		else if (PositionXWithMario() == -1 && PositionYWithMario() == 1)
			if (!isShoot) aniId = ID_ANI_PLANT_RIGHT_TOP_NOT_SHOOT;
			else aniId = ID_ANI_PLANT_RIGHT_TOP_SHOOT;
		else {
			if (!isShoot) aniId = ID_ANI_PLANT_RIGHT_UNDER_NOT_SHOOT;
			else aniId = ID_ANI_PLANT_RIGHT_UNDER_SHOOT;
		}


	}
	else {
		aniId = ID_ANI_PLANT_NOT_SHOOT;
	}

	animations->Get(aniId)->Render(x, y);
}

void CPlantEnemy::SetState(int state) {
	switch (state) {
	case PLANT_STATE_UP:
		isUpping = true;
		isDowning = false;
		isShoot = false;
		time_out_pipe = GetTickCount64();
		break;
	case PLANT_STATE_DOWN:
		isShoot = false;
		isUpping = false;
		isDowning = true;
		time_down_pipe = GetTickCount64();
		break;
	case PLANT_STATE_DEATH:
		isDeleted = true;
		break;
	}
	CGameObject::SetState(state);
}