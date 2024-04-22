
undefined4 getaddressinfo(short *param_1,char *param_2,uint *param_3,undefined4 param_4)

{
  short sVar1;
  char *pcVar2;
  
  sVar1 = *param_1;
  if (sVar1 == 2) {
    pcVar2 = inet_ntop(2,param_1 + 2,param_2,0x2e);
  }
  else {
    if (sVar1 != 10) {
      if (sVar1 == 1) {
        curl_msnprintf(param_2,0x2e,DAT_00038cd0,param_1 + 1,param_4);
        *param_3 = 0;
        return 1;
      }
      goto LAB_00038c7e;
    }
    pcVar2 = inet_ntop(10,param_1 + 4,param_2,0x2e);
  }
  if (pcVar2 != (char *)0x0) {
    *param_3 = ((ushort)param_1[1] & 0xff) << 8 | (uint)((ushort)param_1[1] >> 8);
    return 1;
  }
LAB_00038c7e:
  *param_2 = '\0';
  *param_3 = 0;
  return 0;
}

