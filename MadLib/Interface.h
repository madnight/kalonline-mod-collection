#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <map>

/* Interface Creation */
#define CREATE_INTERFACE(I) \
class I; \
class __Init_##I \
	{ \
	public: \
	__Init_##I() { Interface<##I>::Create(); } \
	~__Init_##I() { } \
	} __i_Init_##I;

class InterfaceManager
{
	private:
		static InterfaceManager* _pInstance;
		std::map<size_t, void*> _Instances;
		//CScopeLock Lock;

	public:
		InterfaceManager() { this->_Instances.clear(); }
		void Add(size_t hash, void* Instance)
		{
			if (!this->_Instances.count(hash))
				this->_Instances[hash] = Instance;
		}
		void *Query(size_t hash)
		{
			// Thread safety is unnecessary - already thread safe
			//Lock.Enter();
			void *q = (this->_Instances.count(hash)) ? this->_Instances[hash] : NULL;
			//Lock.Leave();
			return q;
		}
		static __declspec(noinline) InterfaceManager* _GetInstance()
		{
			// Create singleton instance at first call
			if (!InterfaceManager::_pInstance) InterfaceManager::_pInstance = new InterfaceManager;
			return InterfaceManager::_pInstance;
		}
};

template <class T>
class Interface
{
	private:
		T *_Interface;

	public:
		static __declspec(noinline) void Create() { InterfaceManager *iM = InterfaceManager::_GetInstance(); iM->Add(typeid(T).hash_code(), new T); }
		static __declspec(noinline) void Create(T Pointer) { InterfaceManager *iM = InterfaceManager::_GetInstance(); iM->Add(typeid(T).hash_code(), Pointer); }

		Interface() { InterfaceManager *iM = InterfaceManager::_GetInstance(); this->_Interface = (T*)iM->Query(typeid(T).hash_code()); }
		~Interface() { }

		operator T*() const { return _Interface; }
		T* operator->()	{ return _Interface; }
};
#endif