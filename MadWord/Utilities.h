#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> words;

void readConfig()
{
	string buffer;
	ifstream f;  
	ifstream ifile("MadConsoleWords.txt");
	if (ifile) 
	{
		f.open("MadConsoleWords.txt", ios::in);
		while (!f.eof())         
		{
			getline(f, buffer); 
			words.push_back(buffer);
			buffer.clear();
		}
	}
}

bool checkWords(string text){
	for (unsigned int i = 0; i<words.size();i++)
	{
		if (text.find(words[i]) != string::npos)
			return true;
	}
	return false;
}

