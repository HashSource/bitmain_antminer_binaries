
undefined4 max5data(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  if ((int)(uint)(99999 < param_1) <= -param_2) {
    curl_msnprintf(param_3,6,"%5lld",param_4,param_1,param_2);
    return param_3;
  }
  if (-param_2 < (int)(uint)(0x9c3fff < param_1)) {
    iVar1 = param_2 >> 0x14;
    if (param_2 < (int)(uint)(param_1 < 0x6400000)) {
      __aeabi_ldivmod(param_1 & 0xfffff,0,0x19999,0,param_1 >> 0x14 | param_2 << 0xc,iVar1);
      curl_msnprintf(param_3,6,"%2lld.%0lldM");
      return param_3;
    }
    if ((int)((param_2 + -2) - (uint)(param_1 < 0x71000000)) < 0 ==
        (SBORROW4(param_2,2) != SBORROW4(param_2 + -2,(uint)(param_1 < 0x71000000)))) {
      iVar1 = param_2 >> 0x1e;
      if (param_2 < 0x19) {
        __aeabi_ldivmod(param_1 & 0x3fffffff,0,0x6666666,0,param_1 >> 0x1e | param_2 << 2,iVar1);
        curl_msnprintf(param_3,6,"%2lld.%0lldG");
        return param_3;
      }
      if (0x9c3 < param_2) {
        if (param_2 < 0x271000) {
          iVar1 = param_2 >> 8;
        }
        else {
          iVar1 = param_2 >> 0x12;
        }
        if (param_2 < 0x271000) {
          pcVar2 = "%4lldT";
        }
        else {
          pcVar2 = "%4lldP";
        }
        curl_msnprintf(param_3,6,pcVar2,param_2 >> 0x1f,iVar1,param_2 >> 0x1f);
        return param_3;
      }
      pcVar2 = "%4lldG";
      uVar3 = param_1 >> 0x1e | param_2 << 2;
    }
    else {
      pcVar2 = "%4lldM";
      uVar3 = param_1 >> 0x14 | param_2 << 0xc;
    }
  }
  else {
    pcVar2 = "%4lldk";
    iVar1 = param_2 >> 10;
    uVar3 = param_1 >> 10 | param_2 << 0x16;
  }
  curl_msnprintf(param_3,6,pcVar2,uVar3,uVar3,iVar1);
  return param_3;
}

