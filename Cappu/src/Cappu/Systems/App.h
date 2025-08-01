#pragma once

#include "Cappu/Systems/Window.h"
#include "Cappu/Events/WindowEvents.h"

#include "Cappu/Systems/Core.h"
#include "Cappu/Systems/Input.h"

#include "Cappu/Systems/LayerManager.h"

namespace Cappu {

	class App {
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		inline static Window& GetWindow() { return *Get().m_window; }
	private:
		inline static App& Get() { return *s_instance; }
		bool onWindowClose(WindowCloseEvent& event);

	private:
		Unique<Window> m_window = nullptr;
		bool m_running = true;
		bool m_minimized = false;

		float m_lastTime = 0.0f;

		LayerManager m_layerManager;

		static App* s_instance;
	};

	//To be defined in client
	App* CreateApp();

}


