#pragma once

#include <fmt/core.h>
#include <fmt/color.h>
#include <chrono>

using namespace fmt;

// Macros for easy logging
#define LOG(...) ConsoleLogger::Log(__VA_ARGS__) // Default log with log and optional level - category - color - styles
#define LOG_WARNING(...) ConsoleLogger::LogWarning(__VA_ARGS__) // Warning log with log and optional category
#define LOG_ERROR(...) ConsoleLogger::LogError(__VA_ARGS__) // Error log with log and optional category
#define VECTOR_STRING(vector) format("({}, {})", vector.x, vector.y) // Return vector to string format

/// <summary>
/// Level of a log
/// </summary>
enum LogLevel
{
	Info,
	Warning,
	Error,
	Debug
};

/// <summary>
/// Class for console log
/// </summary>
class ConsoleLogger
{
public:
	/// <summary>
	/// Display a log in the console
	/// </summary>
	static void Log(const std::string_view& _log);
	/// <summary>
	/// Display a log in the console with a specific color
	/// </summary>
	static void Log(const std::string_view& _log, const terminal_color& _color);
	/// <summary>
	/// Display a log in the console with a specific level
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level);
	/// <summary>
	/// Display a log in the console with a specific category
	/// </summary>
	static void Log(const std::string_view& _log, const std::string_view& _category);
	/// <summary>
	/// Display a log in the console with a specific level and color
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const terminal_color& _color);
	/// <summary>
	/// Display a log in the console with a specific level and category
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category);
	/// <summary>
	/// Display a log in the console with a specific category and color
	/// </summary>
	static void Log(const std::string_view& _log, const std::string_view& _category, const terminal_color& _color);
	/// <summary>
	/// Display a log in the console with a specific level, category and color
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const terminal_color& _color);

	/// <summary>
	/// Display a log in the console with text styles
	/// </summary>
	static void Log(const std::string_view& _log, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific color and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const terminal_color& _color, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific level and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific category and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const std::string_view& _category, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific level, color and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const terminal_color& _color, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific level, category and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific category, color and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const std::string_view& _category, const terminal_color& _color, const text_style& _styles);
	/// <summary>
	/// Display a log in the console with a specific level, category, color and text styles
	/// </summary>
	static void Log(const std::string_view& _log, const LogLevel& _level, const std::string_view& _category, const terminal_color& _color, const text_style& _styles);

	/// <summary>
	/// Display a warning log in the console with a specific category
	/// </summary>
	static void LogWarning(const std::string_view& _log, const std::string_view& _category = "LOG");

	/// <summary>
	/// Display an error log in the console with a specific category 
	/// </summary>
	static void LogError(const std::string_view& _log, const std::string_view& _category = "LOG");

	/// <summary>
	/// Define the timestamp format for the logs
	/// </summary>
	static std::string GetTimestamp();
};
