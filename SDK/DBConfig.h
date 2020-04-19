#ifndef __DBCONFIG_H
#define __DBCONFIG_H

#include <vector>

class DBSection;

class IDBConfig
{
private:
    struct _SConfig
    {
        std::string _File;
        DBSection *_FileSection;
    };
    std::map<std::string, _SConfig*> _Configs;

public:
    IDBConfig();
    ~IDBConfig();

    void SetFile(std::string DBName, std::string File);
    bool IsLoaded(std::string DBName);
    std::string Find(std::string File);	// Returns DBName loaded from File if found
    bool Load(std::string DBName, std::string File);
    bool Save(std::string DBName);
    void Delete(std::string DBName);

    DBSection& Get(std::string DBName);
};

// Object class

class DBSection
{
private:
    std::string _Name;
    std::string _sValue;
    std::vector<double> _vfValues;

    std::vector<DBSection*> _SectionList;

protected:
    DBSection(std::string Name, std::string _Section);

public:
    virtual ~DBSection();

    size_t Size();

    DBSection *Get(std::string Section);
    DBSection *Get(size_t Offset);

    std::string GetName();
    std::string GetString();
    int GetInt();
    double GetFloat();
    std::vector<double> GetArray();

    DBSection& operator[](const std::string& Section);

    friend class IDBConfig;
};

#endif
