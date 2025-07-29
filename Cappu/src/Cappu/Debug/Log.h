#pragma once

#if _DEBUG
	#define CAPPU_ASSERT(status, message, ...) Cappu::Assert(status, message, __VA_ARGS__)
#else
	#define CAPPU_ASSERT(status, message, ...)
#endif

#define CAPPU_LOG(message, ...) Cappu::Log(Cappu::LogType::Message, message, __VA_ARGS__)
#define CAPPU_WARN(message, ...) Cappu::Log(Cappu::LogType::Warning, message, __VA_ARGS__)
#define CAPPU_ERROR(message, ...) Cappu::Log(Cappu::LogType::Error, message, __VA_ARGS__)

namespace Cappu {
	enum class LogType {
		Message, Error, Warning
	};

	void Log(LogType type, const char* message, ...);

	void Assert(int status, const char* message, ...);
}
