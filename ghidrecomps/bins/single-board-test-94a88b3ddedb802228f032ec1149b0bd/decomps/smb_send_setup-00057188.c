
undefined4 smb_send_setup(undefined4 *param_1)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 auStack_4a8 [24];
  undefined1 auStack_490 [24];
  undefined4 local_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined4 local_468;
  undefined4 uStack_464;
  undefined4 local_460;
  undefined4 uStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  undefined4 local_450;
  undefined4 uStack_44c;
  undefined1 local_448;
  undefined1 local_447;
  undefined4 local_444;
  undefined1 local_440;
  undefined2 uStack_43f;
  undefined4 uStack_43d;
  undefined1 local_439;
  uint local_438;
  undefined1 local_431;
  undefined4 local_430;
  undefined1 uStack_42c;
  undefined4 local_42b;
  undefined4 local_427;
  undefined4 local_423;
  undefined4 local_41f;
  undefined4 local_41b;
  undefined4 local_417;
  undefined4 local_413;
  undefined4 local_40f;
  undefined4 local_40b;
  undefined4 local_407;
  undefined4 local_403;
  undefined4 local_3ff;
  char cStack_3fb;
  char acStack_3fa [5];
  char acStack_3f5 [4];
  char acStack_3f1 [4];
  char acStack_3ed [4];
  char acStack_3e9 [4];
  char acStack_3e5 [6];
  char acStack_3df [30];
  char acStack_3c1 [925];
  
  sVar1 = strlen((char *)param_1[0xf1]);
  sVar2 = strlen((char *)param_1[0xf2]);
  if (sVar1 + sVar2 + 0x4d < 0x401) {
    Curl_ntlm_core_mk_lm_hash(*param_1,param_1[0x49],auStack_4a8);
    Curl_ntlm_core_lm_resp(auStack_4a8,param_1 + 0xf3,&local_478);
    Curl_ntlm_core_mk_nt_hash(*param_1,param_1[0x49],auStack_490);
    Curl_ntlm_core_lm_resp(auStack_490,param_1 + 0xf3,&local_460);
    memset(&local_448,0,0x41d);
    uStack_43d = param_1[0xf5];
    local_430 = local_430 & 0xff000000;
    local_438 = (local_438 >> 8 & 0xff0000) << 8 | 0x1800;
    local_440 = 0;
    uStack_43f = 1;
    local_444 = 0x1900000;
    local_431 = 8;
    local_439 = 0x18;
    local_448 = 0xd;
    local_447 = 0xff;
    local_427 = uStack_474;
    local_42b = local_478;
    local_423 = uStack_470;
    local_41f = uStack_46c;
    local_41b = local_468;
    local_417 = uStack_464;
    local_413 = local_460;
    local_40f = uStack_45c;
    pcVar4 = (char *)param_1[0xf1];
    local_407 = uStack_454;
    local_403 = local_450;
    local_3ff = uStack_44c;
    local_40b = uStack_458;
    strcpy(&cStack_3fb,pcVar4);
    sVar1 = strlen(pcVar4);
    pcVar4 = (char *)param_1[0xf2];
    pcVar5 = acStack_3fa + sVar1;
    strcpy(pcVar5,pcVar4);
    sVar2 = strlen(pcVar4);
    pcVar5 = pcVar5 + ((sVar2 + 0x1c) - (int)&local_42b);
    builtin_strncpy(acStack_3fa + sVar2 + sVar1 + 1,"arm-unknown-linux-gnu",0x16);
    builtin_strncpy(acStack_3fa + sVar2 + sVar1 + 0x17,"curl",5);
    local_430._3_1_ = SUB41(pcVar5,0);
    uStack_42c = (undefined1)((uint)pcVar5 >> 8);
    uVar3 = smb_send_message(param_1,0x73,&local_448,pcVar5 + 0x1d);
  }
  else {
    uVar3 = 0x3f;
  }
  return uVar3;
}

