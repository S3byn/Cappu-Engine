#pragma once

#include "Events.h"

#include <cstdint>
#include <sstream>

namespace Cappu {

	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(int x, int y) : m_x(x), m_y(y) {}

		inline int GetX() const { return m_x; }
		inline int GetY() const { return m_y; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << "x: " << m_x << ", y: " << m_y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)

	private:
		int m_x, m_y;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolled: " << "xOffset: " << m_xOffset << ", yOffset: " << m_yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		float m_xOffset, m_yOffset;
	};

	class MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_button; }

	protected:
		MouseButtonEvent(int button) : m_button(button) {}
		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
