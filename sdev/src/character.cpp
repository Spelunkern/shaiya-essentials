#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CStaticText.h"
#include "include/shaiya/include/CTexture.h"
using namespace shaiya;

namespace character
{
    void init(CCharacter* user)
    {
        user->title = {};
    }

    void reset(CCharacter* user)
    {
        if (user->title.text)
        {
            if (user->title.text->texture)
            {
                user->title.text->texture->Release();
                user->title.text->texture = nullptr;
            }

            Static::operator_delete(user->title.text);
            user->title.text = nullptr;
        }
    }
}

unsigned u0x419E79 = 0x419E79;
void __declspec(naked) naked_0x419E73()
{
    __asm
    {
        // original
        mov [esi+0x434],ebx

        pushad

        push esi
        call character::init
        add esp,0x4

        popad

        jmp u0x419E79
    }
}

unsigned u0x419623 = 0x419623;
void __declspec(naked) naked_0x41961D()
{
    __asm
    {
        pushad

        push edi
        call character::reset
        add esp,0x4

        popad

        // original
        mov eax,[edi+0x2AC]
        jmp u0x419623
    }
}

void hook::character()
{
    // initialize custom members
    util::detour((void*)0x419E73, naked_0x419E73, 6);
    // reset
    util::detour((void*)0x41961D, naked_0x41961D, 6);

    // change allocation from 0x43C to 0x444

    int size = 0x444;
    util::write_memory((void*)0x41CC97, &size, 4);
    util::write_memory((void*)0x41F055, &size, 4);
    util::write_memory((void*)0x476F9F, &size, 4);
    util::write_memory((void*)0x490250, &size, 4);
    util::write_memory((void*)0x4EFE68, &size, 4);
    util::write_memory((void*)0x4F7318, &size, 4);
    util::write_memory((void*)0x59A3F3, &size, 4);
    util::write_memory((void*)0x59A6DD, &size, 4);
}