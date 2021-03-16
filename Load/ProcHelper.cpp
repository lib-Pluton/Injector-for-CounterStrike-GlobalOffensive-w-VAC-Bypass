#include "ProcHelper.h"

DWORD cProcHelper::FindProcByName(LPCSTR lpProcName) 
{
	PROCESSENTRY32 PE32{ 0 };
	PE32.dwSize = sizeof(PE32);

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap == INVALID_HANDLE_VALUE) {
		std::cout << "Snap Creation Failed: " << GetLastError() << std::endl;
		return 0;
	}

	bool bRet = Process32First(hSnap, &PE32);

	for (unsigned int i = 0; i < PE32.dwSize; i++)
	{

		if (!strcmp(lpProcName, PE32.szExeFile)) {
			return PE32.th32ProcessID;
		}

		bool bRet = Process32Next(hSnap, &PE32);

		// ÎÏÒÈÌÈÇÀÖÈß
		Sleep(1);
	}
	return 0;

	CloseHandle(hSnap);
	free(&PE32);

	return 0;
}

string cProcHelper::ProcPath(const char* cProcName)
{
	char buf[1024];

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			const char* cBuffer = (_bstr_t)entry.szExeFile;
			if (_stricmp(cBuffer, cProcName) == 0)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

				GetProcessImageFileNameA(hProcess, buf, sizeof(buf));

				CloseHandle(hProcess);
			}
		}
	}

	CloseHandle(snapshot);

	return buf;
}

bool cProcHelper::CloseProc(const char* cProcName)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			const char* cBuffer = (_bstr_t)entry.szExeFile;
			if (_stricmp(cBuffer, cProcName) == 0)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

				TerminateProcess(hProcess, 0);

				CloseHandle(hProcess);
				CloseHandle(snapshot);
				return true;
			}
		}
	}

	CloseHandle(snapshot);
	return false;
}

string cProcHelper::TreatGetedProcPath(string sProcPath, const char* cProcName)
{
	string sNewProcPath = sProcPath;

	// Del cProcName From Path
	sNewProcPath = sNewProcPath.substr(0, sNewProcPath.find(cProcName));

	// Replace DiskName To Real DiskName
	string sDisk, sNewDisk;
	if (sNewProcPath.find("Volume1") != std::string::npos)
	{
		sDisk = "Volume1";
		sNewDisk = "C:";

		sNewProcPath = sNewProcPath.substr(sNewProcPath.find(sDisk) + sDisk.size(), sNewProcPath.size());

		sNewProcPath = sNewDisk + sNewProcPath;
	}
	else if (sNewProcPath.find("Volume2") != std::string::npos)
	{
		sDisk = "Volume2";
		sNewDisk = "D:";

		sNewProcPath = sNewProcPath.substr(sNewProcPath.find(sDisk) + sDisk.size(), sNewProcPath.size());

		sNewProcPath = sNewDisk + sNewProcPath;
	}

	return sNewProcPath;
}

cProcHelper ProcHelper;