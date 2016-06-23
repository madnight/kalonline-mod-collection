#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct MixItem
{
	int index;
	int info;
};

struct MixItem create(int index, int info)
{
	MixItem item;
	item.index = index;
	item.info = info;
	return item;
}

vector<MixItem> MixItems;

void ReadConfig()
{
	string prefix = "[Mix Item]";

	string prefix_index = "Index";
	string prefix_info = "Info";

	ifstream f;  
	string s,t;
	ifstream ifile("MadRealtime.txt");
	if (ifile) 
	{
		f.open("MadRealtime.txt", ios::in); 
		while (!f.eof())      
		{
			getline(f, s);       
			if (s.substr(0, prefix.size()) == prefix) 
			{
				int index,info;

				getline(f, s);
				if (s.substr(0, prefix_index.size()) == prefix_index)
				{
					t = (s.substr(8,20));	
					index =  atoi( t.c_str() );		
				}

				getline(f, s);
				if (s.substr(0, prefix_info.size()) == prefix_info)
				{
					t = (s.substr(8,20));	
					info =  atoi( t.c_str() );
				}

				if (index && info)
					MixItems.push_back(create(index,info));
			}		
		}
		f.close();            
	}
}
