#pragma once

#include "Cappu/Systems/App.h"

extern Cappu::App* Cappu::CreateApp();

#if defined(CAPPU_PLATFORM_WINDOWS) && !defined(_DEBUG)
#include <Windows.h>

int WINAPI WinMain(_In_ HINSTANCE hInstace, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	auto app = Cappu::CreateApp();
	app->Run();
	delete app;
	return 0;
}

#else

int main() {
	auto app = Cappu::CreateApp();
	app->Run();
	delete app;
	return 0;
}

#endif
