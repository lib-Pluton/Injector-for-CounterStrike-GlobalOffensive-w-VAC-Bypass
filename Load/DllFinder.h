#pragma once

#include "Includes.h"

typedef void(*LPSEARCHFUNC)(LPCTSTR lpszFileName);

extern string DllName;

extern BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = FALSE);
extern void SaveDllName(LPCTSTR lpszFileName);
extern void FindDllInPath(string sPath);