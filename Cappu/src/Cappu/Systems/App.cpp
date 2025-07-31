#include "CappuPCH.h"
#include "App.h"

Cappu::App* Cappu::App::s_instance = nullptr;

Cappu::App::App() {
	CAPPU_ASSERT(!s_instance, "An instance of Cappu::App already exists!");
	s_instance = this;

	m_window = Window::Create();
	m_window->SetEventCallback(CAPPU_BIND_EVENT_FN(App::OnEvent));
}

Cappu::App::~App() {

}

void Cappu::App::Run() {
	while (m_running){
		m_window->OnUpdate();
	}
}

void Cappu::App::OnEvent(Event& event) {
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<WindowCloseEvent>(CAPPU_BIND_EVENT_FN(App::onWindowClose));
}

bool Cappu::App::onWindowClose(WindowCloseEvent& event) {
	m_running = false;
	return false;
}

