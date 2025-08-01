#pragma once

#include "Cappu/Systems/Input.h"

namespace Cappu {

	class WinInput : public Input {
	protected:
		 bool getKey(int keyCode) override;
		 bool getKeyPressed(int keyCode) override;
		 bool getKeyReleased(int keyCode) override;

		 int getMouseX() override;
		 int getMouseY() override;

		 bool getMouseButton(int button) override;
		 bool getMouseButtonPressed(int button) override;
		 bool getMouseButtonReleased(int button) override;
	};

}

