#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> // _tcscmp
#include <vector>
#include <stdlib.h>

using namespace std;


DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
    DWORD dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
            {
                dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}
int main()
{
    int ct = 12;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ct);
    SetConsoleTitle("Among Us Hack by Nextro - Private Version 1.4");
    HWND hwnd_AC = FindWindowA(NULL, "Among Us");
    if (hwnd_AC == nullptr)
    {
        cout << "\t\t\t\t   Game Not Found Please Launch The Game" << endl;
        Sleep(3000);
        exit(-1);
    }
    else
    {
        cout << "\t\t\t\t   Game Found Please Wait..." << endl;
        Sleep(3000);
        system("cls");

    }
    if (hwnd_AC != FALSE);
    DWORD pID = NULL; // Game process ID
    GetWindowThreadProcessId(hwnd_AC, &pID);
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    char gameName[] = "UnityPlayer.dll";
    DWORD gameBaseAddress = GetModuleBaseAddress(_T(gameName), pID);
    char gameName1[] = "GameAssembly.dll";
    DWORD gameBaseAddress1 = GetModuleBaseAddress(_T(gameName1), pID);
    DWORD speedaddy = 0x0129273C;
    vector<DWORD> speedoffsets{ 0x5C,0x160,0x7F0,0x5D4,0x14 };
    DWORD speed = NULL;
    // getting the value at gamebase + offset and storing it on baseAddress
    // Speed Hax hack values
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + speedaddy), &speed, sizeof(speed), 0);
    DWORD speedptraddy = speed; // the address we need
    for (int i = 0; i < speedoffsets.size() - 1; i++) // we dont want to change the last offset value so we do -1
    {
        ReadProcessMemory(phandle, (LPVOID*)(speedptraddy + speedoffsets.at(i)), &speedptraddy, sizeof(speedptraddy), 0);
    }
    speedptraddy += speedoffsets.at(speedoffsets.size() - 1); // adding the last offset
    // Kill Cooldown
    DWORD Killcdaddy = 0x00DA5A84;
    vector<DWORD> Killcdoffsets{ 0x5C,0x4,0x20 };
    DWORD Killcd = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + Killcdaddy), &Killcd, sizeof(Killcd), 0);
    DWORD Killcdptraddy = Killcd;
    for (int i = 0; i < Killcdoffsets.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(Killcdptraddy + Killcdoffsets.at(i)), &Killcdptraddy, sizeof(Killcdptraddy), 0);
    }
    Killcdptraddy += Killcdoffsets.at(Killcdoffsets.size() - 1); // adding the last offset
    // Kill Timer
    DWORD killtimeraddy = 0x00DA5A84;
    vector<DWORD> killtimeroffsets{ 0x5C,0x0,0x44 };
    DWORD killtimer = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + killtimeraddy), &killtimer, sizeof(killtimer), 0);
    DWORD killtimerptraddy = killtimer;
    for (int i = 0; i < killtimeroffsets.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(killtimerptraddy + killtimeroffsets.at(i)), &killtimerptraddy, sizeof(killtimerptraddy), 0);
    }
    killtimerptraddy += killtimeroffsets.at(killtimeroffsets.size() - 1); // adding the last offset
    //Impostor Vision
    DWORD imposvisionaddy = 0x01295838;
    vector<DWORD> imposvisionoffsets{ 0x5C,0x4,0x1C };
    DWORD imposvision = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + imposvisionaddy), &imposvision, sizeof(imposvision), 0);
    DWORD imposvisionptraddy = imposvision;
    for (int i = 0; i < imposvisionoffsets.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(imposvisionptraddy + imposvisionoffsets.at(i)), &imposvisionptraddy, sizeof(imposvisionptraddy), 0);
    }
    imposvisionptraddy += imposvisionoffsets.at(imposvisionoffsets.size() - 1);
    // CrewMate Vision
    DWORD crewmatevisionaddy = 0x0129273C;
    vector<DWORD> crewmatevisionoffsets{ 0x5C,0x7F0,0x724,0x18 };
    DWORD crewmatevision = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + crewmatevisionaddy), &crewmatevision, sizeof(crewmatevision), 0);
    DWORD crewmatevisionptraddy = crewmatevision;
    for (int i = 0; i < crewmatevisionoffsets.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(crewmatevisionptraddy + crewmatevisionoffsets.at(i)), &crewmatevisionptraddy, sizeof(crewmatevisionptraddy), 0);
    }
    crewmatevisionptraddy += crewmatevisionoffsets.at(crewmatevisionoffsets.size() - 1);
    // Noclip
    DWORD noclip1addy = 0x012A86E0;
    vector<DWORD> noclippointers{ 0x80,0x5C,0x0 };
    DWORD noclip1 = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + noclip1addy), &noclip1, sizeof(noclip1), 0);
    DWORD noclipointeraddy = noclip1;
    for (int i = 0; i < noclippointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(noclipointeraddy + noclippointers.at(i)), &noclipointeraddy, sizeof(noclipointeraddy), 0);
    }
    noclipointeraddy += noclippointers.at(noclippointers.size() - 1);
    // X cord
    DWORD xcordaddy = 0x012A86E0;
    vector<DWORD> xcordpointers{ 0x80,0x5C,0x2C };
    DWORD xcords = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + xcordaddy), &xcords, sizeof(xcords), 0);
    DWORD xcordptraddy = xcords;
    for (int i = 0; i < xcordpointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(xcordptraddy + xcordpointers.at(i)), &xcordptraddy, sizeof(xcordptraddy), 0);
    }
    xcordptraddy += xcordpointers.at(xcordpointers.size() - 1);
    // Y cord
    DWORD ycordaddy = 0x012A86E0;
    vector<DWORD> ycordpointers{ 0x80,0x5C,0x2C };
    DWORD ycords = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress + ycordaddy), &ycords, sizeof(ycords), 0);
    DWORD ycordptraddy = ycords;
    for (int i = 0; i < ycordpointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(ycordptraddy + ycordpointers.at(i)), &ycordptraddy, sizeof(ycordptraddy), 0);
    }
    ycordptraddy += ycordpointers.at(ycordpointers.size() - 1);
    // SkinChanger
    DWORD hSkinaddy = 0x00DAF750;
    vector<DWORD> hSkinPointers{ 0x4C,0x8,0x10,0x44,0x0,0x210,0xF74 };
    DWORD hSkin = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + hSkinaddy), &hSkin, sizeof(hSkin), 0);
    DWORD hSkinPointeraddy = hSkin;
    for (int i = 0; i < hSkinPointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(hSkinPointeraddy + hSkinPointers.at(i)), &hSkinPointeraddy, sizeof(hSkinPointeraddy), 0);
    }
    hSkinPointeraddy += hSkinPointers.at(hSkinPointers.size() - 1);
    // CharacterState /0 = Crewmate / 1 = Impostor / 257 = Ghost /
    DWORD charstateaddy = 0x00DAF3E8;
    vector<DWORD> charstatepointers{ 0x5C,0x20,0x34,0X28 };
    DWORD charstatecords = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + charstateaddy), &charstatecords, sizeof(charstatecords), 0);
    DWORD charstateptraddy = charstatecords;
    for (int i = 0; i < charstatepointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(charstateptraddy + charstatepointers.at(i)), &charstateptraddy, sizeof(charstateptraddy), 0);
    }
    charstateptraddy += charstatepointers.at(charstatepointers.size() - 1);
    // ColorChanger
    DWORD hColaddy = 0x00DA5A84;
    vector<DWORD> hColPointers{ 0x5C,0x0,0x34,0x10 };
    DWORD hCol = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + hColaddy), &hCol, sizeof(hCol), 0);
    DWORD hColptraddy = hCol;
    for (int i = 0; i < hColPointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(hColptraddy + hColPointers.at(i)), &hColptraddy, sizeof(hColptraddy), 0);
    }
    hColptraddy += hColPointers.at(hColPointers.size() - 1);
    //Respawn
    DWORD hrpaddy = 0x00DA5A84;
    vector<DWORD> hrpPointers{ 0x5C,0x0,0x34,0x29 };
    DWORD hrp = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + hrpaddy), &hrp, sizeof(hrp), 0);
    DWORD hrpptraddy = hrp;
    for (int i = 0; i < hrpPointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(hrpptraddy + hrpPointers.at(i)), &hrpptraddy, sizeof(hrpptraddy), 0);
    }
    hrpptraddy += hrpPointers.at(hrpPointers.size() - 1);
    //Discussion Vote
    DWORD disctimeaddy = 0x00DA5A84;
    vector<DWORD> disctimePointers{ 0x5C,0x4,0x44 };
    DWORD disctime = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + disctimeaddy), &disctime, sizeof(disctime), 0);
    DWORD disctimeptraddy = disctime;
    for (int i = 0; i < disctimePointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(disctimeptraddy + disctimePointers.at(i)), &disctimeptraddy, sizeof(disctimeptraddy), 0);
    }
    disctimeptraddy += disctimePointers.at(disctimePointers.size() - 1);
    //Voting Time
    DWORD votetimeaddy = 0x00DA5A84;
    vector<DWORD> votetimePointers{ 0x5C,0x4,0x48 };
    DWORD votetime = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + votetimeaddy), &votetime, sizeof(votetime), 0);
    DWORD votetimeptraddy = votetime;
    for (int i = 0; i < votetimePointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(votetimeptraddy + votetimePointers.at(i)), &votetimeptraddy, sizeof(votetimeptraddy), 0);
    }
    votetimeptraddy += votetimePointers.at(votetimePointers.size() - 1);
    //LocalPlayerName
    DWORD lPlayerNameaddy = 0x00DA5A84;
    vector<DWORD> lPlayerNamePointers{ 0x5C,0x0,0x34, 0xC, 0xC };
    DWORD lPlayerName = NULL;
    unsigned long idk = ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddress1 + lPlayerNameaddy), &lPlayerName, sizeof(DWORD), 0);
    DWORD lPlayerNameptraddy = lPlayerName;
    for (int i = 0; i < lPlayerNamePointers.size() - 1; i++)
    {
        ReadProcessMemory(phandle, (LPVOID*)(lPlayerNameptraddy + lPlayerNamePointers.at(i)), &lPlayerNameptraddy, sizeof(lPlayerNameptraddy), 0);
    }
    lPlayerNameptraddy += lPlayerNamePointers.at(lPlayerNamePointers.size() - 1);
    wchar_t name[10];
    ReadProcessMemory(phandle, (LPVOID)lPlayerNameptraddy, &name, sizeof(name), 0);
    // see impostor
    DWORD cimposter = gameBaseAddress1 + 0x002124A8;
    DWORD bytes;
    BYTE imposBytes[6] = { 0x90,0x90,0x90,0x90,0x90,0x90 };
    // turn off see impos hack
    DWORD imposoff = gameBaseAddress1 + 0x002124A8;
    DWORD imposoffbyte;
    BYTE imposoffBytes[6] = { 0x0F,0x84,0x2D,0x02,0x00,0x00 };

    // see impostor while voting
    DWORD cimpostervote = gameBaseAddress1 + 0x001B2439;
    DWORD bytes1;
    BYTE imposvoteBytes[1] = { 0xEB };
    // turn off see impos vote
    DWORD imposvoteoff = gameBaseAddress1 + 0x001B2439;
    DWORD imposvoteoffbyte;
    BYTE imposoffvoteBytes[1] = { 0x75 };
    wcout << "\t\t\t\t   [!] Name | " << name << endl;
    // The Ui Design -- Will Make a menu after im done adding more options --
    cout << "\t\t\t\t   [!] Menu :" << endl;
    cout << "\t\t\t\t   [!] Press 0 to Exit" << endl;
    cout << "\t\t\t\t   [!] Press 1 to Activate Speed Hack" << endl;
    cout << "\t\t\t\t   [!] Press 2 to Activate No Kill Cooldown Speed Hack" << endl;
    cout << "\t\t\t\t   [!] Press 3 to Activate Impos Vision Hack" << endl;
    cout << "\t\t\t\t   [!] Press 4 to Activate Noclip Hack" << endl;
    cout << "\t\t\t\t   [!] Press 5 to Activate CrewMate Vision Hack" << endl;
    cout << "\t\t\t\t   [!] Press 6 to Teleport To Cafetteria Hack" << endl;
    cout << "\t\t\t\t   [!] Press 7 to Activate Skin Changer Hack" << endl;
    cout << "\t\t\t\t   [!] Press 8 to Activate Color Changer Hack" << endl;
    cout << "\t\t\t\t   [!] Press 9 to Activate Skip Vote Hack(host)" << endl;
    cout << "\t\t\t\t   [!] Press F1 to Activate Reveal Impostor Hack(F2 to turn it off)" << endl;
    cout << "\t\t\t\t   [!] Press c for Crewmate, \n\t\t\t\t   [!] Press i for Impostor, \n\t\t\t\t   [!] Press g for Ghost" << endl;
    cout << "\t\t\t\t   [!] Press r to Respawn" << endl;
    while (true)
    {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) // exiting
        {
            return 0;
        }

        if (GetAsyncKeyState(VK_NUMPAD1))
        {
            cout << "\t\t\t\t|| Speed Hack Active |" << endl;
            float hSpeed = NULL;
            hSpeed = 5;

            WriteProcessMemory(phandle, (LPVOID*)(speedptraddy), &hSpeed, 4, 0);

        }
        if (GetAsyncKeyState(VK_NUMPAD2))
        {
            cout << "Kill Cooldown Hack - " << " True" << endl;

            float hKill = NULL;
            hKill = 0.01;
            float hKillTimer = NULL;
            hKillTimer = 1;
            WriteProcessMemory(phandle, (LPVOID*)(Killcdptraddy), &hKill, sizeof(hKill), 0);
            WriteProcessMemory(phandle, (LPVOID*)(killtimerptraddy), &hKillTimer, sizeof(hKillTimer), 0);
        }

        if (GetAsyncKeyState(VK_NUMPAD3))
        {
            cout << "Impos Vision Hack - " << " True" << endl;

            float hImposVis = NULL;
            hImposVis = 10;

            WriteProcessMemory(phandle, (LPVOID*)(imposvisionptraddy), &hImposVis, sizeof(hImposVis), 0);
        }
        if (GetAsyncKeyState(VK_NUMPAD4))
        {
            DWORD noclip;
            noclip = 1;

            cout << "Noclip Hack (Ur Always Imposter When Host) -  " << "True (Note : Wait a Few Seconds Before It Starts" << endl;

            WriteProcessMemory(phandle, (LPVOID*)(noclipointeraddy), &noclip, sizeof(noclip), 0);
        }
        if (GetAsyncKeyState(VK_NUMPAD5))
        {
            float hcrewmatevis;
            hcrewmatevis = 10;

            cout << "Crewmate Vision Hack - " << " True" << endl;

            WriteProcessMemory(phandle, (LPVOID*)(crewmatevisionptraddy), &hcrewmatevis, sizeof(hcrewmatevis), 0);

        }
        if (GetAsyncKeyState(VK_NUMPAD6))
        {

            float xCord;
            xCord = 0.9;

            float yCord;
            yCord = 0.9;

            cout << "Teleport to Caffeteria -  " << "True " << endl;
            WriteProcessMemory(phandle, (LPVOID*)(xcordptraddy), &xCord, sizeof(xCord), 0);
            WriteProcessMemory(phandle, (LPVOID*)(ycordptraddy), &yCord, sizeof(yCord), 0);


        }
        if (GetAsyncKeyState(VK_NUMPAD7))
        {
            cout << "Skin Changer Active " << endl;
            int skinid[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
            int skinid1[15] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            for (;;)
            {
                for (int i = 1; i < 15; i++)
                {

                    WriteProcessMemory(phandle, (LPVOID*)hSkinPointeraddy, &skinid[i], sizeof(int), 0);

                    if (i >= 15)
                        for (int ii = 15; ii > 1; i--)

                            WriteProcessMemory(phandle, (LPVOID*)hSkinPointeraddy, &skinid1[ii], sizeof(int), 0);

                    if (i <= 1)
                        WriteProcessMemory(phandle, (LPVOID*)hSkinPointeraddy, &skinid[i], sizeof(int), 0);

                }
            }

        }
        void colorhack();
        {
            char chaxx;
            chaxx = (GetAsyncKeyState(VK_NUMPAD8));
            if (chaxx)
            {
                cout << "Color Changer Active " << endl;
                int colorid[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
                int colorid1[12] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
                for (int i = 0; i < 12; i++)
                {
                    while (chaxx != NULL)
                    {
                        WriteProcessMemory(phandle, (LPVOID*)hColptraddy, &colorid[i], sizeof(int), 0);

                        if (i >= 12)
                            for (int ii = 12; ii > 0; i--)

                                WriteProcessMemory(phandle, (LPVOID*)hColptraddy, &colorid1[ii], sizeof(int), 0);
                    }
                }
            }
        }
        if (GetAsyncKeyState(VK_NUMPAD9))
        {
            DWORD hDiscTime;
            hDiscTime = 1;

            cout << "Vote Time Hack - " << " True" << endl;

            WriteProcessMemory(phandle, (LPVOID*)(disctimeptraddy), &hDiscTime, sizeof(hDiscTime), 0);
            WriteProcessMemory(phandle, (LPVOID*)(votetimeptraddy), &hDiscTime, sizeof(hDiscTime), 0);

        }
        if (GetAsyncKeyState(0x47))
        {
            DWORD hGhost;
            hGhost = 257;

            cout << " Ur Now Ghost " << endl;

            WriteProcessMemory(phandle, (LPVOID*)charstateptraddy, &hGhost, sizeof(hGhost), 0);
            Sleep(3000);
        }

        if (GetAsyncKeyState(0x49))
        {
            DWORD hImpos;
            hImpos = 1;

            cout << " Ur Now Impostor " << endl;

            WriteProcessMemory(phandle, (LPVOID*)charstateptraddy, &hImpos, sizeof(hImpos), 0);
            Sleep(3000);
        }

        if (GetAsyncKeyState(0x43))
        {
            DWORD hCrewmate;
            hCrewmate = 0;

            cout << " Ur Now Crewmate " << endl;

            WriteProcessMemory(phandle, (LPVOID*)charstateptraddy, &hCrewmate, sizeof(hCrewmate), 0);
            Sleep(3000);
        }

        if (GetAsyncKeyState(0x52))
        {
            BYTE hRespawn;
            hRespawn = 0;

            cout << " Respawned... " << endl;

            WriteProcessMemory(phandle, (BYTE*)hrpptraddy, &hRespawn, sizeof(hRespawn), 0);
            Sleep(3000);
        }

        if (GetAsyncKeyState(VK_F1))
        {
            cout << "Reveal Impostor - Active" << endl;
            WriteProcessMemory(phandle, (PVOID)cimposter, imposBytes, 6, &bytes);
            WriteProcessMemory(phandle, (PVOID)cimpostervote, imposvoteBytes, 1, &bytes1);

        }
        if (GetAsyncKeyState(VK_F2))
        {
            cout << "Reveal Impostor - False" << endl;
            WriteProcessMemory(phandle, (PVOID)imposoff, imposoffBytes, 6, &imposoffbyte);
            WriteProcessMemory(phandle, (PVOID)imposvoteoff, imposoffvoteBytes, 1, &imposvoteoffbyte);

        }
    }
}