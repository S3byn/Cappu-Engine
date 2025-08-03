#pragma once

#include "Cappu/Systems/Window.h"
#include "Cappu/Events/WindowEvents.h"

#include "Cappu/Systems/Core.h"
#include "Cappu/Systems/Input.h"

#include "Cappu/Systems/LayerManager.h"
#include "Cappu/ImGui/ImGuiLayer.h"

namespace Cappu {

	class App {
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Window& GetWindow() { return *Get().m_window; }

	private:
		inline static App& Get() { return *s_instance; }
		bool onWindowClose(WindowCloseEvent& event);

	private:
		Unique<Window> m_window = nullptr;
		LayerManager m_layerManager;
		static App* s_instance;

		ImGuiLayer* m_imGuiLayer = nullptr;

		bool m_minimized = false;
		bool m_running = true;

		float m_lastTime = 0.0f;

		uint32_t vao, vbo, ibo;
	};

	//To be defined in client
	App* CreateApp();

}


