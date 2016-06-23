#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LevelReward
{
	int level;
	int item_index;
	int item_amount;
};

struct LevelReward create(int lvl, int index, int amount)
{
	LevelReward reward;
	reward.level = lvl;
	reward.item_index = index;
	reward.item_amount = amount;
	return reward;
}

vector<LevelReward> levelrewardvec;

void readConfig()
{
	string prefix = "[Reward Item]";

	string prefix_level = "Level";
	string prefix_index = "Index";
	string prefix_amount = "Amount";

	ifstream f;  
	string s;
	string t;
	ifstream ifile("MadLevelReward.txt");
	if (ifile) 
	{
		f.open("MadLevelReward.txt", ios::in); // Öffne Datei aus Parameter
		while (!f.eof())          // Solange noch Daten vorliegen
		{
			getline(f, s);        // Lese eine Zeile
			if (s.substr(0, prefix.size()) == prefix) 
			{
				int level,index,amount;
			     ostringstream consolepost;	
				getline(f, s);
				if (s.substr(0, prefix_level.size()) == prefix_level)
				{
					t = (s.substr(8,20));	
					level =  atoi( t.c_str() );		
				}

				getline(f, s);
				if (s.substr(0, prefix_index.size()) == prefix_index)
				{
					t = (s.substr(8,20));	
					index =  atoi( t.c_str() );
				}

				getline(f, s);
				if (s.substr(0, prefix_amount.size()) == prefix_amount)
				{
					t = (s.substr(8,20));	
					amount =  atoi( t.c_str() );
				}
				if (level != 0 && index != 0 && amount != 0)
					levelrewardvec.push_back(create(level,index,amount));
			}		
		}
		f.close();            
	}
}
