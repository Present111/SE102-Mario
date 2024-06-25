#include "BoomBrick.h"
#include "PlayScene.h"
#include "Game.h"
#include "debug.h"
#include "BreakBrick.h"
#include "Button.h"
#include "Coin.h"

void CBoomBrick::Render()
{
	if (!checkObjectInCamera(this)) return;

	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BOOMBRICK)->Render(x, y);
	//RenderBoundingBox();
}


void CBoomBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BOOMBRICK_BBOX_WIDTH / 2;
	t = y - BOOMBRICK_BBOX_HEIGHT / 2;
	r = l + BOOMBRICK_BBOX_WIDTH;
	b = t + float(BRICK_BBOX_HEIGHT / 1.5);
}
void CBoomBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!checkObjectInCamera(this)) return;
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	if (isUseButton) {
		if (!isStopLoop)
		{
			SetState(BRICK_STATE_GOLD);
			isStopLoop = true;
		}
	}
	else {
		CButton* button = NULL;
		for (size_t i = 0; i < scene->GetListObject().size(); i++) {
			if (scene->GetListObject()[i]->IsButton() == 1) {
				button = dynamic_cast<CButton*>(scene->GetListObject()[i]);
				if (button->GetIsCollected()) isUseButton = true;
				button = NULL;
				break;
			}
		}
	}
	if (isBreak) {
		CBreakBrick* break1 = new CBreakBrick(x, y);
		break1->SetState(BREAK_STATE_TOP_RIGHT);
		CBreakBrick* break2 = new CBreakBrick(x, y);
		break2->SetState(BREAK_STATE_TOP_LEFT);
		CBreakBrick* break3 = new CBreakBrick(x, y);
		break3->SetState(BREAK_STATE_BOTTOM_RIGHT);
		CBreakBrick* break4 = new CBreakBrick(x, y);
		break4->SetState(BREAK_STATE_BOTTOM_LEFT);
		scene->AddObject(break1);
		scene->AddObject(break2);
		scene->AddObject(break3);
		scene->AddObject(break4);
		Delete();
		isBreak = false;
	}
	if (isGold) {
		CCoin* coin = new CCoin(x, y);
		scene->AddObject(coin);
		Delete();
		isGold = false;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CBoomBrick::SetState(int state) {
	switch (state) {
	case BRICK_STATE_DELETE:
		isBreak = true;
		platform->Delete();
		break;
	case BRICK_STATE_GOLD:
		platform->Delete();
		isGold = true;
		break;
	}
	CGameObject::SetState(state);
}