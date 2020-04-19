class ISkill
{

public:
    void *Offset;

public:
    ISkill()
    {
    }

    ISkill(void *Packet);
    virtual ~ISkill();

    void *GetOffset();
    int GetIndex();
    int GetGrade();
    int DecreaseMana();
    void *GetPlayer();
};