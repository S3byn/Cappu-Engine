#include "CappuPCH.h"
#include "GLRenderContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Cappu/Debug/Log.h"

Cappu::GLRenderContext::GLRenderContext(GLFWwindow* windowHandle) : m_windowHandle(windowHandle) {
	int status = 0;
	if (windowHandle != nullptr) status = 1;

	CAPPU_ASSERT(status, "Window handle is not valid");
}

void Cappu::GLRenderContext::Init() {
	glfwMakeContextCurrent(m_windowHandle);
	int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	CAPPU_ASSERT(success, "Unable to initialize GLAD!");
}

void Cappu::GLRenderContext::SwapBuffers() {
	glfwSwapBuffers(m_windowHandle);
}
