#pragma once

#include "Core.h"

namespace Cappu {
	class Input {
	public:
		inline static bool GetKey(int keyCode) { return s_instance->getKey(keyCode); }
		inline static bool GetKeyPressed(int keyCode) { return s_instance->getKeyPressed(keyCode); }
		inline static bool GetKeyReleased(int keyCode) { return s_instance->getKeyReleased(keyCode); }

		inline static int GetMouseX() { return s_instance->getMouseX(); }
		inline static int GetMouseY() { return s_instance->getMouseY(); }

		inline static bool GetMouseButton(int button) { return s_instance->getMouseButton(button); }
		inline static bool GetMouseButtonPressed(int button) { return s_instance->getMouseButtonPressed(button); }
		inline static bool GetMouseButtonReleased(int button) { return s_instance->getMouseButtonReleased(button); }

	protected:
		virtual bool getKey(int keyCode) = 0;
		virtual bool getKeyPressed(int keyCode) = 0;
		virtual bool getKeyReleased(int keyCode) = 0;

		virtual int getMouseX() = 0;
		virtual int getMouseY() = 0;

		virtual bool getMouseButton(int button) = 0;
		virtual bool getMouseButtonPressed(int button) = 0;
		virtual bool getMouseButtonReleased(int button) = 0;

	private:
		static Unique<Input> s_instance;
	};
}
