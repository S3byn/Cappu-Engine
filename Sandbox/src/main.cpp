#define CAPPU_ENTRY_POINT
#include <Cappu.h>

#include "Test.h"

class Game : public Cappu::App {
public:
	Game() {
		Test* test = new Test();
		PushLayer(test);

		if (Cappu::Input::GetKeyPressed((int)'D')) {
			PopLayer(test);
		}
	}
	~Game() {}
};

Cappu::App* Cappu::CreateApp() {
	return new Game;
}
