#pragma once

#include "Includes.h"

class cProcHelper
{
public:
	DWORD FindProcByName(LPCSTR lpProcName);
	string ProcPath(const char* cProcName);
	bool CloseProc(const char* cProcName);
	string TreatGetedProcPath(string sProcPath, const char* cProcName);
};
extern cProcHelper ProcHelper;
