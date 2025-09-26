
undefined4 tls_parse_stoc_maxfragmentlen(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2[1] != 1) {
    ossl_statem_fatal(param_1,0x32,0x245,0x6e,"ssl/statem/extensions_clnt.c",0x516);
    return 0;
  }
  uVar2 = (uint)*(byte *)*param_2;
  param_2[1] = 0;
  *param_2 = (byte *)*param_2 + 1;
  if (uVar2 - 1 < 4) {
    if (*(byte *)(param_1 + 0x5c0) == uVar2) {
      *(byte *)(*(int *)(param_1 + 0x474) + 0x1ec) = *(byte *)(param_1 + 0x5c0);
      return 1;
    }
    uVar1 = 0x52b;
  }
  else {
    uVar1 = 0x51e;
  }
  ossl_statem_fatal(param_1,0x2f,0x245,0xe8,"ssl/statem/extensions_clnt.c",uVar1);
  return 0;
}

