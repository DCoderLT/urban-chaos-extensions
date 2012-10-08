#ifndef UCC_RADIO_H
#define UCC_RADIO_H

namespace UCX {
	namespace Core {
		namespace Radio {
			struct MessageData {
				  void* Source;
					char Text[256];
					int Duration;
					int Unknown;
			};

			// length = 8
			extern MessageData * ActiveMessages;
			extern int & ActiveMessageIndex;

			inline void __cdecl Echo(const char *String, int Duration) {
				JMP_STD(0x495F50);
			}

			inline void __cdecl Echo(void *Speaker, int Duration, const char *Format, ...) {
				JMP_STD(0x48F980);
			}

		};
	};
};

#endif