#include "CappuPCH.h"
#include "WinWindow.h"

#include "Cappu/Events/WindowEvents.h"
#include "Cappu/Events/KeyEvents.h"
#include "Cappu/Events/MouseEvents.h"

static bool s_glfwInit = false;

Cappu::Unique<Cappu::Window> Cappu::Window::Create(const WindowProps& props) {
	return CreateUnique<WinWindow>(props);
}

Cappu::WinWindow::WinWindow(const WindowProps& props) {
	init(props);
}

Cappu::WinWindow::~WinWindow() {
	shutdown();
}

void Cappu::WinWindow::init(const WindowProps& props) {
	m_data.title = props.title;
	m_data.width = props.width;
	m_data.height = props.height;

	//Initialize GLFW
	if (!s_glfwInit) {
		int success = glfwInit();
		CAPPU_ASSERT(success, "Unable to initialize GLFW!");
		s_glfwInit = true;
	}

	//Create window
	m_window = glfwCreateWindow(props.width, props.height, m_data.title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_window);

	glfwSetWindowUserPointer(m_window, &m_data);
	SetVSync(true);
	
	setCallbacks();
}

void Cappu::WinWindow::shutdown() {
	glfwDestroyWindow(m_window);
}

void Cappu::WinWindow::OnUpdate() {
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

void Cappu::WinWindow::SetVSync(bool enable) {
	glfwSwapInterval(enable);
	m_data.vsync = enable;
}

bool Cappu::WinWindow::IsVSync() const {
	return m_data.vsync;
}

inline void Cappu::WinWindow::setCallbacks() {
	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		data.width = width;
		data.height = height;

		WindowResizeEvent event(width, height);
		data.eventCallback(event);
	});

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		WindowCloseEvent event;
		data.eventCallback(event);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

		switch (action) {
			case GLFW_PRESS: {
				KeyPressedEvent event(key, false);
				data.eventCallback(event);
				break;
			}

			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);
				data.eventCallback(event);
				break;
			}

			case GLFW_REPEAT: {
				KeyPressedEvent event(key, true);
				data.eventCallback(event);
				break;
			}
		}
	});

	glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int chr) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		KeyTypedEvent event(chr);
		data.eventCallback(event);
	});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

		switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressedEvent event(button);
				data.eventCallback(event);
				break;
			}

			case GLFW_RELEASE: {
				MouseButtonReleasedEvent event(button);
				data.eventCallback(event);
				break;
			}
		}
	});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.eventCallback(event);
	});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos) {
		WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
		MouseMovedEvent event((int)xPos, (int)yPos);
		data.eventCallback(event);
	});
}
