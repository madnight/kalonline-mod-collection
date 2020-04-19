#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <map>

#include "Lock.h"

/* Interface Creation */

#ifndef SORA_PLUGIN
#define CREATE_INTERFACE(I) \
	class I; \
	class __Init_##I \
	{ \
		public: \
			__Init_##I() { Interface<##I>::Create(); } \
			~__Init_##I() { } \
	} __i_Init_##I;
#else
#include "Deflector.h"
#define CREATE_INTERFACE(I) \
	class I; \
	class __Init_##I \
		{ \
		public: \
		__Init_##I() \
		{ \
			Interface<IDeflector> __Base_Deflector_Instance(IDeflector::GetDeflectorInstance()); \
			Interface<##I>::Create(); \
		} \
		~__Init_##I() { } \
		} __i_Init_##I;
#endif

class InterfaceManager
{
	private:
		struct _Instance { void *Pointer; bool CanDelete; _Instance() { CanDelete = false; } };

		static InterfaceManager* _pInstance;
		std::map<size_t, _Instance> _Instances;
		//Lock Lock;

	public:
		InterfaceManager() { this->_Instances.clear(); }
		void *Add(size_t hash, void* Instance)
		{
			this->_Instances[hash].Pointer = Instance;
			return Instance;
		}
		void *Query(size_t hash)
		{
			// Thread safety is unnecessary - already thread safe
			//Lock.Enter();
			void *q = (this->_Instances.count(hash)) ? this->_Instances[hash].Pointer : NULL;
			//Lock.Leave();
			return q;
		}
		void Purge()
		{
			std::map<size_t, _Instance>::iterator I = this->_Instances.begin();
			while(I != this->_Instances.end())
			{
				if ((*I).second.CanDelete)
				{
					delete (*I).second.Pointer;
					I = this->_Instances.erase(I);
				}
				else I++;
			}
		}
		void Ephemeralize(size_t hash)
		{
			this->_Instances[hash].CanDelete = true;
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
		static __declspec(noinline) void Create()
		{
			InterfaceManager *iM = InterfaceManager::_GetInstance();
			if (!(T*)iM->Query(typeid(T).hash_code())) iM->Add(typeid(T).hash_code(), new T);
		}
		static void Purge()
		{
			InterfaceManager *iM = InterfaceManager::_GetInstance();
			iM->Purge();
		}
		static void Ephemeralize()
		{
			InterfaceManager *iM = InterfaceManager::_GetInstance();
			iM->Ephemeralize(typeid(T).hash_code());
		}

		Interface()
		{
			InterfaceManager *iM = InterfaceManager::_GetInstance();
			this->_Interface = (T*)iM->Query(typeid(T).hash_code());
			if (!this->_Interface) this->_Interface = (T*)iM->Add(typeid(T).hash_code(), new T);
		}
		Interface(T *Pointer)
		{
			InterfaceManager *iM = InterfaceManager::_GetInstance();
			this->_Interface = (T*)iM->Query(typeid(T).hash_code());
			if (!this->_Interface) this->_Interface = (T*)iM->Add(typeid(T).hash_code(), Pointer);
		}
		~Interface() { }

		operator T*() const { return _Interface; }
		T* operator->()	{ return _Interface; }
};
#endif