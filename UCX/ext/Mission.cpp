#include "../core/Mission.h"
#include "Debug.h"

using namespace UCX::Ext;

DEFINE_HOOK(0x425DE0, Mission_ReadDescriptor, 5)
{
	GET_STACK(char *, input, 0x4);
	GET_STACK(char , Version, 0x8);
	GET_STACK(Mission_Data *, Data, 0xC);

	if(Version != 4) {
		return 0;
	}

	int delims = sscanf(input,
      "%d : %d : %d : %d : %d : %d : %d : %s : %[^:] : %*s",
      &Data->ObjectID,
      &Data->GroupID,
      &Data->ParentID,
      &Data->ParentIsGroup,
      &Data->Type,
      &Data->Flags,
      &Data->District,
			Data->Filename,
      Data->Title);

	if(delims != 9) {
		Debug::Log("sscanf parsed %d tokens instead of 9! Input = \n%s\n", delims, input);
		Debug::DumpStack(R, 0x100);
		ExitProcess(1);
	}

	delims = 0;
	char *delim9 = NULL;
	for(char * delim = strtok(input, ":"); delim && *delim; delim = strtok(NULL, ":")) {
		++delims;
		if(delims == 10) {
			delim9 = delim;
			break;
		}
	}

	if(delim9) {
		strcpy(Data->Briefing, delim9);
		for(char * it = Data->Briefing; *it; ++it) {
			if(*it == '|') {
				*it = '\n';
			}
		}
	}

	return 0x425F5B;
}
