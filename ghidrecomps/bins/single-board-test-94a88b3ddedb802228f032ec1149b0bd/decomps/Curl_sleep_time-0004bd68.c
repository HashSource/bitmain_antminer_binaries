
uint Curl_sleep_time(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined8 uVar5;
  
  if ((param_1 | param_2) == 0) {
    return 0;
  }
  uVar2 = param_1 >> 10 | param_2 << 0x16;
  iVar3 = ((int)param_2 >> 10) + param_2 + CARRY4(uVar2,param_1);
  bVar4 = uVar2 + param_1 < param_3;
  if ((int)((iVar3 - param_4) - (uint)bVar4) < 0 ==
      (SBORROW4(iVar3,param_4) != SBORROW4(iVar3 - param_4,(uint)bVar4))) {
    iVar3 = (param_2 - ((int)param_2 >> 10)) - (uint)(param_1 < uVar2);
    bVar4 = param_3 < param_1 - uVar2;
    if ((int)((param_4 - iVar3) - (uint)bVar4) < 0 ==
        (SBORROW4(param_4,iVar3) != SBORROW4(param_4 - iVar3,(uint)bVar4))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      uVar1 = param_1 >> 6 | param_2 << 0x1a;
      bVar4 = CARRY4(param_1,uVar1);
      param_1 = param_1 + uVar1;
      param_2 = param_2 + ((int)param_2 >> 6) + (uint)bVar4;
    }
  }
  else {
    uVar1 = param_1 >> 6 | param_2 << 0x1a;
    uVar2 = 1;
    bVar4 = param_1 < uVar1;
    param_1 = param_1 - uVar1;
    param_2 = (param_2 - ((int)param_2 >> 6)) - (uint)bVar4;
  }
  uVar5 = __aeabi_ldivmod(param_5 * 1000,param_5 * 1000 >> 0x1f,param_1,param_2,param_4);
  iVar3 = (int)((ulonglong)uVar5 >> 0x20);
  uVar1 = (uint)uVar5;
  if (((int)(iVar3 - (uint)(uVar1 < uVar2)) < 0 == (SBORROW4(iVar3,(uint)(uVar1 < uVar2)) != false))
     && (uVar2 = uVar1, iVar3 == 0 && uVar1 == 0x80000000)) {
    return 0x7fffffff;
  }
  return uVar2;
}

