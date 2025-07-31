#pragma once

#include "Cappu/Events/Events.h"

#include "Cappu/Systems/Core.h"

namespace Cappu {
	
	struct WindowProps {
		std::string title;
		uint32_t width;
		uint32_t height;

		WindowProps(const std::string& title = "Cappu Game", uint32_t width = 1280, uint32_t height = 720) :
			title(title), width(width), height(height) { }
	};
	
	class Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual float GetAspect() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetHandle() const = 0;

		static Unique<Window> Create(const WindowProps& props = WindowProps());
	};

}
