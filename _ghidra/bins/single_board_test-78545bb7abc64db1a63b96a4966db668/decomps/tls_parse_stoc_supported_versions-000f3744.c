
undefined4 tls_parse_stoc_supported_versions(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (1 < (uint)param_2[1]) {
    puVar3 = (undefined1 *)*param_2;
    iVar4 = param_2[1] - 2;
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    *param_2 = puVar3 + 2;
    param_2[1] = iVar4;
    if (iVar4 == 0) {
      if (CONCAT11(uVar1,uVar2) == 0x304) {
        if (param_3 != 0x800) {
          *param_1 = 0x304;
        }
        return 1;
      }
      ossl_statem_fatal(param_1,0x2f,0x264,0x74,"ssl/statem/extensions_clnt.c",0x703);
      return 0;
    }
  }
  ossl_statem_fatal(param_1,0x32,0x264,0x9f,"ssl/statem/extensions_clnt.c",0x6f8);
  return 0;
}

