#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <codecvt>

#include <cstdio>
#include <Windows.h>
#include <psapi.h>
#include <TlHelp32.h>
#include <comdef.h>

#include "urlmon.h"
#pragma comment (lib, "urlmon.lib")

#include "Shlwapi.h"
#pragma comment(lib, "Shlwapi.lib")

using namespace std;

#define CMD_White 15
#define CMD_Yellow 14
#define CMD_Red 12
#define CMD_Green 10