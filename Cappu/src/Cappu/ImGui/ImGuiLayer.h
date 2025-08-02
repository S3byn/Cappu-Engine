#pragma once

#include "Cappu/Systems/Layer.h"


namespace Cappu {

	class ImGuiLayer : public Layer{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnImGuiDraw() override;

		void Begin();
		void End();
	private:
		float m_time = 0.0f;
	};

}

