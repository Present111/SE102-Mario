#include "Data.h"

CData::CData() {
	Up = 4;
	score = 0;
	position_x_world_map = MARIO_START_WORLD_MAP_X;
	position_y_world_map = MARIO_START_WORLD_MAP_Y;
	level = 1;
	coin = 0;
	card1 = 0;
	card2 = 0;
	card3 = 0;
}

void CData::SavePositionXWorldMap(float f) { position_x_world_map = f; }
void CData::SavePositionYWorldMap(float f) { position_y_world_map = f; }
void CData::SaveLevel(int l) { level = l; }
void CData::SaveScore(int s) { score = s; }
void CData::SaveCoin(int c) { coin = c; }
void CData::SaveUp(int u) { Up = u; }
void CData::SaveCard1(int c1) { card1 = c1; }
void CData::SaveCard2(int c2) { card2 = c2; }
void CData::SaveCard3(int c3) { card3 = c3; }