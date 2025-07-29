#include "App.h"

#include "Cappu/Debug/Log.h"

Cappu::App::App() {
	CAPPU_LOG("log");
	CAPPU_WARN("warn");
	CAPPU_ERROR("error");
}

Cappu::App::~App() {

}

void Cappu::App::Run() {
	while (true);
}
