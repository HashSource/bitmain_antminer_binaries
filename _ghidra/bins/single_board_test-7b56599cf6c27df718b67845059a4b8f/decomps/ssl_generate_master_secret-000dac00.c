
undefined1 * ssl_generate_master_secret(int param_1,void *param_2,size_t param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  size_t __n;
  int iVar7;
  undefined1 *__s;
  int iVar8;
  
  uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x10);
  if ((uVar5 & 0x1c8) == 0) {
    puVar1 = (undefined1 *)
             (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0xc))
                       (param_1,*(int *)(param_1 + 0x474) + 0x48,param_2,param_3,
                        *(int *)(param_1 + 0x474) + 4);
    if (puVar1 != (undefined1 *)0x0) {
      puVar1 = (undefined1 *)0x1;
    }
  }
  else {
    __n = *(size_t *)(*(int *)(param_1 + 0x7c) + 0x25c);
    uVar4 = (undefined1)(__n >> 8);
    if ((int)(uVar5 << 0x1c) < 0) {
      iVar6 = __n * 2 + 4;
      puVar2 = (undefined1 *)CRYPTO_malloc(iVar6,"ssl/s3_lib.c",0x1215);
      param_3 = __n;
      if (puVar2 == (undefined1 *)0x0) {
        puVar1 = (undefined1 *)0x0;
        goto LAB_000dacda;
      }
      __s = puVar2 + 2;
      puVar2[1] = (char)__n;
      *puVar2 = uVar4;
      memset(__s,0,__n);
    }
    else {
      iVar6 = __n + 4 + param_3;
      puVar1 = (undefined1 *)CRYPTO_malloc(iVar6,"ssl/s3_lib.c",0x1215);
      if (puVar1 == (undefined1 *)0x0) goto LAB_000dacda;
      __s = puVar1 + 2;
      puVar1[1] = (char)param_3;
      *puVar1 = (char)(param_3 >> 8);
      memcpy(__s,param_2,param_3);
      puVar2 = puVar1;
    }
    __s[param_3] = uVar4;
    __s[param_3 + 1] = (char)__n;
    memcpy(__s + param_3 + 2,*(void **)(*(int *)(param_1 + 0x7c) + 600),__n);
    CRYPTO_clear_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 600),__n,"ssl/s3_lib.c",0x1222);
    iVar7 = *(int *)(param_1 + 0x474);
    iVar3 = *(int *)(param_1 + 0x7c);
    iVar8 = *(int *)(*(int *)(param_1 + 4) + 100);
    *(undefined4 *)(iVar3 + 600) = 0;
    *(undefined4 *)(iVar3 + 0x25c) = 0;
    iVar3 = (**(code **)(iVar8 + 0xc))(param_1,iVar7 + 0x48,puVar2,iVar6,iVar7 + 4);
    if (iVar3 == 0) {
      CRYPTO_clear_free(puVar2,iVar6,"ssl/s3_lib.c",0x1228);
      puVar1 = (undefined1 *)0x0;
    }
    else {
      puVar1 = (undefined1 *)0x1;
      CRYPTO_clear_free(puVar2,iVar6,"ssl/s3_lib.c",0x122c);
    }
  }
LAB_000dacda:
  if (param_2 != (void *)0x0) {
    if (param_4 == 0) {
      OPENSSL_cleanse(param_2,param_3);
    }
    else {
      CRYPTO_clear_free(param_2,param_3,"ssl/s3_lib.c",0x123e);
    }
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar6 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar6 + 0x250) = 0;
    *(undefined4 *)(iVar6 + 0x254) = 0;
  }
  return puVar1;
}

