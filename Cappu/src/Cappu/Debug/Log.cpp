#include "CappuPCH.h"
#include "Log.h"

void PrintLogHeader(Cappu::LogType type) {
	time_t now = time(nullptr);
	struct tm timeInfo;
	char buffer[9];

	localtime_s(&timeInfo, &now);
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeInfo);
	
	#ifdef CAPPU_PLATFORM_WINDOWS 
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (type) {
		case Cappu::LogType::Message: 
			SetConsoleTextAttribute(consoleHandle, 0x2);
			printf("[i][%s] ", buffer); 
		break;

		case Cappu::LogType::Error: 
			SetConsoleTextAttribute(consoleHandle, 0x4);
			printf("[x][%s] ", buffer); 
		break;

		case Cappu::LogType::Warning: 
			SetConsoleTextAttribute(consoleHandle, 0x6);
			printf("[!][%s] ", buffer);
		break;
	}

	SetConsoleTextAttribute(consoleHandle, 0x7);

	#else

	switch (type) {
		case Cappu::LogType::Message: printf("\033[32m[i][%s] \033[0m", buffer); break;
		case Cappu::LogType::Error: printf("\033[31m[x][%s] \033[0m", buffer); break;
		case Cappu::LogType::Warning: printf("\033[33m[!][%s] \033[0m", buffer); break;
	}
	
	#endif
}

void Cappu::Log(LogType type, const char* message, ...) {
	PrintLogHeader(type);

	va_list args;
	va_start(args, message);

	vprintf(message, args);

	va_end(args);

	printf("\n");
}

void Cappu::Assert(int status, const char* message, ...) {
	//If we did not assert just return
	if(status) return;

	//Otherwise print error and assert
	PrintLogHeader(LogType::Error);

	va_list args;
	va_start(args, message);

	vprintf(message, args);

	va_end(args);

	printf("\n");

	__debugbreak();
}
