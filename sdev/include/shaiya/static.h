#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/SkillTypes.h>
#include "common.h"
#include "Camera.h"
#include "CPlayerData.h"
#include "CWorldMgr.h"
#include "HealPointType.h"
#include "LoginVersion.h"
#include "TargetType.h"

namespace shaiya
{
    struct CSwordEffect;

    #pragma pack(push, 1)
    struct ExtraHotkey
    {
        int key1;   // DIK_NUMPAD1
        int key2;   // DIK_NUMPAD2
        int key3;   // DIK_NUMPAD3
        int key4;   // DIK_NUMPAD4
        int key5;   // DIK_NUMPAD5
        int key6;   // DIK_NUMPAD6
        int key7;   // DIK_NUMPAD7
        int key8;   // DIK_NUMPAD8
        int key9;   // DIK_NUMPAD9
        int key10;  // DIK_NUMPAD0
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct HotkeyOptions
    {
        int moveLeft;        // DIK_A
        int moveForward;     // DIK_W
        int walkLeft;        // DIK_Q
        int walkRun;         // DIK_TAB
        int sitStand;        // DIK_C
        int statWindow;      // DIK_T
        int skillWindow;     // DIK_K
        int questWindow;     // DIK_U
        int optionWindow;    // DIK_O
        int miniMap;         // DIK_V
        int moveRight;       // DIK_D
        int moveBackward;    // DIK_S
        int walkRight;       // DIK_E
        int autoMove;        // DIK_W
        int jump;            // DIK_SPACE
        int inventory;       // DIK_I
        int subSkillWindow;  // DIK_B
        int guildWindow;     // DIK_G
        int map;             // DIK_M
        int closeWindow;     // DIK_ESCAPE
    };
    #pragma pack(pop)


    #pragma pack(push, 1)
    // the .data section
    struct Static
    {
        PAD(212);                            //0x7AB000
        LoginVersion loginVersion;           //0x7AB0D4
        D2D_SIZE_U client;                   //0x7AB0D8
        D3DVIEWPORT9 viewport;               //0x7AB0E0
        // 0x7AB0F8
        PAD(2788);
        uint32_t targetId;                   //0x7ABBDC
        TargetType targetType;               //0x7ABBE0
        PAD(16164);
        WNDCLASSEXA wndClassExa;             //0x7AFB08
        // 0x7AFB38
        PAD(68584);
        String<260> iniFileName;             //0x7C0720
        // 0x7C0824
        PAD(1384);
        bool32_t enableWaterSurface;         //0x7C0D8C
        bool32_t enableShadows;              //0x7C0D90
        float viewFarthest;                  //0x7C0D94
        float viewNearest;                   //0x7C0D98
        // 0: 16-bit, 1: 32-bit
        int32_t colorDepth;                  //0x7C0D9C
        float baseMoveSpeed;                 //0x7C0DA0
        float fogNearest;                    //0x7C0DA4
        float fogFarthest;                   //0x7C0DA8
        float fogStart;                      //0x7C0DAC
        float fogEnd;                        //0x7C0DB0
        bool32_t disableFog;                 //0x7C0DB4
        float modelFarthest;                 //0x7C0DB8
        float grassFarthest;                 //0x7C0DBC
        // user, npc, mob
        float otherFarthest;                 //0x7C0DC0
        PAD(12);
        String<16> ipv4;                     //0x7C0DD0
        // 0x7C0DE0
        PAD(172);
        ExtraHotkey extraHotkey;             //0x7C0E8C
        HotkeyOptions hotkeyOptions;         //0x7C0EB4
        // 0x7C0F04
        PAD(1176);
        HWND hwnd;                           //0x7C139C
        HINSTANCE hinst;                     //0x7C13A0
        bool32_t isFullscreenWindow;         //0x7C13A4
        PAD(4);
        bool32_t isActiveWindow;             //0x7C13AC
        PAD(1408);
        uint32_t sysmsg_v2;                  //0x7C1930  <v2>
        HealPointType sysmsg_up;             //0x7C1934  <up>
        SkillStatusType sysmsg_zz;           //0x7C1935  <zz>
        HealPointType sysmsg_hp;             //0x7C1936  <hp>
        PAD(1);
        Array<char, 512> sysmsg_r;           //0x7C1938  <r> (lapis)
        Array<char, 512> sysmsg_t;           //0x7C1B38  <t> (target)
        Array<char, 1024> sysmsg_b;          //0x7C1D38  <b>
        Array<char, 512> sysmsg_s;           //0x7C2138  <s> (skill)
        Array<char, 512> sysmsg_p;           //0x7C2338  <p> (player)
        Array<char, 512> sysmsg_i;           //0x7C2538  <i> (item)
        uint32_t sysmsg_v3;                  //0x7C2738  <v3>
        uint32_t sysmsg_v;                   //0x7C273C  <v>
        Array<char, 1024> sysmsg_buffer1;    //0x7C2740
        Array<char, 1024> sysmsg_buffer2;    //0x7C2B40
        Array<char, 1024> sysmsg_buffer3;    //0x7C2F40
        Array<char, 1024> sysmsg_buffer4;    //0x7C3340
        Array<char, 1024> sysmsg_buffer5;    //0x7C3740
        // 0:5 (switches buffers)
        uint32_t sysmsg_bufferIndex;         //0x7C3B40
        PAD(200);
        int32_t cursorX;                     //0x7C3C0C
        int32_t cursorY;                     //0x7C3C10
        PAD(3660);
        CSwordEffect* seffEventEffect;       //0x7C4A60
        CSwordEffect* seffWeather;           //0x7C4A64
        CWorldMgr worldMgr;                  //0x7C4A68
        CSwordEffect* seffLoginCloud;        //0x906DE0
        CSwordEffect* seffWeapon;            //0x906DE4
        PAD(25576);
        CPlayerData playerData;              //0x90D1D0
        // 0x22B0208
        PAD(6384);
        int32_t killLv;                      //0x22B1AF8
        int32_t deathLv;                     //0x22B1AFC
        PAD(16040);
        Array<wchar_t, 1024> wideBuffer1;    //0x22B59A8
        Array<wchar_t, 1024> wideBuffer2;    //0x22B61A8
        LPDIRECT3DDEVICE9 device;            //0x22B69A8
        PAD(4);
        Camera camera;                       //0x22B69B0
        // 0x22B7FE4
        PAD(16);
        float fps;                           //0x22B7FF4
        PAD(237504);
        LPDIRECTSOUND8 directSound8;         //0x22F1FB8
        PAD(33608);
        int socket;                          //0x22FA304
        PAD(21368);
        String<260> exeFileName;             //0x22FF680
        // 0x22FF784
        PAD(116);
        CRITICAL_SECTION cs;                 //0x22FF7F8
        // 0x22FF810
        PAD(568);
        HMODULE hModule;                     //0x22FFA48
        PAD(21940);
        // 0x2305000 (.rsrc)

        // static functions

        static void DrawRect(D3DCOLOR argb, int x, int y, int w, int h);
        static void SysMsgToChatBox(int messageType, int messageNumber, int unknown);
        static bool PlayWav(const char* wavFileName, D3DVECTOR* origin, float volume, bool repeat);

        // D3DX utilities (deprecated)

        static D3DXMATRIX* D3DXMatrixMultiply(D3DXMATRIX* out, D3DXMATRIX* mat1, D3DXMATRIX* mat2);
        static D3DXMATRIX* D3DXMatrixRotationY(D3DXMATRIX* out, float angle);
        static D3DXMATRIX* D3DXMatrixRotationZ(D3DXMATRIX* out, float angle);

        // CRT

        static void operator_delete(void* block);
        static void* operator_new(size_t size);
    };
    #pragma pack(pop)

    static_assert(sizeof(Static) == 0x1B5A000);
    static auto g_var = (Static*)0x7AB000;
}
