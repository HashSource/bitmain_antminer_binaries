
undefined4 tls_parse_ctos_maxfragmentlen(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2[1] != 1) {
    ossl_statem_fatal(param_1,0x32,0x23b,0x6e,"ssl/statem/extensions_srvr.c",0xbb);
    return 0;
  }
  bVar1 = *(byte *)*param_2;
  param_2[1] = 0;
  *param_2 = (byte *)*param_2 + 1;
  if (bVar1 - 1 < 4) {
    if (*(int *)(param_1 + 0x8c) == 0) {
      iVar2 = *(int *)(param_1 + 0x474);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x474);
      if ((uint)*(byte *)(iVar2 + 0x1ec) != (uint)bVar1) {
        uVar3 = 0xcf;
        goto LAB_000f47c8;
      }
    }
    *(byte *)(iVar2 + 0x1ec) = bVar1;
    return 1;
  }
  uVar3 = 0xc3;
LAB_000f47c8:
  ossl_statem_fatal(param_1,0x2f,0x23b,0xe8,"ssl/statem/extensions_srvr.c",uVar3);
  return 0;
}

