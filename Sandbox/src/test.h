#pragma once

#include <Cappu.h>

class Test : public Cappu::Layer {
public:
	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(float delta) override;

private:
};


