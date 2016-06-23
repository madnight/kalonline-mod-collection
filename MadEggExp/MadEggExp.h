#include <MainPlayer.h>


int EggExpTable[200];

void loadexp()
{
	EggExpTable[0]=0;
	EggExpTable[1]=7900;
	EggExpTable[2]=9120;
	EggExpTable[3]=11520;
	EggExpTable[4]=14880;
	EggExpTable[5]=19200;
	EggExpTable[6]=24480;
	EggExpTable[7]=30720;
	EggExpTable[8]=37920;
	EggExpTable[9]=46080;
	EggExpTable[10]=55200;
	EggExpTable[11]=65280;
	EggExpTable[12]=76320;
	EggExpTable[13]=88320;
	EggExpTable[14]=101280;
	EggExpTable[15]=115200;
	EggExpTable[16]=130080;
	EggExpTable[17]=145920;
	EggExpTable[18]=162720;
	EggExpTable[19]=180480;
	EggExpTable[20]=199200;
	EggExpTable[21]=218880;
	EggExpTable[22]=239520;
	EggExpTable[23]=261120;
	EggExpTable[24]=283680;
	EggExpTable[25]=307200;
	EggExpTable[26]=331680;
	EggExpTable[27]=357120;
	EggExpTable[28]=383520;
	EggExpTable[29]=410880;
	EggExpTable[30]=439200;
	EggExpTable[31]=468480;
	EggExpTable[32]=498720;
	EggExpTable[33]=529920;
	EggExpTable[34]=562080;
	EggExpTable[35]=595200;
	EggExpTable[36]=629280;
	EggExpTable[37]=664320;
	EggExpTable[38]=700320;
	EggExpTable[39]=737280;
	EggExpTable[40]=775200;
	EggExpTable[41]=814080;
	EggExpTable[42]=853920;
	EggExpTable[43]=894720;
	EggExpTable[44]=936480;
	EggExpTable[45]=979200;
	EggExpTable[46]=1022880;
	EggExpTable[47]=1067520;
	EggExpTable[48]=1113120;
	EggExpTable[49]=1159680;
	EggExpTable[50]=1207200;
	EggExpTable[51]=1255680;
	EggExpTable[52]=1305120;
	EggExpTable[53]=1355520;
	EggExpTable[54]=1406880;
	EggExpTable[55]=1459200;
	EggExpTable[56]=1512480;
	EggExpTable[57]=1566720;
	EggExpTable[58]=1621920;
	EggExpTable[59]=1678080;
	EggExpTable[60]=1735200;
	EggExpTable[61]=1793280;
	EggExpTable[62]=1852320;
	EggExpTable[63]=1912320;
	EggExpTable[64]=1973280;
	EggExpTable[65]=2035200;
	EggExpTable[66]=2098080;
	EggExpTable[67]=2161920;
	EggExpTable[68]=2226720;
	EggExpTable[69]=2292480;
	EggExpTable[70]=2359200;
	EggExpTable[71]=2426880;
	EggExpTable[72]=2495520;
	EggExpTable[73]=2565120;
	EggExpTable[74]=2635680;
	EggExpTable[75]=2707200;
	EggExpTable[76]=2779680;
	EggExpTable[77]=2853120;
	EggExpTable[78]=2927520;
	EggExpTable[79]=3002880;
	EggExpTable[80]=3079200;
	EggExpTable[81]=3156480;
	EggExpTable[82]=3234720;
	EggExpTable[83]=3313920;
	EggExpTable[84]=3394080;
	EggExpTable[85]=3475200;
	EggExpTable[86]=3557280;
	EggExpTable[87]=3640320;
	EggExpTable[88]=3724320;
	EggExpTable[89]=3809280;
	EggExpTable[90]=3895200;
	EggExpTable[91]=3982080;
	EggExpTable[92]=4069920;
	EggExpTable[93]=4158720;
	EggExpTable[94]=4248480;
	EggExpTable[95]=4339200;
	EggExpTable[96]=4430880;
	EggExpTable[97]=4523520;
	EggExpTable[98]=4617120;
	EggExpTable[99]=4711680;
	EggExpTable[100]=2;
	EggExpTable[101]=2;
	EggExpTable[102]=2;
	EggExpTable[103]=2;
	EggExpTable[104]=2;
}



namespace CItem
{
	static LONG (__thiscall *SendItemInfo)(void *a5,int, char a6) = (LONG (__thiscall*)(void *a5, int, char a6))0x00427430; 
	static int (__thiscall *IsState)(int thispointer, int a2) = (int (__thiscall*)(int thispointer, int a2))0x00427130;
}
namespace CItemTransform
{
	static void (__thiscall *SaveInfo)(int,int a4) = (void (__thiscall*)(int,int a4))0x0042F2C0; 
}




void __fastcall EggExp(int *ItemArray,void*, int *PlayerArray, int Type)
{

	Server::Console::WriteBlue("Debug1");
	int result; 
	if ( PlayerArray[113] != ItemArray[8] || (result = CItem::IsState((int)ItemArray,1), !result) || (result = (int)ItemArray, ItemArray[23] >= 100) )
		ItemArray[25] = 0;

	if ( Type == 1 )
	{
		Server::Console::WriteBlue("Debug2");
		ItemArray[25] += 1;

		if ( ItemArray[25] >= 180 )
		{
			Server::Console::WriteBlue("Debug3");
			ItemArray[25] = 0;
			ItemArray[24] += PlayerArray[15] * 4;
			CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);
		}
	}
	else
	{
		Server::Console::WriteBlue("Debug4");
		ItemArray[24] += PlayerArray[15];
		CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);	
	}
	if ( ItemArray[24] >= EggExpTable[ItemArray[23]] )
	{

		Server::Console::WriteBlue("Debug5");
		if ( PlayerArray[15] <= ItemArray[23] ){}
		ItemArray[24] -= EggExpTable[ItemArray[23]];
		ItemArray[23] += 1;

		CItemTransform::SaveInfo((int)ItemArray,1);
		CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);
	}

}





void __fastcall  CPlayer__UpdateTransformExp(void* thisp,void* _edx,int Type)
{
	Server::CIOCriticalSection::Enter( (void*) ( (DWORD)thisp+1020) );
  if ( *(DWORD *)( (DWORD)thisp + 1108) )
   EggExp(*(int* *)( (DWORD)thisp + 1108),_edx,(int*) thisp, Type);
  Server::CIOCriticalSection::Leave( (void*) ( (DWORD)thisp+1020) );
}












namespace MadEggExp
{
	namespace CIOServer 
	{
		void __stdcall Start(int start)
		{
			Server::CIOServer::Start(start);
			//loadexp();
			Server::Console::WriteBlue("[MadEggExp started credits goes to Bloodx for Source]");
		}
	}

	namespace CItem
	{
		void __fastcall  CItemTransform__UpdateExp(int *ItemArray, void* _edx, int *PlayerArray, int Type)
		{
			int result; 
			if ( PlayerArray[113] != ItemArray[8] || 
				(result = Server::CItem::IsState((int)ItemArray,1), !result) || 
				(result = (int)ItemArray, ItemArray[23] >= 100) )
				ItemArray[25] = 0;

			if ( Type == 1 )
			{
				ItemArray[25] += 1;

				if ( ItemArray[25] >= 180 )
				{
					ItemArray[25] = 0;
					ItemArray[24] += PlayerArray[15] * 4;
					Server::CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);
				}
			}
			else
			{
				ItemArray[24] += PlayerArray[15];
				Server::CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);	
			}
			if ( ItemArray[24] >= EggExpTable[ItemArray[23]] )
			{
				if ( PlayerArray[15] <= ItemArray[23] ){}
				ItemArray[24] -= EggExpTable[ItemArray[23]];
				ItemArray[23] += 1;

				Server::CItem::CItemTransform__SaveInfo((int)ItemArray,1);
				Server::CItem::SendItemInfo((void*)ItemArray,(int)PlayerArray, 92);
			}
		}
	}

}