#pragma once

#include "Events.h"

#include <cstdint>
#include <sstream>

namespace Cappu {

	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint32_t width, uint32_t height) :
			m_width(width), m_height(height) {}

		inline uint32_t GetWidth() const { return m_width; }
		inline uint32_t GetHeight() const { return m_height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		uint32_t m_width, m_height;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	};

}
