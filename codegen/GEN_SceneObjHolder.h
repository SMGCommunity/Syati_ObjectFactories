#pragma once

#include "ActorCreation.h"

#ifdef INCLUDE_PRIVATE
{{IncludeList}}
#endif

enum ExtSceneObj {
    ExtSceneObj_START = SCENE_OBJ_WII_MESSAGE_BOARD_MAIL_SENDER,
{{SceneObjIdNameList}}
    ExtSceneObj_END,
    ExtSceneObj_COUNT = ExtSceneObj_END - ExtSceneObj_START - 1,
};

#ifdef INCLUDE_PRIVATE
const CreateSceneObjEntry cNewCreateSceneObjTable[] = {
	//DUMMY - This is never read
	{ 1234567890, NULL },
{{SceneObjList}}
};

#define cNewCreateSceneObjTableCount_END (&cNewCreateSceneObjTable[sizeof(cNewCreateSceneObjTable) / sizeof(*cNewCreateSceneObjTable)])
#endif