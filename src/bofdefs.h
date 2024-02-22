#pragma once

#ifdef BOF
#include "beacon.h"

WINUSERAPI int WINAPI USER32$MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

WINBASEAPI int __cdecl MSVCRT$rand();
WINBASEAPI int __cdecl MSVCRT$memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);

#define MessageBoxA USER32$MessageBoxA 

#define rand MSVCRT$rand 
#define memcmp MSVCRT$memcmp 

#else
#define BeaconPrintf(x, y, ...) printf(y, ##__VA_ARGS__)
#endif

