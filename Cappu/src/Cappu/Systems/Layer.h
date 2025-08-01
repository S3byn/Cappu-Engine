#pragma once

#include "Cappu/Events/Events.h"

namespace Cappu {

	class Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float delta) {}
		virtual void OnImGuiDraw() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_name; }

	private:
		std::string m_name;

	};


}

