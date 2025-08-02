#pragma once

#include "Cappu/Renderer/RenderContext.h"

struct GLFWwindow;

namespace Cappu {

	class GLRenderContext : public RenderContext {
	public:
		GLRenderContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_windowHandle;
	};

}

