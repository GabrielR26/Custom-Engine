#pragma once

#include "Utils/Utils.h"

#define DECLARE_TYPE(ClassType, ParentType)						\
typedef ParentType Super;										\
public:                                                         \
    static const TypeInfo* StaticTypeInfo()						\
    {                                                           \
        static TypeInfo typeInfo{ #ClassType, GenerateTypeID(), ParentType::StaticTypeInfo() }; \
        return &typeInfo;										\
    }                                                           \
                                                                \
    virtual const TypeInfo* GetTypeInfo() const override		\
    {                                                           \
        return ClassType::StaticTypeInfo();						\
    }															\
	virtual ~ClassType() = default;								\
private:														\
	ClassType& operator=(ClassType&&);							\
	ClassType& operator=(const ClassType&);								


using TypeID = size_t;
/// <summary>
/// Generate a TypeId for Class type
/// </summary>
/// <returns> Class' TypeId </returns>
inline TypeID GenerateTypeID()
{
	static TypeID _lastId = 0;
	return _lastId++;
}

/// <summary>
/// Wrapper for Class id, name and parent
/// </summary>
struct TypeInfo
{
	string name;
	TypeID id;
	const TypeInfo* parent;
};

/// <summary>
/// Base class for all derived Class in CustomEngine
/// </summary>
class Base
{
protected:
	bool isEnabled = true;
	bool isPendingDestroy = false;

public:
	inline bool IsEnabled() const { return isEnabled; }
	inline bool IsPendingDestroy() const { return isPendingDestroy; }
	inline bool IsValidForEvent() const { return !isPendingDestroy && isEnabled; }
	inline void SetIsEnabled(const bool _isEnabled) { isEnabled = _isEnabled; }

private:
	Base() = default;
	friend class Object;
	friend class Scene;
	friend class SaveData;

public:
	~Base() = default;

	virtual const TypeInfo* GetTypeInfo() const = 0;
	static const TypeInfo* StaticTypeInfo()
	{
		static TypeInfo typeInfo{ "Base", GenerateTypeID(), nullptr };
		return &typeInfo;
	}

	/// <summary>
	/// Check if current Class is derived from a Class type
	/// </summary>
	/// <typeparam name="T"> Class type </typeparam>
	/// <returns> True if derived. False otherwise </returns>
	template<typename T>
	bool IsA() const
	{
		const TypeInfo* _current = GetTypeInfo();
		const TypeInfo* _target = T::StaticTypeInfo();

		while (_current && _target)
		{
			if (_current->id == _target->id)
				return true;
			_current = _current->parent;
		}
		return false;
	}
};
