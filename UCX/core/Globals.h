#ifndef UCC_GLOBALS_H
#define UCC_GLOBALS_H

#include <Windows.h>
#include "Generic.h"

struct person {
	byte bodyClass;
	byte x[3];
	int wat;
	int wat1;
	short health;
	byte q[2];
	byte w[2];
	byte stat_stamina;
	byte stat_constitution;
	byte qw[94];
	byte ammo_pistol;
	byte qweqw;
	byte ammo_ssg;
	byte ammo_m16;
	byte qwee;
	byte qwrq;
	byte stat_strength;
	byte civs_killed;
	byte qerw[4];
	byte stateFlags;
	byte stat_reflexes;
	int boop[3];
};

struct blob {
	byte nop[0x24];
	person *body;
};

int* GetScreenHeight() {
	return (int*)0x1AFCBC0;
}

int* GetScreenWidth() {
	return (int*)0x1AFCBB8;
}

char* GlobalRadarMsg() {
	return (char *)0xDD00F8;
}

DWORD* lastRadarPrintTime() {
	return (DWORD *)0xDD0300;
}

byte* showFPS() {
	return (byte*)0x8AA2B8;
}

short* Fade() {
	return (short*)0x4F6562;
}

int* DrawDistance() {
	return (int*)0x4F6570;
}

int* CrimeRate() {
	return (int *)0x7077B6;
}

int* badsArrested() {
	return (int*)0x9041F8;
}

int* civsArrested() {
	return (int*)0x9041FC;
}

int* badsKilled() {
	return (int*)0x90422C;
}

int* civsKilled() {
	return (int*)0x904228;
}

int* bonusesFound() {
	return (int*)0x904234;
}

bool* skipClumps() {
	return (bool*)0xFFB5C0;
}

bool* stealthMode() {
	return (bool*)0x6AA368;
}

int* debugMode() {
	return (int*)0x6AA36C;
}

int* colourFade() {
	return (int*)0x6CF318;
}

const int colourFadeLevel() {
	return 256 - 4 * (*colourFade());
}

blob** arrOfObjects() {
	return (blob **)0x707704;
}

#endif
