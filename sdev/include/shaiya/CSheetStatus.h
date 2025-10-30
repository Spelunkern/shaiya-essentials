#pragma once
#include <shaiya/include/common.h>
#include "CWindow.h"

namespace shaiya
{
    #pragma pack(push, 1)
    // 0x52CEB0
    struct CSheetStatus : CWindow
    {
        PAD(28);
        // STR,REC,INT,WIS,DEX,LUC
        Array<uint16_t, 6> addPoints;  //0x40
        int32_t usablePoints;          //0x4C
        bool isAddPointsWindowActive;  //0x50
        PAD(27307);
        // 0x6AFC
    };
    #pragma pack(pop)

    static_assert(sizeof(CSheetStatus) == 0x6AFC);
}
