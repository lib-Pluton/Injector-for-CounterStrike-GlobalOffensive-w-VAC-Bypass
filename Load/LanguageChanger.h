#pragma once

#include "Includes.h"

namespace Lang
{
	string CANT_RENAME = "Cant to rename injector. Closing...";

	string STEAM_PATH_NOT_FOUNDED = "Steam path not founded. Need to run Steam.exe. Closing...";

	string SEARCH_STEAM = "Searching Steam.exe...";
	string STEAM_TRYING_START = "Steam.exe closes, trying to Start...";
	string STEAM_CANT_START = "Cant start Steam.exe. Open Steam.exe. Closing...";
	string STEAM_FOUNDED = "Steam.exe found!";

	string SEARCH_CSGO = "Searching csgo.exe...";
	string CSGO_FOUNDED_FOR_INJECT = "CSGO.exe running, trying to close...";
	string CANT_CLOSE_CSGO_FOR_INJECT = "Cant close CSGO.exe. Try to close CSGO.exe and run loader. Closing...";
	string CSGO_NOT_FOUNDED_FOR_INJECT = "Good, CSGO.exe Closed, starting Inject!";
	string INJECT_ERROR = "Injecting error. Closing...";
	string CANT_INJECT = "Cant injecting. Closing...";
	string CAN_INJECT = "Injecting!";
	string CANT_FIND_DLL = "Cant find hack dll. Closing...";
	string CAN_FIND_DLL = "Finded hack dll!";
	string DLL_IS = "Starting inject ";
	string WAIT_CSGO = "Waiting csgo.exe...";
	string CSGO_FOUNDED = "CSGO.exe found!";


	void LoadRussian()
	{
		CANT_RENAME = "Не могу переименовать инжектор. Закрытие...";
		STEAM_PATH_NOT_FOUNDED = "Папка Стима не найдена. Нужно запустить Стим. Закрытие...";
		SEARCH_STEAM = "Ищу Steam.exe...";
		STEAM_TRYING_START = "Steam.exe закрыт, пытаюсь запустить...";
		STEAM_CANT_START = "Не могу запустить Steam.exe. Откройти сами Steam.exe. Закрытие...";
		STEAM_FOUNDED = "Steam.exe Найден!";
		SEARCH_CSGO = "Ищу CSGO.exe...";
		CSGO_FOUNDED_FOR_INJECT = "CSGO.exe открыт, пытаюсь закрыть...";
		CANT_CLOSE_CSGO_FOR_INJECT = "Не удалось закрыть CSGO.exe. Попробуйте запустить первым лоадер. Закрытие...";
		CSGO_NOT_FOUNDED_FOR_INJECT = "Хорошо, CSGO.exe закрыт, начинаю инжект!";
		INJECT_ERROR = "Ошибка при инжекте. Закрытие...";
		CANT_INJECT = "Не получится заинжектить. Закрытие...";
		CAN_INJECT = "Можно инжектить!";
		CANT_FIND_DLL = "Не могу найти длл чита. Закрытие...";
		CAN_FIND_DLL = "Длл чита найдена!";
		DLL_IS = "Начинаю инжект ";
		WAIT_CSGO = "Ожидание CSGO.exe...";
		CSGO_FOUNDED = "CSGO.exe Найден!";
	}

	string GetWinLanguage()
	{
		WCHAR wcBuffer[16];
		GetSystemDefaultLocaleName(wcBuffer, 16);

		return ws2s(wcBuffer);
	}


}