#include "CappuPCH.h"
#include "App.h"

#include <GLFW/glfw3.h>

Cappu::App* Cappu::App::s_instance = nullptr;

Cappu::App::App() {
	CAPPU_ASSERT(!s_instance, "An instance of Cappu::App already exists!");
	s_instance = this;

	m_window = Window::Create();
	m_window->SetEventCallback(CAPPU_BIND_EVENT_FN(App::OnEvent));
	
	m_imGuiLayer = new ImGuiLayer();
	PushOverlay(m_imGuiLayer);
}

Cappu::App::~App() {}

void Cappu::App::PushLayer(Layer* layer) {
	m_layerManager.PushLayer(layer);
	layer->OnAttach();
}

void Cappu::App::PushOverlay(Layer* overlay) {
	m_layerManager.PushLayer(overlay);
	overlay->OnAttach();
}

void Cappu::App::Run() {
	while (m_running){
		float time = (float)glfwGetTime();
		float delta = time - m_lastTime;
		m_lastTime = time;

		if (!m_minimized) {
			for (auto layer : m_layerManager) layer->OnUpdate(delta);
		}
		m_imGuiLayer->Begin();

		for (auto layer : m_layerManager) layer->OnImGuiDraw();

		m_imGuiLayer->End();

		m_window->OnUpdate();
	}
}

void Cappu::App::OnEvent(Event& event) {
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<WindowCloseEvent>(CAPPU_BIND_EVENT_FN(App::onWindowClose));

	for (auto it = m_layerManager.end(); it != m_layerManager.begin();) {
		(*--it)->OnEvent(event);
		if (event.handled) {
			break;
		}
	}
}

bool Cappu::App::onWindowClose(WindowCloseEvent& event) {
	m_running = false;
	return false;
}

