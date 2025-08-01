#include "CappuPCH.h"
#include "LayerManager.h"

Cappu::LayerManager::LayerManager() { }

Cappu::LayerManager::~LayerManager() {
	for (auto layer : m_layers) {
		delete layer;
	}
}

void Cappu::LayerManager::PushLayer(Layer* layer) {
	m_layers.emplace(m_layers.begin() + m_layerIndex, layer);
	m_layerIndex++;
}

void Cappu::LayerManager::PushOverlay(Layer* overlay) {
	m_layers.emplace_back(overlay);
}

void Cappu::LayerManager::PopLayer(Layer* layer) {
	auto it = std::find(m_layers.begin(), m_layers.end(), layer);
	if (it != m_layers.end()) {
		m_layers.erase(it);
		m_layerIndex--;
	}
}

void Cappu::LayerManager::PopOverlay(Layer* overlay) {
	auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
	if (it != m_layers.end()) {
		m_layers.erase(it);
	}
}
