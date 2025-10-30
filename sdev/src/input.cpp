#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/shaiya/CSheetStatus.h"
#include "include/shaiya/Static.h"
using namespace shaiya;

namespace input
{
    void apply_status_points_by_key_state(CSheetStatus* sheetStatus, int statusIndex, int addPoints)
    {
        auto ctrlKeyDown = GetAsyncKeyState(VK_CONTROL) & 0x8000;
        if (ctrlKeyDown && sheetStatus->usablePoints >= addPoints)
        {
            sheetStatus->usablePoints -= addPoints;
            sheetStatus->addPoints[statusIndex] += addPoints;
        }
        else
        {
            sheetStatus->usablePoints -= 1;
            sheetStatus->addPoints[statusIndex] += 1;
        }
    }
}

unsigned u0x528D96 = 0x528D96;
void __declspec(naked) naked_0x528D8D()
{
    __asm
    {
        pushad

        push 0xA
        push eax
        push esi
        call input::apply_status_points_by_key_state
        add esp,0xC

        popad

        jmp u0x528D96
    }
}

void hook::input()
{
    // hold ctrl key to apply stats x10
    util::detour((void*)0x528D8D, naked_0x528D8D, 9);
}
