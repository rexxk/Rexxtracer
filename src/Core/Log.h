#pragma once

#include <format>
#include <print>
#include <string>



namespace Nut
{

	enum class LogType
	{
		Trace,
		Info,
		Warn,
		Error,
		Fatal,
	};


	template<LogType Type, typename ... Args>
	class Log
	{
	public:
		Log(std::format_string<Args...> fmt, Args&&... args)
		{
			std::string color;

			switch (Type)
			{
			case LogType::Trace: color = "37"; break;
			case LogType::Info: color = "32"; break;
			case LogType::Warn: color = "93"; break;
			case LogType::Error: color = "31"; break;
			case LogType::Fatal: color = "41"; break;

			default: color = 32; break;
			}

			const auto log = std::format("\033[{}m{}\033[m", color, std::format(fmt, std::forward<Args>(args)...));

			std::println("{}", log);
		}

	};


	template<LogType Type = {}, class ... Args>
	Log(std::format_string<Args...>, Args&& ...) -> Log<Type, Args...>;

	template<class ... Args>
	using trace = Log<LogType::Trace, Args...>;

	template<class ... Args>
	using info = Log<LogType::Info, Args...>;

	template<class ... Args>
	using warn = Log<LogType::Warn, Args...>;

	template<class ... Args>
	using error = Log<LogType::Error, Args...>;

	template<class ... Args>
	using fatal = Log<LogType::Fatal, Args...>;


}


#define LOG_CORE_TRACE(msg, ...) Nut::trace(msg, __VA_ARGS__)
#define LOG_CORE_INFO(msg, ...) Nut::info(msg, __VA_ARGS__)
#define LOG_CORE_WARN(msg, ...) NUt::warn(msg, __VA_ARGS__)
#define LOG_CORE_ERROR(msg, ...) Nut::error(msg, __VA_ARGS__)
#define LOG_CORE_FATAL(msg, ...) Nut::fatal(msg, __VA_ARGS__)



#define ASSERT(condition, msg, ...) { if (!condition) { Nut::error(msg, __VA_ARGS__); __debugbreak(); }}
