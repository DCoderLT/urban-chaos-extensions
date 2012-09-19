#include "ScreenMessage.h"
#include "../core/Screen.h"

using namespace UCX::Ext;

std::vector<ScreenMessage*> ScreenMessage::Messages;

void ScreenMessage::Update()  {
	UpdateColor();
	if(Frame) {
		UCX::Core::Screen::OutputText_Left(this->Content, 15, 15, this->DWColor());
	}
}

DWORD ScreenMessage::DWColor() const {
	return Color.AsDWORD();
}

void ScreenMessage::UpdateColor() {
	Frame -= 8;
	if(Color.R > 0) {
		Color.R -= 8;
	}
	if(Color.G > 0) {
		Color.G -= 8;
	}
	if(Color.B > 0) {
		Color.B -= 8;
	}
}
