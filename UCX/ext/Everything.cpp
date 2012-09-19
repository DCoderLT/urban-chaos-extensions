#include "Debug.h"
#include "../core/Statics.h"

#include "../core/DisplayManager.h"
#include "../core/Screenshots.h"
#include "FileSystem.h"
#include "../core/Magic.h"
#include "../core/Screen.h"
#include "ScreenMessage.h"

#include "../core/Globals.h"
#include "../core/Keymaps.h"

using namespace UCX::Core;
using namespace UCX::Ext;

bool __stdcall DllMain(HANDLE hInstance,DWORD dwReason,LPVOID v) {
	switch(dwReason) {
	case DLL_PROCESS_ATTACH:
		Debug::LogFileOpen();
		Debug::Log("ATTACH\n");
		break;
	case DLL_PROCESS_DETACH:
		Debug::Log("DETACH\n");
		Debug::LogFileClose();
		break;
	}

	return true; 
}


DEFINE_HOOK(0x476A65, sub_4769F0_1, 7)
{
	auto active = !!Magic::SlowdownRemaining;
	new ScreenMessage(active ? "Slowdown on" : "Slowdown is off", 0, 0, 200);
	return 0;
}

DEFINE_HOOK(0x476B06, sub_4769F0_2, 5)
{
	R->EAX(128);
	return 0x476B0B;
}


DEFINE_HOOK(0x490EC3, Radar_Draw, 6)
{
	for(unsigned int i = ScreenMessage::Messages.size(); i > 0; --i) {
		auto idx = i - 1;
		Debug::Log("First loop pass over message %d\n", idx);
		ScreenMessage *msg = ScreenMessage::Messages[idx];
		if(msg->TimeToDie()) {
			Debug::Log("Deleting message %d\n", idx);
			delete msg;
		}
	}

	for(unsigned int i = 0; i < ScreenMessage::Messages.size(); ++i) {
		Debug::Log("Second loop pass over message %d\n", i);
		ScreenMessage::Messages[i]->Update();
	}

	if(auto remain = Magic::SlowdownRemaining) {
		ColorStruct clr(200, 200, 200);
		char timeLeft[32];
		int seconds = remain / 100;
		_snprintf(timeLeft, 32, "%02d:%02d", seconds / 60, seconds % 60);
		Screen::OutputText_Left(timeLeft, 100, 50, clr.AsDWORD());
	}

	return 0;
}


DEFINE_HOOK(0x412B00, Engine_MakeScreenshot, 0)
{
	wchar_t FullName[MAX_PATH] = L"\0",
		Filename[64] = L"\0";

	FileSystem::CreateFolder(L"screenshots");
	int idx = 0;
	bool found = false;
	do {
		swprintf(Filename, 64, L"screenshots\\scrn%03d.bmp", idx);
		FileSystem::PathTo(FullName, Filename);
		HANDLE hExisting = CreateFile(FullName, FILE_WRITE_ACCESS, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
		if(hExisting == INVALID_HANDLE_VALUE) {
			found = true;
		} else {
			CloseHandle(hExisting);
		}
		++idx;
	} while(!found && idx <= 9999);

	//	strcpy(Filename + 14, ".bmp");
	if(found) {
		if(FILE *imgFile = _wfopen(FullName, L"wb")) {
			DisplayManager * Mgr = DisplayManager::Instance;
			int width = Mgr->ScreenWidth;
			int height = Mgr->ScreenHeight;
			int arrayLen = width * height;
			int BPP = Mgr->Aux->GetBitsPerPixel();

			bmpfile_full_header h;

			h.magic[0] = 'B';
			h.magic[1] = 'M';

			h.creator1 = h.creator2 = 0;

			h.header_sz = 40;
			h.width = width;
			h.height = -height; // magic! no need to reverse rows this way
			h.nplanes = 1;
			h.bitspp = 16;
			h.compress_type = BI_BITFIELDS;
			h.bmp_bytesz = arrayLen * 2;
			h.hres = 4000;
			h.vres = 4000;
			h.ncolors = h.nimpcolors = 0;

			h.R = 0xF800;
			h.G = 0x07E0;
			h.B = 0x001F; // look familiar?

			h.bmp_offset = sizeof(h);
			h.filesz = h.bmp_offset + h.bmp_bytesz;
			fwrite(&h, sizeof(h), 1, imgFile);

			byte * pixels = Mgr->ScreenPixels;
			WORD * processed = new WORD[arrayLen], * buffer = processed;

			ColorStruct CLR;
			Color16Struct C16;

			if(BPP == 16) {
				for(int r = 0; r < height; ++r) {
					byte * rowPixels = &pixels[r * Mgr->Pitch];
					WORD * rowWPixels = reinterpret_cast<WORD *>(rowPixels);
					for(int c = 0; c < width; ++c) {
						WORD clrw = *rowWPixels;
						CLR(CLR, clrw);
						C16 = CLR;
						C16.SwapRB();
						*buffer = *(WORD *)&C16;
						++buffer;
						++rowWPixels;
					}
				}
			} else {
				for(int r = 0; r < height; ++r) {
					byte * rowPixels = &pixels[r * Mgr->Pitch];
					DWORD * rowWPixels = reinterpret_cast<DWORD *>(rowPixels);
					for(int c = 0; c < width; ++c) {
						DWORD clrw = *rowWPixels;
						CLR(CLR, clrw);
						C16 = CLR;
						C16.SwapRB();
						*buffer = *(WORD *)&C16;
						++buffer;
						++rowWPixels;
					}
				}
			}
			fwrite(processed, 2, arrayLen, imgFile);

			fclose(imgFile);

			delete[] processed;

			char * Message = new char[256];
			_snprintf(Message, 256, "Saved screenshot to %ls", Filename);
			new ScreenMessage(Message, 200, 0, 200);
			delete[] Message;
		}
	}

	return 0x412BB6;
}


// cheat controller
DEFINE_HOOK(0x41243D, Debug_TextEntered, 5)
{
	LEA_STACK(char *, input, 0x1C);

	new ScreenMessage(input, 0xFF, 0xFF, 0xFF);

	return 0x41244F;
}

// keypress controller
DEFINE_HOOK(0x413ADF, Debug_ProcessKeypresses_ProcessCustomPresses, 6)
{
	auto k = static_cast<byte>(PressedKey::KEY_TILDE);

	if(isKeyDown(k)) {
		wchar_t Filename[0x1000];
		Debug::CreateDump(NULL, Filename);
		char Message[0x2000];
		_snprintf(Message, 0x2000, "Memory dump written to %ls", Filename);

		unsetKey(k);
	}

	return 0;
}


#if 0
DEFINE_HOOK(0x4129AE, Debug_TextEntered, 6)
{
	byte * ptr1 = (byte *)0x4F196C;
	byte * ptr2 = (byte *)0x8A9DB8;

	static byte ix = 0;

	GET(byte *, c, ECX);
	GET(byte *, b, EBX);

	GET(char *, command, ESI);
	if(*command) {
		ix = (byte)atoi(command);
	}

	*c = ix;

	byte pix1 = ptr1[ix];

	byte * tw24 = (byte *)(*(int*)(b + 0x24));
	*(byte *)&tw24[0x60] = 1;

	byte * tw20 = (byte *)(*(int*)(b + 0x20));
	*(int *)&tw20[0x2C] = (int)(&(ptr2[56 * pix1]));

	char * Message = new char[32];
	_snprintf(Message, 256, "Applied model %d", ix);
	new ScreenMessage(Message, 0, 200, 0);

	++ix;
	if(ix > 15) {
		ix = 0;
	}

	return 0x4129C2;
}
#endif

DEFINE_HOOK(0x4887C2, sub_488780, 9)
{
	R->ECX(5);
	return 0x488819;
}
