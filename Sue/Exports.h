#ifndef __EXPORTS_H
#define __EXPORTS_H

class IExports
{
	public:
		static FARPROC p[15*4];
		static unsigned long _p;

	private:
		virtual void Initialize();
		HINSTANCE hL;

	friend class ICore;
};

#endif