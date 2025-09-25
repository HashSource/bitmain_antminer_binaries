
int tls_parse_stoc_sct(int param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  void *__dest;
  int iVar1;
  undefined4 uVar2;
  uint __n;
  
  if (param_3 == 0x4000) {
    return 1;
  }
  if (*(int *)(param_1 + 0x5d0) == 0) {
    if ((param_3 & 0x100) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
    }
    iVar1 = custom_ext_find(*(int *)(param_1 + 0x404) + 0xf0,uVar2,0x12);
    if (iVar1 != 0) {
      iVar1 = custom_ext_parse(param_1,param_3,0x12,*param_2,param_2[1],param_4,param_5);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    ossl_statem_fatal(param_1,0x6e,0x234,0x6e,"ssl/statem/extensions_clnt.c",0x5fe);
    iVar1 = 0;
  }
  else {
    __n = param_2[1];
    CRYPTO_free(*(void **)(param_1 + 0x540));
    *(short *)(param_1 + 0x544) = (short)__n;
    *(undefined4 *)(param_1 + 0x540) = 0;
    iVar1 = 1;
    if (__n != 0) {
      __dest = CRYPTO_malloc(__n,"ssl/statem/extensions_clnt.c",0x5e5);
      *(void **)(param_1 + 0x540) = __dest;
      if (__dest == (void *)0x0) {
        *(undefined2 *)(param_1 + 0x544) = 0;
        ossl_statem_fatal(param_1,0x50,0x234,0x41,"ssl/statem/extensions_clnt.c",0x5e9);
        iVar1 = 0;
      }
      else {
        if (__n <= (uint)param_2[1]) {
          memcpy(__dest,(void *)*param_2,__n);
          *param_2 = *param_2 + __n;
          param_2[1] = param_2[1] - __n;
          return 1;
        }
        ossl_statem_fatal(param_1,0x50,0x234,0x44,"ssl/statem/extensions_clnt.c",0x5ee);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

