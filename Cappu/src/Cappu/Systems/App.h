#pragma once

namespace Cappu {

	class App {
	public:
		App();
		virtual ~App();

		void Run();

	private:
	};

	//To be defined in client
	App* CreateApp();

}


