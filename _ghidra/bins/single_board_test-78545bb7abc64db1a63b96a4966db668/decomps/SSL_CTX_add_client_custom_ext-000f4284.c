
undefined4
SSL_CTX_add_client_custom_ext
          (int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  undefined4 *ptr;
  undefined4 *ptr_00;
  int iVar1;
  void *pvVar2;
  int iVar3;
  void *__s;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = param_4;
  ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl/statem/extensions_cust.c",0x1a1);
  ptr_00 = (undefined4 *)CRYPTO_malloc(8,"ssl/statem/extensions_cust.c",0x1a3);
  if (ptr_00 == (undefined4 *)0x0 || ptr == (undefined4 *)0x0) {
    CRYPTO_free(ptr);
    CRYPTO_free(ptr_00);
    return 0;
  }
  ptr[2] = param_4;
  iVar3 = *(int *)(param_1 + 0xc0);
  *ptr = param_5;
  ptr[1] = param_3;
  *ptr_00 = param_7;
  ptr_00[1] = param_6;
  if (param_2 == 0x12) {
    iVar1 = SSL_CTX_ct_is_enabled(param_1);
    if (iVar1 != 0) goto LAB_000f42e0;
    SSL_extension_supported(0x12);
  }
  else {
    iVar1 = SSL_extension_supported(param_2);
    if ((iVar1 != 0) || (0xffff < param_2)) goto LAB_000f42e0;
  }
  iVar1 = custom_ext_find(iVar3 + 0xf0,0,param_2,0,uVar5);
  if ((iVar1 == 0) &&
     (pvVar2 = CRYPTO_realloc(*(void **)(iVar3 + 0xf0),(*(int *)(iVar3 + 0xf4) + 1) * 0x24,
                              "ssl/statem/extensions_cust.c",0x185), pvVar2 != (void *)0x0)) {
    *(void **)(iVar3 + 0xf0) = pvVar2;
    iVar4 = *(int *)(iVar3 + 0xf4) * 0x24;
    __s = (void *)((int)pvVar2 + iVar4);
    memset(__s,0,0x24);
    iVar1 = *(int *)(iVar3 + 0xf4);
    *(undefined4 *)((int)__s + 4) = 0;
    *(undefined4 *)((int)__s + 8) = 0x1d0;
    *(undefined4 *)((int)__s + 0x1c) = 0xf3ce1;
    *(undefined4 *)((int)__s + 0x10) = 0xf3ca9;
    *(undefined4 *)((int)__s + 0x14) = 0xf3cc9;
    *(short *)((int)pvVar2 + iVar4) = (short)param_2;
    *(undefined4 **)((int)__s + 0x18) = ptr;
    *(undefined4 **)((int)__s + 0x20) = ptr_00;
    *(int *)(iVar3 + 0xf4) = iVar1 + 1;
    return 1;
  }
LAB_000f42e0:
  CRYPTO_free(ptr);
  CRYPTO_free(ptr_00);
  return 0;
}

