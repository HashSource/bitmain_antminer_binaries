
undefined4
custom_ext_parse(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint extraout_r3;
  uint uVar3;
  bool bVar4;
  undefined4 local_24 [2];
  
  if ((param_2 & 0x180) == 0) {
    iVar2 = 2;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  iVar2 = custom_ext_find(*(int *)(param_1 + 0x404) + 0xf0,iVar2,param_3,0);
  if ((iVar2 != 0) &&
     (iVar1 = extension_is_relevant(param_1,*(undefined4 *)(iVar2 + 8),param_2), iVar1 != 0)) {
    if (((param_2 & 0x700) != 0) && ((*(uint *)(iVar2 + 0xc) & 2) == 0)) {
      ossl_statem_fatal(param_1,0x6e,0x22b,0x6e,"ssl/statem/extensions_cust.c",0x8f);
      return 0;
    }
    bVar4 = (param_2 & 0x4080) != 0;
    uVar3 = extraout_r3;
    if (bVar4) {
      uVar3 = *(uint *)(iVar2 + 0xc) | 1;
    }
    if (bVar4) {
      *(uint *)(iVar2 + 0xc) = uVar3;
    }
    if ((*(code **)(iVar2 + 0x1c) != (code *)0x0) &&
       (iVar2 = (**(code **)(iVar2 + 0x1c))
                          (param_1,param_3,param_2,param_4,param_5,param_6,param_7,local_24,
                           *(undefined4 *)(iVar2 + 0x20)), iVar2 < 1)) {
      ossl_statem_fatal(param_1,local_24[0],0x22b,0x6e,"ssl/statem/extensions_cust.c",0xa3);
      return 0;
    }
  }
  return 1;
}

