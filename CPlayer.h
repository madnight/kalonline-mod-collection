/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
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