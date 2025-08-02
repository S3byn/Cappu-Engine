#define CAPPU_ENTRY_POINT
#include <Cappu.h>

#include "Test.h"

class Game : public Cappu::App {
public:
	Game() {}
	~Game() {}
};

Cappu::App* Cappu::CreateApp() {
	return new Game;
}
