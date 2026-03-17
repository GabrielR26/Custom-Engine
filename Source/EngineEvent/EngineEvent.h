#pragma once

#include "Base.h"

#define ENGINE_EVENT(event, ...) EngineEvent<__VA_ARGS__>* event = new EngineEvent<__VA_ARGS__>(); typedef EngineEvent<__VA_ARGS__>* EE##event;

/// <summary>
/// Delegate to store instance and function's pointer
/// </summary>
/// <typeparam name="...Args"> Parameters' Class of pointed function </typeparam>
template <typename... Args>
class Delegate final
{
private:
	typedef void(Base::* Function)(Args...);
	Function function = nullptr;
	Base* instance = nullptr;

public:
	Delegate() = default;

	/// <summary>
	/// Bind the delegate
	/// </summary>
	/// <typeparam name="Class"> Class of the instance </typeparam>
	/// <param name="_instance"> Instance to call the delegate </param>
	/// <param name="_ptr"> Function to callback </param>
	template<typename Class>
	void Bind(Class* _instance, void(Class::* _ptr)(Args...))
	{
		instance = _instance;
		function = reinterpret_cast<Function>(_ptr);
	};

	/// <summary>
	/// Unbind the delegate
	/// </summary>
	void Unbind()
	{
		function = nullptr;
		instance = nullptr;
	};

	/// <summary>
	/// Call the pointed function on Class' instance.
	/// Check if Class' instance is valid
	/// </summary>
	/// <param name="..._args"> Parameters of the pointed function </param>
	void Execute(Args... _args)
	{
		if (!instance || !function)
			return;
		if (!instance->IsValidForEvent())
			return;
		return (instance->*function)(_args...);
	};

	/// <summary>
	/// Compare given Class' instance and pointed function to current delegate
	/// </summary>
	/// <typeparam name="Class"> Class of the instance </typeparam>
	/// <param name="_instance"> Instance to compare </param>
	/// <param name="_ptr"> Pointed function to compare </param>
	/// <returns> Return true if Class' instance and pointed function are the same. False otherwise </returns>
	template<typename Class>
	bool IsSame(Class* _instance, void(Class::* _ptr)(Args...))
	{
		return instance == _instance && function == _ptr;
	}
};

/// <summary>
/// Delegates list wrapper for events in CustomEngine
/// </summary>
/// <typeparam name="...Args"> Parameters' Class of listed delegates </typeparam>
template <typename... Args>
class EngineEvent final
{
private:
	vector<Delegate<Args...>> delegates;

public:
	EngineEvent() = default;

	/// <summary>
	/// Add a new delegate
	/// </summary>
	/// <typeparam name="Class"> Class of the instance </typeparam>
	/// <param name="_instance"> Instance to call the delegate </param>
	/// <param name="_ptr"> Function to callback </param>
	template<typename Class>
	void AddListener(Class* _instance, void(Class::* _ptr)(Args...))
	{
		Delegate<Args...> _delegate;
		_delegate.Bind<Class>(_instance, _ptr);
		delegates.push_back(_delegate);
	}

	/// <summary>
	/// Remove a listed delegate (if found)
	/// </summary>
	/// <typeparam name="Class"> Class of the instance </typeparam>
	/// <param name="_instance"> Instance to call the delegate </param>
	/// <param name="_ptr"> Function to callback </param>
	template<typename Class>
	void RemoveListener(Class* _instance, void(Class::* _ptr)(Args...))
	{
		size_t _size = delegates.size();
		for (size_t i = 0; i < _size; i++)
		{
			Delegate<Args...>& _delegate = delegates[i];
			if (_delegate.IsSame(_instance, _ptr))
			{
				delegates[i].Unbind();
				delegates.erase(delegates.begin() + i);
				break;
			}
		}
	}

	/// <summary>
	/// Clear delegates list
	/// </summary>
	void RemoveAllListeners()
	{
		delegates.clear();
	}

	/// <summary>
	/// Execute callback on all listed delegates
	/// </summary>
	/// <param name="..._params"> Parameters of listed delegates </param>
	void Invoke(Args... _params)
	{
		if (delegates.empty())
			return;

		for (Delegate<Args...> _delegate : delegates)
			_delegate.Execute(_params...);
	}
};

//template <typename Class, typename... Params>
//using Action = EngineEvent<void, Class, Params...>;
//template <typename Res, typename Class, typename... Params>
//using Func = EngineEvent<Res, Class, Params...>;
