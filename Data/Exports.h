#include <windows.h>

void InitializeADVAPI32()
{
    hL = LoadLibrary(".\\advapi32.dll");
    if (!hL) return;
    p[0] = GetProcAddress(hL,"A_SHAFinal");
    p[1] = GetProcAddress(hL,"A_SHAInit");
    p[2] = GetProcAddress(hL,"A_SHAUpdate");
    p[3] = GetProcAddress(hL,"AbortSystemShutdownA");
    p[4] = GetProcAddress(hL,"AbortSystemShutdownW");
    p[5] = GetProcAddress(hL,"AccessCheck");
    p[6] = GetProcAddress(hL,"AccessCheckAndAuditAlarmA");
    p[7] = GetProcAddress(hL,"AccessCheckAndAuditAlarmW");
    p[8] = GetProcAddress(hL,"AccessCheckByType");
    p[9] = GetProcAddress(hL,"AccessCheckByTypeAndAuditAlarmA");
    p[10] = GetProcAddress(hL,"AccessCheckByTypeAndAuditAlarmW");
    p[11] = GetProcAddress(hL,"AccessCheckByTypeResultList");
    p[12] = GetProcAddress(hL,"AccessCheckByTypeResultListAndAuditAlarmA");
    p[13] = GetProcAddress(hL,"AccessCheckByTypeResultListAndAuditAlarmByHandleA");
    p[14] = GetProcAddress(hL,"AccessCheckByTypeResultListAndAuditAlarmByHandleW");
    p[15] = GetProcAddress(hL,"AccessCheckByTypeResultListAndAuditAlarmW");
    p[16] = GetProcAddress(hL,"AddAccessAllowedAce");
    p[17] = GetProcAddress(hL,"AddAccessAllowedAceEx");
    p[18] = GetProcAddress(hL,"AddAccessAllowedObjectAce");
    p[19] = GetProcAddress(hL,"AddAccessDeniedAce");
    p[20] = GetProcAddress(hL,"AddAccessDeniedAceEx");
    p[21] = GetProcAddress(hL,"AddAccessDeniedObjectAce");
    p[22] = GetProcAddress(hL,"AddAce");
    p[23] = GetProcAddress(hL,"AddAuditAccessAce");
    p[24] = GetProcAddress(hL,"AddAuditAccessAceEx");
    p[25] = GetProcAddress(hL,"AddAuditAccessObjectAce");
    p[26] = GetProcAddress(hL,"AddConditionalAce");
    p[27] = GetProcAddress(hL,"AddMandatoryAce");
    p[28] = GetProcAddress(hL,"AddUsersToEncryptedFile");
    p[29] = GetProcAddress(hL,"AddUsersToEncryptedFileEx");
    p[30] = GetProcAddress(hL,"AdjustTokenGroups");
    p[31] = GetProcAddress(hL,"AdjustTokenPrivileges");
    p[32] = GetProcAddress(hL,"AllocateAndInitializeSid");
    p[33] = GetProcAddress(hL,"AllocateLocallyUniqueId");
    p[34] = GetProcAddress(hL,"AreAllAccessesGranted");
    p[35] = GetProcAddress(hL,"AreAnyAccessesGranted");
    p[36] = GetProcAddress(hL,"AuditComputeEffectivePolicyBySid");
    p[37] = GetProcAddress(hL,"AuditComputeEffectivePolicyByToken");
    p[38] = GetProcAddress(hL,"AuditEnumerateCategories");
    p[39] = GetProcAddress(hL,"AuditEnumeratePerUserPolicy");
    p[40] = GetProcAddress(hL,"AuditEnumerateSubCategories");
    p[41] = GetProcAddress(hL,"AuditFree");
    p[42] = GetProcAddress(hL,"AuditLookupCategoryGuidFromCategoryId");
    p[43] = GetProcAddress(hL,"AuditLookupCategoryIdFromCategoryGuid");
    p[44] = GetProcAddress(hL,"AuditLookupCategoryNameA");
    p[45] = GetProcAddress(hL,"AuditLookupCategoryNameW");
    p[46] = GetProcAddress(hL,"AuditLookupSubCategoryNameA");
    p[47] = GetProcAddress(hL,"AuditLookupSubCategoryNameW");
    p[48] = GetProcAddress(hL,"AuditQueryGlobalSaclA");
    p[49] = GetProcAddress(hL,"AuditQueryGlobalSaclW");
    p[50] = GetProcAddress(hL,"AuditQueryPerUserPolicy");
    p[51] = GetProcAddress(hL,"AuditQuerySecurity");
    p[52] = GetProcAddress(hL,"AuditQuerySystemPolicy");
    p[53] = GetProcAddress(hL,"AuditSetGlobalSaclA");
    p[54] = GetProcAddress(hL,"AuditSetGlobalSaclW");
    p[55] = GetProcAddress(hL,"AuditSetPerUserPolicy");
    p[56] = GetProcAddress(hL,"AuditSetSecurity");
    p[57] = GetProcAddress(hL,"AuditSetSystemPolicy");
    p[58] = GetProcAddress(hL,"BackupEventLogA");
    p[59] = GetProcAddress(hL,"BackupEventLogW");
    p[60] = GetProcAddress(hL,"BuildExplicitAccessWithNameA");
    p[61] = GetProcAddress(hL,"BuildExplicitAccessWithNameW");
    p[62] = GetProcAddress(hL,"BuildImpersonateExplicitAccessWithNameA");
    p[63] = GetProcAddress(hL,"BuildImpersonateExplicitAccessWithNameW");
    p[64] = GetProcAddress(hL,"BuildImpersonateTrusteeA");
    p[65] = GetProcAddress(hL,"BuildImpersonateTrusteeW");
    p[66] = GetProcAddress(hL,"BuildSecurityDescriptorA");
    p[67] = GetProcAddress(hL,"BuildSecurityDescriptorW");
    p[68] = GetProcAddress(hL,"BuildTrusteeWithNameA");
    p[69] = GetProcAddress(hL,"BuildTrusteeWithNameW");
    p[70] = GetProcAddress(hL,"BuildTrusteeWithObjectsAndNameA");
    p[71] = GetProcAddress(hL,"BuildTrusteeWithObjectsAndNameW");
    p[72] = GetProcAddress(hL,"BuildTrusteeWithObjectsAndSidA");
    p[73] = GetProcAddress(hL,"BuildTrusteeWithObjectsAndSidW");
    p[74] = GetProcAddress(hL,"BuildTrusteeWithSidA");
    p[75] = GetProcAddress(hL,"BuildTrusteeWithSidW");
    p[76] = GetProcAddress(hL,"CancelOverlappedAccess");
    p[77] = GetProcAddress(hL,"ChangeServiceConfig2A");
    p[78] = GetProcAddress(hL,"ChangeServiceConfig2W");
    p[79] = GetProcAddress(hL,"ChangeServiceConfigA");
    p[80] = GetProcAddress(hL,"ChangeServiceConfigW");
    p[81] = GetProcAddress(hL,"CheckTokenMembership");
    p[82] = GetProcAddress(hL,"ClearEventLogA");
    p[83] = GetProcAddress(hL,"ClearEventLogW");
    p[84] = GetProcAddress(hL,"CloseCodeAuthzLevel");
    p[85] = GetProcAddress(hL,"CloseEncryptedFileRaw");
    p[86] = GetProcAddress(hL,"CloseEventLog");
    p[87] = GetProcAddress(hL,"CloseServiceHandle");
    p[88] = GetProcAddress(hL,"CloseThreadWaitChainSession");
    p[89] = GetProcAddress(hL,"CloseTrace");
    p[90] = GetProcAddress(hL,"CommandLineFromMsiDescriptor");
    p[91] = GetProcAddress(hL,"ComputeAccessTokenFromCodeAuthzLevel");
    p[92] = GetProcAddress(hL,"ControlService");
    p[93] = GetProcAddress(hL,"ControlServiceExA");
    p[94] = GetProcAddress(hL,"ControlServiceExW");
    p[95] = GetProcAddress(hL,"ControlTraceA");
    p[96] = GetProcAddress(hL,"ControlTraceW");
    p[97] = GetProcAddress(hL,"ConvertAccessToSecurityDescriptorA");
    p[98] = GetProcAddress(hL,"ConvertAccessToSecurityDescriptorW");
    p[99] = GetProcAddress(hL,"ConvertSDToStringSDRootDomainA");
    p[100] = GetProcAddress(hL,"ConvertSDToStringSDRootDomainW");
    p[101] = GetProcAddress(hL,"ConvertSecurityDescriptorToAccessA");
    p[102] = GetProcAddress(hL,"ConvertSecurityDescriptorToAccessNamedA");
    p[103] = GetProcAddress(hL,"ConvertSecurityDescriptorToAccessNamedW");
    p[104] = GetProcAddress(hL,"ConvertSecurityDescriptorToAccessW");
    p[105] = GetProcAddress(hL,"ConvertSecurityDescriptorToStringSecurityDescriptorA");
    p[106] = GetProcAddress(hL,"ConvertSecurityDescriptorToStringSecurityDescriptorW");
    p[107] = GetProcAddress(hL,"ConvertSidToStringSidA");
    p[108] = GetProcAddress(hL,"ConvertSidToStringSidW");
    p[109] = GetProcAddress(hL,"ConvertStringSDToSDDomainA");
    p[110] = GetProcAddress(hL,"ConvertStringSDToSDDomainW");
    p[111] = GetProcAddress(hL,"ConvertStringSDToSDRootDomainA");
    p[112] = GetProcAddress(hL,"ConvertStringSDToSDRootDomainW");
    p[113] = GetProcAddress(hL,"ConvertStringSecurityDescriptorToSecurityDescriptorA");
    p[114] = GetProcAddress(hL,"ConvertStringSecurityDescriptorToSecurityDescriptorW");
    p[115] = GetProcAddress(hL,"ConvertStringSidToSidA");
    p[116] = GetProcAddress(hL,"ConvertStringSidToSidW");
    p[117] = GetProcAddress(hL,"ConvertToAutoInheritPrivateObjectSecurity");
    p[118] = GetProcAddress(hL,"CopySid");
    p[119] = GetProcAddress(hL,"CreateCodeAuthzLevel");
    p[120] = GetProcAddress(hL,"CreatePrivateObjectSecurity");
    p[121] = GetProcAddress(hL,"CreatePrivateObjectSecurityEx");
    p[122] = GetProcAddress(hL,"CreatePrivateObjectSecurityWithMultipleInheritance");
    p[123] = GetProcAddress(hL,"CreateProcessAsUserA");
    p[124] = GetProcAddress(hL,"CreateProcessAsUserW");
    p[125] = GetProcAddress(hL,"CreateProcessWithLogonW");
    p[126] = GetProcAddress(hL,"CreateProcessWithTokenW");
    p[127] = GetProcAddress(hL,"CreateRestrictedToken");
    p[128] = GetProcAddress(hL,"CreateServiceA");
    p[129] = GetProcAddress(hL,"CreateServiceW");
    p[130] = GetProcAddress(hL,"CreateTraceInstanceId");
    p[131] = GetProcAddress(hL,"CreateWellKnownSid");
    p[132] = GetProcAddress(hL,"CredBackupCredentials");
    p[133] = GetProcAddress(hL,"CredDeleteA");
    p[134] = GetProcAddress(hL,"CredDeleteW");
    p[135] = GetProcAddress(hL,"CredEncryptAndMarshalBinaryBlob");
    p[136] = GetProcAddress(hL,"CredEnumerateA");
    p[137] = GetProcAddress(hL,"CredEnumerateW");
    p[138] = GetProcAddress(hL,"CredFindBestCredentialA");
    p[139] = GetProcAddress(hL,"CredFindBestCredentialW");
    p[140] = GetProcAddress(hL,"CredFree");
    p[141] = GetProcAddress(hL,"CredGetSessionTypes");
    p[142] = GetProcAddress(hL,"CredGetTargetInfoA");
    p[143] = GetProcAddress(hL,"CredGetTargetInfoW");
    p[144] = GetProcAddress(hL,"CredIsMarshaledCredentialA");
    p[145] = GetProcAddress(hL,"CredIsMarshaledCredentialW");
    p[146] = GetProcAddress(hL,"CredIsProtectedA");
    p[147] = GetProcAddress(hL,"CredIsProtectedW");
    p[148] = GetProcAddress(hL,"CredMarshalCredentialA");
    p[149] = GetProcAddress(hL,"CredMarshalCredentialW");
    p[150] = GetProcAddress(hL,"CredProfileLoaded");
    p[151] = GetProcAddress(hL,"CredProfileUnloaded");
    p[152] = GetProcAddress(hL,"CredProtectA");
    p[153] = GetProcAddress(hL,"CredProtectW");
    p[154] = GetProcAddress(hL,"CredReadA");
    p[155] = GetProcAddress(hL,"CredReadByTokenHandle");
    p[156] = GetProcAddress(hL,"CredReadDomainCredentialsA");
    p[157] = GetProcAddress(hL,"CredReadDomainCredentialsW");
    p[158] = GetProcAddress(hL,"CredReadW");
    p[159] = GetProcAddress(hL,"CredRenameA");
    p[160] = GetProcAddress(hL,"CredRenameW");
    p[161] = GetProcAddress(hL,"CredRestoreCredentials");
    p[162] = GetProcAddress(hL,"CredUnmarshalCredentialA");
    p[163] = GetProcAddress(hL,"CredUnmarshalCredentialW");
    p[164] = GetProcAddress(hL,"CredUnprotectA");
    p[165] = GetProcAddress(hL,"CredUnprotectW");
    p[166] = GetProcAddress(hL,"CredWriteA");
    p[167] = GetProcAddress(hL,"CredWriteDomainCredentialsA");
    p[168] = GetProcAddress(hL,"CredWriteDomainCredentialsW");
    p[169] = GetProcAddress(hL,"CredWriteW");
    p[170] = GetProcAddress(hL,"CredpConvertCredential");
    p[171] = GetProcAddress(hL,"CredpConvertOneCredentialSize");
    p[172] = GetProcAddress(hL,"CredpConvertTargetInfo");
    p[173] = GetProcAddress(hL,"CredpDecodeCredential");
    p[174] = GetProcAddress(hL,"CredpEncodeCredential");
    p[175] = GetProcAddress(hL,"CredpEncodeSecret");
    p[176] = GetProcAddress(hL,"CryptAcquireContextA");
    p[177] = GetProcAddress(hL,"CryptAcquireContextW");
    p[178] = GetProcAddress(hL,"CryptContextAddRef");
    p[179] = GetProcAddress(hL,"CryptCreateHash");
    p[180] = GetProcAddress(hL,"CryptDecrypt");
    p[181] = GetProcAddress(hL,"CryptDeriveKey");
    p[182] = GetProcAddress(hL,"CryptDestroyHash");
    p[183] = GetProcAddress(hL,"CryptDestroyKey");
    p[184] = GetProcAddress(hL,"CryptDuplicateHash");
    p[185] = GetProcAddress(hL,"CryptDuplicateKey");
    p[186] = GetProcAddress(hL,"CryptEncrypt");
    p[187] = GetProcAddress(hL,"CryptEnumProviderTypesA");
    p[188] = GetProcAddress(hL,"CryptEnumProviderTypesW");
    p[189] = GetProcAddress(hL,"CryptEnumProvidersA");
    p[190] = GetProcAddress(hL,"CryptEnumProvidersW");
    p[191] = GetProcAddress(hL,"CryptExportKey");
    p[192] = GetProcAddress(hL,"CryptGenKey");
    p[193] = GetProcAddress(hL,"CryptGenRandom");
    p[194] = GetProcAddress(hL,"CryptGetDefaultProviderA");
    p[195] = GetProcAddress(hL,"CryptGetDefaultProviderW");
    p[196] = GetProcAddress(hL,"CryptGetHashParam");
    p[197] = GetProcAddress(hL,"CryptGetKeyParam");
    p[198] = GetProcAddress(hL,"CryptGetProvParam");
    p[199] = GetProcAddress(hL,"CryptGetUserKey");
    p[200] = GetProcAddress(hL,"CryptHashData");
    p[201] = GetProcAddress(hL,"CryptHashSessionKey");
    p[202] = GetProcAddress(hL,"CryptImportKey");
    p[203] = GetProcAddress(hL,"CryptReleaseContext");
    p[204] = GetProcAddress(hL,"CryptSetHashParam");
    p[205] = GetProcAddress(hL,"CryptSetKeyParam");
    p[206] = GetProcAddress(hL,"CryptSetProvParam");
    p[207] = GetProcAddress(hL,"CryptSetProviderA");
    p[208] = GetProcAddress(hL,"CryptSetProviderExA");
    p[209] = GetProcAddress(hL,"CryptSetProviderExW");
    p[210] = GetProcAddress(hL,"CryptSetProviderW");
    p[211] = GetProcAddress(hL,"CryptSignHashA");
    p[212] = GetProcAddress(hL,"CryptSignHashW");
    p[213] = GetProcAddress(hL,"CryptVerifySignatureA");
    p[214] = GetProcAddress(hL,"CryptVerifySignatureW");
    p[215] = GetProcAddress(hL,"DecryptFileA");
    p[216] = GetProcAddress(hL,"DecryptFileW");
    p[217] = GetProcAddress(hL,"DeleteAce");
    p[218] = GetProcAddress(hL,"DeleteService");
    p[219] = GetProcAddress(hL,"DeregisterEventSource");
    p[220] = GetProcAddress(hL,"DestroyPrivateObjectSecurity");
    p[221] = GetProcAddress(hL,"DuplicateEncryptionInfoFile");
    p[222] = GetProcAddress(hL,"DuplicateToken");
    p[223] = GetProcAddress(hL,"DuplicateTokenEx");
    p[224] = GetProcAddress(hL,"ElfBackupEventLogFileA");
    p[225] = GetProcAddress(hL,"ElfBackupEventLogFileW");
    p[226] = GetProcAddress(hL,"ElfChangeNotify");
    p[227] = GetProcAddress(hL,"ElfClearEventLogFileA");
    p[228] = GetProcAddress(hL,"ElfClearEventLogFileW");
    p[229] = GetProcAddress(hL,"ElfCloseEventLog");
    p[230] = GetProcAddress(hL,"ElfDeregisterEventSource");
    p[231] = GetProcAddress(hL,"ElfFlushEventLog");
    p[232] = GetProcAddress(hL,"ElfNumberOfRecords");
    p[233] = GetProcAddress(hL,"ElfOldestRecord");
    p[234] = GetProcAddress(hL,"ElfOpenBackupEventLogA");
    p[235] = GetProcAddress(hL,"ElfOpenBackupEventLogW");
    p[236] = GetProcAddress(hL,"ElfOpenEventLogA");
    p[237] = GetProcAddress(hL,"ElfOpenEventLogW");
    p[238] = GetProcAddress(hL,"ElfReadEventLogA");
    p[239] = GetProcAddress(hL,"ElfReadEventLogW");
    p[240] = GetProcAddress(hL,"ElfRegisterEventSourceA");
    p[241] = GetProcAddress(hL,"ElfRegisterEventSourceW");
    p[242] = GetProcAddress(hL,"ElfReportEventA");
    p[243] = GetProcAddress(hL,"ElfReportEventAndSourceW");
    p[244] = GetProcAddress(hL,"ElfReportEventW");
    p[245] = GetProcAddress(hL,"EnableTrace");
    p[246] = GetProcAddress(hL,"EnableTraceEx");
    p[247] = GetProcAddress(hL,"EnableTraceEx2");
    p[248] = GetProcAddress(hL,"EncryptFileA");
    p[249] = GetProcAddress(hL,"EncryptFileW");
    p[250] = GetProcAddress(hL,"EncryptedFileKeyInfo");
    p[251] = GetProcAddress(hL,"EncryptionDisable");
    p[252] = GetProcAddress(hL,"EnumDependentServicesA");
    p[253] = GetProcAddress(hL,"EnumDependentServicesW");
    p[254] = GetProcAddress(hL,"EnumServiceGroupW");
    p[255] = GetProcAddress(hL,"EnumServicesStatusA");
    p[256] = GetProcAddress(hL,"EnumServicesStatusExA");
    p[257] = GetProcAddress(hL,"EnumServicesStatusExW");
    p[258] = GetProcAddress(hL,"EnumServicesStatusW");
    p[259] = GetProcAddress(hL,"EnumerateTraceGuids");
    p[260] = GetProcAddress(hL,"EnumerateTraceGuidsEx");
    p[261] = GetProcAddress(hL,"EqualDomainSid");
    p[262] = GetProcAddress(hL,"EqualPrefixSid");
    p[263] = GetProcAddress(hL,"EqualSid");
    p[264] = GetProcAddress(hL,"EventAccessControl");
    p[265] = GetProcAddress(hL,"EventAccessQuery");
    p[266] = GetProcAddress(hL,"EventAccessRemove");
    p[267] = GetProcAddress(hL,"EventActivityIdControl");
    p[268] = GetProcAddress(hL,"EventEnabled");
    p[269] = GetProcAddress(hL,"EventProviderEnabled");
    p[270] = GetProcAddress(hL,"EventRegister");
    p[271] = GetProcAddress(hL,"EventUnregister");
    p[272] = GetProcAddress(hL,"EventWrite");
    p[273] = GetProcAddress(hL,"EventWriteEndScenario");
    p[274] = GetProcAddress(hL,"EventWriteEx");
    p[275] = GetProcAddress(hL,"EventWriteStartScenario");
    p[276] = GetProcAddress(hL,"EventWriteString");
    p[277] = GetProcAddress(hL,"EventWriteTransfer");
    p[278] = GetProcAddress(hL,"FileEncryptionStatusA");
    p[279] = GetProcAddress(hL,"FileEncryptionStatusW");
    p[280] = GetProcAddress(hL,"FindFirstFreeAce");
    p[281] = GetProcAddress(hL,"FlushEfsCache");
    p[282] = GetProcAddress(hL,"FlushTraceA");
    p[283] = GetProcAddress(hL,"FlushTraceW");
    p[284] = GetProcAddress(hL,"FreeEncryptedFileKeyInfo");
    p[285] = GetProcAddress(hL,"FreeEncryptedFileMetadata");
    p[286] = GetProcAddress(hL,"FreeEncryptionCertificateHashList");
    p[287] = GetProcAddress(hL,"FreeInheritedFromArray");
    p[288] = GetProcAddress(hL,"FreeSid");
    p[289] = GetProcAddress(hL,"GetAccessPermissionsForObjectA");
    p[290] = GetProcAddress(hL,"GetAccessPermissionsForObjectW");
    p[291] = GetProcAddress(hL,"GetAce");
    p[292] = GetProcAddress(hL,"GetAclInformation");
    p[293] = GetProcAddress(hL,"GetAuditedPermissionsFromAclA");
    p[294] = GetProcAddress(hL,"GetAuditedPermissionsFromAclW");
    p[295] = GetProcAddress(hL,"GetCurrentHwProfileA");
    p[296] = GetProcAddress(hL,"GetCurrentHwProfileW");
    p[297] = GetProcAddress(hL,"GetEffectiveRightsFromAclA");
    p[298] = GetProcAddress(hL,"GetEffectiveRightsFromAclW");
    p[299] = GetProcAddress(hL,"GetEncryptedFileMetadata");
    p[300] = GetProcAddress(hL,"GetEventLogInformation");
    p[301] = GetProcAddress(hL,"GetExplicitEntriesFromAclA");
    p[302] = GetProcAddress(hL,"GetExplicitEntriesFromAclW");
    p[303] = GetProcAddress(hL,"GetFileSecurityA");
    p[304] = GetProcAddress(hL,"GetFileSecurityW");
    p[305] = GetProcAddress(hL,"GetInformationCodeAuthzLevelW");
    p[306] = GetProcAddress(hL,"GetInformationCodeAuthzPolicyW");
    p[307] = GetProcAddress(hL,"GetInheritanceSourceA");
    p[308] = GetProcAddress(hL,"GetInheritanceSourceW");
    p[309] = GetProcAddress(hL,"GetKernelObjectSecurity");
    p[310] = GetProcAddress(hL,"GetLengthSid");
    p[311] = GetProcAddress(hL,"GetLocalManagedApplicationData");
    p[312] = GetProcAddress(hL,"GetLocalManagedApplications");
    p[313] = GetProcAddress(hL,"GetManagedApplicationCategories");
    p[314] = GetProcAddress(hL,"GetManagedApplications");
    p[315] = GetProcAddress(hL,"GetMultipleTrusteeA");
    p[316] = GetProcAddress(hL,"GetMultipleTrusteeOperationA");
    p[317] = GetProcAddress(hL,"GetMultipleTrusteeOperationW");
    p[318] = GetProcAddress(hL,"GetMultipleTrusteeW");
    p[319] = GetProcAddress(hL,"GetNamedSecurityInfoA");
    p[320] = GetProcAddress(hL,"GetNamedSecurityInfoExA");
    p[321] = GetProcAddress(hL,"GetNamedSecurityInfoExW");
    p[322] = GetProcAddress(hL,"GetNamedSecurityInfoW");
    p[323] = GetProcAddress(hL,"GetNumberOfEventLogRecords");
    p[324] = GetProcAddress(hL,"GetOldestEventLogRecord");
    p[325] = GetProcAddress(hL,"GetOverlappedAccessResults");
    p[326] = GetProcAddress(hL,"GetPrivateObjectSecurity");
    p[327] = GetProcAddress(hL,"GetSecurityDescriptorControl");
    p[328] = GetProcAddress(hL,"GetSecurityDescriptorDacl");
    p[329] = GetProcAddress(hL,"GetSecurityDescriptorGroup");
    p[330] = GetProcAddress(hL,"GetSecurityDescriptorLength");
    p[331] = GetProcAddress(hL,"GetSecurityDescriptorOwner");
    p[332] = GetProcAddress(hL,"GetSecurityDescriptorRMControl");
    p[333] = GetProcAddress(hL,"GetSecurityDescriptorSacl");
    p[334] = GetProcAddress(hL,"GetSecurityInfo");
    p[335] = GetProcAddress(hL,"GetSecurityInfoExA");
    p[336] = GetProcAddress(hL,"GetSecurityInfoExW");
    p[337] = GetProcAddress(hL,"GetServiceDisplayNameA");
    p[338] = GetProcAddress(hL,"GetServiceDisplayNameW");
    p[339] = GetProcAddress(hL,"GetServiceKeyNameA");
    p[340] = GetProcAddress(hL,"GetServiceKeyNameW");
    p[341] = GetProcAddress(hL,"GetSidIdentifierAuthority");
    p[342] = GetProcAddress(hL,"GetSidLengthRequired");
    p[343] = GetProcAddress(hL,"GetSidSubAuthority");
    p[344] = GetProcAddress(hL,"GetSidSubAuthorityCount");
    p[345] = GetProcAddress(hL,"GetThreadWaitChain");
    p[346] = GetProcAddress(hL,"GetTokenInformation");
    p[347] = GetProcAddress(hL,"GetTraceEnableFlags");
    p[348] = GetProcAddress(hL,"GetTraceEnableLevel");
    p[349] = GetProcAddress(hL,"GetTraceLoggerHandle");
    p[350] = GetProcAddress(hL,"GetTrusteeFormA");
    p[351] = GetProcAddress(hL,"GetTrusteeFormW");
    p[352] = GetProcAddress(hL,"GetTrusteeNameA");
    p[353] = GetProcAddress(hL,"GetTrusteeNameW");
    p[354] = GetProcAddress(hL,"GetTrusteeTypeA");
    p[355] = GetProcAddress(hL,"GetTrusteeTypeW");
    p[356] = GetProcAddress(hL,"GetUserNameA");
    p[357] = GetProcAddress(hL,"GetUserNameW");
    p[358] = GetProcAddress(hL,"GetWindowsAccountDomainSid");
    p[359] = GetProcAddress(hL,"I_QueryTagInformation");
    p[360] = GetProcAddress(hL,"I_ScGetCurrentGroupStateW");
    p[361] = GetProcAddress(hL,"I_ScIsSecurityProcess");
    p[362] = GetProcAddress(hL,"I_ScPnPGetServiceName");
    p[363] = GetProcAddress(hL,"I_ScQueryServiceConfig");
    p[364] = GetProcAddress(hL,"I_ScSendPnPMessage");
    p[365] = GetProcAddress(hL,"I_ScSendTSMessage");
    p[366] = GetProcAddress(hL,"I_ScSetServiceBitsA");
    p[367] = GetProcAddress(hL,"I_ScSetServiceBitsW");
    p[368] = GetProcAddress(hL,"I_ScValidatePnPService");
    p[369] = GetProcAddress(hL,"IdentifyCodeAuthzLevelW");
    p[370] = GetProcAddress(hL,"ImpersonateAnonymousToken");
    p[371] = GetProcAddress(hL,"ImpersonateLoggedOnUser");
    p[372] = GetProcAddress(hL,"ImpersonateNamedPipeClient");
    p[373] = GetProcAddress(hL,"ImpersonateSelf");
    p[374] = GetProcAddress(hL,"InitializeAcl");
    p[375] = GetProcAddress(hL,"InitializeSecurityDescriptor");
    p[376] = GetProcAddress(hL,"InitializeSid");
    p[377] = GetProcAddress(hL,"InitiateShutdownA");
    p[378] = GetProcAddress(hL,"InitiateShutdownW");
    p[379] = GetProcAddress(hL,"InitiateSystemShutdownA");
    p[380] = GetProcAddress(hL,"InitiateSystemShutdownExA");
    p[381] = GetProcAddress(hL,"InitiateSystemShutdownExW");
    p[382] = GetProcAddress(hL,"InitiateSystemShutdownW");
    p[383] = GetProcAddress(hL,"InstallApplication");
    p[384] = GetProcAddress(hL,"IsTextUnicode");
    p[385] = GetProcAddress(hL,"IsTokenRestricted");
    p[386] = GetProcAddress(hL,"IsTokenUntrusted");
    p[387] = GetProcAddress(hL,"IsValidAcl");
    p[388] = GetProcAddress(hL,"IsValidRelativeSecurityDescriptor");
    p[389] = GetProcAddress(hL,"IsValidSecurityDescriptor");
    p[390] = GetProcAddress(hL,"IsValidSid");
    p[391] = GetProcAddress(hL,"IsWellKnownSid");
    p[392] = GetProcAddress(hL,"LockServiceDatabase");
    p[393] = GetProcAddress(hL,"LogonUserA");
    p[394] = GetProcAddress(hL,"LogonUserExA");
    p[395] = GetProcAddress(hL,"LogonUserExExW");
    p[396] = GetProcAddress(hL,"LogonUserExW");
    p[397] = GetProcAddress(hL,"LogonUserW");
    p[398] = GetProcAddress(hL,"LookupAccountNameA");
    p[399] = GetProcAddress(hL,"LookupAccountNameW");
    p[400] = GetProcAddress(hL,"LookupAccountSidA");
    p[401] = GetProcAddress(hL,"LookupAccountSidW");
    p[402] = GetProcAddress(hL,"LookupPrivilegeDisplayNameA");
    p[403] = GetProcAddress(hL,"LookupPrivilegeDisplayNameW");
    p[404] = GetProcAddress(hL,"LookupPrivilegeNameA");
    p[405] = GetProcAddress(hL,"LookupPrivilegeNameW");
    p[406] = GetProcAddress(hL,"LookupPrivilegeValueA");
    p[407] = GetProcAddress(hL,"LookupPrivilegeValueW");
    p[408] = GetProcAddress(hL,"LookupSecurityDescriptorPartsA");
    p[409] = GetProcAddress(hL,"LookupSecurityDescriptorPartsW");
    p[410] = GetProcAddress(hL,"LsaAddAccountRights");
    p[411] = GetProcAddress(hL,"LsaAddPrivilegesToAccount");
    p[412] = GetProcAddress(hL,"LsaClearAuditLog");
    p[413] = GetProcAddress(hL,"LsaClose");
    p[414] = GetProcAddress(hL,"LsaCreateAccount");
    p[415] = GetProcAddress(hL,"LsaCreateSecret");
    p[416] = GetProcAddress(hL,"LsaCreateTrustedDomain");
    p[417] = GetProcAddress(hL,"LsaCreateTrustedDomainEx");
    p[418] = GetProcAddress(hL,"LsaDelete");
    p[419] = GetProcAddress(hL,"LsaDeleteTrustedDomain");
    p[420] = GetProcAddress(hL,"LsaEnumerateAccountRights");
    p[421] = GetProcAddress(hL,"LsaEnumerateAccounts");
    p[422] = GetProcAddress(hL,"LsaEnumerateAccountsWithUserRight");
    p[423] = GetProcAddress(hL,"LsaEnumeratePrivileges");
    p[424] = GetProcAddress(hL,"LsaEnumeratePrivilegesOfAccount");
    p[425] = GetProcAddress(hL,"LsaEnumerateTrustedDomains");
    p[426] = GetProcAddress(hL,"LsaEnumerateTrustedDomainsEx");
    p[427] = GetProcAddress(hL,"LsaFreeMemory");
    p[428] = GetProcAddress(hL,"LsaGetQuotasForAccount");
    p[429] = GetProcAddress(hL,"LsaGetRemoteUserName");
    p[430] = GetProcAddress(hL,"LsaGetSystemAccessAccount");
    p[431] = GetProcAddress(hL,"LsaGetUserName");
    p[432] = GetProcAddress(hL,"LsaICLookupNames");
    p[433] = GetProcAddress(hL,"LsaICLookupNamesWithCreds");
    p[434] = GetProcAddress(hL,"LsaICLookupSids");
    p[435] = GetProcAddress(hL,"LsaICLookupSidsWithCreds");
    p[436] = GetProcAddress(hL,"LsaLookupNames");
    p[437] = GetProcAddress(hL,"LsaLookupNames2");
    p[438] = GetProcAddress(hL,"LsaLookupPrivilegeDisplayName");
    p[439] = GetProcAddress(hL,"LsaLookupPrivilegeName");
    p[440] = GetProcAddress(hL,"LsaLookupPrivilegeValue");
    p[441] = GetProcAddress(hL,"LsaLookupSids");
    p[442] = GetProcAddress(hL,"LsaManageSidNameMapping");
    p[443] = GetProcAddress(hL,"LsaNtStatusToWinError");
    p[444] = GetProcAddress(hL,"LsaOpenAccount");
    p[445] = GetProcAddress(hL,"LsaOpenPolicy");
    p[446] = GetProcAddress(hL,"LsaOpenPolicySce");
    p[447] = GetProcAddress(hL,"LsaOpenSecret");
    p[448] = GetProcAddress(hL,"LsaOpenTrustedDomain");
    p[449] = GetProcAddress(hL,"LsaOpenTrustedDomainByName");
    p[450] = GetProcAddress(hL,"LsaQueryDomainInformationPolicy");
    p[451] = GetProcAddress(hL,"LsaQueryForestTrustInformation");
    p[452] = GetProcAddress(hL,"LsaQueryInfoTrustedDomain");
    p[453] = GetProcAddress(hL,"LsaQueryInformationPolicy");
    p[454] = GetProcAddress(hL,"LsaQuerySecret");
    p[455] = GetProcAddress(hL,"LsaQuerySecurityObject");
    p[456] = GetProcAddress(hL,"LsaQueryTrustedDomainInfo");
    p[457] = GetProcAddress(hL,"LsaQueryTrustedDomainInfoByName");
    p[458] = GetProcAddress(hL,"LsaRemoveAccountRights");
    p[459] = GetProcAddress(hL,"LsaRemovePrivilegesFromAccount");
    p[460] = GetProcAddress(hL,"LsaRetrievePrivateData");
    p[461] = GetProcAddress(hL,"LsaSetDomainInformationPolicy");
    p[462] = GetProcAddress(hL,"LsaSetForestTrustInformation");
    p[463] = GetProcAddress(hL,"LsaSetInformationPolicy");
    p[464] = GetProcAddress(hL,"LsaSetInformationTrustedDomain");
    p[465] = GetProcAddress(hL,"LsaSetQuotasForAccount");
    p[466] = GetProcAddress(hL,"LsaSetSecret");
    p[467] = GetProcAddress(hL,"LsaSetSecurityObject");
    p[468] = GetProcAddress(hL,"LsaSetSystemAccessAccount");
    p[469] = GetProcAddress(hL,"LsaSetTrustedDomainInfoByName");
    p[470] = GetProcAddress(hL,"LsaSetTrustedDomainInformation");
    p[471] = GetProcAddress(hL,"LsaStorePrivateData");
    p[472] = GetProcAddress(hL,"MD4Final");
    p[473] = GetProcAddress(hL,"MD4Init");
    p[474] = GetProcAddress(hL,"MD4Update");
    p[475] = GetProcAddress(hL,"MD5Final");
    p[476] = GetProcAddress(hL,"MD5Init");
    p[477] = GetProcAddress(hL,"MD5Update");
    p[478] = GetProcAddress(hL,"MSChapSrvChangePassword");
    p[479] = GetProcAddress(hL,"MSChapSrvChangePassword2");
    p[480] = GetProcAddress(hL,"MakeAbsoluteSD");
    p[481] = GetProcAddress(hL,"MakeAbsoluteSD2");
    p[482] = GetProcAddress(hL,"MakeSelfRelativeSD");
    p[483] = GetProcAddress(hL,"MapGenericMask");
    p[484] = GetProcAddress(hL,"NotifyBootConfigStatus");
    p[485] = GetProcAddress(hL,"NotifyChangeEventLog");
    p[486] = GetProcAddress(hL,"NotifyServiceStatusChange");
    p[487] = GetProcAddress(hL,"NotifyServiceStatusChangeA");
    p[488] = GetProcAddress(hL,"NotifyServiceStatusChangeW");
    p[489] = GetProcAddress(hL,"ObjectCloseAuditAlarmA");
    p[490] = GetProcAddress(hL,"ObjectCloseAuditAlarmW");
    p[491] = GetProcAddress(hL,"ObjectDeleteAuditAlarmA");
    p[492] = GetProcAddress(hL,"ObjectDeleteAuditAlarmW");
    p[493] = GetProcAddress(hL,"ObjectOpenAuditAlarmA");
    p[494] = GetProcAddress(hL,"ObjectOpenAuditAlarmW");
    p[495] = GetProcAddress(hL,"ObjectPrivilegeAuditAlarmA");
    p[496] = GetProcAddress(hL,"ObjectPrivilegeAuditAlarmW");
    p[497] = GetProcAddress(hL,"OpenBackupEventLogA");
    p[498] = GetProcAddress(hL,"OpenBackupEventLogW");
    p[499] = GetProcAddress(hL,"OpenEncryptedFileRawA");
    p[500] = GetProcAddress(hL,"OpenEncryptedFileRawW");
    p[501] = GetProcAddress(hL,"OpenEventLogA");
    p[502] = GetProcAddress(hL,"OpenEventLogW");
    p[503] = GetProcAddress(hL,"OpenProcessToken");
    p[504] = GetProcAddress(hL,"OpenSCManagerA");
    p[505] = GetProcAddress(hL,"OpenSCManagerW");
    p[506] = GetProcAddress(hL,"OpenServiceA");
    p[507] = GetProcAddress(hL,"OpenServiceW");
    p[508] = GetProcAddress(hL,"OpenThreadToken");
    p[509] = GetProcAddress(hL,"OpenThreadWaitChainSession");
    p[510] = GetProcAddress(hL,"OpenTraceA");
    p[511] = GetProcAddress(hL,"OpenTraceW");
    p[512] = GetProcAddress(hL,"PerfAddCounters");
    p[513] = GetProcAddress(hL,"PerfCloseQueryHandle");
    p[514] = GetProcAddress(hL,"PerfCreateInstance");
    p[515] = GetProcAddress(hL,"PerfDecrementULongCounterValue");
    p[516] = GetProcAddress(hL,"PerfDecrementULongLongCounterValue");
    p[517] = GetProcAddress(hL,"PerfDeleteCounters");
    p[518] = GetProcAddress(hL,"PerfDeleteInstance");
    p[519] = GetProcAddress(hL,"PerfEnumerateCounterSet");
    p[520] = GetProcAddress(hL,"PerfEnumerateCounterSetInstances");
    p[521] = GetProcAddress(hL,"PerfIncrementULongCounterValue");
    p[522] = GetProcAddress(hL,"PerfIncrementULongLongCounterValue");
    p[523] = GetProcAddress(hL,"PerfOpenQueryHandle");
    p[524] = GetProcAddress(hL,"PerfQueryCounterData");
    p[525] = GetProcAddress(hL,"PerfQueryCounterInfo");
    p[526] = GetProcAddress(hL,"PerfQueryCounterSetRegistrationInfo");
    p[527] = GetProcAddress(hL,"PerfQueryInstance");
    p[528] = GetProcAddress(hL,"PerfSetCounterRefValue");
    p[529] = GetProcAddress(hL,"PerfSetCounterSetInfo");
    p[530] = GetProcAddress(hL,"PerfSetULongCounterValue");
    p[531] = GetProcAddress(hL,"PerfSetULongLongCounterValue");
    p[532] = GetProcAddress(hL,"PerfStartProvider");
    p[533] = GetProcAddress(hL,"PerfStartProviderEx");
    p[534] = GetProcAddress(hL,"PerfStopProvider");
    p[535] = GetProcAddress(hL,"PrivilegeCheck");
    p[536] = GetProcAddress(hL,"PrivilegedServiceAuditAlarmA");
    p[537] = GetProcAddress(hL,"PrivilegedServiceAuditAlarmW");
    p[538] = GetProcAddress(hL,"ProcessIdleTasks");
    p[539] = GetProcAddress(hL,"ProcessIdleTasksW");
    p[540] = GetProcAddress(hL,"ProcessTrace");
    p[541] = GetProcAddress(hL,"QueryAllTracesA");
    p[542] = GetProcAddress(hL,"QueryAllTracesW");
    p[543] = GetProcAddress(hL,"QueryRecoveryAgentsOnEncryptedFile");
    p[544] = GetProcAddress(hL,"QuerySecurityAccessMask");
    p[545] = GetProcAddress(hL,"QueryServiceConfig2A");
    p[546] = GetProcAddress(hL,"QueryServiceConfig2W");
    p[547] = GetProcAddress(hL,"QueryServiceConfigA");
    p[548] = GetProcAddress(hL,"QueryServiceConfigW");
    p[549] = GetProcAddress(hL,"QueryServiceLockStatusA");
    p[550] = GetProcAddress(hL,"QueryServiceLockStatusW");
    p[551] = GetProcAddress(hL,"QueryServiceObjectSecurity");
    p[552] = GetProcAddress(hL,"QueryServiceStatus");
    p[553] = GetProcAddress(hL,"QueryServiceStatusEx");
    p[554] = GetProcAddress(hL,"QueryTraceA");
    p[555] = GetProcAddress(hL,"QueryTraceW");
    p[556] = GetProcAddress(hL,"QueryUsersOnEncryptedFile");
    p[557] = GetProcAddress(hL,"ReadEncryptedFileRaw");
    p[558] = GetProcAddress(hL,"ReadEventLogA");
    p[559] = GetProcAddress(hL,"ReadEventLogW");
    p[560] = GetProcAddress(hL,"RegCloseKey");
    p[561] = GetProcAddress(hL,"RegConnectRegistryA");
    p[562] = GetProcAddress(hL,"RegConnectRegistryExA");
    p[563] = GetProcAddress(hL,"RegConnectRegistryExW");
    p[564] = GetProcAddress(hL,"RegConnectRegistryW");
    p[565] = GetProcAddress(hL,"RegCopyTreeA");
    p[566] = GetProcAddress(hL,"RegCopyTreeW");
    p[567] = GetProcAddress(hL,"RegCreateKeyA");
    p[568] = GetProcAddress(hL,"RegCreateKeyExA");
    p[569] = GetProcAddress(hL,"RegCreateKeyExW");
    p[570] = GetProcAddress(hL,"RegCreateKeyTransactedA");
    p[571] = GetProcAddress(hL,"RegCreateKeyTransactedW");
    p[572] = GetProcAddress(hL,"RegCreateKeyW");
    p[573] = GetProcAddress(hL,"RegDeleteKeyA");
    p[574] = GetProcAddress(hL,"RegDeleteKeyExA");
    p[575] = GetProcAddress(hL,"RegDeleteKeyExW");
    p[576] = GetProcAddress(hL,"RegDeleteKeyTransactedA");
    p[577] = GetProcAddress(hL,"RegDeleteKeyTransactedW");
    p[578] = GetProcAddress(hL,"RegDeleteKeyValueA");
    p[579] = GetProcAddress(hL,"RegDeleteKeyValueW");
    p[580] = GetProcAddress(hL,"RegDeleteKeyW");
    p[581] = GetProcAddress(hL,"RegDeleteTreeA");
    p[582] = GetProcAddress(hL,"RegDeleteTreeW");
    p[583] = GetProcAddress(hL,"RegDeleteValueA");
    p[584] = GetProcAddress(hL,"RegDeleteValueW");
    p[585] = GetProcAddress(hL,"RegDisablePredefinedCache");
    p[586] = GetProcAddress(hL,"RegDisablePredefinedCacheEx");
    p[587] = GetProcAddress(hL,"RegDisableReflectionKey");
    p[588] = GetProcAddress(hL,"RegEnableReflectionKey");
    p[589] = GetProcAddress(hL,"RegEnumKeyA");
    p[590] = GetProcAddress(hL,"RegEnumKeyExA");
    p[591] = GetProcAddress(hL,"RegEnumKeyExW");
    p[592] = GetProcAddress(hL,"RegEnumKeyW");
    p[593] = GetProcAddress(hL,"RegEnumValueA");
    p[594] = GetProcAddress(hL,"RegEnumValueW");
    p[595] = GetProcAddress(hL,"RegFlushKey");
    p[596] = GetProcAddress(hL,"RegGetKeySecurity");
    p[597] = GetProcAddress(hL,"RegGetValueA");
    p[598] = GetProcAddress(hL,"RegGetValueW");
    p[599] = GetProcAddress(hL,"RegLoadAppKeyA");
    p[600] = GetProcAddress(hL,"RegLoadAppKeyW");
    p[601] = GetProcAddress(hL,"RegLoadKeyA");
    p[602] = GetProcAddress(hL,"RegLoadKeyW");
    p[603] = GetProcAddress(hL,"RegLoadMUIStringA");
    p[604] = GetProcAddress(hL,"RegLoadMUIStringW");
    p[605] = GetProcAddress(hL,"RegNotifyChangeKeyValue");
    p[606] = GetProcAddress(hL,"RegOpenCurrentUser");
    p[607] = GetProcAddress(hL,"RegOpenKeyA");
    p[608] = GetProcAddress(hL,"RegOpenKeyExA");
    p[609] = GetProcAddress(hL,"RegOpenKeyExW");
    p[610] = GetProcAddress(hL,"RegOpenKeyTransactedA");
    p[611] = GetProcAddress(hL,"RegOpenKeyTransactedW");
    p[612] = GetProcAddress(hL,"RegOpenKeyW");
    p[613] = GetProcAddress(hL,"RegOpenUserClassesRoot");
    p[614] = GetProcAddress(hL,"RegOverridePredefKey");
    p[615] = GetProcAddress(hL,"RegQueryInfoKeyA");
    p[616] = GetProcAddress(hL,"RegQueryInfoKeyW");
    p[617] = GetProcAddress(hL,"RegQueryMultipleValuesA");
    p[618] = GetProcAddress(hL,"RegQueryMultipleValuesW");
    p[619] = GetProcAddress(hL,"RegQueryReflectionKey");
    p[620] = GetProcAddress(hL,"RegQueryValueA");
    p[621] = GetProcAddress(hL,"RegQueryValueExA");
    p[622] = GetProcAddress(hL,"RegQueryValueExW");
    p[623] = GetProcAddress(hL,"RegQueryValueW");
    p[624] = GetProcAddress(hL,"RegRenameKey");
    p[625] = GetProcAddress(hL,"RegReplaceKeyA");
    p[626] = GetProcAddress(hL,"RegReplaceKeyW");
    p[627] = GetProcAddress(hL,"RegRestoreKeyA");
    p[628] = GetProcAddress(hL,"RegRestoreKeyW");
    p[629] = GetProcAddress(hL,"RegSaveKeyA");
    p[630] = GetProcAddress(hL,"RegSaveKeyExA");
    p[631] = GetProcAddress(hL,"RegSaveKeyExW");
    p[632] = GetProcAddress(hL,"RegSaveKeyW");
    p[633] = GetProcAddress(hL,"RegSetKeySecurity");
    p[634] = GetProcAddress(hL,"RegSetKeyValueA");
    p[635] = GetProcAddress(hL,"RegSetKeyValueW");
    p[636] = GetProcAddress(hL,"RegSetValueA");
    p[637] = GetProcAddress(hL,"RegSetValueExA");
    p[638] = GetProcAddress(hL,"RegSetValueExW");
    p[639] = GetProcAddress(hL,"RegSetValueW");
    p[640] = GetProcAddress(hL,"RegUnLoadKeyA");
    p[641] = GetProcAddress(hL,"RegUnLoadKeyW");
    p[642] = GetProcAddress(hL,"RegisterEventSourceA");
    p[643] = GetProcAddress(hL,"RegisterEventSourceW");
    p[644] = GetProcAddress(hL,"RegisterIdleTask");
    p[645] = GetProcAddress(hL,"RegisterServiceCtrlHandlerA");
    p[646] = GetProcAddress(hL,"RegisterServiceCtrlHandlerExA");
    p[647] = GetProcAddress(hL,"RegisterServiceCtrlHandlerExW");
    p[648] = GetProcAddress(hL,"RegisterServiceCtrlHandlerW");
    p[649] = GetProcAddress(hL,"RegisterTraceGuidsA");
    p[650] = GetProcAddress(hL,"RegisterTraceGuidsW");
    p[651] = GetProcAddress(hL,"RegisterWaitChainCOMCallback");
    p[652] = GetProcAddress(hL,"RemoveTraceCallback");
    p[653] = GetProcAddress(hL,"RemoveUsersFromEncryptedFile");
    p[654] = GetProcAddress(hL,"ReportEventA");
    p[655] = GetProcAddress(hL,"ReportEventW");
    p[656] = GetProcAddress(hL,"RevertToSelf");
    p[657] = GetProcAddress(hL,"SaferCloseLevel");
    p[658] = GetProcAddress(hL,"SaferComputeTokenFromLevel");
    p[659] = GetProcAddress(hL,"SaferCreateLevel");
    p[660] = GetProcAddress(hL,"SaferGetLevelInformation");
    p[661] = GetProcAddress(hL,"SaferGetPolicyInformation");
    p[662] = GetProcAddress(hL,"SaferIdentifyLevel");
    p[663] = GetProcAddress(hL,"SaferRecordEventLogEntry");
    p[664] = GetProcAddress(hL,"SaferSetLevelInformation");
    p[665] = GetProcAddress(hL,"SaferSetPolicyInformation");
    p[666] = GetProcAddress(hL,"SaferiChangeRegistryScope");
    p[667] = GetProcAddress(hL,"SaferiCompareTokenLevels");
    p[668] = GetProcAddress(hL,"SaferiIsDllAllowed");
    p[669] = GetProcAddress(hL,"SaferiIsExecutableFileType");
    p[670] = GetProcAddress(hL,"SaferiPopulateDefaultsInRegistry");
    p[671] = GetProcAddress(hL,"SaferiRecordEventLogEntry");
    p[672] = GetProcAddress(hL,"SaferiSearchMatchingHashRules");
    p[673] = GetProcAddress(hL,"SetAclInformation");
    p[674] = GetProcAddress(hL,"SetEncryptedFileMetadata");
    p[675] = GetProcAddress(hL,"SetEntriesInAccessListA");
    p[676] = GetProcAddress(hL,"SetEntriesInAccessListW");
    p[677] = GetProcAddress(hL,"SetEntriesInAclA");
    p[678] = GetProcAddress(hL,"SetEntriesInAclW");
    p[679] = GetProcAddress(hL,"SetEntriesInAuditListA");
    p[680] = GetProcAddress(hL,"SetEntriesInAuditListW");
    p[681] = GetProcAddress(hL,"SetFileSecurityA");
    p[682] = GetProcAddress(hL,"SetFileSecurityW");
    p[683] = GetProcAddress(hL,"SetInformationCodeAuthzLevelW");
    p[684] = GetProcAddress(hL,"SetInformationCodeAuthzPolicyW");
    p[685] = GetProcAddress(hL,"SetKernelObjectSecurity");
    p[686] = GetProcAddress(hL,"SetNamedSecurityInfoA");
    p[687] = GetProcAddress(hL,"SetNamedSecurityInfoExA");
    p[688] = GetProcAddress(hL,"SetNamedSecurityInfoExW");
    p[689] = GetProcAddress(hL,"SetNamedSecurityInfoW");
    p[690] = GetProcAddress(hL,"SetPrivateObjectSecurity");
    p[691] = GetProcAddress(hL,"SetPrivateObjectSecurityEx");
    p[692] = GetProcAddress(hL,"SetSecurityAccessMask");
    p[693] = GetProcAddress(hL,"SetSecurityDescriptorControl");
    p[694] = GetProcAddress(hL,"SetSecurityDescriptorDacl");
    p[695] = GetProcAddress(hL,"SetSecurityDescriptorGroup");
    p[696] = GetProcAddress(hL,"SetSecurityDescriptorOwner");
    p[697] = GetProcAddress(hL,"SetSecurityDescriptorRMControl");
    p[698] = GetProcAddress(hL,"SetSecurityDescriptorSacl");
    p[699] = GetProcAddress(hL,"SetSecurityInfo");
    p[700] = GetProcAddress(hL,"SetSecurityInfoExA");
    p[701] = GetProcAddress(hL,"SetSecurityInfoExW");
    p[702] = GetProcAddress(hL,"SetServiceBits");
    p[703] = GetProcAddress(hL,"SetServiceObjectSecurity");
    p[704] = GetProcAddress(hL,"SetServiceStatus");
    p[705] = GetProcAddress(hL,"SetThreadToken");
    p[706] = GetProcAddress(hL,"SetTokenInformation");
    p[707] = GetProcAddress(hL,"SetTraceCallback");
    p[708] = GetProcAddress(hL,"SetUserFileEncryptionKey");
    p[709] = GetProcAddress(hL,"SetUserFileEncryptionKeyEx");
    p[710] = GetProcAddress(hL,"StartServiceA");
    p[711] = GetProcAddress(hL,"StartServiceCtrlDispatcherA");
    p[712] = GetProcAddress(hL,"StartServiceCtrlDispatcherW");
    p[713] = GetProcAddress(hL,"StartServiceW");
    p[714] = GetProcAddress(hL,"StartTraceA");
    p[715] = GetProcAddress(hL,"StartTraceW");
    p[716] = GetProcAddress(hL,"StopTraceA");
    p[717] = GetProcAddress(hL,"StopTraceW");
    p[718] = GetProcAddress(hL,"SystemFunction001");
    p[719] = GetProcAddress(hL,"SystemFunction002");
    p[720] = GetProcAddress(hL,"SystemFunction003");
    p[721] = GetProcAddress(hL,"SystemFunction004");
    p[722] = GetProcAddress(hL,"SystemFunction005");
    p[723] = GetProcAddress(hL,"SystemFunction006");
    p[724] = GetProcAddress(hL,"SystemFunction007");
    p[725] = GetProcAddress(hL,"SystemFunction008");
    p[726] = GetProcAddress(hL,"SystemFunction009");
    p[727] = GetProcAddress(hL,"SystemFunction010");
    p[728] = GetProcAddress(hL,"SystemFunction011");
    p[729] = GetProcAddress(hL,"SystemFunction012");
    p[730] = GetProcAddress(hL,"SystemFunction013");
    p[731] = GetProcAddress(hL,"SystemFunction014");
    p[732] = GetProcAddress(hL,"SystemFunction015");
    p[733] = GetProcAddress(hL,"SystemFunction016");
    p[734] = GetProcAddress(hL,"SystemFunction017");
    p[735] = GetProcAddress(hL,"SystemFunction018");
    p[736] = GetProcAddress(hL,"SystemFunction019");
    p[737] = GetProcAddress(hL,"SystemFunction020");
    p[738] = GetProcAddress(hL,"SystemFunction021");
    p[739] = GetProcAddress(hL,"SystemFunction022");
    p[740] = GetProcAddress(hL,"SystemFunction023");
    p[741] = GetProcAddress(hL,"SystemFunction024");
    p[742] = GetProcAddress(hL,"SystemFunction025");
    p[743] = GetProcAddress(hL,"SystemFunction026");
    p[744] = GetProcAddress(hL,"SystemFunction027");
    p[745] = GetProcAddress(hL,"SystemFunction028");
    p[746] = GetProcAddress(hL,"SystemFunction029");
    p[747] = GetProcAddress(hL,"SystemFunction030");
    p[748] = GetProcAddress(hL,"SystemFunction031");
    p[749] = GetProcAddress(hL,"SystemFunction032");
    p[750] = GetProcAddress(hL,"SystemFunction033");
    p[751] = GetProcAddress(hL,"SystemFunction034");
    p[752] = GetProcAddress(hL,"SystemFunction035");
    p[753] = GetProcAddress(hL,"SystemFunction036");
    p[754] = GetProcAddress(hL,"SystemFunction040");
    p[755] = GetProcAddress(hL,"SystemFunction041");
    p[756] = GetProcAddress(hL,"TraceEvent");
    p[757] = GetProcAddress(hL,"TraceEventInstance");
    p[758] = GetProcAddress(hL,"TraceMessage");
    p[759] = GetProcAddress(hL,"TraceMessageVa");
    p[760] = GetProcAddress(hL,"TraceSetInformation");
    p[761] = GetProcAddress(hL,"TreeResetNamedSecurityInfoA");
    p[762] = GetProcAddress(hL,"TreeResetNamedSecurityInfoW");
    p[763] = GetProcAddress(hL,"TreeSetNamedSecurityInfoA");
    p[764] = GetProcAddress(hL,"TreeSetNamedSecurityInfoW");
    p[765] = GetProcAddress(hL,"TrusteeAccessToObjectA");
    p[766] = GetProcAddress(hL,"TrusteeAccessToObjectW");
    p[767] = GetProcAddress(hL,"UninstallApplication");
    p[768] = GetProcAddress(hL,"UnlockServiceDatabase");
    p[769] = GetProcAddress(hL,"UnregisterIdleTask");
    p[770] = GetProcAddress(hL,"UnregisterTraceGuids");
    p[771] = GetProcAddress(hL,"UpdateTraceA");
    p[772] = GetProcAddress(hL,"UpdateTraceW");
    p[773] = GetProcAddress(hL,"UsePinForEncryptedFilesA");
    p[774] = GetProcAddress(hL,"UsePinForEncryptedFilesW");
    p[775] = GetProcAddress(hL,"WmiCloseBlock");
    p[776] = GetProcAddress(hL,"WmiDevInstToInstanceNameA");
    p[777] = GetProcAddress(hL,"WmiDevInstToInstanceNameW");
    p[778] = GetProcAddress(hL,"WmiEnumerateGuids");
    p[779] = GetProcAddress(hL,"WmiExecuteMethodA");
    p[780] = GetProcAddress(hL,"WmiExecuteMethodW");
    p[781] = GetProcAddress(hL,"WmiFileHandleToInstanceNameA");
    p[782] = GetProcAddress(hL,"WmiFileHandleToInstanceNameW");
    p[783] = GetProcAddress(hL,"WmiFreeBuffer");
    p[784] = GetProcAddress(hL,"WmiMofEnumerateResourcesA");
    p[785] = GetProcAddress(hL,"WmiMofEnumerateResourcesW");
    p[786] = GetProcAddress(hL,"WmiNotificationRegistrationA");
    p[787] = GetProcAddress(hL,"WmiNotificationRegistrationW");
    p[788] = GetProcAddress(hL,"WmiOpenBlock");
    p[789] = GetProcAddress(hL,"WmiQueryAllDataA");
    p[790] = GetProcAddress(hL,"WmiQueryAllDataMultipleA");
    p[791] = GetProcAddress(hL,"WmiQueryAllDataMultipleW");
    p[792] = GetProcAddress(hL,"WmiQueryAllDataW");
    p[793] = GetProcAddress(hL,"WmiQueryGuidInformation");
    p[794] = GetProcAddress(hL,"WmiQuerySingleInstanceA");
    p[795] = GetProcAddress(hL,"WmiQuerySingleInstanceMultipleA");
    p[796] = GetProcAddress(hL,"WmiQuerySingleInstanceMultipleW");
    p[797] = GetProcAddress(hL,"WmiQuerySingleInstanceW");
    p[798] = GetProcAddress(hL,"WmiReceiveNotificationsA");
    p[799] = GetProcAddress(hL,"WmiReceiveNotificationsW");
    p[800] = GetProcAddress(hL,"WmiSetSingleInstanceA");
    p[801] = GetProcAddress(hL,"WmiSetSingleInstanceW");
    p[802] = GetProcAddress(hL,"WmiSetSingleItemA");
    p[803] = GetProcAddress(hL,"WmiSetSingleItemW");
    p[804] = GetProcAddress(hL,"WriteEncryptedFileRaw");
    p[805] = GetProcAddress(hL,(LPCSTR)"1000");
}

void FinalizeADVAPI32()
{
    FreeLibrary(hL);
}

extern "C" __declspec(naked) void __stdcall __E__0__()
{
    __asm
    {
        jmp p[0*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__1__()
{
    __asm
    {
        jmp p[1*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__2__()
{
    __asm
    {
        jmp p[2*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__3__()
{
    __asm
    {
        jmp p[3*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__4__()
{
    __asm
    {
        jmp p[4*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__5__()
{
    __asm
    {
        jmp p[5*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__6__()
{
    __asm
    {
        jmp p[6*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__7__()
{
    __asm
    {
        jmp p[7*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__8__()
{
    __asm
    {
        jmp p[8*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__9__()
{
    __asm
    {
        jmp p[9*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__10__()
{
    __asm
    {
        jmp p[10*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__11__()
{
    __asm
    {
        jmp p[11*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__12__()
{
    __asm
    {
        jmp p[12*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__13__()
{
    __asm
    {
        jmp p[13*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__14__()
{
    __asm
    {
        jmp p[14*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__15__()
{
    __asm
    {
        jmp p[15*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__16__()
{
    __asm
    {
        jmp p[16*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__17__()
{
    __asm
    {
        jmp p[17*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__18__()
{
    __asm
    {
        jmp p[18*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__19__()
{
    __asm
    {
        jmp p[19*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__20__()
{
    __asm
    {
        jmp p[20*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__21__()
{
    __asm
    {
        jmp p[21*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__22__()
{
    __asm
    {
        jmp p[22*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__23__()
{
    __asm
    {
        jmp p[23*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__24__()
{
    __asm
    {
        jmp p[24*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__25__()
{
    __asm
    {
        jmp p[25*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__26__()
{
    __asm
    {
        jmp p[26*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__27__()
{
    __asm
    {
        jmp p[27*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__28__()
{
    __asm
    {
        jmp p[28*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__29__()
{
    __asm
    {
        jmp p[29*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__30__()
{
    __asm
    {
        jmp p[30*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__31__()
{
    __asm
    {
        jmp p[31*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__32__()
{
    __asm
    {
        jmp p[32*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__33__()
{
    __asm
    {
        jmp p[33*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__34__()
{
    __asm
    {
        jmp p[34*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__35__()
{
    __asm
    {
        jmp p[35*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__36__()
{
    __asm
    {
        jmp p[36*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__37__()
{
    __asm
    {
        jmp p[37*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__38__()
{
    __asm
    {
        jmp p[38*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__39__()
{
    __asm
    {
        jmp p[39*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__40__()
{
    __asm
    {
        jmp p[40*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__41__()
{
    __asm
    {
        jmp p[41*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__42__()
{
    __asm
    {
        jmp p[42*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__43__()
{
    __asm
    {
        jmp p[43*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__44__()
{
    __asm
    {
        jmp p[44*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__45__()
{
    __asm
    {
        jmp p[45*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__46__()
{
    __asm
    {
        jmp p[46*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__47__()
{
    __asm
    {
        jmp p[47*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__48__()
{
    __asm
    {
        jmp p[48*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__49__()
{
    __asm
    {
        jmp p[49*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__50__()
{
    __asm
    {
        jmp p[50*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__51__()
{
    __asm
    {
        jmp p[51*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__52__()
{
    __asm
    {
        jmp p[52*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__53__()
{
    __asm
    {
        jmp p[53*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__54__()
{
    __asm
    {
        jmp p[54*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__55__()
{
    __asm
    {
        jmp p[55*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__56__()
{
    __asm
    {
        jmp p[56*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__57__()
{
    __asm
    {
        jmp p[57*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__58__()
{
    __asm
    {
        jmp p[58*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__59__()
{
    __asm
    {
        jmp p[59*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__60__()
{
    __asm
    {
        jmp p[60*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__61__()
{
    __asm
    {
        jmp p[61*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__62__()
{
    __asm
    {
        jmp p[62*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__63__()
{
    __asm
    {
        jmp p[63*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__64__()
{
    __asm
    {
        jmp p[64*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__65__()
{
    __asm
    {
        jmp p[65*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__66__()
{
    __asm
    {
        jmp p[66*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__67__()
{
    __asm
    {
        jmp p[67*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__68__()
{
    __asm
    {
        jmp p[68*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__69__()
{
    __asm
    {
        jmp p[69*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__70__()
{
    __asm
    {
        jmp p[70*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__71__()
{
    __asm
    {
        jmp p[71*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__72__()
{
    __asm
    {
        jmp p[72*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__73__()
{
    __asm
    {
        jmp p[73*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__74__()
{
    __asm
    {
        jmp p[74*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__75__()
{
    __asm
    {
        jmp p[75*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__76__()
{
    __asm
    {
        jmp p[76*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__77__()
{
    __asm
    {
        jmp p[77*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__78__()
{
    __asm
    {
        jmp p[78*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__79__()
{
    __asm
    {
        jmp p[79*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__80__()
{
    __asm
    {
        jmp p[80*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__81__()
{
    __asm
    {
        jmp p[81*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__82__()
{
    __asm
    {
        jmp p[82*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__83__()
{
    __asm
    {
        jmp p[83*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__84__()
{
    __asm
    {
        jmp p[84*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__85__()
{
    __asm
    {
        jmp p[85*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__86__()
{
    __asm
    {
        jmp p[86*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__87__()
{
    __asm
    {
        jmp p[87*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__88__()
{
    __asm
    {
        jmp p[88*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__89__()
{
    __asm
    {
        jmp p[89*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__90__()
{
    __asm
    {
        jmp p[90*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__91__()
{
    __asm
    {
        jmp p[91*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__92__()
{
    __asm
    {
        jmp p[92*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__93__()
{
    __asm
    {
        jmp p[93*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__94__()
{
    __asm
    {
        jmp p[94*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__95__()
{
    __asm
    {
        jmp p[95*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__96__()
{
    __asm
    {
        jmp p[96*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__97__()
{
    __asm
    {
        jmp p[97*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__98__()
{
    __asm
    {
        jmp p[98*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__99__()
{
    __asm
    {
        jmp p[99*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__100__()
{
    __asm
    {
        jmp p[100*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__101__()
{
    __asm
    {
        jmp p[101*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__102__()
{
    __asm
    {
        jmp p[102*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__103__()
{
    __asm
    {
        jmp p[103*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__104__()
{
    __asm
    {
        jmp p[104*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__105__()
{
    __asm
    {
        jmp p[105*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__106__()
{
    __asm
    {
        jmp p[106*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__107__()
{
    __asm
    {
        jmp p[107*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__108__()
{
    __asm
    {
        jmp p[108*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__109__()
{
    __asm
    {
        jmp p[109*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__110__()
{
    __asm
    {
        jmp p[110*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__111__()
{
    __asm
    {
        jmp p[111*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__112__()
{
    __asm
    {
        jmp p[112*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__113__()
{
    __asm
    {
        jmp p[113*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__114__()
{
    __asm
    {
        jmp p[114*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__115__()
{
    __asm
    {
        jmp p[115*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__116__()
{
    __asm
    {
        jmp p[116*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__117__()
{
    __asm
    {
        jmp p[117*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__118__()
{
    __asm
    {
        jmp p[118*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__119__()
{
    __asm
    {
        jmp p[119*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__120__()
{
    __asm
    {
        jmp p[120*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__121__()
{
    __asm
    {
        jmp p[121*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__122__()
{
    __asm
    {
        jmp p[122*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__123__()
{
    __asm
    {
        jmp p[123*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__124__()
{
    __asm
    {
        jmp p[124*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__125__()
{
    __asm
    {
        jmp p[125*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__126__()
{
    __asm
    {
        jmp p[126*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__127__()
{
    __asm
    {
        jmp p[127*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__128__()
{
    __asm
    {
        jmp p[128*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__129__()
{
    __asm
    {
        jmp p[129*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__130__()
{
    __asm
    {
        jmp p[130*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__131__()
{
    __asm
    {
        jmp p[131*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__132__()
{
    __asm
    {
        jmp p[132*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__133__()
{
    __asm
    {
        jmp p[133*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__134__()
{
    __asm
    {
        jmp p[134*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__135__()
{
    __asm
    {
        jmp p[135*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__136__()
{
    __asm
    {
        jmp p[136*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__137__()
{
    __asm
    {
        jmp p[137*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__138__()
{
    __asm
    {
        jmp p[138*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__139__()
{
    __asm
    {
        jmp p[139*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__140__()
{
    __asm
    {
        jmp p[140*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__141__()
{
    __asm
    {
        jmp p[141*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__142__()
{
    __asm
    {
        jmp p[142*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__143__()
{
    __asm
    {
        jmp p[143*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__144__()
{
    __asm
    {
        jmp p[144*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__145__()
{
    __asm
    {
        jmp p[145*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__146__()
{
    __asm
    {
        jmp p[146*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__147__()
{
    __asm
    {
        jmp p[147*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__148__()
{
    __asm
    {
        jmp p[148*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__149__()
{
    __asm
    {
        jmp p[149*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__150__()
{
    __asm
    {
        jmp p[150*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__151__()
{
    __asm
    {
        jmp p[151*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__152__()
{
    __asm
    {
        jmp p[152*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__153__()
{
    __asm
    {
        jmp p[153*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__154__()
{
    __asm
    {
        jmp p[154*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__155__()
{
    __asm
    {
        jmp p[155*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__156__()
{
    __asm
    {
        jmp p[156*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__157__()
{
    __asm
    {
        jmp p[157*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__158__()
{
    __asm
    {
        jmp p[158*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__159__()
{
    __asm
    {
        jmp p[159*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__160__()
{
    __asm
    {
        jmp p[160*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__161__()
{
    __asm
    {
        jmp p[161*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__162__()
{
    __asm
    {
        jmp p[162*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__163__()
{
    __asm
    {
        jmp p[163*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__164__()
{
    __asm
    {
        jmp p[164*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__165__()
{
    __asm
    {
        jmp p[165*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__166__()
{
    __asm
    {
        jmp p[166*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__167__()
{
    __asm
    {
        jmp p[167*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__168__()
{
    __asm
    {
        jmp p[168*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__169__()
{
    __asm
    {
        jmp p[169*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__170__()
{
    __asm
    {
        jmp p[170*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__171__()
{
    __asm
    {
        jmp p[171*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__172__()
{
    __asm
    {
        jmp p[172*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__173__()
{
    __asm
    {
        jmp p[173*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__174__()
{
    __asm
    {
        jmp p[174*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__175__()
{
    __asm
    {
        jmp p[175*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__176__()
{
    __asm
    {
        jmp p[176*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__177__()
{
    __asm
    {
        jmp p[177*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__178__()
{
    __asm
    {
        jmp p[178*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__179__()
{
    __asm
    {
        jmp p[179*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__180__()
{
    __asm
    {
        jmp p[180*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__181__()
{
    __asm
    {
        jmp p[181*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__182__()
{
    __asm
    {
        jmp p[182*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__183__()
{
    __asm
    {
        jmp p[183*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__184__()
{
    __asm
    {
        jmp p[184*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__185__()
{
    __asm
    {
        jmp p[185*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__186__()
{
    __asm
    {
        jmp p[186*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__187__()
{
    __asm
    {
        jmp p[187*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__188__()
{
    __asm
    {
        jmp p[188*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__189__()
{
    __asm
    {
        jmp p[189*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__190__()
{
    __asm
    {
        jmp p[190*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__191__()
{
    __asm
    {
        jmp p[191*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__192__()
{
    __asm
    {
        jmp p[192*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__193__()
{
    __asm
    {
        jmp p[193*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__194__()
{
    __asm
    {
        jmp p[194*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__195__()
{
    __asm
    {
        jmp p[195*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__196__()
{
    __asm
    {
        jmp p[196*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__197__()
{
    __asm
    {
        jmp p[197*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__198__()
{
    __asm
    {
        jmp p[198*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__199__()
{
    __asm
    {
        jmp p[199*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__200__()
{
    __asm
    {
        jmp p[200*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__201__()
{
    __asm
    {
        jmp p[201*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__202__()
{
    __asm
    {
        jmp p[202*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__203__()
{
    __asm
    {
        jmp p[203*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__204__()
{
    __asm
    {
        jmp p[204*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__205__()
{
    __asm
    {
        jmp p[205*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__206__()
{
    __asm
    {
        jmp p[206*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__207__()
{
    __asm
    {
        jmp p[207*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__208__()
{
    __asm
    {
        jmp p[208*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__209__()
{
    __asm
    {
        jmp p[209*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__210__()
{
    __asm
    {
        jmp p[210*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__211__()
{
    __asm
    {
        jmp p[211*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__212__()
{
    __asm
    {
        jmp p[212*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__213__()
{
    __asm
    {
        jmp p[213*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__214__()
{
    __asm
    {
        jmp p[214*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__215__()
{
    __asm
    {
        jmp p[215*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__216__()
{
    __asm
    {
        jmp p[216*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__217__()
{
    __asm
    {
        jmp p[217*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__218__()
{
    __asm
    {
        jmp p[218*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__219__()
{
    __asm
    {
        jmp p[219*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__220__()
{
    __asm
    {
        jmp p[220*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__221__()
{
    __asm
    {
        jmp p[221*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__222__()
{
    __asm
    {
        jmp p[222*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__223__()
{
    __asm
    {
        jmp p[223*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__224__()
{
    __asm
    {
        jmp p[224*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__225__()
{
    __asm
    {
        jmp p[225*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__226__()
{
    __asm
    {
        jmp p[226*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__227__()
{
    __asm
    {
        jmp p[227*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__228__()
{
    __asm
    {
        jmp p[228*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__229__()
{
    __asm
    {
        jmp p[229*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__230__()
{
    __asm
    {
        jmp p[230*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__231__()
{
    __asm
    {
        jmp p[231*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__232__()
{
    __asm
    {
        jmp p[232*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__233__()
{
    __asm
    {
        jmp p[233*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__234__()
{
    __asm
    {
        jmp p[234*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__235__()
{
    __asm
    {
        jmp p[235*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__236__()
{
    __asm
    {
        jmp p[236*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__237__()
{
    __asm
    {
        jmp p[237*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__238__()
{
    __asm
    {
        jmp p[238*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__239__()
{
    __asm
    {
        jmp p[239*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__240__()
{
    __asm
    {
        jmp p[240*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__241__()
{
    __asm
    {
        jmp p[241*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__242__()
{
    __asm
    {
        jmp p[242*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__243__()
{
    __asm
    {
        jmp p[243*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__244__()
{
    __asm
    {
        jmp p[244*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__245__()
{
    __asm
    {
        jmp p[245*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__246__()
{
    __asm
    {
        jmp p[246*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__247__()
{
    __asm
    {
        jmp p[247*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__248__()
{
    __asm
    {
        jmp p[248*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__249__()
{
    __asm
    {
        jmp p[249*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__250__()
{
    __asm
    {
        jmp p[250*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__251__()
{
    __asm
    {
        jmp p[251*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__252__()
{
    __asm
    {
        jmp p[252*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__253__()
{
    __asm
    {
        jmp p[253*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__254__()
{
    __asm
    {
        jmp p[254*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__255__()
{
    __asm
    {
        jmp p[255*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__256__()
{
    __asm
    {
        jmp p[256*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__257__()
{
    __asm
    {
        jmp p[257*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__258__()
{
    __asm
    {
        jmp p[258*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__259__()
{
    __asm
    {
        jmp p[259*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__260__()
{
    __asm
    {
        jmp p[260*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__261__()
{
    __asm
    {
        jmp p[261*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__262__()
{
    __asm
    {
        jmp p[262*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__263__()
{
    __asm
    {
        jmp p[263*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__264__()
{
    __asm
    {
        jmp p[264*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__265__()
{
    __asm
    {
        jmp p[265*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__266__()
{
    __asm
    {
        jmp p[266*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__267__()
{
    __asm
    {
        jmp p[267*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__268__()
{
    __asm
    {
        jmp p[268*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__269__()
{
    __asm
    {
        jmp p[269*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__270__()
{
    __asm
    {
        jmp p[270*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__271__()
{
    __asm
    {
        jmp p[271*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__272__()
{
    __asm
    {
        jmp p[272*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__273__()
{
    __asm
    {
        jmp p[273*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__274__()
{
    __asm
    {
        jmp p[274*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__275__()
{
    __asm
    {
        jmp p[275*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__276__()
{
    __asm
    {
        jmp p[276*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__277__()
{
    __asm
    {
        jmp p[277*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__278__()
{
    __asm
    {
        jmp p[278*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__279__()
{
    __asm
    {
        jmp p[279*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__280__()
{
    __asm
    {
        jmp p[280*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__281__()
{
    __asm
    {
        jmp p[281*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__282__()
{
    __asm
    {
        jmp p[282*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__283__()
{
    __asm
    {
        jmp p[283*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__284__()
{
    __asm
    {
        jmp p[284*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__285__()
{
    __asm
    {
        jmp p[285*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__286__()
{
    __asm
    {
        jmp p[286*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__287__()
{
    __asm
    {
        jmp p[287*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__288__()
{
    __asm
    {
        jmp p[288*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__289__()
{
    __asm
    {
        jmp p[289*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__290__()
{
    __asm
    {
        jmp p[290*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__291__()
{
    __asm
    {
        jmp p[291*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__292__()
{
    __asm
    {
        jmp p[292*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__293__()
{
    __asm
    {
        jmp p[293*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__294__()
{
    __asm
    {
        jmp p[294*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__295__()
{
    __asm
    {
        jmp p[295*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__296__()
{
    __asm
    {
        jmp p[296*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__297__()
{
    __asm
    {
        jmp p[297*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__298__()
{
    __asm
    {
        jmp p[298*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__299__()
{
    __asm
    {
        jmp p[299*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__300__()
{
    __asm
    {
        jmp p[300*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__301__()
{
    __asm
    {
        jmp p[301*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__302__()
{
    __asm
    {
        jmp p[302*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__303__()
{
    __asm
    {
        jmp p[303*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__304__()
{
    __asm
    {
        jmp p[304*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__305__()
{
    __asm
    {
        jmp p[305*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__306__()
{
    __asm
    {
        jmp p[306*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__307__()
{
    __asm
    {
        jmp p[307*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__308__()
{
    __asm
    {
        jmp p[308*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__309__()
{
    __asm
    {
        jmp p[309*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__310__()
{
    __asm
    {
        jmp p[310*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__311__()
{
    __asm
    {
        jmp p[311*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__312__()
{
    __asm
    {
        jmp p[312*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__313__()
{
    __asm
    {
        jmp p[313*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__314__()
{
    __asm
    {
        jmp p[314*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__315__()
{
    __asm
    {
        jmp p[315*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__316__()
{
    __asm
    {
        jmp p[316*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__317__()
{
    __asm
    {
        jmp p[317*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__318__()
{
    __asm
    {
        jmp p[318*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__319__()
{
    __asm
    {
        jmp p[319*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__320__()
{
    __asm
    {
        jmp p[320*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__321__()
{
    __asm
    {
        jmp p[321*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__322__()
{
    __asm
    {
        jmp p[322*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__323__()
{
    __asm
    {
        jmp p[323*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__324__()
{
    __asm
    {
        jmp p[324*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__325__()
{
    __asm
    {
        jmp p[325*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__326__()
{
    __asm
    {
        jmp p[326*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__327__()
{
    __asm
    {
        jmp p[327*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__328__()
{
    __asm
    {
        jmp p[328*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__329__()
{
    __asm
    {
        jmp p[329*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__330__()
{
    __asm
    {
        jmp p[330*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__331__()
{
    __asm
    {
        jmp p[331*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__332__()
{
    __asm
    {
        jmp p[332*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__333__()
{
    __asm
    {
        jmp p[333*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__334__()
{
    __asm
    {
        jmp p[334*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__335__()
{
    __asm
    {
        jmp p[335*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__336__()
{
    __asm
    {
        jmp p[336*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__337__()
{
    __asm
    {
        jmp p[337*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__338__()
{
    __asm
    {
        jmp p[338*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__339__()
{
    __asm
    {
        jmp p[339*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__340__()
{
    __asm
    {
        jmp p[340*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__341__()
{
    __asm
    {
        jmp p[341*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__342__()
{
    __asm
    {
        jmp p[342*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__343__()
{
    __asm
    {
        jmp p[343*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__344__()
{
    __asm
    {
        jmp p[344*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__345__()
{
    __asm
    {
        jmp p[345*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__346__()
{
    __asm
    {
        jmp p[346*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__347__()
{
    __asm
    {
        jmp p[347*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__348__()
{
    __asm
    {
        jmp p[348*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__349__()
{
    __asm
    {
        jmp p[349*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__350__()
{
    __asm
    {
        jmp p[350*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__351__()
{
    __asm
    {
        jmp p[351*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__352__()
{
    __asm
    {
        jmp p[352*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__353__()
{
    __asm
    {
        jmp p[353*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__354__()
{
    __asm
    {
        jmp p[354*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__355__()
{
    __asm
    {
        jmp p[355*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__356__()
{
    __asm
    {
        jmp p[356*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__357__()
{
    __asm
    {
        jmp p[357*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__358__()
{
    __asm
    {
        jmp p[358*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__359__()
{
    __asm
    {
        jmp p[359*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__360__()
{
    __asm
    {
        jmp p[360*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__361__()
{
    __asm
    {
        jmp p[361*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__362__()
{
    __asm
    {
        jmp p[362*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__363__()
{
    __asm
    {
        jmp p[363*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__364__()
{
    __asm
    {
        jmp p[364*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__365__()
{
    __asm
    {
        jmp p[365*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__366__()
{
    __asm
    {
        jmp p[366*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__367__()
{
    __asm
    {
        jmp p[367*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__368__()
{
    __asm
    {
        jmp p[368*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__369__()
{
    __asm
    {
        jmp p[369*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__370__()
{
    __asm
    {
        jmp p[370*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__371__()
{
    __asm
    {
        jmp p[371*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__372__()
{
    __asm
    {
        jmp p[372*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__373__()
{
    __asm
    {
        jmp p[373*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__374__()
{
    __asm
    {
        jmp p[374*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__375__()
{
    __asm
    {
        jmp p[375*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__376__()
{
    __asm
    {
        jmp p[376*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__377__()
{
    __asm
    {
        jmp p[377*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__378__()
{
    __asm
    {
        jmp p[378*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__379__()
{
    __asm
    {
        jmp p[379*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__380__()
{
    __asm
    {
        jmp p[380*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__381__()
{
    __asm
    {
        jmp p[381*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__382__()
{
    __asm
    {
        jmp p[382*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__383__()
{
    __asm
    {
        jmp p[383*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__384__()
{
    __asm
    {
        jmp p[384*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__385__()
{
    __asm
    {
        jmp p[385*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__386__()
{
    __asm
    {
        jmp p[386*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__387__()
{
    __asm
    {
        jmp p[387*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__388__()
{
    __asm
    {
        jmp p[388*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__389__()
{
    __asm
    {
        jmp p[389*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__390__()
{
    __asm
    {
        jmp p[390*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__391__()
{
    __asm
    {
        jmp p[391*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__392__()
{
    __asm
    {
        jmp p[392*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__393__()
{
    __asm
    {
        jmp p[393*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__394__()
{
    __asm
    {
        jmp p[394*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__395__()
{
    __asm
    {
        jmp p[395*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__396__()
{
    __asm
    {
        jmp p[396*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__397__()
{
    __asm
    {
        jmp p[397*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__398__()
{
    __asm
    {
        jmp p[398*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__399__()
{
    __asm
    {
        jmp p[399*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__400__()
{
    __asm
    {
        jmp p[400*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__401__()
{
    __asm
    {
        jmp p[401*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__402__()
{
    __asm
    {
        jmp p[402*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__403__()
{
    __asm
    {
        jmp p[403*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__404__()
{
    __asm
    {
        jmp p[404*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__405__()
{
    __asm
    {
        jmp p[405*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__406__()
{
    __asm
    {
        jmp p[406*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__407__()
{
    __asm
    {
        jmp p[407*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__408__()
{
    __asm
    {
        jmp p[408*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__409__()
{
    __asm
    {
        jmp p[409*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__410__()
{
    __asm
    {
        jmp p[410*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__411__()
{
    __asm
    {
        jmp p[411*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__412__()
{
    __asm
    {
        jmp p[412*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__413__()
{
    __asm
    {
        jmp p[413*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__414__()
{
    __asm
    {
        jmp p[414*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__415__()
{
    __asm
    {
        jmp p[415*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__416__()
{
    __asm
    {
        jmp p[416*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__417__()
{
    __asm
    {
        jmp p[417*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__418__()
{
    __asm
    {
        jmp p[418*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__419__()
{
    __asm
    {
        jmp p[419*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__420__()
{
    __asm
    {
        jmp p[420*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__421__()
{
    __asm
    {
        jmp p[421*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__422__()
{
    __asm
    {
        jmp p[422*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__423__()
{
    __asm
    {
        jmp p[423*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__424__()
{
    __asm
    {
        jmp p[424*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__425__()
{
    __asm
    {
        jmp p[425*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__426__()
{
    __asm
    {
        jmp p[426*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__427__()
{
    __asm
    {
        jmp p[427*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__428__()
{
    __asm
    {
        jmp p[428*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__429__()
{
    __asm
    {
        jmp p[429*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__430__()
{
    __asm
    {
        jmp p[430*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__431__()
{
    __asm
    {
        jmp p[431*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__432__()
{
    __asm
    {
        jmp p[432*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__433__()
{
    __asm
    {
        jmp p[433*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__434__()
{
    __asm
    {
        jmp p[434*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__435__()
{
    __asm
    {
        jmp p[435*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__436__()
{
    __asm
    {
        jmp p[436*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__437__()
{
    __asm
    {
        jmp p[437*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__438__()
{
    __asm
    {
        jmp p[438*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__439__()
{
    __asm
    {
        jmp p[439*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__440__()
{
    __asm
    {
        jmp p[440*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__441__()
{
    __asm
    {
        jmp p[441*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__442__()
{
    __asm
    {
        jmp p[442*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__443__()
{
    __asm
    {
        jmp p[443*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__444__()
{
    __asm
    {
        jmp p[444*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__445__()
{
    __asm
    {
        jmp p[445*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__446__()
{
    __asm
    {
        jmp p[446*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__447__()
{
    __asm
    {
        jmp p[447*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__448__()
{
    __asm
    {
        jmp p[448*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__449__()
{
    __asm
    {
        jmp p[449*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__450__()
{
    __asm
    {
        jmp p[450*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__451__()
{
    __asm
    {
        jmp p[451*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__452__()
{
    __asm
    {
        jmp p[452*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__453__()
{
    __asm
    {
        jmp p[453*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__454__()
{
    __asm
    {
        jmp p[454*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__455__()
{
    __asm
    {
        jmp p[455*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__456__()
{
    __asm
    {
        jmp p[456*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__457__()
{
    __asm
    {
        jmp p[457*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__458__()
{
    __asm
    {
        jmp p[458*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__459__()
{
    __asm
    {
        jmp p[459*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__460__()
{
    __asm
    {
        jmp p[460*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__461__()
{
    __asm
    {
        jmp p[461*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__462__()
{
    __asm
    {
        jmp p[462*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__463__()
{
    __asm
    {
        jmp p[463*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__464__()
{
    __asm
    {
        jmp p[464*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__465__()
{
    __asm
    {
        jmp p[465*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__466__()
{
    __asm
    {
        jmp p[466*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__467__()
{
    __asm
    {
        jmp p[467*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__468__()
{
    __asm
    {
        jmp p[468*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__469__()
{
    __asm
    {
        jmp p[469*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__470__()
{
    __asm
    {
        jmp p[470*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__471__()
{
    __asm
    {
        jmp p[471*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__472__()
{
    __asm
    {
        jmp p[472*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__473__()
{
    __asm
    {
        jmp p[473*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__474__()
{
    __asm
    {
        jmp p[474*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__475__()
{
    __asm
    {
        jmp p[475*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__476__()
{
    __asm
    {
        jmp p[476*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__477__()
{
    __asm
    {
        jmp p[477*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__478__()
{
    __asm
    {
        jmp p[478*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__479__()
{
    __asm
    {
        jmp p[479*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__480__()
{
    __asm
    {
        jmp p[480*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__481__()
{
    __asm
    {
        jmp p[481*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__482__()
{
    __asm
    {
        jmp p[482*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__483__()
{
    __asm
    {
        jmp p[483*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__484__()
{
    __asm
    {
        jmp p[484*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__485__()
{
    __asm
    {
        jmp p[485*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__486__()
{
    __asm
    {
        jmp p[486*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__487__()
{
    __asm
    {
        jmp p[487*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__488__()
{
    __asm
    {
        jmp p[488*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__489__()
{
    __asm
    {
        jmp p[489*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__490__()
{
    __asm
    {
        jmp p[490*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__491__()
{
    __asm
    {
        jmp p[491*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__492__()
{
    __asm
    {
        jmp p[492*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__493__()
{
    __asm
    {
        jmp p[493*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__494__()
{
    __asm
    {
        jmp p[494*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__495__()
{
    __asm
    {
        jmp p[495*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__496__()
{
    __asm
    {
        jmp p[496*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__497__()
{
    __asm
    {
        jmp p[497*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__498__()
{
    __asm
    {
        jmp p[498*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__499__()
{
    __asm
    {
        jmp p[499*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__500__()
{
    __asm
    {
        jmp p[500*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__501__()
{
    __asm
    {
        jmp p[501*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__502__()
{
    __asm
    {
        jmp p[502*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__503__()
{
    __asm
    {
        jmp p[503*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__504__()
{
    __asm
    {
        jmp p[504*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__505__()
{
    __asm
    {
        jmp p[505*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__506__()
{
    __asm
    {
        jmp p[506*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__507__()
{
    __asm
    {
        jmp p[507*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__508__()
{
    __asm
    {
        jmp p[508*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__509__()
{
    __asm
    {
        jmp p[509*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__510__()
{
    __asm
    {
        jmp p[510*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__511__()
{
    __asm
    {
        jmp p[511*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__512__()
{
    __asm
    {
        jmp p[512*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__513__()
{
    __asm
    {
        jmp p[513*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__514__()
{
    __asm
    {
        jmp p[514*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__515__()
{
    __asm
    {
        jmp p[515*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__516__()
{
    __asm
    {
        jmp p[516*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__517__()
{
    __asm
    {
        jmp p[517*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__518__()
{
    __asm
    {
        jmp p[518*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__519__()
{
    __asm
    {
        jmp p[519*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__520__()
{
    __asm
    {
        jmp p[520*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__521__()
{
    __asm
    {
        jmp p[521*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__522__()
{
    __asm
    {
        jmp p[522*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__523__()
{
    __asm
    {
        jmp p[523*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__524__()
{
    __asm
    {
        jmp p[524*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__525__()
{
    __asm
    {
        jmp p[525*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__526__()
{
    __asm
    {
        jmp p[526*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__527__()
{
    __asm
    {
        jmp p[527*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__528__()
{
    __asm
    {
        jmp p[528*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__529__()
{
    __asm
    {
        jmp p[529*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__530__()
{
    __asm
    {
        jmp p[530*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__531__()
{
    __asm
    {
        jmp p[531*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__532__()
{
    __asm
    {
        jmp p[532*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__533__()
{
    __asm
    {
        jmp p[533*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__534__()
{
    __asm
    {
        jmp p[534*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__535__()
{
    __asm
    {
        jmp p[535*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__536__()
{
    __asm
    {
        jmp p[536*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__537__()
{
    __asm
    {
        jmp p[537*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__538__()
{
    __asm
    {
        jmp p[538*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__539__()
{
    __asm
    {
        jmp p[539*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__540__()
{
    __asm
    {
        jmp p[540*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__541__()
{
    __asm
    {
        jmp p[541*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__542__()
{
    __asm
    {
        jmp p[542*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__543__()
{
    __asm
    {
        jmp p[543*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__544__()
{
    __asm
    {
        jmp p[544*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__545__()
{
    __asm
    {
        jmp p[545*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__546__()
{
    __asm
    {
        jmp p[546*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__547__()
{
    __asm
    {
        jmp p[547*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__548__()
{
    __asm
    {
        jmp p[548*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__549__()
{
    __asm
    {
        jmp p[549*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__550__()
{
    __asm
    {
        jmp p[550*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__551__()
{
    __asm
    {
        jmp p[551*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__552__()
{
    __asm
    {
        jmp p[552*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__553__()
{
    __asm
    {
        jmp p[553*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__554__()
{
    __asm
    {
        jmp p[554*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__555__()
{
    __asm
    {
        jmp p[555*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__556__()
{
    __asm
    {
        jmp p[556*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__557__()
{
    __asm
    {
        jmp p[557*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__558__()
{
    __asm
    {
        jmp p[558*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__559__()
{
    __asm
    {
        jmp p[559*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__560__()
{
    __asm
    {
        jmp p[560*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__561__()
{
    __asm
    {
        jmp p[561*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__562__()
{
    __asm
    {
        jmp p[562*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__563__()
{
    __asm
    {
        jmp p[563*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__564__()
{
    __asm
    {
        jmp p[564*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__565__()
{
    __asm
    {
        jmp p[565*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__566__()
{
    __asm
    {
        jmp p[566*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__567__()
{
    __asm
    {
        jmp p[567*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__568__()
{
    __asm
    {
        jmp p[568*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__569__()
{
    __asm
    {
        jmp p[569*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__570__()
{
    __asm
    {
        jmp p[570*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__571__()
{
    __asm
    {
        jmp p[571*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__572__()
{
    __asm
    {
        jmp p[572*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__573__()
{
    __asm
    {
        jmp p[573*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__574__()
{
    __asm
    {
        jmp p[574*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__575__()
{
    __asm
    {
        jmp p[575*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__576__()
{
    __asm
    {
        jmp p[576*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__577__()
{
    __asm
    {
        jmp p[577*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__578__()
{
    __asm
    {
        jmp p[578*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__579__()
{
    __asm
    {
        jmp p[579*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__580__()
{
    __asm
    {
        jmp p[580*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__581__()
{
    __asm
    {
        jmp p[581*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__582__()
{
    __asm
    {
        jmp p[582*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__583__()
{
    __asm
    {
        jmp p[583*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__584__()
{
    __asm
    {
        jmp p[584*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__585__()
{
    __asm
    {
        jmp p[585*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__586__()
{
    __asm
    {
        jmp p[586*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__587__()
{
    __asm
    {
        jmp p[587*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__588__()
{
    __asm
    {
        jmp p[588*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__589__()
{
    __asm
    {
        jmp p[589*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__590__()
{
    __asm
    {
        jmp p[590*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__591__()
{
    __asm
    {
        jmp p[591*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__592__()
{
    __asm
    {
        jmp p[592*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__593__()
{
    __asm
    {
        jmp p[593*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__594__()
{
    __asm
    {
        jmp p[594*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__595__()
{
    __asm
    {
        jmp p[595*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__596__()
{
    __asm
    {
        jmp p[596*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__597__()
{
    __asm
    {
        jmp p[597*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__598__()
{
    __asm
    {
        jmp p[598*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__599__()
{
    __asm
    {
        jmp p[599*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__600__()
{
    __asm
    {
        jmp p[600*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__601__()
{
    __asm
    {
        jmp p[601*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__602__()
{
    __asm
    {
        jmp p[602*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__603__()
{
    __asm
    {
        jmp p[603*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__604__()
{
    __asm
    {
        jmp p[604*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__605__()
{
    __asm
    {
        jmp p[605*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__606__()
{
    __asm
    {
        jmp p[606*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__607__()
{
    __asm
    {
        jmp p[607*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__608__()
{
    __asm
    {
        jmp p[608*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__609__()
{
    __asm
    {
        jmp p[609*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__610__()
{
    __asm
    {
        jmp p[610*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__611__()
{
    __asm
    {
        jmp p[611*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__612__()
{
    __asm
    {
        jmp p[612*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__613__()
{
    __asm
    {
        jmp p[613*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__614__()
{
    __asm
    {
        jmp p[614*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__615__()
{
    __asm
    {
        jmp p[615*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__616__()
{
    __asm
    {
        jmp p[616*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__617__()
{
    __asm
    {
        jmp p[617*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__618__()
{
    __asm
    {
        jmp p[618*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__619__()
{
    __asm
    {
        jmp p[619*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__620__()
{
    __asm
    {
        jmp p[620*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__621__()
{
    __asm
    {
        jmp p[621*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__622__()
{
    __asm
    {
        jmp p[622*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__623__()
{
    __asm
    {
        jmp p[623*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__624__()
{
    __asm
    {
        jmp p[624*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__625__()
{
    __asm
    {
        jmp p[625*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__626__()
{
    __asm
    {
        jmp p[626*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__627__()
{
    __asm
    {
        jmp p[627*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__628__()
{
    __asm
    {
        jmp p[628*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__629__()
{
    __asm
    {
        jmp p[629*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__630__()
{
    __asm
    {
        jmp p[630*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__631__()
{
    __asm
    {
        jmp p[631*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__632__()
{
    __asm
    {
        jmp p[632*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__633__()
{
    __asm
    {
        jmp p[633*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__634__()
{
    __asm
    {
        jmp p[634*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__635__()
{
    __asm
    {
        jmp p[635*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__636__()
{
    __asm
    {
        jmp p[636*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__637__()
{
    __asm
    {
        jmp p[637*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__638__()
{
    __asm
    {
        jmp p[638*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__639__()
{
    __asm
    {
        jmp p[639*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__640__()
{
    __asm
    {
        jmp p[640*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__641__()
{
    __asm
    {
        jmp p[641*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__642__()
{
    __asm
    {
        jmp p[642*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__643__()
{
    __asm
    {
        jmp p[643*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__644__()
{
    __asm
    {
        jmp p[644*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__645__()
{
    __asm
    {
        jmp p[645*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__646__()
{
    __asm
    {
        jmp p[646*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__647__()
{
    __asm
    {
        jmp p[647*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__648__()
{
    __asm
    {
        jmp p[648*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__649__()
{
    __asm
    {
        jmp p[649*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__650__()
{
    __asm
    {
        jmp p[650*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__651__()
{
    __asm
    {
        jmp p[651*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__652__()
{
    __asm
    {
        jmp p[652*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__653__()
{
    __asm
    {
        jmp p[653*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__654__()
{
    __asm
    {
        jmp p[654*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__655__()
{
    __asm
    {
        jmp p[655*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__656__()
{
    __asm
    {
        jmp p[656*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__657__()
{
    __asm
    {
        jmp p[657*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__658__()
{
    __asm
    {
        jmp p[658*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__659__()
{
    __asm
    {
        jmp p[659*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__660__()
{
    __asm
    {
        jmp p[660*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__661__()
{
    __asm
    {
        jmp p[661*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__662__()
{
    __asm
    {
        jmp p[662*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__663__()
{
    __asm
    {
        jmp p[663*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__664__()
{
    __asm
    {
        jmp p[664*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__665__()
{
    __asm
    {
        jmp p[665*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__666__()
{
    __asm
    {
        jmp p[666*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__667__()
{
    __asm
    {
        jmp p[667*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__668__()
{
    __asm
    {
        jmp p[668*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__669__()
{
    __asm
    {
        jmp p[669*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__670__()
{
    __asm
    {
        jmp p[670*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__671__()
{
    __asm
    {
        jmp p[671*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__672__()
{
    __asm
    {
        jmp p[672*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__673__()
{
    __asm
    {
        jmp p[673*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__674__()
{
    __asm
    {
        jmp p[674*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__675__()
{
    __asm
    {
        jmp p[675*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__676__()
{
    __asm
    {
        jmp p[676*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__677__()
{
    __asm
    {
        jmp p[677*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__678__()
{
    __asm
    {
        jmp p[678*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__679__()
{
    __asm
    {
        jmp p[679*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__680__()
{
    __asm
    {
        jmp p[680*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__681__()
{
    __asm
    {
        jmp p[681*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__682__()
{
    __asm
    {
        jmp p[682*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__683__()
{
    __asm
    {
        jmp p[683*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__684__()
{
    __asm
    {
        jmp p[684*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__685__()
{
    __asm
    {
        jmp p[685*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__686__()
{
    __asm
    {
        jmp p[686*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__687__()
{
    __asm
    {
        jmp p[687*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__688__()
{
    __asm
    {
        jmp p[688*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__689__()
{
    __asm
    {
        jmp p[689*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__690__()
{
    __asm
    {
        jmp p[690*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__691__()
{
    __asm
    {
        jmp p[691*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__692__()
{
    __asm
    {
        jmp p[692*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__693__()
{
    __asm
    {
        jmp p[693*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__694__()
{
    __asm
    {
        jmp p[694*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__695__()
{
    __asm
    {
        jmp p[695*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__696__()
{
    __asm
    {
        jmp p[696*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__697__()
{
    __asm
    {
        jmp p[697*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__698__()
{
    __asm
    {
        jmp p[698*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__699__()
{
    __asm
    {
        jmp p[699*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__700__()
{
    __asm
    {
        jmp p[700*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__701__()
{
    __asm
    {
        jmp p[701*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__702__()
{
    __asm
    {
        jmp p[702*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__703__()
{
    __asm
    {
        jmp p[703*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__704__()
{
    __asm
    {
        jmp p[704*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__705__()
{
    __asm
    {
        jmp p[705*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__706__()
{
    __asm
    {
        jmp p[706*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__707__()
{
    __asm
    {
        jmp p[707*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__708__()
{
    __asm
    {
        jmp p[708*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__709__()
{
    __asm
    {
        jmp p[709*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__710__()
{
    __asm
    {
        jmp p[710*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__711__()
{
    __asm
    {
        jmp p[711*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__712__()
{
    __asm
    {
        jmp p[712*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__713__()
{
    __asm
    {
        jmp p[713*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__714__()
{
    __asm
    {
        jmp p[714*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__715__()
{
    __asm
    {
        jmp p[715*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__716__()
{
    __asm
    {
        jmp p[716*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__717__()
{
    __asm
    {
        jmp p[717*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__718__()
{
    __asm
    {
        jmp p[718*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__719__()
{
    __asm
    {
        jmp p[719*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__720__()
{
    __asm
    {
        jmp p[720*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__721__()
{
    __asm
    {
        jmp p[721*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__722__()
{
    __asm
    {
        jmp p[722*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__723__()
{
    __asm
    {
        jmp p[723*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__724__()
{
    __asm
    {
        jmp p[724*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__725__()
{
    __asm
    {
        jmp p[725*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__726__()
{
    __asm
    {
        jmp p[726*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__727__()
{
    __asm
    {
        jmp p[727*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__728__()
{
    __asm
    {
        jmp p[728*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__729__()
{
    __asm
    {
        jmp p[729*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__730__()
{
    __asm
    {
        jmp p[730*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__731__()
{
    __asm
    {
        jmp p[731*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__732__()
{
    __asm
    {
        jmp p[732*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__733__()
{
    __asm
    {
        jmp p[733*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__734__()
{
    __asm
    {
        jmp p[734*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__735__()
{
    __asm
    {
        jmp p[735*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__736__()
{
    __asm
    {
        jmp p[736*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__737__()
{
    __asm
    {
        jmp p[737*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__738__()
{
    __asm
    {
        jmp p[738*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__739__()
{
    __asm
    {
        jmp p[739*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__740__()
{
    __asm
    {
        jmp p[740*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__741__()
{
    __asm
    {
        jmp p[741*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__742__()
{
    __asm
    {
        jmp p[742*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__743__()
{
    __asm
    {
        jmp p[743*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__744__()
{
    __asm
    {
        jmp p[744*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__745__()
{
    __asm
    {
        jmp p[745*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__746__()
{
    __asm
    {
        jmp p[746*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__747__()
{
    __asm
    {
        jmp p[747*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__748__()
{
    __asm
    {
        jmp p[748*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__749__()
{
    __asm
    {
        jmp p[749*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__750__()
{
    __asm
    {
        jmp p[750*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__751__()
{
    __asm
    {
        jmp p[751*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__752__()
{
    __asm
    {
        jmp p[752*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__753__()
{
    __asm
    {
        jmp p[753*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__754__()
{
    __asm
    {
        jmp p[754*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__755__()
{
    __asm
    {
        jmp p[755*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__756__()
{
    __asm
    {
        jmp p[756*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__757__()
{
    __asm
    {
        jmp p[757*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__758__()
{
    __asm
    {
        jmp p[758*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__759__()
{
    __asm
    {
        jmp p[759*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__760__()
{
    __asm
    {
        jmp p[760*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__761__()
{
    __asm
    {
        jmp p[761*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__762__()
{
    __asm
    {
        jmp p[762*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__763__()
{
    __asm
    {
        jmp p[763*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__764__()
{
    __asm
    {
        jmp p[764*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__765__()
{
    __asm
    {
        jmp p[765*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__766__()
{
    __asm
    {
        jmp p[766*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__767__()
{
    __asm
    {
        jmp p[767*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__768__()
{
    __asm
    {
        jmp p[768*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__769__()
{
    __asm
    {
        jmp p[769*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__770__()
{
    __asm
    {
        jmp p[770*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__771__()
{
    __asm
    {
        jmp p[771*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__772__()
{
    __asm
    {
        jmp p[772*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__773__()
{
    __asm
    {
        jmp p[773*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__774__()
{
    __asm
    {
        jmp p[774*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__775__()
{
    __asm
    {
        jmp p[775*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__776__()
{
    __asm
    {
        jmp p[776*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__777__()
{
    __asm
    {
        jmp p[777*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__778__()
{
    __asm
    {
        jmp p[778*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__779__()
{
    __asm
    {
        jmp p[779*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__780__()
{
    __asm
    {
        jmp p[780*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__781__()
{
    __asm
    {
        jmp p[781*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__782__()
{
    __asm
    {
        jmp p[782*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__783__()
{
    __asm
    {
        jmp p[783*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__784__()
{
    __asm
    {
        jmp p[784*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__785__()
{
    __asm
    {
        jmp p[785*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__786__()
{
    __asm
    {
        jmp p[786*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__787__()
{
    __asm
    {
        jmp p[787*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__788__()
{
    __asm
    {
        jmp p[788*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__789__()
{
    __asm
    {
        jmp p[789*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__790__()
{
    __asm
    {
        jmp p[790*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__791__()
{
    __asm
    {
        jmp p[791*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__792__()
{
    __asm
    {
        jmp p[792*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__793__()
{
    __asm
    {
        jmp p[793*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__794__()
{
    __asm
    {
        jmp p[794*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__795__()
{
    __asm
    {
        jmp p[795*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__796__()
{
    __asm
    {
        jmp p[796*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__797__()
{
    __asm
    {
        jmp p[797*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__798__()
{
    __asm
    {
        jmp p[798*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__799__()
{
    __asm
    {
        jmp p[799*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__800__()
{
    __asm
    {
        jmp p[800*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__801__()
{
    __asm
    {
        jmp p[801*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__802__()
{
    __asm
    {
        jmp p[802*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__803__()
{
    __asm
    {
        jmp p[803*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__804__()
{
    __asm
    {
        jmp p[804*4];
    }
}

extern "C" __declspec(naked) void __stdcall __E__805__()
{
    __asm
    {
        jmp p[805*4];
    }
}