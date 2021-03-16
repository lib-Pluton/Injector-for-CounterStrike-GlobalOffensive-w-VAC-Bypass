#pragma once

#include "Includes.h"
#include "LanguageChanger.h"
using namespace Lang;

string GetMyPath() 
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

void SetConsoleSettings()
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 120, 40 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	setlocale(LC_ALL, "Rus");

	if (GetWinLanguage() == "ru-RU")
		LoadRussian();
}