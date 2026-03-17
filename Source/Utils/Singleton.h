#pragma once

#include "Utils.h"

template <typename T>
class Singleton
{
protected:
	static inline T* instance = nullptr;
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

public:
	static T* Instance() 
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}

	void DestroyInstance() 
	{
		delete instance;
		instance = nullptr;
	}
};

//#include <memory>
//template <typename T>
//class Singleton 
//{
//public:
//    static inline std::unique_ptr<T> instance = nullptr;
//
//    Singleton() = default;
//    ~Singleton() 
//    { 
//        OnDestroy(); 
//    }
//
//    Singleton(const Singleton&) = delete;
//    Singleton& operator=(const Singleton&) = delete;
//
//public:
//    static T* Instance() 
// {
//        if (!instance)
//            instance = std::make_unique<T>();
//        return instance.get();
//    }
//
//    virtual void OnDestroy() {}
//};

//template <typename T>
//class Singleton
//{
//private:
//	static inline T* instance = nullptr;
//
//protected:
//	Singleton() = default;
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//public:
//	static T* Instance()
//	{
//		if (instance == nullptr)
//			instance = new T();
//		return instance;
//	}
//
//	virtual void OnDestroy() 
//	{
//		delete instance;
//		instance = nullptr;
//		LOG("Destroy Singleton");
//	};
//};