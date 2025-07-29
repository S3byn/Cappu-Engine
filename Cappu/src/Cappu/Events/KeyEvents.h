#pragma once

#include "Events.h"

#include <sstream>

namespace Cappu {
	
	class KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_keyCode; }

	protected:
		KeyEvent(int keyCode) : 
			m_keyCode(keyCode) { }
		int m_keyCode;
	};
	
	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, bool repeats) :
			KeyEvent(keyCode), m_repeats(repeats) { }

		inline bool IsRepeat() const { return m_repeats; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << ", Repeats: " << (m_repeats ? "true" : "false");
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool m_repeats;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) :
			KeyEvent(keyCode) { }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}
