#pragma once

#include "Includes.h"

#include "ProcHelper.h"

class cSteamSpoof
{
public:
	cSteamSpoof();
	void Initialize();

	void MainSteamDllSpoof();

	void SpoofSteamDll();
	void UnSpoofSteamDll();

	bool IsSteamDllExists();
	bool IsPathExist();
	bool IsSpoofed();

	string GetSteamPath();
	string GetSteamDllName();
	string GetNewSteamDllName();
	
private:
	bool m_bPathExists;
	bool m_bSpoofed;
	string m_sSteamPath;
	string m_sSteamDll;
	string m_sNewSteamDll;

protected:
	void GetSteamDll();
	bool CheckSpoof();
	string GetSteamPath2();
};