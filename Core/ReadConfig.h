char ConfigCheck[50], ConfigClient[50], ConfigEngine[50], ConfigConfig[50],
     ConfigMConfig[50], ConfigEpk[50], SinCheck[50], PlayerCheck[50],
     Active2ndPwd[50], ThiefActiveCheck[50], ShopRewardCheck[50], LicenseSerial[75];
std::string Door = "Hell", Door2 = "Hell", Door3 = "Hell", Door4 = "Hell",
            Door5 = "Hell", Door6 = "Hell", Door7 = "Hell", Door8 = "Hell";
std::string ConfigCheckDB3 = "Hell", ConfigCheckDB4 = "Hell";
char key1 = '255', key2 = '255', key3 = '255', key4 = '255', key5 = '255',
     key6 = '255', key7 = '255';
const char *ConfigCheckDB1, *ConfigCheckDB2;
DWORD port = 65505;
int ConfigMix = 0, ConfigImp = 0, ConfigDBCheck = 0;
int EggExpTime = 0, EggExpKill = 0, ConfigMaxDamage = 0, ConfigMaxMagAtk = 0,
    ConfigMaxPhyAtk = 0;
int EmokQuestIndex = 0, EmokX = 0, EmokY = 0, EmokMap = 0, EmokCert = 0;
int MysteryResetItem = 0, MysteryQuest = 0;
bool LicenseSerialCheck = false;
int FishLowest = 0, FishLow = 0, FishNormal = 0, FishHard = 0, FishHardest = 0;
int KnightManaCirculation = 0, Knight, KPWWReduce = 0, KPWWMul = 0, KPWWMin = 0,
    KPWWMax = 0;
int KPOBReduce = 0, KPOBMul = 0, KPOBMin = 0, KPOBMax = 0;
int KSSReduce = 0, KSSMul = 0, KSSMin = 0, KSSMax = 0, KSSDBMin = 0,
    KSSDBMax = 0;
int KSDReduce = 0, KSDMul = 0, KSDMin = 0, KSDMax = 0;
int MageManaCirculation = 0, MRIAmount = 0, ArcherManaCirculation = 0;
int MSDReduce = 0, MSDMul = 0, MSDMin = 0, MSDMax = 0;
int MFBReduce = 0, MFBMul = 0, MFBMin = 0, MFBMax = 0;
int MIAReduce = 0, MIAMul = 0, MIAMin = 0, MIAMax = 0;
int MIcicleReduce = 0, MIcicleMul = 0, MIcicleMin = 0, MIcicleMax = 0;
int MTBReduce = 0, MTBMul = 0, MTBMin = 0, MTBMax = 0;
int AVAReduce = 0, AVAMul = 0, AVAMin = 0, AVAMax = 0;
int AAEReduce = 0, AAEMul = 0, AAEMin = 0, AAEMax = 0;
int AARReduce = 0, AARMul = 0, AARMin = 0, AARMax = 0;
int EBSMul = 0, EBSReduce = 0, ERAReduce = 0, ERAMul = 0, ETBReduce = 0,
    ETBMul = 0;
int ALAReduce = 0, ALAMul = 0;
int ACSReduce = 0, ACSMul = 0, ACSMin = 0, ACSMax = 0;
int MLAReduce = 0, MLAMul = 0, MLAMin = 0, MLAMax = 0;
int MFIReduce = 0, MFIMul = 0, MFIMin = 0, MFIMax = 0;
int MMIReduce = 0, MMIMul = 0, MMIMin = 0, MMIMax = 0;
int TEShinReduce = 0, TEShinMul = 0, TEZilReduce = 0, TEZilMul = 0,
    TEWhirReduce = 0, TEWhirMul = 0;
int TWOHReduce = 0, TWOHMul = 0, TWOHMin = 0, TWOHMax = 0;
int TSBReduce = 0, TSBMul = 0, TSBMin = 0, TSBMax = 0;
int TSSReduce = 0, TSSMul = 0, TSSMin = 0, TSSMax = 0;
int TLSReduce = 0, TLSMul = 0, TLSMin = 0, TLSMax = 0;
int TDOKReduce = 0, TDOKMul = 0, TDOKMin = 0, TDOKMax = 0;
int TCOReduce = 0, TCOMin = 0, TCOMax = 0, MageFakeDamage = 0;
int TCAReduce = 0, TCAMin = 0, TCAMax = 0;
int TTBSReduce = 0, TTBSMul = 0, TTBSMin = 0, TTBSMax = 0;
int TSAReduce = 0, TSAMul = 0, TSAMin = 0, TSAMax = 0;
int TSuBReduce = 0, TSuBMul = 0, TSuBMin = 0, TSuBMax = 0;
int TFBReduce = 0, TFBMul = 0, TFBMin = 0, TFBMax = 0;
int TAssReduce = 0, TAssMul = 0, TAssMin = 0, TAssMax = 0;
int TVSReduce = 0, TVSMul = 0, TVSMin = 0, TVSMax = 0;
int TRupReduce = 0, TRupMul = 0, TRupMin = 0, TRupMax = 0;
int TFWReduce = 0, TFWMul = 0, TFWMin = 0, TFWMax = 0;
int TStranReduce = 0, TStranMul = 0, TStranMin = 0, TStranMax = 0;
int TStunReduce = 0, TStunMul = 0, TStunMin = 0, TStunMax = 0;
int BFMap = 0, BFQuest = 0, ScenarioMap = 0, ScenarioQuest = 0,
    DonationCoin = 0, F10Quest = 0, BFTime = 0, ScenarioTime = 0;
int DTQuest = 0, DTLimit = 0, ConfigPVPMaxDmg = 100000;
unsigned __int64 F10Exp = 1, HellQuest = 0, HellMap = 0, HellX = 0, HellY = 0,
                 HellReturnX = 0, HellReturnY = 0, HellSummonX = 0, HellSummonY = 0;
char boxnotice[BUFSIZ], moveto[BUFSIZ], block[BUFSIZ], unblock[BUFSIZ],
     hardblock[BUFSIZ], newnotice[BUFSIZ], donatename[BUFSIZ], mutename[BUFSIZ];
int newnoticetype = 0, buffid = 0, geonamount = 0, speedvalue = 0,
    summonindex = 1, summonamount = 1, donateamount = 1, cwtotaltime = 0,
    mutetime = 0;
const char *MyReLisansCheckChar = "nothing";
std::string MyReLisansCheckStr = "nothing";
int ShopRewardTime = 0, ShopRewardIndex = 0, ShopRewardAmount = 0;
char ExpEventStart[50] = "Hell", ExpEventEnd[50] = "Hell",
                         ActiveExpEvent[50] = "Hell";
int LMSLimit = 0, LMSQuest = 0, LMSMap = 0, LMSX = 0, LMSY = 0;
int PLQuest = 0, PLMap = 0, PLRNPC = 0, PLBNPC = 0;
int NWOEMul = 0, NWOEMin = 0, NWOEMax = 0, NWOEReduce = 0;
int NOHSMul = 0, NOHSMin = 0, NOHSMax = 0, NOHSReduce = 0;
int NAOTMMul = 0, NAOTMMin = 0, NAOTMMax = 0, NAOTMReduce = 0;
int NMFMul = 0, NMFMin = 0, NMFMax = 0, NMFReduce = 0;
int NSOTAMul = 0, NSOTAMin = 0, NSOTAMax = 0, NSOTAReduce = 0;
int NMPMul = 0, NMPMin = 0, NMPMax = 0, NMPReduce = 0;
int NCSMul = 0, NCSMin = 0, NCSMax = 0, NCSReduce = 0;
int NSOGMul = 0, NSOGMin = 0, NSOGMax = 0, NSOGReduce = 0;
int NDAMul = 0, NDAMin = 0, NDAMax = 0, NDAReduce = 0;
int NBOMMul = 0, NBOMMin = 0, NBOMMax = 0, NBOMReduce = 0;
int ENPCQ = 0, ENPCRQ = 0, ENPCDL = 0, ENPCIA = 0, ENPCDU = 0, ENPCII = 0,
    ENPCDD = 0, ENPCDC = 0;
char HGST[50] = "";
int HGXC = 0, HGYC = 0, HGMapI = 0, HGMobI = 0, HGDM = 0, HGDTu = 0, HGEA = 0;
int HGDW = 0, HGDTh = 0, HGDF = 0, HGDSa = 0, HGDSu = 0;
char HGNM[50] = "", HGNTu[50] = "", HGNW[50] = "", HGNTh[50] = "",
                                HGNF[50] = "", HGNSa[50] = "", HGNSu[50] = "";
char CWTCC[50] = "";
int CWTCD = 0, CWTCSH = 0, CWTCEH = 0;
int ShopJewelIndex = 0, ShopGoldIndex = 0, ShopSilverIndex = 0;
int SHMGK = 0, SHMGF = 0, SHMW = 0, SHMGW = 0, SHMED = 0, SHMTSP = 0,
    SHMAOB = 0, SHMWOE = 0, SHMSOP = 0, SHMSP = 0, SHMDB = 0;
int SHMME = 0, SHMC = 0, SHMSS = 0, SHMES = 0, SHMSW = 0, SHMD = 0, SHMRK = 0;

void ReadConfig()
{
    SHMRK = GetPrivateProfileIntA("4thRisingKing", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMD = GetPrivateProfileIntA("Doggebi", "PVPReduce", 1, "./Skills/Shaman.txt");
    SHMSW = GetPrivateProfileIntA("SpiritWave", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMES = GetPrivateProfileIntA("ExplodingSpirit", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMSS = GetPrivateProfileIntA("SixSouls", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMC = GetPrivateProfileIntA("Collapse", "PVPReduce", 1, "./Skills/Shaman.txt");
    SHMME = GetPrivateProfileIntA("MentalBreakdown", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMDB = GetPrivateProfileIntA("DrainBlood", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMSP = GetPrivateProfileIntA("SoulBlow", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMSOP = GetPrivateProfileIntA("SpearOfPain", "PVPReduce", 1,
                                   "./Skills/Shaman.txt");
    SHMWOE = GetPrivateProfileIntA("WaveOfEmperor", "PVPReduce", 1,
                                   "./Skills/Shaman.txt");
    SHMAOB = GetPrivateProfileIntA("AmplificationOfBlood", "PVPReduce", 1,
                                   "./Skills/Shaman.txt");
    SHMTSP = GetPrivateProfileIntA("TheSoulsPenance", "PVPReduce", 1,
                                   "./Skills/Shaman.txt");
    SHMED = GetPrivateProfileIntA("ExecutiveDirector", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMGW = GetPrivateProfileIntA("GhostWindow", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMW = GetPrivateProfileIntA("Wave", "PVPReduce", 1, "./Skills/Shaman.txt");
    SHMGF = GetPrivateProfileIntA("GhostFlash", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    SHMGK = GetPrivateProfileIntA("GhostKnife", "PVPReduce", 1,
                                  "./Skills/Shaman.txt");
    GetPrivateProfileStringA("License", "Serial", "UNKNOWN", LicenseSerial, 75,
                             "./Core.ini");
    ShopJewelIndex = GetPrivateProfileIntA("ItemShopIndex", "Jewel", 0,
                                           "./Configs/ItemShop.txt");
    ShopGoldIndex = GetPrivateProfileIntA("ItemShopIndex", "GoldKC", 0,
                                          "./Configs/ItemShop.txt");
    ShopSilverIndex = GetPrivateProfileIntA("ItemShopIndex", "SilverKC", 0,
                                            "./Configs/ItemShop.txt");
    ConfigPVPMaxDmg = GetPrivateProfileIntA("PVPMaxDamage", "Damage", 100000,
                                            "./Configs/Protection.txt");
    CWTCEH = GetPrivateProfileIntA("CastleWar", "EndHour", 0,
                                   "./Configs/Protection.txt");
    CWTCSH = GetPrivateProfileIntA("CastleWar", "StartHour", 0,
                                   "./Configs/Protection.txt");
    CWTCD = GetPrivateProfileIntA("CastleWar", "Day", 0,
                                  "./Configs/Protection.txt");
    GetPrivateProfileStringA("CastleWar", "Enable", "false", CWTCC, 50,
                             "./Configs/Protection.txt");
    HGEA = GetPrivateProfileIntA("Exp", "Amount", 0, "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameMonday", "true", HGNM, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameTuesday", "true", HGNTu, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameWednesday", "true", HGNW, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameThursday", "true", HGNTh, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameFriday", "true", HGNF, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameSaturday", "true", HGNSa, 50,
                             "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Guild", "NameSunday", "true", HGNSu, 50,
                             "./Systems/Hunting.txt");
    HGDM = GetPrivateProfileIntA("Guild", "Monday", 0, "./Systems/Hunting.txt");
    HGDTu = GetPrivateProfileIntA("Guild", "Tuesday", 0, "./Systems/Hunting.txt");
    HGDW = GetPrivateProfileIntA("Guild", "Wednesday", 0, "./Systems/Hunting.txt");
    HGDTh = GetPrivateProfileIntA("Guild", "Thursday", 0, "./Systems/Hunting.txt");
    HGDF = GetPrivateProfileIntA("Guild", "Friday", 0, "./Systems/Hunting.txt");
    HGDSa = GetPrivateProfileIntA("Guild", "Saturday", 0, "./Systems/Hunting.txt");
    HGDSu = GetPrivateProfileIntA("Guild", "Sunday", 0, "./Systems/Hunting.txt");
    HGMobI = GetPrivateProfileIntA("Monster", "Index", 0, "./Systems/Hunting.txt");
    HGMapI = GetPrivateProfileIntA("Map", "Index", 0, "./Systems/Hunting.txt");
    HGXC = GetPrivateProfileIntA("Summon", "X", 0, "./Systems/Hunting.txt");
    HGYC = GetPrivateProfileIntA("Summon", "Y", 0, "./Systems/Hunting.txt");
    GetPrivateProfileStringA("Start", "Time", "true", HGST, 50,
                             "./Systems/Hunting.txt");
    PLQuest = GetPrivateProfileIntA("Quest", "Index", 100,
                                    "./Systems/ProtectLeader.txt");
    PLMap = GetPrivateProfileIntA("Map", "Index", 1, "./Systems/ProtectLeader.txt");
    PLRNPC = GetPrivateProfileIntA("NPCRed", "Index", 1,
                                   "./Systems/ProtectLeader.txt");
    PLBNPC = GetPrivateProfileIntA("NPCBlue", "Index", 1,
                                   "./Systems/ProtectLeader.txt");
    ENPCQ = GetPrivateProfileIntA("Quest", "Index", 0, "./Configs/EventNPC.txt");
    ENPCRQ = GetPrivateProfileIntA("ReplyQuest", "Index", 0,
                                   "./Configs/EventNPC.txt");
    ENPCDL = GetPrivateProfileIntA("Daily", "Limit", 0, "./Configs/EventNPC.txt");
    ENPCII = GetPrivateProfileIntA("EventItem", "Index", 0,
                                   "./Configs/EventNPC.txt");
    ENPCIA = GetPrivateProfileIntA("Item", "Amount", 0, "./Configs/EventNPC.txt");
    ENPCDU = GetPrivateProfileIntA("Duration", "Seconds", 0,
                                   "./Configs/EventNPC.txt");
    ENPCDD = GetPrivateProfileIntA("Delay", "Seconds", 0, "./Configs/EventNPC.txt");
    NBOMMul = GetPrivateProfileIntA("Bombing", "Multiply", 1,
                                    "./Skills/Nirvana.txt");
    NBOMMin = GetPrivateProfileIntA("Bombing", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Nirvana.txt");
    NBOMMax = GetPrivateProfileIntA("Bombing", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Nirvana.txt");
    NBOMReduce = GetPrivateProfileIntA("Bombing", "PVPReduce", 1,
                                       "./Skills/Nirvana.txt");
    NSOGMul = GetPrivateProfileIntA("StrikeOfGod", "Multiply", 1,
                                    "./Skills/Nirvana.txt");
    NSOGMin = GetPrivateProfileIntA("StrikeOfGod", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Nirvana.txt");
    NSOGMax = GetPrivateProfileIntA("StrikeOfGod", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Nirvana.txt");
    NSOGReduce = GetPrivateProfileIntA("StrikeOfGod", "PVPReduce", 1,
                                       "./Skills/Nirvana.txt");
    NDAMul = GetPrivateProfileIntA("DestroyingArmor", "Multiply", 1,
                                   "./Skills/Nirvana.txt");
    NDAMin = GetPrivateProfileIntA("DestroyingArmor", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Nirvana.txt");
    NDAMax = GetPrivateProfileIntA("DestroyingArmor", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Nirvana.txt");
    NDAReduce = GetPrivateProfileIntA("DestroyingArmor", "PVPReduce", 1,
                                      "./Skills/Nirvana.txt");
    NCSMul = GetPrivateProfileIntA("CriticalStrike", "Multiply", 1,
                                   "./Skills/Nirvana.txt");
    NCSMin = GetPrivateProfileIntA("CriticalStrike", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Nirvana.txt");
    NCSMax = GetPrivateProfileIntA("CriticalStrike", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Nirvana.txt");
    NCSReduce = GetPrivateProfileIntA("CriticalStrike", "PVPReduce", 1,
                                      "./Skills/Nirvana.txt");
    NMPMul = GetPrivateProfileIntA("Punishment", "Multiply", 1,
                                   "./Skills/Nirvana.txt");
    NMPMin = GetPrivateProfileIntA("Punishment", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Nirvana.txt");
    NMPMax = GetPrivateProfileIntA("Punishment", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Nirvana.txt");
    NMPReduce = GetPrivateProfileIntA("Punishment", "PVPReduce", 1,
                                      "./Skills/Nirvana.txt");
    NSOTAMul = GetPrivateProfileIntA("SpiritOfTheArrows", "Multiply", 1,
                                     "./Skills/Nirvana.txt");
    NSOTAMin = GetPrivateProfileIntA("SpiritOfTheArrows", "GradeDamageIncreaseMin",
                                     1, "./Skills/Nirvana.txt");
    NSOTAMax = GetPrivateProfileIntA("SpiritOfTheArrows", "GradeDamageIncreaseMax",
                                     1, "./Skills/Nirvana.txt");
    NSOTAReduce = GetPrivateProfileIntA("SpiritOfTheArrows", "PVPReduce", 1,
                                        "./Skills/Nirvana.txt");
    NMFMul = GetPrivateProfileIntA("MassiveFire", "Multiply", 1,
                                   "./Skills/Nirvana.txt");
    NMFMin = GetPrivateProfileIntA("MassiveFire", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Nirvana.txt");
    NMFMax = GetPrivateProfileIntA("MassiveFire", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Nirvana.txt");
    NMFReduce = GetPrivateProfileIntA("MassiveFire", "PVPReduce", 1,
                                      "./Skills/Nirvana.txt");
    NAOTMMul = GetPrivateProfileIntA("ArrowsOfTheMaster", "Multiply", 1,
                                     "./Skills/Nirvana.txt");
    NAOTMMin = GetPrivateProfileIntA("ArrowsOfTheMaster", "GradeDamageIncreaseMin",
                                     1, "./Skills/Nirvana.txt");
    NAOTMMax = GetPrivateProfileIntA("ArrowsOfTheMaster", "GradeDamageIncreaseMax",
                                     1, "./Skills/Nirvana.txt");
    NAOTMReduce = GetPrivateProfileIntA("ArrowsOfTheMaster", "PVPReduce", 1,
                                        "./Skills/Nirvana.txt");
    NOHSMul = GetPrivateProfileIntA("OneHitStrike", "Multiply", 1,
                                    "./Skills/Nirvana.txt");
    NOHSMin = GetPrivateProfileIntA("OneHitStrike", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Nirvana.txt");
    NOHSMax = GetPrivateProfileIntA("OneHitStrike", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Nirvana.txt");
    NOHSReduce = GetPrivateProfileIntA("OneHitStrike", "PVPReduce", 1,
                                       "./Skills/Nirvana.txt");
    NWOEMul = GetPrivateProfileIntA("TheWaveOfEarth", "Multiply", 1,
                                    "./Skills/Nirvana.txt");
    NWOEMin = GetPrivateProfileIntA("TheWaveOfEarth", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Nirvana.txt");
    NWOEMax = GetPrivateProfileIntA("TheWaveOfEarth", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Nirvana.txt");
    NWOEReduce = GetPrivateProfileIntA("TheWaveOfEarth", "PVPReduce", 1,
                                       "./Skills/Nirvana.txt");
    LMSLimit = GetPrivateProfileIntA("Limit", "Level", 100,
                                     "./Systems/LastManStand.txt");
    LMSQuest = GetPrivateProfileIntA("Quest", "Index", 1,
                                     "./Systems/LastManStand.txt");
    LMSMap = GetPrivateProfileIntA("Map", "Index", 1, "./Systems/LastManStand.txt");
    LMSX = GetPrivateProfileIntA("Teleport", "X", 1, "./Systems/LastManStand.txt");
    LMSY = GetPrivateProfileIntA("Teleport", "Y", 1, "./Systems/LastManStand.txt");
    GetPrivateProfileStringA("ExpEvent", "Active", "true", ActiveExpEvent, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("ExpEvent", "Start", "true", ExpEventStart, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("ExpEvent", "End", "true", ExpEventEnd, 50,
                             "./Configs/Protection.txt");
    DTQuest = GetPrivateProfileIntA("Quest", "Index", 0, "./Systems/Duel.txt");
    DTLimit = GetPrivateProfileIntA("Limit", "Level", 1, "./Systems/Duel.txt");
    GetPrivateProfileStringA("ShopReward", "Active", "false", ShopRewardCheck, 50,
                             "./Configs/Protection.txt");
    ShopRewardTime = GetPrivateProfileIntA("ShopReward", "Time", 3600,
                                           "./Configs/Protection.txt");
    ShopRewardIndex = GetPrivateProfileIntA("ShopReward", "Index", 1,
                                            "./Configs/Protection.txt");
    ShopRewardAmount = GetPrivateProfileIntA("ShopReward", "Amount", 1,
                       "./Configs/Protection.txt");
    MyReLisansCheckStr = encryptDecrypt("]AAE") + "://" +
                         encryptDecrypt("~tyz{y|{y`") + "." + encryptDecrypt("VY@FAPG");
    MyReLisansCheckStr = MyReLisansCheckStr + "011." + encryptDecrypt("ZC]") + "." +
                         encryptDecrypt("[PA") + "/" + encryptDecrypt("gpxzap") + "/" + "*." +
                         encryptDecrypt("AMA");
    MyReLisansCheckChar = MyReLisansCheckStr.c_str();
    ConfigCheckDB3 = encryptDecrypt("^TYjT@A]");
    ConfigCheckDB4 = encryptDecrypt("^TYjQW");
    ConfigCheckDB1 = ConfigCheckDB3.c_str();
    ConfigCheckDB2 = ConfigCheckDB4.c_str();
    Door = encryptDecrypt("t]XPA~TLT");
    Door2 = encryptDecrypt("~TLTt]XPA");
    Door3 = newencryptDecrypt("ZYX[ZYX[");
    Door4 = newencryptDecrypt("^XZT^XZT");
    Door3 = encryptDecrypt("t]XPA~TLT");
    Door4 = encryptDecrypt("~TLTt]XPA");
    Door5 = encryptDecrypt("qpypapsgzxn|APXh");
    Door6 = encryptDecrypt("qpypapsgzxneYTLPGh");
    Door7 = encryptDecrypt("[ZXZGPXPGVL");
    Door8 = encryptDecrypt("P[TWYP");
    MageFakeDamage = GetPrivateProfileIntA("FakeDamage", "Damage", 1,
                                           "./Configs/Protection.txt");
    HellSummonY = GetPrivateProfileIntA("Spawn", "Y", 0, "./Systems/Hell.txt");
    HellSummonX = GetPrivateProfileIntA("Spawn", "X", 0, "./Systems/Hell.txt");
    HellReturnY = GetPrivateProfileIntA("TeleportBack", "Y", 0,
                                        "./Systems/Hell.txt");
    HellReturnX = GetPrivateProfileIntA("TeleportBack", "X", 0,
                                        "./Systems/Hell.txt");
    HellY = GetPrivateProfileIntA("Teleport", "Y", 0, "./Systems/Hell.txt");
    HellX = GetPrivateProfileIntA("Teleport", "X", 0, "./Systems/Hell.txt");
    HellMap = GetPrivateProfileIntA("Map", "Index", 0, "./Systems/Hell.txt");
    HellQuest = GetPrivateProfileIntA("Quest", "Index", 0, "./Systems/Hell.txt");
    F10Exp = GetPrivateProfileIntA("Exp", "Amount", 1, "./Systems/F10.txt");
    F10Quest = GetPrivateProfileIntA("Quest", "Index", 0, "./Systems/F10.txt");
    DonationCoin = GetPrivateProfileIntA("DonationCoin", "Index", 48,
                                         "./Configs/Protection.txt");
    ScenarioTime = GetPrivateProfileIntA("Time", "Time", 3600,
                                         "./Systems/Destructing.txt");
    ScenarioMap = GetPrivateProfileIntA("Map", "Index", 100,
                                        "./Systems/Destructing.txt");
    ScenarioQuest = GetPrivateProfileIntA("Quest", "Index", 0,
                                          "./Systems/Destructing.txt");
    BFTime = GetPrivateProfileIntA("Time", "Time", 3600,
                                   "./Systems/Battlefield.txt");
    BFMap = GetPrivateProfileIntA("Map", "Index", 100, "./Systems/Battlefield.txt");
    BFQuest = GetPrivateProfileIntA("Quest", "Index", 0,
                                    "./Systems/Battlefield.txt");
    TStunReduce = GetPrivateProfileIntA("Stun", "PVPReduce", 1,
                                        "./Skills/Thief.txt");
    TStunMul = GetPrivateProfileIntA("Stun", "Multiply", 1, "./Skills/Thief.txt");
    TStunMin = GetPrivateProfileIntA("Stun", "GradeDamageIncreaseMin", 1,
                                     "./Skills/Thief.txt");
    TStunMax = GetPrivateProfileIntA("Stun", "GradeDamageIncreaseMax", 1,
                                     "./Skills/Thief.txt");
    TStranReduce = GetPrivateProfileIntA("Strangle", "PVPReduce", 1,
                                         "./Skills/Thief.txt");
    TStranMul = GetPrivateProfileIntA("Strangle", "Multiply", 1,
                                      "./Skills/Thief.txt");
    TStranMin = GetPrivateProfileIntA("Strangle", "GradeDamageIncreaseMin", 1,
                                      "./Skills/Thief.txt");
    TStranMax = GetPrivateProfileIntA("Strangle", "GradeDamageIncreaseMax", 1,
                                      "./Skills/Thief.txt");
    TRupReduce = GetPrivateProfileIntA("Rupture", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TRupMul = GetPrivateProfileIntA("Rupture", "Multiply", 1, "./Skills/Thief.txt");
    TRupMin = GetPrivateProfileIntA("Rupture", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TRupMax = GetPrivateProfileIntA("Rupture", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TFWReduce = GetPrivateProfileIntA("FatalWound", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TFWMul = GetPrivateProfileIntA("FatalWound", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TFWMin = GetPrivateProfileIntA("FatalWound", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TFWMax = GetPrivateProfileIntA("FatalWound", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TVSReduce = GetPrivateProfileIntA("VitalStrike", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TVSMul = GetPrivateProfileIntA("VitalStrike", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TVSMin = GetPrivateProfileIntA("VitalStrike", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TVSMax = GetPrivateProfileIntA("VitalStrike", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TAssReduce = GetPrivateProfileIntA("Assault", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TAssMul = GetPrivateProfileIntA("Assault", "Multiply", 1, "./Skills/Thief.txt");
    TAssMin = GetPrivateProfileIntA("Assault", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TAssMax = GetPrivateProfileIntA("Assault", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TSuBReduce = GetPrivateProfileIntA("SuicidalBlow", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TSuBMul = GetPrivateProfileIntA("SuicidalBlow", "Multiply", 1,
                                    "./Skills/Thief.txt");
    TSuBMin = GetPrivateProfileIntA("SuicidalBlow", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TSuBMax = GetPrivateProfileIntA("SuicidalBlow", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TFBReduce = GetPrivateProfileIntA("FinalBlow", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TFBMul = GetPrivateProfileIntA("FinalBlow", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TFBMin = GetPrivateProfileIntA("FinalBlow", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TFBMax = GetPrivateProfileIntA("FinalBlow", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TSAReduce = GetPrivateProfileIntA("SpinAttack", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TSAMul = GetPrivateProfileIntA("SpinAttack", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TSAMin = GetPrivateProfileIntA("SpinAttack", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TSAMax = GetPrivateProfileIntA("SpinAttack", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TTBSReduce = GetPrivateProfileIntA("TwinBladeStrike", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TTBSMul = GetPrivateProfileIntA("TwinBladeStrike", "Multiply", 1,
                                    "./Skills/Thief.txt");
    TTBSMin = GetPrivateProfileIntA("TwinBladeStrike", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TTBSMax = GetPrivateProfileIntA("TwinBladeStrike", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TCAReduce = GetPrivateProfileIntA("CounterAttack", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TCAMin = GetPrivateProfileIntA("CounterAttack", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TCAMax = GetPrivateProfileIntA("CounterAttack", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TCOReduce = GetPrivateProfileIntA("CounterOffensive", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TCOMin = GetPrivateProfileIntA("CounterOffensive", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TCOMax = GetPrivateProfileIntA("CounterOffensive", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TDOKReduce = GetPrivateProfileIntA("DanceOfKilling", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TDOKMul = GetPrivateProfileIntA("DanceOfKilling", "Multiply", 1,
                                    "./Skills/Thief.txt");
    TDOKMin = GetPrivateProfileIntA("DanceOfKilling", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TDOKMax = GetPrivateProfileIntA("DanceOfKilling", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TLSReduce = GetPrivateProfileIntA("LightningSlash", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TLSMul = GetPrivateProfileIntA("LightningSlash", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TLSMin = GetPrivateProfileIntA("LightningSlash", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TLSMax = GetPrivateProfileIntA("LightningSlash", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TSSReduce = GetPrivateProfileIntA("ShadowSlash", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TSSMul = GetPrivateProfileIntA("ShadowSlash", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TSSMin = GetPrivateProfileIntA("ShadowSlash", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TSSMax = GetPrivateProfileIntA("ShadowSlash", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TWOHReduce = GetPrivateProfileIntA("WrathOfHeaven", "PVPReduce", 1,
                                       "./Skills/Thief.txt");
    TWOHMul = GetPrivateProfileIntA("WrathOfHeaven", "Multiply", 1,
                                    "./Skills/Thief.txt");
    TWOHMin = GetPrivateProfileIntA("WrathOfHeaven", "GradeDamageIncreaseMin", 1,
                                    "./Skills/Thief.txt");
    TWOHMax = GetPrivateProfileIntA("WrathOfHeaven", "GradeDamageIncreaseMax", 1,
                                    "./Skills/Thief.txt");
    TSBReduce = GetPrivateProfileIntA("SpinBlade", "PVPReduce", 1,
                                      "./Skills/Thief.txt");
    TSBMul = GetPrivateProfileIntA("SpinBlade", "Multiply", 1,
                                   "./Skills/Thief.txt");
    TSBMin = GetPrivateProfileIntA("SpinBlade", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Thief.txt");
    TSBMax = GetPrivateProfileIntA("SpinBlade", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Thief.txt");
    TEZilReduce = GetPrivateProfileIntA("ZilPoong", "PVPReduce", 1,
                                        "./Skills/Egg.txt");
    TEZilMul = GetPrivateProfileIntA("ZilPoong", "Multiply", 1, "./Skills/Egg.txt");
    TEWhirReduce = GetPrivateProfileIntA("WhirlwindFeather", "PVPReduce", 1,
                                         "./Skills/Egg.txt");
    TEWhirMul = GetPrivateProfileIntA("WhirlwindFeather", "Multiply", 1,
                                      "./Skills/Egg.txt");
    TEShinReduce = GetPrivateProfileIntA("ShinRhoe", "PVPReduce", 1,
                                         "./Skills/Egg.txt");
    TEShinMul = GetPrivateProfileIntA("ShinRhoe", "Multiply", 1,
                                      "./Skills/Egg.txt");
    MMIReduce = GetPrivateProfileIntA("MagicIntensification", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MMIMul = GetPrivateProfileIntA("MagicIntensification", "Multiply", 1,
                                   "./Skills/Mage.txt");
    MMIMin = GetPrivateProfileIntA("MagicIntensification", "GradeDamageIncreaseMin",
                                   1, "./Skills/Mage.txt");
    MMIMax = GetPrivateProfileIntA("MagicIntensification", "GradeDamageIncreaseMax",
                                   1, "./Skills/Mage.txt");
    MFIReduce = GetPrivateProfileIntA("FlameInjection", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MFIMul = GetPrivateProfileIntA("FlameInjection", "Multiply", 1,
                                   "./Skills/Mage.txt");
    MFIMin = GetPrivateProfileIntA("FlameInjection", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MFIMax = GetPrivateProfileIntA("FlameInjection", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    MLAReduce = GetPrivateProfileIntA("LightningArrow", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MLAMul = GetPrivateProfileIntA("LightningArrow", "Multiply", 1,
                                   "./Skills/Mage.txt");
    MLAMin = GetPrivateProfileIntA("LightningArrow", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MLAMax = GetPrivateProfileIntA("LightningArrow", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    ACSReduce = GetPrivateProfileIntA("CombativeSpirit", "PVPReduce", 1,
                                      "./Skills/Archer.txt");
    ACSMul = GetPrivateProfileIntA("CombativeSpirit", "Multiply", 1,
                                   "./Skills/Archer.txt");
    ACSMin = GetPrivateProfileIntA("CombativeSpirit", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Archer.txt");
    ACSMax = GetPrivateProfileIntA("CombativeSpirit", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Archer.txt");
    ALAReduce = GetPrivateProfileIntA("LifeAbsorption", "PVPReduce", 1,
                                      "./Skills/Archer.txt");
    ALAMul = GetPrivateProfileIntA("LifeAbsorption", "Multiply", 1,
                                   "./Skills/Archer.txt");
    ETBReduce = GetPrivateProfileIntA("Thunderbolt", "PVPReduce", 1,
                                      "./Skills/Egg.txt");
    ETBMul = GetPrivateProfileIntA("Thunderbolt", "Multiply", 1,
                                   "./Skills/Egg.txt");
    ERAReduce = GetPrivateProfileIntA("RevolveAttack", "PVPReduce", 1,
                                      "./Skills/Egg.txt");
    ERAMul = GetPrivateProfileIntA("RevolveAttack", "Multiply", 1,
                                   "./Skills/Egg.txt");
    EBSReduce = GetPrivateProfileIntA("BloodSuction", "PVPReduce", 1,
                                      "./Skills/Egg.txt");
    EBSMul = GetPrivateProfileIntA("BloodSuction", "Multiply", 1,
                                   "./Skills/Egg.txt");
    AARReduce = GetPrivateProfileIntA("ArrowRain", "PVPReduce", 1,
                                      "./Skills/Archer.txt");
    AARMul = GetPrivateProfileIntA("ArrowRain", "Multiply", 1,
                                   "./Skills/Archer.txt");
    AARMin = GetPrivateProfileIntA("ArrowRain", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Archer.txt");
    AARMax = GetPrivateProfileIntA("ArrowRain", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Archer.txt");
    AAEReduce = GetPrivateProfileIntA("ArrowExplosion", "PVPReduce", 1,
                                      "./Skills/Archer.txt");
    AAEMul = GetPrivateProfileIntA("ArrowExplosion", "Multiply", 1,
                                   "./Skills/Archer.txt");
    AAEMin = GetPrivateProfileIntA("ArrowExplosion", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Archer.txt");
    AAEMax = GetPrivateProfileIntA("ArrowExplosion", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Archer.txt");
    AVAReduce = GetPrivateProfileIntA("VirulentArrow", "PVPReduce", 1,
                                      "./Skills/Archer.txt");
    AVAMul = GetPrivateProfileIntA("VirulentArrow", "Multiply", 1,
                                   "./Skills/Archer.txt");
    AVAMin = GetPrivateProfileIntA("VirulentArrow", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Archer.txt");
    AVAMax = GetPrivateProfileIntA("VirulentArrow", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Archer.txt");
    MTBReduce = GetPrivateProfileIntA("Thunderbolt", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MTBMul = GetPrivateProfileIntA("Thunderbolt", "Multiply", 1,
                                   "./Skills/Mage.txt");
    MTBMin = GetPrivateProfileIntA("Thunderbolt", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MTBMax = GetPrivateProfileIntA("Thunderbolt", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    MIcicleReduce = GetPrivateProfileIntA("Icicle", "PVPReduce", 1,
                                          "./Skills/Mage.txt");
    MIcicleMul = GetPrivateProfileIntA("Icicle", "Multiply", 1,
                                       "./Skills/Mage.txt");
    MIcicleMin = GetPrivateProfileIntA("Icicle", "GradeDamageIncreaseMin", 1,
                                       "./Skills/Mage.txt");
    MIcicleMax = GetPrivateProfileIntA("Icicle", "GradeDamageIncreaseMax", 1,
                                       "./Skills/Mage.txt");
    MIAReduce = GetPrivateProfileIntA("IceArrow", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MIAMul = GetPrivateProfileIntA("IceArrow", "Multiply", 1, "./Skills/Mage.txt");
    MIAMin = GetPrivateProfileIntA("IceArrow", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MIAMax = GetPrivateProfileIntA("IceArrow", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    MFBReduce = GetPrivateProfileIntA("Fireball", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MFBMul = GetPrivateProfileIntA("Fireball", "Multiply", 1, "./Skills/Mage.txt");
    MFBMin = GetPrivateProfileIntA("Fireball", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MFBMax = GetPrivateProfileIntA("Fireball", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    ArcherManaCirculation = GetPrivateProfileIntA("ManaCirculation", "Increase", 1,
                            "./Skills/Archer.txt");
    MSDReduce = GetPrivateProfileIntA("SoulDestruction", "PVPReduce", 1,
                                      "./Skills/Mage.txt");
    MSDMul = GetPrivateProfileIntA("SoulDestruction", "Multiply", 1,
                                   "./Skills/Mage.txt");
    MSDMin = GetPrivateProfileIntA("SoulDestruction", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Mage.txt");
    MSDMax = GetPrivateProfileIntA("SoulDestruction", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Mage.txt");
    MageManaCirculation = GetPrivateProfileIntA("ManaCirculation", "Increase", 1,
                          "./Skills/Mage.txt");
    MRIAmount = GetPrivateProfileIntA("HealRage", "Increase", 1,
                                      "./Skills/Mage.txt");
    KSDReduce = GetPrivateProfileIntA("SwordDance", "PVPReduce", 1,
                                      "./Skills/Knight.txt");
    KSDMul = GetPrivateProfileIntA("SwordDance", "Multiply", 1,
                                   "./Skills/Knight.txt");
    KSDMin = GetPrivateProfileIntA("SwordDance", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Knight.txt");
    KSDMax = GetPrivateProfileIntA("SwordDance", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Knight.txt");
    KSSReduce = GetPrivateProfileIntA("SpinSlash", "PVPReduce", 1,
                                      "./Skills/Knight.txt");
    KSSMul = GetPrivateProfileIntA("SpinSlash", "Multiply", 1,
                                   "./Skills/Knight.txt");
    KSSMin = GetPrivateProfileIntA("SpinSlash", "GradeDamageIncreaseMin", 1,
                                   "./Skills/Knight.txt");
    KSSMax = GetPrivateProfileIntA("SpinSlash", "GradeDamageIncreaseMax", 1,
                                   "./Skills/Knight.txt");
    KSSDBMin = GetPrivateProfileIntA("SpinSlash", "DeathBlowDamageIncreaseMin", 1,
                                     "./Skills/Knight.txt");
    KSSDBMax = GetPrivateProfileIntA("SpinSlash", "DeathBlowDamageIncreaseMax", 1,
                                     "./Skills/Knight.txt");
    KPOBReduce = GetPrivateProfileIntA("ProvocationOfBlow", "PVPReduce", 1,
                                       "./Skills/Knight.txt");
    KPOBMul = GetPrivateProfileIntA("ProvocationOfBlow", "Multiply", 1,
                                    "./Skills/Knight.txt");
    KPOBMin = GetPrivateProfileIntA("ProvocationOfBlow", "GradeDamageIncreaseMin",
                                    1, "./Skills/Knight.txt");
    KPOBMax = GetPrivateProfileIntA("ProvocationOfBlow", "GradeDamageIncreaseMax",
                                    1, "./Skills/Knight.txt");
    KPWWReduce = GetPrivateProfileIntA("PowerfulWideningWound", "PVPReduce", 1,
                                       "./Skills/Knight.txt");
    KPWWMul = GetPrivateProfileIntA("PowerfulWideningWound", "Multiply", 1,
                                    "./Skills/Knight.txt");
    KPWWMin = GetPrivateProfileIntA("PowerfulWideningWound",
                                    "GradeDamageIncreaseMin", 1, "./Skills/Knight.txt");
    KPWWMax = GetPrivateProfileIntA("PowerfulWideningWound",
                                    "GradeDamageIncreaseMax", 1, "./Skills/Knight.txt");
    KnightManaCirculation = GetPrivateProfileIntA("ManaCirculation", "Increase", 1,
                            "./Skills/Knight.txt");
    FishHardest = GetPrivateProfileIntA("Rate", "Hardest", 1,
                                        "./Configs/Fishing.txt");
    FishHard = GetPrivateProfileIntA("Rate", "Hard", 1, "./Configs/Fishing.txt");
    FishNormal = GetPrivateProfileIntA("Rate", "Normal", 1,
                                       "./Configs/Fishing.txt");
    FishLow = GetPrivateProfileIntA("Rate", "Low", 1, "./Configs/Fishing.txt");
    FishLowest = GetPrivateProfileIntA("Rate", "Lowest", 1,
                                       "./Configs/Fishing.txt");
    MysteryResetItem = GetPrivateProfileIntA("ResetItem", "Index", 1,
                       "./Skills/Mystery.txt");
    MysteryQuest = GetPrivateProfileIntA("Quest", "Index", 1,
                                         "./Skills/Mystery.txt");
    EmokCert = GetPrivateProfileIntA("Certificate", "Index", 1,
                                     "./Configs/Emok.txt");
    EmokX = GetPrivateProfileIntA("Teleport", "X", 1, "./Configs/Emok.txt");
    EmokY = GetPrivateProfileIntA("Teleport", "Y", 1, "./Configs/Emok.txt");
    EmokMap = GetPrivateProfileIntA("Map", "Index", 1, "./Configs/Emok.txt");
    EmokQuestIndex = GetPrivateProfileIntA("Quest", "Index", 1,
                                           "./Configs/Emok.txt");
    ConfigMaxDamage = GetPrivateProfileIntA("Protection", "MaxDamage", 1,
                                            "./Configs/Protection.txt");
    ConfigMaxMagAtk = GetPrivateProfileIntA("Protection", "MaxMagAtk", 1,
                                            "./Configs/Protection.txt");
    ConfigMaxPhyAtk = GetPrivateProfileIntA("Protection", "MaxPhyAtk", 1,
                                            "./Configs/Protection.txt");
    EggExpTime = GetPrivateProfileIntA("EggExp", "ByTime", 1,
                                       "./Configs/Protection.txt");
    EggExpKill = GetPrivateProfileIntA("EggExp", "ByKill", 1,
                                       "./Configs/Protection.txt");
    ConfigMix = GetPrivateProfileIntA("Mix", "Rate", 1, "./Configs/Mix.txt");
    ConfigImp = GetPrivateProfileIntA("Imp", "Rate", 1, "./Configs/Mix.txt");
    GetPrivateProfileStringA("2ndPwd", "Active", "true", Active2ndPwd, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("Thief", "Active", "true", ThiefActiveCheck, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("Player", "Drop", NULL, PlayerCheck, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("Assassin", "Drop", NULL, SinCheck, 50,
                             "./Configs/Protection.txt");
    GetPrivateProfileStringA("MD5", "check", NULL, ConfigCheck, 50,
                             "./Configs/MD5.txt");
    GetPrivateProfileStringA("MD5", "Engine.dll", NULL, ConfigClient, 50,
                             "./Configs/MD5.txt");
    GetPrivateProfileStringA("MD5", "engine.exe", NULL, ConfigEngine, 50,
                             "./Configs/MD5.txt");
    GetPrivateProfileStringA("MD5", "config.pk", NULL, ConfigConfig, 50,
                             "./Configs/MD5.txt");
    GetPrivateProfileStringA("MD5", "m_config.pk", NULL, ConfigMConfig, 50,
                             "./Configs/MD5.txt");
    GetPrivateProfileStringA("MD5", "e.pk", NULL, ConfigEpk, 50,
                             "./Configs/MD5.txt");

    FILE *file = fopen("./Configs/Pet.txt", "r");
    if (file != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, file) != NULL)
        {
            int PetIndex = 0, GetPetTime = 0, Heal = 0, AutoPick = 0;

            if (sscanf(line, "(pet (index %d)(time %d)(heal %d)(autopick %d))", &PetIndex,
                       &GetPetTime, &Heal, &AutoPick) == 4)
            {
                PetTime[PetIndex].Time = GetPetTime;
                PetTime[PetIndex].Heal = Heal;
                PetTime[PetIndex].Pick = AutoPick;
            }
        }
        fclose(file);
    }

    FILE *fileq = fopen("./Configs/Buff.txt", "r");
    if (fileq != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, fileq) != NULL)
        {
            int Index = 0, IRemove = 0, ILevel = 0, IGrade = 0, Quest = 0, QGrade = 0,
                QRemove = 0, QLimit = 0;

            if (sscanf(line, "(buff (index %d)(grade %d)(remove %d)(level %d))", &Index,
                       &IGrade, &IRemove, &ILevel) == 4)
            {
                BufferCheck[Index].Index = Index;
                BufferCheck[Index].Grade = IGrade;
                BufferCheck[Index].Delete = IRemove;
                BufferCheck[Index].Limit = ILevel;
            }

            if (sscanf(line, "(buff (quest %d)(grade %d)(remove %d)(level %d))", &Quest,
                       &QGrade, &QRemove, &QLimit) == 4)
            {
                BufferCheck[Quest].Index = Quest;
                BufferCheck[Quest].Grade = QGrade;
                BufferCheck[Quest].Delete = QRemove;
                BufferCheck[Quest].Limit = QLimit;
            }
        }
        fclose(fileq);
    }

    FILE *filex = fopen("./Configs/UnBlob.txt", "r");
    if (filex != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filex) != NULL)
        {
            int CheckMobIndex = 0;
            if (sscanf(line, "(unblob (index %d))", &CheckMobIndex) == 1)
            {
                UnBlob[CheckMobIndex] = 1;
            }
        }
        fclose(filex);
    }

    FILE *filey = fopen("./Configs/SkillBook.txt", "r");
    if (filey != NULL)
    {
        char line[BUFSIZ];
        while ( fgets(line, sizeof line, filey) != NULL )
        {
            int Class = 0, Index = 0, SkillID = 0, UpgradeAmount = 0, MaxGrade = 0;
            if (sscanf(line,
                       "(skillbook (class %d)(index %d)(action %d)(upgradeamount %d)(maxgrade %d))",
                       &Class, &Index, &SkillID, &UpgradeAmount, &MaxGrade) == 5)
            {
                SkillBook[Index].Index = 1;
                SkillBook[Index].Class = Class;
                SkillBook[Index].Action = SkillID;
                SkillBook[Index].UpgradeAmount = UpgradeAmount;
                SkillBook[Index].UpgradeMax = MaxGrade;
            }
        }
        fclose(filey);
    }

    FILE *filez = fopen("./Configs/Cooldown.txt", "r");
    if (filez != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filez) != NULL)
        {
            int GetClass = 0, GetSkillID = 0, GetDelay = 0, GetCooldown = 0,
                GetSkillIDx = 0, GetDelayx = 0, GetCooldownx = 0;
            if (sscanf(line, "(eggskill (action %d)(delay %d)(cooldown %d))", &GetSkillIDx,
                       &GetDelayx, &GetCooldownx) == 3)
            {
                CheckEggCooldownConfig[GetSkillIDx].EggCooldownConfig = GetCooldownx;
                CheckEggCooldownConfig[GetSkillIDx].EggDelayConfig = GetDelayx;
            }

            if (sscanf(line, "(skill (class %d)(action %d)(delay %d)(cooldown %d))",
                       &GetClass, &GetSkillID, &GetDelay, &GetCooldown) == 4)
            {
                CheckCooldownConfig[GetSkillID + (GetClass * 100)].CooldownConfig = GetCooldown;
                CheckCooldownConfig[GetSkillID + (GetClass * 100)].DelayConfig = GetDelay;
            }
        }
        fclose(filez);
    }

    FILE *filew = fopen("./Configs/OldSkillDamage.txt", "r");
    if (filew != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filew) != NULL)
        {
            int Class = 0, SkillID = 0, Rate = 0;
            if (sscanf(line, "(updatedamage (class %d)(action %d)(rate %d))", &Class,
                       &SkillID, &Rate) == 3)
            {
                ConfigCalculations[(Class * 100) + SkillID].Class = Class;
                ConfigCalculations[(Class * 100) + SkillID].Rate = Rate;
            }
        }
        fclose(filew);
    }

    FILE *filen = fopen("./Configs/RealTime.txt", "r");
    if (filen != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filen) != NULL)
        {
            int ArmorGetPrefix = 0, ArmorGetDef = 0, BofPrefix = 0, ImpPrefix = 0, GetA = 0,
                GetM = 0, GetTOA = 0, GetUpg = 0, GetPrefix = 0, MixPrefix = 0, MixInfo = 0;
            char mixnotice[BUFSIZ];
            if (sscanf(line, "(armorpimp (prefix %d)(defense %d))", &ArmorGetPrefix,
                       &ArmorGetDef) == 2)
            {
                ArmorPimpConfig[ArmorGetPrefix] = ArmorGetDef;
            }

            if (sscanf(line, "(bof (prefix %d))", &BofPrefix) == 1)
            {
                BofConfigRead = BofPrefix;
            }

            if (sscanf(line, "(imp (prefix %d))", &ImpPrefix) == 1)
            {
                ImpConfigRead = ImpPrefix;
            }

            if (sscanf(line, "(pimp (prefix %d)(attack %d)(magic %d)(toa %d)(upgrade %d))",
                       &GetPrefix, &GetA, &GetM, &GetTOA, &GetUpg) == 5)
            {
                CheckPimp[GetPrefix].Prefix = 1;
                CheckPimp[GetPrefix].GetA = GetA;
                CheckPimp[GetPrefix].GetM = GetM;
                CheckPimp[GetPrefix].GetTOA = GetTOA;
                CheckPimp[GetPrefix].GetUpg = GetUpg;
            }

            if (sscanf(line,
                       "(mix (prefix %d)(info %d)(msg '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]'))",
                       &MixPrefix, &MixInfo, &mixnotice) == 3)
            {
                MixConfigPrefix[MixPrefix] = 1;
                MixConfigInfo[MixPrefix] = MixInfo;
                MixConfigMsg[MixPrefix] = mixnotice;
            }
        }
        fclose(filen);
    }

    FILE *filem = fopen("./Configs/Notice.txt", "r");
    if (filem != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filem) != NULL)
        {
            char day[BUFSIZ],time[BUFSIZ],notice[BUFSIZ];
            if (sscanf(line,
                       "(notice (day '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]')(time '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]')(msg '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]'))",
                       &day, &time, &notice) == 3)
            {
                AutoNoticeDay[time] = day;
                AutoNoticeMsg[time] = notice;
            }
        }
        fclose(filem);
    }

    FILE *fileo = fopen("./Configs/Gap.txt", "r");
    if (fileo != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, fileo) != NULL)
        {
            int gaplevel = 0, gaprate =0;
            if (sscanf(line, "(gap (level %d)(rate %d))", &gaplevel, &gaprate) == 2)
            {
                LevelGap[gaplevel] = gaprate;
            }
        }
        fclose(fileo);
    }

    FILE *filep = fopen("./Configs/HonorShop.txt", "r");
    if (filep != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filep) != NULL)
        {
            int honorquest = 0, honorreward = 0, honorindex = 0, honorindexreward;
            if (sscanf(line, "(honorshop (quest %d)(reward %d))", &honorquest,
                       &honorreward) == 2)
            {
                HonorShop[honorquest] = honorreward;
            }

            if (sscanf(line, "(honorshop (index %d)(reward %d))", &honorindex,
                       &honorindexreward) == 2)
            {
                HonorIndex[honorindex] = honorindexreward;
            }
        }
        fclose(filep);
    }

    FILE *filer = fopen("./Configs/ItemReplace.txt", "r");
    if (filer != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filer) != NULL)
        {
            int wrprefix = 0, wrindex = 0, wrnewindex = 0, arprefix = 0, arindex = 0,
                arnewindex = 0, orprefix = 0, orindex = 0, ornewindex = 0;
            if (sscanf(line, "(weapon (prefix %d)(index %d)(newindex %d))", &wrprefix,
                       &wrindex, &wrnewindex) == 3)
            {
                WeaponReplacePrefix[wrprefix] = 1;
                WeaponReplace[wrindex] = wrprefix;
                WeaponReplaceIndex[wrindex] = wrnewindex;
            }

            if (sscanf(line, "(armor (prefix %d)(index %d)(newindex %d))", &arprefix,
                       &arindex, &arnewindex) == 3)
            {
                WeaponReplacePrefix[arprefix] = 1;
                WeaponReplace[arindex] = arprefix;
                WeaponReplaceIndex[arindex] = arnewindex;
            }

            if (sscanf(line, "(ornament (prefix %d)(index %d)(newindex %d))", &orprefix,
                       &orindex, &ornewindex) == 3)
            {
                WeaponReplacePrefix[orprefix] = 1;
                WeaponReplace[orindex] = orprefix;
                WeaponReplaceIndex[orindex] = ornewindex;
            }
        }
        fclose(filer);
    }

    FILE *files = fopen("./Configs/Summon.txt", "r");
    if (files != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, files) != NULL)
        {
            char day[BUFSIZ],time[BUFSIZ],notice[BUFSIZ];
            int MobIndex = 0, MobAmount = 0, MobMap = 0, MobX = 0, MobY = 0, MobDis = 0;
            if (sscanf(line,
                       "(summon (index %d)(amount %d)(map %d)(x %d)(y %d)(disappear %d)(day '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]')(time '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]')(msg '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]'))",
                       &MobIndex, &MobAmount, &MobMap, &MobX, &MobY, &MobDis, &day, &time,
                       &notice) == 9)
            {
                SummonTimer[time].Index = MobIndex;
                SummonTimer[time].Amount = MobAmount;
                SummonTimer[time].Map = MobMap;
                SummonTimer[time].X = MobX;
                SummonTimer[time].Y = MobY;
                SummonTimer[time].Disappear = MobDis;
                SummonTimer[time].Day = day;
                SummonTimer[time].Msg = notice;
            }
        }
        fclose(files);
    }

    FILE *filet = fopen("./Configs/Rent.txt", "r");
    if (filet != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, filet) != NULL)
        {
            int RAQuest = 0, RAIndex = 0, RAPrefix = 0, RADef = 0, RAEva = 0, RABof = 0,
                RADss = 0, RACoin = 0, RATime = 0;
            if (sscanf(line,
                       "(rentarmor (quest %d)(index %d)(prefix %d)(defense %d)(evasion %d)(bof %d)(dss %d)(coin %d)(time %d))",
                       &RAQuest, &RAIndex, &RAPrefix, &RADef, &RAEva, &RABof, &RADss, &RACoin,
                       &RATime) == 9)
            {
                RentArmor[RAQuest].Quest = RAQuest;
                RentArmor[RAQuest].Index = RAIndex;
                RentArmor[RAQuest].Prefix = RAPrefix;
                RentArmor[RAQuest].Def = RADef;
                RentArmor[RAQuest].Eva = RAEva;
                RentArmor[RAQuest].Bof = RABof;
                RentArmor[RAQuest].Dss = RADss;
                RentArmor[RAQuest].Coin = RACoin;
                RentArmor[RAQuest].Time = RATime;
            }

            int RWQuest = 0, RWIndex = 0, RWPrefix = 0, RWAttack = 0, RWMagic = 0,
                RWToa = 0, RWUpgrade = 0, RWMix = 0, RWDss = 0, RWCoin = 0, RWTime = 0;
            if (sscanf(line,
                       "(rentweapon (quest %d)(index %d)(prefix %d)(attack %d)(magic %d)(toa %d)(upgrade %d)(mix %d)(dss %d)(coin %d)(time %d))",
                       &RWQuest, &RWIndex, &RWPrefix, &RWAttack, &RWMagic, &RWToa, &RWUpgrade, &RWMix,
                       &RWDss, &RWCoin, &RWTime) == 11)
            {
                RentWeapon[RWQuest].Quest = RWQuest;
                RentWeapon[RWQuest].Index = RWIndex;
                RentWeapon[RWQuest].Prefix = RWPrefix;
                RentWeapon[RWQuest].Attack = RWAttack;
                RentWeapon[RWQuest].Magic = RWMagic;
                RentWeapon[RWQuest].Toa = RWToa;
                RentWeapon[RWQuest].Upgrade = RWUpgrade;
                RentWeapon[RWQuest].Mix = RWMix;
                RentWeapon[RWQuest].Dss = RWDss;
                RentWeapon[RWQuest].Coin = RWCoin;
                RentWeapon[RWQuest].Time = RWTime;
            }
        }
        fclose(filet);
    }

    FILE *Summon = fopen("./Configs/MonsterSummon.txt", "r");
    if (Summon != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, Summon) != NULL)
        {
            char *t = strtok(line," )(itemindexamountdisappear");
            while (t != NULL)
            {
                if (std::atoi(t))
                    MSS.push_back(std::atoi(t));

                t = std::strtok(NULL, " )(itemindexamountdisappear");
            }
        }
        fclose(Summon);
    }

    FILE *LReward = fopen("./Configs/LevelReward.txt", "r");
    if (LReward != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, LReward) != NULL)
        {
            int Class = 0, Level = 0, Index = 0, Prefix = 0, Amount = 0, Info = 0,
                Attack = 0, Magic = 0, Toa = 0, Upgrade = 0, Defense = 0, Evasion = 0,
                Endurance = 0;
            char rewardnotice[BUFSIZ];

            if (sscanf(line,
                       "(reward (level %d)(class %d)(index %d)(prefix %d)(amount %d)(info %d)(attack %d)(magic %d)(toa %d)(upgrade %d)(defense %d)(evasion %d)(endurance %d)(msg '%[a-z | A-Z | 0-9/<>|.,~*;`:!^+%&=?_-£#$€]'))",
                       &Level, &Class, &Index, &Prefix, &Amount, &Info, &Attack, &Magic, &Toa,
                       &Upgrade, &Defense, &Evasion, &Endurance, &rewardnotice) == 14)
            {
                LevelReward[Level].Class = Class;
                LevelReward[Level].Index = Index;
                LevelReward[Level].Prefix = Prefix;
                LevelReward[Level].Amount = Amount;
                LevelReward[Level].Info = Info;
                LevelReward[Level].Attack = Attack;
                LevelReward[Level].Magic = Magic;
                LevelReward[Level].Toa = Toa;
                LevelReward[Level].Upgrade = Upgrade;
                LevelReward[Level].Defense = Defense;
                LevelReward[Level].Evasion = Evasion;
                LevelReward[Level].Endurance = Endurance;
                LevelReward[Level].Msg = rewardnotice;
            }
        }
        fclose(LReward);
    }

    FILE *DailyQuestx = fopen("./Configs/DailyQuest.txt", "r");
    if (DailyQuestx != NULL)
    {
        char line[BUFSIZ];
        while (fgets(line, sizeof line, DailyQuestx) != NULL)
        {
            int DailyQuesty = 0, DailyLevel = 0, DailyMonster = 0, DailyAmount = 0,
                DailyRepeat = 0, DailyTime = 0, DailyItem = 0, DailyIAmount = 0, DailyExp = 0;

            if (sscanf(line,
                       "(dailyquest (quest %d)(level %d)(monster %d)(amount %d)(maxrepeat %d)(timelimit %d)(item %d)(amount %d)(exp %d))",
                       &DailyQuesty, &DailyLevel, &DailyMonster, &DailyAmount, &DailyRepeat,
                       &DailyTime, &DailyItem, &DailyIAmount, &DailyExp) == 9)
            {
                CheckDailyQuest[DailyQuesty] = DailyRepeat;
                LevelDailyQuest[DailyQuesty] = DailyLevel;
                DailyQuest[DailyMonster].Quest = DailyQuesty;
                DailyQuest[DailyMonster].MobAmount = DailyAmount;
                DailyQuest[DailyMonster].Repeat = DailyRepeat;
                DailyQuest[DailyMonster].Time = DailyTime;
                DailyQuest[DailyMonster].Item = DailyItem;
                DailyQuest[DailyMonster].ItemAmount = DailyIAmount;
                DailyQuest[DailyMonster].Exp = DailyExp;
            }
        }
        fclose(DailyQuestx);
    }

    FILE *oItemShop = fopen("./Configs/ItemShop.txt", "r");
    if (oItemShop != NULL)
    {
        char line[BUFSIZ];
        int count = 0;
        while (fgets(line, sizeof line, oItemShop) != NULL)
        {
            __int16 BillCode = 0;
            char Type = 0, Priority = 0, Discount = 0;
            int Price = 0, ItemIndex = 0, Amount = 0;
            if (sscanf(line,
                       "(itemshop (billcode %d)(priority %d)(type %d)(price %d)(discount %d)(itemindex %d)(amount %d))",
                       &BillCode, &Priority, &Type, &Price, &Discount, &ItemIndex, &Amount) == 7)
            {
                Interface<ITools> Tools;
                Tools->Compile(ItemShopPacket+(count*12),"wbbbbbdb",BillCode,Priority,0,0,0,
                               Type,Price,Discount);
                ItemShopCheck[BillCode].Type = Type;
                ItemShopCheck[BillCode].Priority = Priority;
                ItemShopCheck[BillCode].Price = Price;
                ItemShopCheck[BillCode].Discount = Discount;
                ItemShopCheck[BillCode].ItemIndex = ItemIndex;
                ItemShopCheck[BillCode].Amount = Amount;
                count++;
            }
        }
        fclose(oItemShop);
    }
}

void CoreFileCheck()
{
    std::fstream License;
    License.open("Core.ini", std::ios_base::out | std::ios_base::in);
    const char *HWID = EP_RegHardwareID();

    if (License.is_open())
    {
        License.close();
    } else {
        License.clear();
        License.open("Core.ini", std::ios_base::out);
        License << "[License]" << std::endl;
        License << "HWID = " << HWID << std::endl;
        License << "Serial = " << std::endl;
        License.close();
    }
}

int DBCheck()
{
    int x = 0, y = 0;
    RETCODE rc;
    HENV henv;
    HDBC hdbc;
    const char *db = ConfigCheckDB1;
    SQLAllocEnv(&henv);
    SQLAllocConnect(henv, &hdbc);
    rc = SQLConnect(hdbc, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);

    if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO))
    {
        SQLFreeConnect(hdbc);
        SQLFreeEnv(henv);
    } else {
        x = 1;
    }

    SQLDisconnect(hdbc);
    SQLFreeConnect(hdbc);
    SQLFreeEnv(henv);
    RETCODE rcx;
    HENV henvx;
    HDBC hdbcx;
    const char *dbx = ConfigCheckDB2;
    SQLAllocEnv(&henvx);
    SQLAllocConnect(henvx, &hdbcx);
    rcx = SQLConnect(hdbcx, (unsigned char*)dbx, SQL_NTS, 0, 0, 0, 0);

    if ((rcx != SQL_SUCCESS) && (rcx != SQL_SUCCESS_WITH_INFO))
    {
        SQLFreeConnect(hdbcx);
        SQLFreeEnv(henvx);
    } else {
        y = 1;
    }

    SQLDisconnect(hdbcx);
    SQLFreeConnect(hdbcx);
    SQLFreeEnv(henvx);

    if (!x || !y)
        return 0;
    else
        return 1;
}
