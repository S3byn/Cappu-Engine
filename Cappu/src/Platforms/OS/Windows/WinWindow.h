#pragma once

#include "Cappu/Systems/Window.h"

#include <GLFW/glfw3.h>

namespace Cappu {

	class WinWindow : public Window{
	public:
		WinWindow(const WindowProps& props);
		virtual ~WinWindow();

		void OnUpdate() override;


		uint32_t GetWidth() const override { return m_data.width; }
		uint32_t GetHeight() const override { return m_data.height; }
		float GetAspect() const override { return (float)m_data.width / (float)m_data.height; }

		void SetEventCallback(const EventCallbackFn& callback) override { m_data.eventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

		void* GetHandle() const override { return m_window; }
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		inline virtual void setCallbacks();

	private:
		GLFWwindow* m_window;

		struct WindowData {
			std::string title;
			uint32_t width, height;
			bool vsync;

			EventCallbackFn eventCallback;
		};
		WindowData m_data;
	};

}

