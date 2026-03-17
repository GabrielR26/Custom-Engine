#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <fstream>
#include <source_location>
#include <string>
#include <format>
#include <vector>
#include "ConsoleLogger.h"
#include "json.hpp"

using namespace sf;
using namespace std;
using namespace filesystem;
using json = nlohmann::json;

#define STRINGIFY(_toStringify) #_toStringify
#define COMBINE_TOKEN_TWO(A, B) A##B

#define VECTOR_ZERO Vector2f(0.f, 0.f)
#define VECTOR_ONE Vector2f(1.f, 1.f)
#define VECTOR_X Vector2f(1.f, 0.f)
#define VECTOR_Y Vector2f(0.f, 1.f)
#define VECTOR_CENTER Vector2f(Engine::GetMainWindowSize().x * 0.5f, Engine::GetMainWindowSize().y * 0.5f) // Position of window's center

#define THROW_IF_NULLPTR(_ptr) if (_ptr == nullptr) THROW_ERROR(format("{} is nullptr", #_ptr))
#define THROW_ERROR(_msg) throw runtime_error(format("{} - {} - Line {} : {}", RemovePath(__FILE__), __FUNCTION__, __LINE__, _msg));

/// <summary>
/// Remove path of a file's path
/// </summary>
/// <param name="_filePath"> File's path </param>
/// <returns> Remaining file's name </returns>
static string RemovePath(const char* _filePath)
{
	string _fileName(_filePath);
	return _fileName.substr(_fileName.find_last_of('\\') + 1);
}

#define RAND_BOOL (Random<int>::Rand() == 1 ? true : false) // Random boolean
#define RAND_INT_RANGE(min, max) Random<int>::Rand(min, max) // Random integer between min and max
#define RAND_FLOAT() Random<float>::Rand() // Random float between 0.0 and 1.0
#define RAND_FLOAT_RANGE(min, max) Random<float>::Rand(min, max) // Random float between min and max

template<typename T>
concept Numeric = floating_point<T> || integral<T>;
template <Numeric T>
class Random
{
public:
	static T Rand(const T& _min = 0, const T& _max = 1)
	{
		static mt19937 _generator(random_device{}());
		if constexpr (is_integral_v<T>)
		{
			uniform_int_distribution<T> _distribution(_min, _max);
			return _distribution(_generator);
		}
		else
		{
			uniform_real_distribution<T> _distribution(_min, _max);
			return _distribution(_generator);
		}
	}
};
