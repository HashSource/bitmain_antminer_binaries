
undefined4 tls_parse_stoc_ec_pt_formats(int param_1,undefined4 *param_2)

{
  void *__dest;
  uint uVar1;
  uint __n;
  byte *__src;
  
  if (param_2[1] != 0) {
    uVar1 = param_2[1] - 1;
    __n = (uint)*(byte *)*param_2;
    if (__n <= uVar1) {
      __src = (byte *)*param_2 + 1;
      if (__n == uVar1) {
        *param_2 = __src + __n;
        param_2[1] = 0;
        if (*(int *)(param_1 + 0x8c) != 0) {
          return 1;
        }
        if (__n != 0) {
          *(undefined4 *)(param_1 + 0x568) = 0;
          CRYPTO_free(*(void **)(param_1 + 0x56c));
          __dest = CRYPTO_malloc(__n,"ssl/statem/extensions_clnt.c",0x56e);
          *(void **)(param_1 + 0x56c) = __dest;
          if (__dest == (void *)0x0) {
            *(undefined4 *)(param_1 + 0x568) = 0;
            ossl_statem_fatal(param_1,0x50,0x244,0x44,"ssl/statem/extensions_clnt.c",0x572);
            return 0;
          }
          *(uint *)(param_1 + 0x568) = __n;
          memcpy(__dest,__src,__n);
          return 1;
        }
        ossl_statem_fatal(param_1,0x32,0x244,0x10f,"ssl/statem/extensions_clnt.c",0x568);
        return 0;
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x244,0x6e,"ssl/statem/extensions_clnt.c",0x561);
  return 0;
}

