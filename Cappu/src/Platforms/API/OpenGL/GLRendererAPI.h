#pragma once

#include "Cappu/Systems/Core.h"

#include "Cappu/Renderer/RendererAPI.h"

namespace Cappu {

	class GLRendererAPI : public RendererAPI{
	public:
		void Init() override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		void Clear(const glm::vec4& color) override;

		//void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};

}

