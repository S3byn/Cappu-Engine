#include "CappuPCH.h"
#include "App.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Cappu/Renderer/Renderer.h"

Cappu::App* Cappu::App::s_instance = nullptr;

Cappu::App::App() {
	CAPPU_ASSERT(!s_instance, "An instance of Cappu::App already exists!");
	s_instance = this;

	m_window = Window::Create();
	m_window->SetEventCallback(CAPPU_BIND_EVENT_FN(App::OnEvent));
	
	m_imGuiLayer = new ImGuiLayer();
	PushOverlay(m_imGuiLayer);

	float vertexData[] = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	uint32_t indices[] = {
		0,1,2,
		3,2,0
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	glBindVertexArray(0);
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
		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);

		RenderCommand::Clear({0.0f,0.0f,0.0f,1.0f});

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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

