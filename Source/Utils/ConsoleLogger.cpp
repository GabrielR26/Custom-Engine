
#include "ConsoleLogger.h"

void ConsoleLogger::Log(const std::string_view& _log)
{
	Log(_log, LogLevel::Info, "LOG", terminal_color::white);
}

void ConsoleLogger::Log(const std::string_view& _log, const terminal_color& _color)
{
	Log(_log, LogLevel::Info, "LOG", _color);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level)
{
	Log(_log, _level, "LOG", terminal_color::white);
}

void ConsoleLogger::Log(const std::string_view& _log, const std::string_view& _category)
{
	Log(_log, LogLevel::Info, _category, terminal_color::white);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const terminal_color& _color)
{
	Log(_log, _level, "LOG", _color);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category)
{
	Log(_log, _level, _category, terminal_color::white);
}

void ConsoleLogger::Log(const std::string_view& _log, const std::string_view& _category, const terminal_color& _color)
{
	Log(_log, LogLevel::Info, _category, _color);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const terminal_color& _color)
{
	Log(_log, _level, _category, _color, emphasis());
}

void ConsoleLogger::Log(const std::string_view& _log, const text_style& _styles)
{
	Log(_log, LogLevel::Info, "LOG", terminal_color::white, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const terminal_color& _color, const text_style& _styles)
{
	Log(_log, LogLevel::Info, "LOG", _color, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const text_style& _styles)
{
	Log(_log, _level, "LOG", terminal_color::white, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const std::string_view& _category, const text_style& _styles)
{
	Log(_log, LogLevel::Info, _category, terminal_color::white, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const terminal_color& _color, const text_style& _styles)
{
	Log(_log, _level, "LOG", _color, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const text_style& _styles)
{
	Log(_log, _level, _category, terminal_color::white, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const std::string_view& _category, const terminal_color& _color, const text_style& _styles)
{
	Log(_log, LogLevel::Info, _category, _color, _styles);
}

void ConsoleLogger::Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const terminal_color& _color, const text_style& _styles)
{
	std::string _timestamp = GetTimestamp();
	std::string _strLevel;
	switch (_level)
	{
	case LogLevel::Info:
		_strLevel = "INFO";
		break;
	case LogLevel::Warning:
		_strLevel = "WARNING";
		break;
	case LogLevel::Error:
		_strLevel = "ERROR";
		break;
	case LogLevel::Debug:
		_strLevel = "DEBUG";
		break;
	}
	print(fg(_color) | _styles, "{0} [{1}] [{2}] => {3}\n", _timestamp, _category, _strLevel, _log);
}

void ConsoleLogger::LogWarning(const std::string_view& _log, const std::string_view& _category)
{
	Log(_log, LogLevel::Warning, _category, terminal_color::yellow, emphasis::italic);
}

void ConsoleLogger::LogError(const std::string_view& _log, const std::string_view& _category)
{
	Log(_log, LogLevel::Error, _category, terminal_color::red, emphasis::italic | emphasis::blink);
}

std::string ConsoleLogger::GetTimestamp()
{
	using namespace std;
	using namespace std::chrono;

	time_t _time = system_clock::to_time_t(system_clock::now());
	tm _localTime{};

#ifdef _WIN32
	localtime_s(&_localTime, &_time);
#else
	localtime_r(&_time, &_localTime);
#endif

	ostringstream _oss;
	_oss << put_time(&_localTime, "[%H:%M:%S]");
	return _oss.str();
}

