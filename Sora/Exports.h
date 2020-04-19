#ifndef __EXPORTS_H
#define __EXPORTS_H

class IExports
{
	public:
		IExports();
		~IExports();

		static FARPROC p[3];
		static unsigned long _p;

	private:
		virtual void Initialize();
		HINSTANCE hL;
};

#endif