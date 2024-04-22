
undefined4 max5data(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  if ((int)(-(uint)(99999 < param_1) - param_2) < 0 ==
      (SBORROW4(-param_2,(uint)(99999 < param_1)) != false)) {
    curl_msnprintf(param_3,6,DAT_0003de48,param_4,param_1,param_2);
    return param_3;
  }
  if ((int)((DAT_0003de64 - param_2) - (uint)(DAT_0003de60 < param_1)) < 0 ==
      (SBORROW4(DAT_0003de64,param_2) !=
      SBORROW4(DAT_0003de64 - param_2,(uint)(DAT_0003de60 < param_1)))) {
    iVar1 = param_2 >> 10;
    uVar3 = param_1 >> 10 | param_2 << 0x16;
    uVar2 = DAT_0003de50;
  }
  else {
    iVar1 = param_2 >> 0x14;
    if ((int)(param_2 - (uint)(param_1 < 0x6400000)) < 0 !=
        (SBORROW4(param_2,(uint)(param_1 < 0x6400000)) != false)) {
      __aeabi_ldivmod(param_1 & 0xfffff,0,0x19999,0,param_1 >> 0x14 | param_2 << 0xc,iVar1);
      curl_msnprintf(param_3,6,DAT_0003de4c);
      return param_3;
    }
    if ((int)((param_2 + -2) - (uint)(param_1 < 0x71000000)) < 0 ==
        (SBORROW4(param_2,2) != SBORROW4(param_2 + -2,(uint)(param_1 < 0x71000000)))) {
      iVar1 = param_2 >> 0x1e;
      if (param_2 + -0x19 < 0 != (SBORROW4(param_2,0x19) != false)) {
        __aeabi_ldivmod(param_1 & 0x3fffffff,0,0x6666666,0,param_1 >> 0x1e | param_2 << 2,iVar1);
        curl_msnprintf(param_3,6,DAT_0003de58);
        return param_3;
      }
      if (0x9c3 - param_2 < 0 != (SBORROW4(0x9c3,param_2) != false)) {
        bVar5 = SBORROW4(0x270fff,param_2) != false;
        bVar4 = 0x270fff - param_2 < 0;
        if (bVar4 == bVar5) {
          iVar1 = param_2 >> 8;
        }
        else {
          iVar1 = param_2 >> 0x12;
        }
        uVar2 = DAT_0003de40;
        if (bVar4 != bVar5) {
          uVar2 = DAT_0003de44;
        }
        curl_msnprintf(param_3,6,uVar2,param_2 >> 0x1f,iVar1,param_2 >> 0x1f);
        return param_3;
      }
      uVar3 = param_1 >> 0x1e | param_2 << 2;
      uVar2 = DAT_0003de5c;
    }
    else {
      uVar3 = param_1 >> 0x14 | param_2 << 0xc;
      uVar2 = DAT_0003de54;
    }
  }
  curl_msnprintf(param_3,6,uVar2,uVar3,uVar3,iVar1);
  return param_3;
}

