
undefined4 gost_imit_init_cpa(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined *)(iVar1 + 0x1028) = 0;
  *(undefined *)(iVar1 + 0x1020) = 0;
  *(undefined *)(iVar1 + 0x1021) = 0;
  *(undefined *)(iVar1 + 0x1029) = 0;
  *(undefined *)(iVar1 + 0x1022) = 0;
  *(undefined *)(iVar1 + 0x102a) = 0;
  *(undefined *)(iVar1 + 0x1023) = 0;
  *(undefined *)(iVar1 + 0x102b) = 0;
  *(undefined *)(iVar1 + 0x1024) = 0;
  *(undefined *)(iVar1 + 0x102c) = 0;
  *(undefined *)(iVar1 + 0x1025) = 0;
  *(undefined *)(iVar1 + 0x102d) = 0;
  *(undefined *)(iVar1 + 0x1026) = 0;
  *(undefined *)(iVar1 + 0x102e) = 0;
  *(undefined *)(iVar1 + 0x1027) = 0;
  *(undefined *)(iVar1 + 0x102f) = 0;
  *(undefined4 *)(iVar1 + 0x1030) = 0;
  *(undefined4 *)(iVar1 + 0x1038) = 0;
  *(undefined4 *)(iVar1 + 0x1034) = 1;
  gost_init(iVar1,Gost28147_CryptoProParamSetA,(undefined *)(iVar1 + 0x1027),0,param_4);
  return 1;
}

