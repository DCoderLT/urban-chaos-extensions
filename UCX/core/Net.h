#ifndef UCC_NET_H
#define UCC_NET_H

#include "Generic.h"

#include <dplay.h>

namespace UCX {
	namespace Core {

		namespace Networking {
			 inline void __cdecl DirectPlay_Initialize()
				{ JMP_STD(0x4C1EB0); }

				#pragma pack(push, 1)
				struct PlayerData
				{
					byte Active;
					byte Index;
					byte field_2;
					byte field_3;
					DPID ID;
					char Name[64];
				};

				struct SessionData
				{
					char SessionName[64];
					int CurrentPlayerCount;
					int MaxPlayerCount;
					GUID GUID_Instance;
					GUID GUID_Application;
				};

				struct ConnectionData
				{
					void *CGUID;
					void *ConnectionData;
					int ConnectionDataSize;
					char Name[64];
				};

				struct LobbyStatus
				{
					byte field_0;
					char field_1;
					char field_2;
					char field_3;
					int field_4;
					int field_8;
				};
				#pragma pack(pop)

				extern PlayerData * Players;
				enum { MaxPlayerCount = 32 };

				extern int& SessionCount;
				extern SessionData * Sessions;
				enum { MaxSessionCount = 16 };

				extern int& ConnectionCount;
				extern ConnectionData * Connections;
				enum { MaxConnectionCount = 8 };

				/*
				 * returns SessionCount
				 */
				inline int __cdecl EnumSessions()
				{ JMP_STD(0x4C21F0); }

		};


	};
};

#endif
