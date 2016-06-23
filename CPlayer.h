class CPlayer
{
private: 
	int* offset;

public:
	CPlayer(int *offset)
	{ 
		this->offset = offset;
	}

	void CIOCriticalSectionEnter(void);
	void CIOCriticalSectionLeave(void);
	bool CheckOnline(void);
	int GetPID(void);
	int GetAdmin(void);
	int GetRange(void);
	int GetUID(void);
	int getLevel(void);
	void InsetItem(int a2, int item);
};