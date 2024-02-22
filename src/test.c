#include <windows.h>
// #include <psapi.h>
// #include <shlwapi.h>
// #include <stdint.h>
#include <stdio.h>

#include "bofdefs.h"
#include "syscalls.c"


#define STATUS_SUCCESS 0x00000000


DWORD test(DWORD pid) {
    HANDLE hProc = NULL;
    OBJECT_ATTRIBUTES objAttr;
    CLIENT_ID cID;

    MessageBoxA(NULL, "start", "Title", MB_OK);
     
    InitializeObjectAttributes(&objAttr, NULL, 0, NULL, NULL);
    cID.UniqueProcess = (HANDLE)(ULONGLONG)pid;
	cID.UniqueThread = 0;
    NTSTATUS st = Sw3NtOpenProcess(&hProc, PROCESS_ALL_ACCESS, &objAttr, &cID);

    if (STATUS_SUCCESS != st) {
        BeaconPrintf(CALLBACK_ERROR, "Failed to open proc with error code 0x%08x.\n", st);
        return -1;
    }
    
    MessageBoxA(NULL, "end", "Title", MB_OK);
    
    BeaconPrintf(CALLBACK_OUTPUT, "Handle: 0x%08x.\n", hProc);

    return 0;
}

#ifdef BOF
VOID go(
    IN PCHAR Buffer,
    IN ULONG Length
)
{
    datap parser;
    DWORD pid;
    DWORD shellcodeLen;
    PCHAR shellcode;

    BeaconDataParse(&parser, Buffer, Length);
    pid = (DWORD)BeaconDataInt(&parser);

    BeaconPrintf(CALLBACK_OUTPUT, "pid: %d\n", pid);

    test(pid);
};
#else
int main(int argc, char* argv[]) {
    DWORD pid;
    PCHAR ptr;

    if (argc != 2) {
        printf("%s: <pid>\n", argv[0]);
        return 1;
    }

    pid = strtoul(argv[1], &ptr, 10);

    printf("pid: %d\n", pid);

    test(pid);

    return 0;
}
#endif

