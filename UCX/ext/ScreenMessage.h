#ifndef UCE_SCREENMESSAGE_H
#define UCE_SCREENMESSAGE_H

#include <vector>
#include <algorithm>
#include "../core/DisplayManager.h"
#include "../core/Screen.h"

using namespace UCX::Core;

namespace UCX {
	namespace Ext {

		class ScreenMessage {
		public:
			static std::vector<ScreenMessage*> Messages;

			void Update();

			bool TimeToDie() const {
				return Frame < 8;
			}

			void UpdateColor();

			DWORD DWColor() const;

			ScreenMessage(char * Text, BYTE R = 0, BYTE G = 0, BYTE B = 0, BYTE Frame = 0) {
				Content = _strdup(Text);
				if(Frame) {
					Color.R = Color.G = Color.B = Frame = 0xF0;
				} else {
					Color.R = R;
					Color.G = G;
					Color.B = B;
					Frame = std::max(R, std::max(G, B)) | 7;
				}
				Messages.push_back(this);
			}

			~ScreenMessage() {
				std::vector<ScreenMessage*>::const_iterator it = std::find(Messages.begin(), Messages.end(), this);
				if(it != Messages.end()) {
					Messages.erase(it);
				}
				free(Content);
				Content = NULL;
			}

			bool operator == (const ScreenMessage &rhs) const {
				return strcmp(this->Content, rhs.Content) == 0
					&& this->Frame == rhs.Frame
					;
			}

			char * Content;
			BYTE Frame;
			ColorStruct Color;
		};
	};
};

#endif
