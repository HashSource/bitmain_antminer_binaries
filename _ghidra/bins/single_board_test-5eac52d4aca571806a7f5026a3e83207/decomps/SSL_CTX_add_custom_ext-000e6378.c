
undefined4
SSL_CTX_add_custom_ext
          (int param_1,uint param_2,uint param_3,int param_4,int param_5,undefined4 param_6,
          undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  void *__s;
  
  if (param_5 == 0 || param_4 != 0) {
    iVar4 = *(int *)(param_1 + 0xc0);
    iVar2 = param_4;
    if (param_2 == 0x12) {
      if (((param_3 & 0x80) != 0) && (iVar1 = SSL_CTX_ct_is_enabled(), iVar1 != 0)) {
        return 0;
      }
      SSL_extension_supported(0x12);
    }
    else {
      iVar1 = SSL_extension_supported(param_2);
      if (iVar1 != 0) {
        return 0;
      }
      if (0xffff < param_2) {
        return 0;
      }
    }
    iVar2 = custom_ext_find(iVar4 + 0xf0,2,param_2,0,iVar2);
    if ((iVar2 == 0) &&
       (pvVar3 = CRYPTO_realloc(*(void **)(iVar4 + 0xf0),(*(int *)(iVar4 + 0xf4) + 1) * 0x24,
                                "ssl/statem/extensions_cust.c",0x185), pvVar3 != (void *)0x0)) {
      *(void **)(iVar4 + 0xf0) = pvVar3;
      iVar1 = *(int *)(iVar4 + 0xf4) * 0x24;
      __s = (void *)((int)pvVar3 + iVar1);
      memset(__s,0,0x24);
      iVar2 = *(int *)(iVar4 + 0xf4);
      *(undefined4 *)((int)__s + 4) = 2;
      *(uint *)((int)__s + 8) = param_3;
      *(undefined4 *)((int)__s + 0x1c) = param_7;
      *(int *)((int)__s + 0x10) = param_4;
      *(int *)((int)__s + 0x14) = param_5;
      *(short *)((int)pvVar3 + iVar1) = (short)param_2;
      *(undefined4 *)((int)__s + 0x18) = param_6;
      *(undefined4 *)((int)__s + 0x20) = param_8;
      *(int *)(iVar4 + 0xf4) = iVar2 + 1;
      return 1;
    }
  }
  return 0;
}

