﻿#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20


#define OBJECT_TYPE_MARIO	0
#define OBJECT_TYPE_BRICK	1
#define OBJECT_TYPE_GOOMBA	2
#define OBJECT_TYPE_GOOMBA_FLY	3
#define OBJECT_TYPE_KOOPA_GREEN	4
#define OBJECT_TYPE_KOOPA_GREEN_FLY 5
#define OBJECT_TYPE_KOOPA_RED 6
#define OBJECT_TYPE_INVISIBLE_BLOCK 7
#define OBJECT_TYPE_COIN 30
#define OBJECT_TYPE_MUSHROOM 31
#define OBJECT_TYPE_LEAF 32
#define OBJECT_TYPE_FLOWERFIRE 33
#define OBJECT_TYPE_BRICKQUESTION_COIN 34
#define OBJECT_TYPE_BRICKQUESTION_ITEM 35
#define OBJECT_TYPE_MUSHROOM_GREEN 36
#define OBJECT_TYPE_BRICKQUESTION_MUSHROOM_GREEN 37
#define OBJECT_TYPE_PIPE_SHORT 60
#define OBJECT_TYPE_PIPE_LONG 70
#define OBJECT_TYPE_PIPE_LONG_GREEN 75
#define OBJECT_TYPE_PLANT_SHOOT 80
#define OBJECT_TYPE_PLANT_NOT_SHOOT 90
#define OBJECT_TYPE_BLOCK 500

#define OBJECT_TYPE_PLATFORM 40

#define OBJECT_TYPE_PORTAL	50


#pragma region MARIO 

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000) //11000
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100) //11100
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10) //11110
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20) //11120

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)//11200
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)//11210
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)//11220
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)//11300
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)//11310
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)//11320
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)//11400
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)//11410
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)//11412
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)//11416
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)//11420
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2)//11422
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)//11426
#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)//11500
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)//11510
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)//11520
#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)//11600
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)//11610
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)//11620

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 5000)//15000

#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)//12000
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)//12100
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)//12110
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)//12120

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)//12200
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)//12210
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)//12220
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)//12300
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)//12310
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)//12320
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)//12400
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)//12410
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)//12412
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)//12416
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)//12420
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)//12422
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)//12426

#define ID_SPRITE_MARIO_SMALL_SIT (ID_SPRITE_MARIO_SMALL + 500)//12500
#define ID_SPRITE_MARIO_SMALL_SIT_LEFT (ID_SPRITE_MARIO_SMALL_SIT + 10)//12510
#define ID_SPRITE_MARIO_SMALL_SIT_RIGHT (ID_SPRITE_MARIO_SMALL_SIT + 20)//12520

#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 600)//12600
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)//12610
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)//12620


#define ID_SPRITE_MARIO_FIRE (ID_SPRITE_MARIO + 3000)//13000
#define ID_SPRITE_MARIO_FIRE_IDLE (ID_SPRITE_MARIO_FIRE + 100)//13100
#define ID_SPRITE_MARIO_FIRE_IDLE_LEFT (ID_SPRITE_MARIO_FIRE_IDLE + 10)//13110
#define ID_SPRITE_MARIO_FIRE_IDLE_RIGHT (ID_SPRITE_MARIO_FIRE_IDLE + 20)//13120

#define ID_SPRITE_MARIO_FIRE_WALKING (ID_SPRITE_MARIO_FIRE + 200)//13200
#define ID_SPRITE_MARIO_FIRE_WALKING_LEFT (ID_SPRITE_MARIO_FIRE_WALKING + 10)//13210
#define ID_SPRITE_MARIO_FIRE_WALKING_RIGHT (ID_SPRITE_MARIO_FIRE_WALKING + 20)//13220
#define ID_SPRITE_MARIO_FIRE_RUNNING (ID_SPRITE_MARIO_FIRE + 300)//13300
#define ID_SPRITE_MARIO_FIRE_RUNNING_LEFT (ID_SPRITE_MARIO_FIRE_RUNNING + 10)//13310
#define ID_SPRITE_MARIO_FIRE_RUNNING_RIGHT (ID_SPRITE_MARIO_FIRE_RUNNING + 20)//13320
#define ID_SPRITE_MARIO_FIRE_JUMP (ID_SPRITE_MARIO_FIRE + 400)//13400
#define ID_SPRITE_MARIO_FIRE_JUMP_WALK (ID_SPRITE_MARIO_FIRE_JUMP + 10)//13410
#define ID_SPRITE_MARIO_FIRE_JUMP_WALK_LEFT (ID_SPRITE_MARIO_FIRE_JUMP_WALK + 2)//13412
#define ID_SPRITE_MARIO_FIRE_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_FIRE_JUMP_WALK + 6)//13416
#define ID_SPRITE_MARIO_FIRE_JUMP_RUN (ID_SPRITE_MARIO_FIRE_JUMP + 20)//13420
#define ID_SPRITE_MARIO_FIRE_JUMP_RUN_LEFT (ID_SPRITE_MARIO_FIRE_JUMP_RUN + 2)//13422
#define ID_SPRITE_MARIO_FIRE_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_FIRE_JUMP_RUN + 6)//13426

#define ID_SPRITE_MARIO_FIRE_SIT (ID_SPRITE_MARIO_FIRE + 500)//13500
#define ID_SPRITE_MARIO_FIRE_SIT_LEFT (ID_SPRITE_MARIO_FIRE_SIT + 10)//13510
#define ID_SPRITE_MARIO_FIRE_SIT_RIGHT (ID_SPRITE_MARIO_FIRE_SIT + 20)//13520

#define ID_SPRITE_MARIO_FIRE_BRACE (ID_SPRITE_MARIO_FIRE + 600)//13600
#define ID_SPRITE_MARIO_FIRE_BRACE_LEFT (ID_SPRITE_MARIO_FIRE_BRACE + 10)//13610
#define ID_SPRITE_MARIO_FIRE_BRACE_RIGHT (ID_SPRITE_MARIO_FIRE_BRACE + 20)//13620


#define ID_SPRITE_MARIO_TAIL (ID_SPRITE_MARIO + 4000)//14000
#define ID_SPRITE_MARIO_TAIL_IDLE (ID_SPRITE_MARIO_TAIL + 100)//14100
#define ID_SPRITE_MARIO_TAIL_IDLE_LEFT (ID_SPRITE_MARIO_TAIL_IDLE + 10)//14110
#define ID_SPRITE_MARIO_TAIL_IDLE_RIGHT (ID_SPRITE_MARIO_TAIL_IDLE + 20)//14120

#define ID_SPRITE_MARIO_TAIL_WALKING (ID_SPRITE_MARIO_TAIL + 200)//14200
#define ID_SPRITE_MARIO_TAIL_WALKING_LEFT (ID_SPRITE_MARIO_TAIL_WALKING + 10)//14210
#define ID_SPRITE_MARIO_TAIL_WALKING_RIGHT (ID_SPRITE_MARIO_TAIL_WALKING + 20)//14220
#define ID_SPRITE_MARIO_TAIL_RUNNING (ID_SPRITE_MARIO_TAIL + 300)//14300
#define ID_SPRITE_MARIO_TAIL_RUNNING_LEFT (ID_SPRITE_MARIO_TAIL_RUNNING + 10)//14310
#define ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT (ID_SPRITE_MARIO_TAIL_RUNNING + 20)//14320
#define ID_SPRITE_MARIO_TAIL_JUMP (ID_SPRITE_MARIO_TAIL + 400)//14400
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK (ID_SPRITE_MARIO_TAIL_JUMP + 10)//14410
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_TAIL_JUMP_WALK + 2)//14412
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_TAIL_JUMP_WALK + 6)//14416
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN (ID_SPRITE_MARIO_TAIL_JUMP + 20)//14420
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_TAIL_JUMP_RUN + 2)//14422
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_TAIL_JUMP_RUN + 6)//14426

#define ID_SPRITE_MARIO_TAIL_SIT (ID_SPRITE_MARIO_TAIL + 500)//14500
#define ID_SPRITE_MARIO_TAIL_SIT_LEFT (ID_SPRITE_MARIO_TAIL_SIT + 10)//14510
#define ID_SPRITE_MARIO_TAIL_SIT_RIGHT (ID_SPRITE_MARIO_TAIL_SIT + 20)//14520

#define ID_SPRITE_MARIO_TAIL_BRACE (ID_SPRITE_MARIO_TAIL + 600)//14600
#define ID_SPRITE_MARIO_TAIL_BRACE_LEFT (ID_SPRITE_MARIO_TAIL_BRACE + 10)//14610
#define ID_SPRITE_MARIO_TAIL_BRACE_RIGHT (ID_SPRITE_MARIO_TAIL_BRACE + 20)//14620

#define ID_SPRITE_MARIO_TAIL_ATTACK (ID_SPRITE_MARIO_TAIL_BRACE + 30)//14630

#pragma endregion 

#define ID_SPRITE_BRICK 20000

#define ID_SPRITE_GOOMBA 30000
#define ID_SPRITE_GOOMBA_WALK (ID_SPRITE_GOOMBA + 1000)
#define ID_SPRITE_GOOMBA_DIE (ID_SPRITE_GOOMBA + 2000)
#define ID_SPRITE_GOOMBA_FLY (ID_SPRITE_GOOMBA +5000)
#define ID_SPRITE_GOOMBA_DIE_UPSIDE (ID_SPRITE_GOOMBA+6000)


#define ID_SPRITE_COIN 40000
#define ID_SPRITE_MUSHROOM 40010
#define ID_SPRITE_LEAF 40020
#define ID_SPRITE_FLOWERFIRE 40030

#define ID_SPRITE_CLOUD 50000
#define ID_SPRITE_CLOUD_BEGIN (ID_SPRITE_CLOUD+1000)
#define ID_SPRITE_CLOUD_MIDDLE (ID_SPRITE_CLOUD+2000)
#define ID_SPRITE_CLOUD_END (ID_SPRITE_CLOUD+3000)

#define ID_SPRITE_FONT_0		50013
#define ID_SPRITE_FONT_1		50014
#define ID_SPRITE_FONT_2		50015
#define ID_SPRITE_FONT_3		50016
#define ID_SPRITE_FONT_4		50017
#define ID_SPRITE_FONT_5		50018
#define ID_SPRITE_FONT_6		50019
#define ID_SPRITE_FONT_7		50020
#define ID_SPRITE_FONT_8		50021
#define ID_SPRITE_FONT_9		50022
#define ID_SPRITE_FONT_A		50023
#define ID_SPRITE_FONT_B		50024
#define ID_SPRITE_FONT_C		50025
#define ID_SPRITE_FONT_D		50026
#define ID_SPRITE_FONT_E		50027
#define ID_SPRITE_FONT_F		50028
#define ID_SPRITE_FONT_G		50029
#define ID_SPRITE_FONT_H		50030
#define ID_SPRITE_FONT_I		50031
#define ID_SPRITE_FONT_J		50032
#define ID_SPRITE_FONT_K		50033
#define ID_SPRITE_FONT_L		50034
#define ID_SPRITE_FONT_M		50035
#define ID_SPRITE_FONT_N		50036
#define ID_SPRITE_FONT_O		50037
#define ID_SPRITE_FONT_P		50038
#define ID_SPRITE_FONT_Q		50039
#define ID_SPRITE_FONT_R		50040
#define ID_SPRITE_FONT_S		50041
#define ID_SPRITE_FONT_T		50042
#define ID_SPRITE_FONT_U		50043
#define ID_SPRITE_FONT_V		50044
#define ID_SPRITE_FONT_W		50045
#define ID_SPRITE_FONT_X		50046
#define ID_SPRITE_FONT_Y		50047
#define ID_SPRITE_FONT_Z		50048

#define ID_SPRITE_HUD						99999
#define ID_SPRITE_ICONMARIO					50003
#define ID_SPRITE_ICONLUIGI					50004
#define ID_SPRITE_FILLARROW					50005


#pragma region ANIMATION_ID







//POWER
#define POWER_ANI_ID 301
#define POWER_MAX_ANI_ID 302
#define SPACE_BETWEEN_POWER_AND_MAX 5
#define MARIO_POWER_FULL 7
#define POWER_WIDTH 8




//HUD

#define HUD_HEIGHT 32

//windown


