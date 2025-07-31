#pragma once

#include "Cappu/Systems/Window.h"
#include "Cappu/Events/WindowEvents.h"

#include "Cappu/Systems/Core.h"

namespace Cappu {

	class App {
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& event);

		inline static App& Get() { return *s_instance; }
		inline Window& GetWindow() { return *m_window; }
	private:
		bool onWindowClose(WindowCloseEvent& event);

	private:
		Unique<Window> m_window = nullptr;
		bool m_running = true;

		static App* s_instance;
	};

	//To be defined in client
	App* CreateApp();

}


