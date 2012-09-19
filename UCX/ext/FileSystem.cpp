#include "FileSystem.h"
#include <cstdio>
#include <windows.h>

using namespace UCX::Ext;

void FileSystem::CreateFolder(wchar_t * dir) {
	wchar_t path[MAX_PATH], buffer[MAX_PATH];

	GetCurrentDirectoryW(MAX_PATH, path);

	swprintf(buffer, MAX_PATH, L"%s\\%s", path, dir);
	CreateDirectoryW(buffer, NULL);
}

wchar_t * FileSystem::PathTo(wchar_t *buffer, wchar_t * relPath) {
	wchar_t path[MAX_PATH];

	GetCurrentDirectoryW(MAX_PATH, path);

	swprintf(buffer, MAX_PATH, L"%s\\%s", path, relPath);

	return buffer;
}
