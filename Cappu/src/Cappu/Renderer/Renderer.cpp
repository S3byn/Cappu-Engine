#include "CappuPCH.h"
#include "Renderer.h"

//#include "Cappu/Renderer/Renderer2D.h"

Cappu::Renderer::SceneData* Cappu::Renderer::m_sceneData = new Cappu::Renderer::SceneData;

void Cappu::Renderer::Init() {
	RenderCommand::Init();
	//Renderer2D::Init();
}

void Cappu::Renderer::OnWindowResize(uint32_t width, uint32_t height) {
	RenderCommand::SetViewport(0, 0, width, height);
}

/*
void Cappu::Renderer::BeginScene(Camera2D& camera) {
	m_sceneData->viewProjMatrix = camera.GetViewProjMatrix();
}
*/

void Cappu::Renderer::EndScene() {

}
/*
void Cappu::Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform) {
	vertexArray->Bind();

	shader->Bind();
	shader->SetMat4("u_viewProjMatrix", m_sceneData->viewProjMatrix);
	shader->SetMat4("u_modelMatrix", transform);

	RenderCommand::DrawIndexed(vertexArray);
}
*/
