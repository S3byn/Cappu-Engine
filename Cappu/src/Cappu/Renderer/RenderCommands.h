#pragma once

#include "Cappu/Systems/Core.h"

#include "Cappu/Renderer/RendererAPI.h"

namespace Cappu {
	class RenderCommand {
	public:
		inline static void Init() {
			s_rendererAPI->Init();
		}

		inline static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
			s_rendererAPI->SetViewport(x,y,width,height);
		}
		inline static void Clear(const glm::vec4& color) {
			s_rendererAPI->Clear(color);
		}

		//inline static void DrawIndexed(const Shared<VertexArray>& vertexArray, uint32_t count = 0) {
	//		s_rendererAPI->DrawIndexed(vertexArray, count);
		//}

	private:
		static RendererAPI* s_rendererAPI;
	};
}
