#pragma once

#include "Includes.h"
#include "Converter.h"
#include "ProcHelper.h"

#include "SpoofSteamDll.h"
#include "DllFinder.h"

#include "LanguageChanger.h"
#include "Other.h"

void StarterText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Yellow);
	printf_s("    __     __   ____    _    _     ____       _       _      _   _____       ____   _   _____  \n");
	printf_s("    \\ \\   / /  / __ \\  | |  | |  / ____|     / \\     | \\    / | |  ___|     | _  \\ | | |___  | \n");
	printf_s("     \\ \\_/ /  | |  | | | |  | | | |         / _ \\    |  \\  /  | | |___      ||_| | | |    / /  \n");
	printf_s("      \\   /   | |  | | | |  | | | | ____   / /_\\ \\   |   \\/   | |  ___|     | _ |  | |   / /   \n");
	printf_s("       | |    | |__| | \\ \\__/ / | |__| |  / _____ \\  | |\\  /| | | |___   _  ||_| | | |  / /__  \n");
	printf_s("       |_|     \\____/   \\____/   \\____/  /_/     \\_\\ |_| \\/ |_| |_____| |_| |____/ |_| |_____| \n");
	printf_s("\n");
	printf_s("                   ____  __     __      _   _   _   ____   _____   _                            \n");
	printf_s("                  | _  \\ \\ \\   / /     | \\ | | | | /  __\\ |  ___| | |                           \n");
	printf_s("                  ||_| |  \\ \\_/ /      |  \\| | | | | |    | |___  | |                           \n");
	printf_s("                  | _ |    \\   /       | \\   | | | | |    |  ___| | |                           \n");
	printf_s("                  ||_| |    | |        | |\\  | | | | |___ | |___  | |___                        \n");
	printf_s("                  |____/    |_|        |_| \\_| |_| \\____/ |_____| |_____|                       \n");
	printf_s("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Green);
}

void FindSteamExe(string sSteamPath)
{
	printf_s("%s\n", SEARCH_STEAM.c_str());
	if (!ProcHelper.FindProcByName("Steam.exe") && !ProcHelper.FindProcByName("steam.exe"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Yellow);
		printf_s("%s\n", STEAM_TRYING_START.c_str());
		ShellExecute(NULL, "open", (sSteamPath + "steam.exe").c_str(), NULL, NULL, SW_SHOWDEFAULT);

		if (!ProcHelper.FindProcByName("Steam.exe") && !ProcHelper.FindProcByName("steam.exe"))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
			printf_s("%s\n", STEAM_CANT_START.c_str());

			Sleep(5000);
			exit(1);
		}

		while (!ProcHelper.FindProcByName("steamwebhelper.exe"))
			Sleep(1000);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Yellow);
		printf_s("Steam óñïåøíî çàïóùåí!\n\n");
		Sleep(1000);
	}
	else 
		printf_s("%s\n\n", STEAM_FOUNDED.c_str());
}

void CloseCSGO()
{
	printf_s("%s\n", SEARCH_CSGO.c_str());
	if (ProcHelper.FindProcByName("csgo.exe"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Yellow);
		printf_s("%s\n", CSGO_FOUNDED_FOR_INJECT.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
		// Plan A
		ProcHelper.CloseProc("csgo.exe");

		// Plan B
		HANDLE hProc = FindWindowA("Valve003", NULL);
		TerminateProcess(hProc, 0);

		Sleep(2000);
	}
	if (ProcHelper.FindProcByName("csgo.exe"))
	{
		printf_s("%s\n", CANT_CLOSE_CSGO_FOR_INJECT.c_str());
		Sleep(5000);
		exit(2);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Green);
	printf_s("%s\n\n", CSGO_NOT_FOUNDED_FOR_INJECT.c_str());
}

void SpoofStart(cSteamSpoof SteamSpoof)
{
	if (!SteamSpoof.IsPathExist())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
		printf_s("%s\n", STEAM_PATH_NOT_FOUNDED.c_str());
		printf_s("%s", SteamSpoof.GetSteamPath().c_str());
		Sleep(5000);
		exit(3);
	}

	// Del old crashhandler1
	if (SteamSpoof.IsSpoofed())
	{
		DeleteFileA((SteamSpoof.GetSteamPath() + "crashhandler.dll").c_str());
		SteamSpoof.UnSpoofSteamDll();
		DeleteFileA((SteamSpoof.GetSteamPath() + "crashhandler1.dll").c_str());
	}
}

void DoSpoof(cSteamSpoof SteamSpoof)
{
	SteamSpoof.MainSteamDllSpoof();
	if (!SteamSpoof.IsSpoofed())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
		printf_s("%s", INJECT_ERROR.c_str());
		Sleep(5000);
		exit(4);
	}
}

void FindDll(string sPath)
{
	FindDllInPath(sPath);
	if (DllName.size() < 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
		printf_s("%s", CANT_FIND_DLL.c_str());
		Sleep(5000);
		exit(5);
	}
	else
		printf_s("%s\n\n", CAN_FIND_DLL.c_str());
}

void DllToSteamDir(cSteamSpoof SteamSpoof, string sPath)
{
	if (!CopyFileA((sPath + DllName).c_str(), (SteamSpoof.GetSteamPath() + "crashhandler.dll").c_str(), 0))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CMD_Red);
		printf_s("%s", CANT_INJECT.c_str());
		Sleep(5000);
		exit(6);
	}
	else
		printf_s("%s\n\n", CAN_INJECT.c_str());

	printf_s("%s\n", (DLL_IS + DllName).c_str());
}

void RunCSGO()
{
	bool IsWaitingCSGO = false;

	while (true)
	{
		if (!IsWaitingCSGO && !ProcHelper.FindProcByName("csgo.exe"))
		{
			IsWaitingCSGO = true;
			system("start steam://rungameid/730");
		}

		if (ProcHelper.FindProcByName("csgo.exe"))
			break;
	}
	printf_s("%s\n\n", CSGO_FOUNDED.c_str());

	if (IsWaitingCSGO)
		Sleep(2000);
}

void WorkWhileIsCSGO(string sSteamPath)
{
	while (true)
	{
		if (!ProcHelper.FindProcByName("csgo.exe"))
			break;

		Sleep(1000);
	}

	while (!DeleteFileA((sSteamPath + "crashhandler.dll").c_str()))
		Sleep(100);

	rename((sSteamPath + "crashhandler1.dll").c_str(), (sSteamPath + "crashhandler.dll").c_str());


	exit(-1);
}
