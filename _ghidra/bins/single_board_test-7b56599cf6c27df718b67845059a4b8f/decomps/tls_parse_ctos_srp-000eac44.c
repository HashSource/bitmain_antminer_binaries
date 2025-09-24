
undefined4 tls_parse_ctos_srp(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  byte *__s;
  uint __n;
  
  if (param_2[1] != 0) {
    uVar3 = param_2[1] - 1;
    __n = (uint)*(byte *)*param_2;
    if (__n <= uVar3) {
      __s = (byte *)*param_2 + 1;
      if (__n == uVar3) {
        *param_2 = __s + __n;
        param_2[1] = 0;
        pvVar1 = memchr(__s,0,__n);
        if (pvVar1 == (void *)0x0) {
          CRYPTO_free(*(void **)(param_1 + 0x61c));
          iVar2 = CRYPTO_strndup(__s,__n,"ssl/statem/../packet_local.h",0x1e5);
          *(int *)(param_1 + 0x61c) = iVar2;
          if (iVar2 != 0) {
            return 1;
          }
          ossl_statem_fatal(param_1,0x50,0x240,0x44,"ssl/statem/extensions_srvr.c",0xef);
          return 0;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x240,0x6e,"ssl/statem/extensions_srvr.c",0xe5);
  return 0;
}

