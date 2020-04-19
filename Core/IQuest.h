class IQuest
{
	public:
		void *Offset;

	public:
		IQuest()
		{
		}
        
    IQuest(void *Object);
    virtual ~IQuest();
    
    void *GetOffset();
    int GetIndex();
	int GetFlag();
};