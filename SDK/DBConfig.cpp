#include "StdAfx.h"

#include <string>
#include <fstream>

#include "Interface.h"

#include "DBConfig.h"
#include "Tools.h"


CREATE_INTERFACE(IDBConfig)

IDBConfig::IDBConfig()
{
	this->_Configs.clear();
}
IDBConfig::~IDBConfig()
{
}

bool IDBConfig::Load(std::string DBName, std::string File)
{
	Interface<ITools> Tools;

	if (this->_Configs.count(DBName)) return false;
	std::fstream f;
	size_t size = 0;

	f.open(File, std::fstream::binary | std::fstream::in);
	if (!f.is_open()) return false;

	f.seekg(0, std::fstream::end);
	size = (size_t)f.tellg();
	f.seekg(0, std::fstream::beg);

	char *Buffer = new char[size+1];
	ZeroMemory(Buffer, size+1);
	f.read(Buffer, size);
	f.close();

	std::string content = Buffer;
	delete Buffer;

	Tools->RemoveComments(content);

	std::string real = "(" + DBName + "\r\n" + content + "\r\n)";

	IDBConfig::_SConfig *_config = new IDBConfig::_SConfig;
	_config->_File = File;
	_config->_FileSection = new DBSection("", real);

	this->_Configs[DBName] = _config;

	return true;
}
void IDBConfig::Delete(std::string DBName)
{
	if (this->_Configs.count(DBName))
	{
		delete this->_Configs[DBName]->_FileSection;
		this->_Configs.erase(this->_Configs.find(DBName));
	}
}
void IDBConfig::SetFile(std::string DBName, std::string File)
{
	if (this->_Configs.count(DBName))
		this->_Configs[DBName]->_File = File;
}
bool IDBConfig::IsLoaded(std::string DBName)
{
	if (this->_Configs.count(DBName)) return true;
	else return false;
}
std::string IDBConfig::Find(std::string File)
{
	for(std::map<std::string, IDBConfig::_SConfig*>::iterator I = this->_Configs.begin(); I != this->_Configs.end(); I++)
		if ((*I).second->_File == File) return (*I).first;
	return "";
}
DBSection& IDBConfig::Get(std::string DBName)
{
	//if (!this->_Configs.count(DBName)) return NULL;
	return *this->_Configs[DBName]->_FileSection;
}

// (meow (blow (this "shit") (off 511845)) (moo (kikoo "lol") (wtf "omg")))

DBSection::DBSection(std::string Name, std::string _Section) : _sValue(""), _Name(Name)
{
	Interface<ITools> Tools;

	this->_vfValues.clear();
	this->_SectionList.clear();

	bool InString = false;
	bool ValueOnly = true;
	std::string Key;

	// Searching for possible subsections
	for(size_t i=1; i < _Section.size(); i++)
	{
		if (_Section[i] == '"') InString = !InString;
		if ((_Section[i] == '(') && (!InString)) { ValueOnly = false; break; }
	}

	// Parsing Section name
	bool __found = false;
	for(size_t i=0, begin=0; i < _Section.size(); i++)
	{
		char c = _Section[i];
		if (c != '(' && c != ')' && c != ' ' && c != '\t' && c != '\r' && c != '\n')
		{
			if (!__found)
			{
				begin = i;
				__found = true;
			}
		}
		else
		{
			if (__found) { Key = _Section.substr(begin, i-begin); break; }
		}
	}

	__found = false;
	if (ValueOnly) // Parsing value
	{
		size_t offset = _Section.find(Key) + Key.length();
		size_t str_offset = _Section.find('"', offset);
		// Check if string
		if (str_offset != std::string::npos)
		{
			size_t str_end = _Section.find('"', str_offset+1);
			this->_sValue = _Section.substr(str_offset, str_end-str_offset+1);
			this->_Name = Key;
		}
		else
		{
			std::string NumSeq = _Section.substr(_Section.find(Key) + Key.length());
			while (true)
			{
				double _d = Tools->GetNextFloat(NumSeq);
				if (NumSeq.length()) this->_vfValues.push_back(_d);
				else break;
			}
		}
	}

	else // Parsing subsections
	{
		size_t Depth = 0;
		InString = false;
		for(size_t last=1, i=1, current=0; i < _Section.length(); i++, current++)
		{
			char c = _Section[i];
			if (c == '"') InString = !InString;

			if (!InString)
			{
				if (c == '(')
				{
					Depth++;
					if (Depth == 1) { last = i; current = 0; }
				}
				else if (c == ')')
				{
					Depth--;
					if (Depth == 0)
					{
						this->_Name = Key;
						this->_SectionList.push_back(new DBSection(Key, _Section.substr(last, current+1)));
						current = 0;
					}
					if (Depth == -1) break;
				}
			}
		}
	}
}

DBSection::~DBSection()
{
	for(size_t i=0; i < this->_SectionList.size(); i++)
		delete this->_SectionList[i];
}

size_t DBSection::Size() { return this->_SectionList.size(); }
DBSection *DBSection::Get(std::string Section)
{
	for(size_t i=0; i < this->_SectionList.size(); i++)
		if (this->_SectionList[i]->_Name == Section) return this->_SectionList[i];
	return NULL;
}
DBSection *DBSection::Get(size_t Offset)
{
	if (this->_SectionList.size() < Offset) return NULL;
	else return this->_SectionList[Offset];
}

std::string DBSection::GetString()
{
	return this->_sValue;
}
double DBSection::GetFloat()
{
	return this->_vfValues[0];
}
int DBSection::GetInt()
{
	return (int)this->_vfValues[0];
}
std::vector<double> DBSection::GetArray()
{
	std::vector<double> _vNew = this->_vfValues;
	return _vNew;
}
std::string DBSection::GetName()
{
	return this->_Name;
}

DBSection& DBSection::operator[](const std::string& Section)
{
	DBSection *Ret = NULL;;
	for(size_t i=0; i < this->_SectionList.size(); i++)
		if (this->_SectionList[i]->_Name == Section) { Ret = this->_SectionList[i]; break; }

	if (!Ret) throw "Unexisting Section Name";
	return *Ret;
}
