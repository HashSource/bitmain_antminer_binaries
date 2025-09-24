
undefined4 tls_parse_ctos_renegotiate(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  byte *__s1;
  uint uVar3;
  int iVar4;
  
  if (param_2[1] != 0) {
    uVar2 = param_2[1] - 1;
    __s1 = (byte *)*param_2 + 1;
    uVar3 = (uint)*(byte *)*param_2;
    param_2[1] = uVar2;
    *param_2 = __s1;
    if (uVar3 <= uVar2) {
      iVar4 = *(int *)(param_1 + 0x7c);
      *param_2 = __s1 + uVar3;
      param_2[1] = uVar2 - uVar3;
      if (*(size_t *)(iVar4 + 0x2f0) != uVar3) {
        ossl_statem_fatal(param_1,0x28,0x1d0,0x151,"ssl/statem/extensions_srvr.c",0x3a);
        return 0;
      }
      iVar1 = memcmp(__s1,(void *)(iVar4 + 0x2b0),*(size_t *)(iVar4 + 0x2f0));
      if (iVar1 != 0) {
        ossl_statem_fatal(param_1,0x28,0x1d0,0x151,"ssl/statem/extensions_srvr.c",0x41);
        return 0;
      }
      *(undefined4 *)(iVar4 + 0x338) = 1;
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x32,0x1d0,0x150,"ssl/statem/extensions_srvr.c",0x33);
  return 0;
}

