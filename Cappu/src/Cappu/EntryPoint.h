#pragma once

extern Cappu::App* Cappu::CreateApp();

int main() {
	auto app = Cappu::CreateApp();
	app->Run();
	delete app;
}
