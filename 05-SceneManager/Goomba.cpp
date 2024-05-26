#include "Goomba.h"
#include "Platform.h"
CGoomba::CGoomba(float x, float y,int model):CGameObject(x, y)
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;
	this->model = model;
	
	SetState(GOOMBA_STATE_WALKING);
	isUpside = false;
	isJump = false;
	isAttack = false;
	isDead = false;
}

void CGoomba::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (isUpside == true) { return; }
	if (state == GOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{ 
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking() && !e->obj->IsPlatform()) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;
	else {
		if (e->ny != 0)
		{
			vy = 0;
		}
		else if (e->nx != 0)
		{
			vx = -vx;
		}
	}
	
	if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatForm(e);
}

void CGoomba::OnCollisionWithPlatForm(LPCOLLISIONEVENT e)
{
	CPlatform* platform = dynamic_cast<CPlatform*>(e->obj);
	if (platform->IsBlocking()) {}
	else if (e->ny < 0) {
		SetY(platform->GetY() - GOOMBA_BBOX_HEIGHT-1);
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if ((isDead == true) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}
	if ((isUpside == true) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT * 2))
	{
		isDeleted = true;
		return;
	}



	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

int CGoomba::GetAniGoompaWing() {
	int aniId = -1;
	if (isAttack) {
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_RED_UPSIDE;
		}
		else {
			if (isDead) {
				aniId = ID_ANI_GOOMBA_RED_DIE;
			}
			else {
				aniId = ID_ANI_GOOMBA_RED;
			}
		}
	}
	else {
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_RED_UPSIDE;
		}
		else if (isJump) {
			aniId = ID_ANI_GOOMBA_RED_FLY_JUMP;
		}
		else aniId = ID_ANI_GOOMBA_RED_FLY_WALKING;
	}


	return aniId;
}

int CGoomba::GetAniGoompaBase() {
	int aniId = -1;
		if (isUpside) {
			aniId = ID_ANI_GOOMBA_UPSIDE;
		}
		else {
			if (isDead) {
				aniId = ID_ANI_GOOMBA_DIE;
			}
			else {
				aniId = ID_ANI_GOOMBA_WALKING;
			}
		}
	return aniId;
}


void CGoomba::Render()
{
	int aniId = -1;
	if (model == GOOMBA_WING) {
		aniId = GetAniGoompaWing();
	}
	else{
		aniId = GetAniGoompaBase();
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x,y);
	//RenderBoundingBox();
}

void CGoomba::SetState(int state)
{	
	switch (state)
	{
		case GOOMBA_STATE_DIE:
			die_start = GetTickCount64();
			y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
			vx = 0;
			vy = 0;
			isDead = true;
			isUpside = false;
			break;
		case GOOMBA_STATE_WALKING: 
			if (model == GOOMBA_BASE) {
				vx = -GOOMBA_WALKING_SPEED;
				isDead = false;
				isJump = false;
				isAttack = false;
				isUpside = false;
			}
			else {
				isDead = false;
				isJump = false;
				isAttack = false;
				isUpside = false;
				vx = -GOOMBA_WALKING_SPEED;
				time_walking = GetTickCount64();
			}
			break;
		case GOOMBA_STATE_FLY:
			vy = -GOOMBA_JUMP_DEFLECT_SPEED;
			isJump = true;
			break;
		case GOOMBA_STATE_IS_ATTACK:
			vx = -GOOMBA_WALKING_SPEED;
			if (model == GOOMBA_WING) {
				if (!isAttack) {
					isAttack = true;
					isDead = false;
					isJump = false;
					isUpside = false;
				}
				else {
					vx = 0;
					die_start = GetTickCount64();
					isDead = true;
					isJump = false;
					isUpside = false;
				}
			}
			else {
				vx = 0;
				die_start = GetTickCount64();
				isDead = true;
				isJump = false;
				isUpside = false;
			};
			break;
		case GOOMBA_STATE_DIE_UPSIDE:
			vx = 0;
			vy = -GOOMBA_JUMP_DEFLECT_SPEED;
			isUpside = true;
			die_start = GetTickCount64();

			break;
	}
	CGameObject::SetState(state);
}


