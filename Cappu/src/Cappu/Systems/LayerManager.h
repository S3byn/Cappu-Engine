#pragma once

#include "Cappu/Systems/Layer.h"

namespace Cappu {

	class LayerManager {
	public:
		LayerManager();
		~LayerManager();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);
	
		std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_layers.end(); }

	private:
		std::vector<Layer*> m_layers;
		uint32_t m_layerIndex = 0;
	};

}

