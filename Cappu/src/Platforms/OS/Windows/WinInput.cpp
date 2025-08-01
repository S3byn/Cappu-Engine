#include "CappuPCH.h"
#include "WinInput.h"

#include "Cappu/Systems/App.h";
#include <GLFW/glfw3.h>

Cappu::Unique<Cappu::Input> Cappu::Input::s_instance = Cappu::CreateUnique<Cappu::WinInput>();

static std::unordered_map<int, bool> prevKeyState;

static std::unordered_map<int, bool> prevMouseState;

bool Cappu::WinInput::getKey(int keyCode) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int state = glfwGetKey(window, keyCode);
	return state == GLFW_PRESS;
    
}

bool Cappu::WinInput::getKeyPressed(int keyCode) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int currentState = glfwGetKey(window, keyCode);
	bool wasDown = prevKeyState[keyCode];

	prevKeyState[keyCode] = (currentState == GLFW_PRESS);

	return (currentState == GLFW_PRESS) && !wasDown;
}

bool Cappu::WinInput::getKeyReleased(int keyCode) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int currentState = glfwGetKey(window, keyCode);
	bool wasDown = prevKeyState[keyCode];

	prevKeyState[keyCode] = (currentState == GLFW_PRESS);

	return (currentState == GLFW_RELEASE) && wasDown;
}

int Cappu::WinInput::getMouseX() {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

    return (int)xPos;
}

int Cappu::WinInput::getMouseY() {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

    return (int)yPos;
}

bool Cappu::WinInput::getMouseButton(int button) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int state = glfwGetMouseButton(window, button);
	return state == GLFW_PRESS;
}

bool Cappu::WinInput::getMouseButtonPressed(int button) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int currentState = glfwGetMouseButton(window, button);
	bool wasDown = prevMouseState[button];

	prevMouseState[button] = (currentState == GLFW_PRESS);

	return (currentState == GLFW_PRESS) && !wasDown;
}

bool Cappu::WinInput::getMouseButtonReleased(int button) {
	GLFWwindow* window = static_cast<GLFWwindow*>(App::GetWindow().GetHandle());
	int currentState = glfwGetMouseButton(window, button);
	bool wasDown = prevMouseState[button];

	prevMouseState[button] = (currentState == GLFW_PRESS);

	return (currentState == GLFW_RELEASE) && wasDown;
}
