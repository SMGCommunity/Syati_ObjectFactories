#include "revolution.h"
#include "kamek/hooks.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Scene/SceneObjHolder.h"

#define INCLUDE_PRIVATE
#include "ModuleData_SceneObjHolder.h"
#undef INCLUDE_PRIVATE

namespace {
    NameObj* newEachObjExt(void* pUnused, int id) {
        for (const CreateSceneObjEntry* pEntry = &cNewCreateSceneObjTable[1]; pEntry < cNewCreateSceneObjTableCount_END; pEntry++) {
            if (pEntry->mSlotId == id) {
                return pEntry->mCreationFunc();
            }
        }

        return nullptr;
    }
}

extern kmSymbol initSceneObjHolder__5SceneFv;
kmWrite16(&initSceneObjHolder__5SceneFv + 0x16, sizeof(SceneObjHolder) + ExtSceneObj_COUNT * sizeof(NameObj*));

extern kmSymbol __ct__14SceneObjHolderFv;
kmWrite16(&__ct__14SceneObjHolderFv + 0x2, ExtSceneObj_END);

extern kmSymbol newEachObj__14SceneObjHolderFi;
kmCall(&newEachObj__14SceneObjHolderFi + 0xEE8, newEachObjExt);