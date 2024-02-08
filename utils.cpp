// FanControl++
// (c) 2024 Pham Nhat Quang (Legend0fHell)
#include "utils.h"

#ifdef _DEBUG
void _dInfo(const wchar_t str[]) {
	const std::wstring new_str(str);
	OutputDebugString((L"[Info] " + new_str + L"\n").c_str());
}
void _dInfo(const std::wstring str) {
	OutputDebugString((L"[Info] " + str + L"\n").c_str());
}
void _dErr(const wchar_t str[]) {
	const std::wstring new_str(str);
	OutputDebugString((L"[ERROR] " + new_str + L"\n").c_str());
}
void _dErr(const std::wstring str) {
	OutputDebugString((L"[ERROR] " + str + L"\n").c_str());
}
#else
void _dInfo(const wchar_t str[]) {}
void _dInfo(const std::wstring str) {}
void _dErr(const wchar_t str[]) {}
void _dErr(const std::wstring str) {}
#endif

std::wstring _ts(const int& value)
{
	return std::to_wstring(value);
}

std::wstring _ts(const wchar_t str[])
{
	std::wstring new_str(str);
	return new_str;
}

std::wstring _ts(const std::vector<int>& vt)
{
	std::wstring new_str;
	for (int idx = 0; idx < vt.size(); ++idx) {
		new_str += std::to_wstring(vt[idx]);
		if (idx != vt.size() - 1) new_str += L" | ";
	}
	return new_str;
}

ULONGLONG convert_to_ull(SYSTEMTIME& st)
{
	ULARGE_INTEGER ul = { 0 };
	FILETIME ft;
	SystemTimeToFileTime(&st, &ft);
	ul.LowPart = ft.dwLowDateTime;
	ul.HighPart = ft.dwHighDateTime;
	// convert ul to milliseconds
	ul.QuadPart /= 10000;
	return ul.QuadPart;
}