#pragma once

#include "Cappu/Systems/Core.h"

#include "Cappu/Renderer/RenderCommands.h"
//#include "Cappu/Renderer/Cameras.h"
//#include "Cappu/Renderer/Shader.h"

namespace Cappu {

	class Renderer {
	public:
		static void Init();
		static void OnWindowResize(uint32_t width, uint32_t height);

		//static void BeginScene(Camera2D& camera);
		static void EndScene();

		//static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData {
			glm::mat4 viewProjMatrix;
		};

		static SceneData* m_sceneData;
	};

}

