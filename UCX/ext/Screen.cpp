#include "Screen.h"
#include <algorithm>

using namespace UCX::Ext;

const ScreenResolution ScreenResolution::Resolutions[OptionCount] = {
	{ 1024,  768, "1024 x  768" },
	{ 1440,  900, "1440 x  900" },
	{ 1280, 1024, "1280 x 1024" },
	{ 1680, 1050, "1680 x 1050" },
	{ 1920, 1080, "1920 x 1080" },
};


DEFINE_HOOK(0x4C1E3C, DialogFunc_PopulateScreenDimensions, 5)
{
	GET(HWND, hWnd, EBP);
	DWORD idx(-1UL);
	std::for_each(ScreenResolution::Resolutions, ScreenResolution::Resolutions + ScreenResolution::OptionCount, [hWnd, idx](const ScreenResolution &res) {
		SendMessageA(hWnd, CB_INSERTSTRING, idx, (LPARAM)res.Text);
	});
	return 0x4C1E87;
}


DEFINE_HOOK(0x4BE918, Game_OpenDisplay_SetScreenDimensions, 5)
{
	GET(int, modeIdx, EAX);
	if(modeIdx < 0 || modeIdx >= ScreenResolution::OptionCount) {
			return 0x4BE960;
	}
	auto &res = ScreenResolution::Resolutions[modeIdx];

	R->EDI(res.Width);
	R->ESI(res.Height);

	return 0x4BE968;
}
