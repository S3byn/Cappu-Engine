#pragma once

namespace Cappu {

	class App {
	public:
		App();
		virtual ~App();

		void Run();

	private:
		bool m_running = true;
	};

	//To be defined in client
	App* CreateApp();

}


