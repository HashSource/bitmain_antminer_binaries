
undefined4 tls1_set_sigalgs(int param_1,int param_2,uint param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *ptr;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  if (((param_3 & 1) != 0) ||
     (ptr = (undefined1 *)CRYPTO_malloc(param_3,"t1_lib.c",0xfd4), ptr == (undefined1 *)0x0)) {
    return 0;
  }
  if (param_3 != 0) {
    param_2 = param_2 + 8;
    uVar6 = 0;
    puVar1 = ptr;
    do {
      iVar3 = *(int *)(param_2 + -8);
      iVar2 = DAT_0024d2e4;
      if ((((iVar3 == tls12_md) || (iVar2 = DAT_0024d2ec, iVar3 == DAT_0024d2e8)) ||
          (iVar2 = DAT_0024d2f4, iVar3 == DAT_0024d2f0)) ||
         (iVar2 = DAT_0024d2fc, iVar3 == DAT_0024d2f8)) {
LAB_001138ba:
        iVar3 = *(int *)(param_2 + -4);
        if (iVar3 != tls12_sig._0_4_) goto LAB_0011389e;
LAB_001138c4:
        puVar5 = tls12_sig;
      }
      else {
        if (iVar3 == DAT_0024d300) {
          puVar4 = &DAT_0024d300;
LAB_001138b8:
          iVar2 = puVar4[1];
          goto LAB_001138ba;
        }
        if (iVar3 == DAT_0024d308) {
          puVar4 = &DAT_0024d308;
          goto LAB_001138b8;
        }
        iVar3 = *(int *)(param_2 + -4);
        iVar2 = -1;
        if (iVar3 == tls12_sig._0_4_) goto LAB_001138c4;
LAB_0011389e:
        if (iVar3 == tls12_sig._8_4_) {
          puVar5 = (undefined1 *)0x24d318;
        }
        else {
          if (iVar3 != tls12_sig._16_4_) goto LAB_001138aa;
          puVar5 = (undefined1 *)0x24d320;
        }
      }
      iVar3 = *(int *)(puVar5 + 4);
      if (iVar3 == -1 || iVar2 == -1) {
LAB_001138aa:
        CRYPTO_free(ptr);
        return 0;
      }
      uVar6 = uVar6 + 2;
      *puVar1 = (char)iVar2;
      puVar1[1] = (char)iVar3;
      param_2 = param_2 + 8;
      puVar1 = puVar1 + 2;
    } while (uVar6 < param_3);
  }
  if (param_4 == 0) {
    if (*(void **)(param_1 + 300) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 300));
    }
    *(undefined1 **)(param_1 + 300) = ptr;
    *(uint *)(param_1 + 0x130) = param_3;
    return 1;
  }
  if (*(void **)(param_1 + 0x134) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x134));
  }
  *(undefined1 **)(param_1 + 0x134) = ptr;
  *(uint *)(param_1 + 0x138) = param_3;
  return 1;
}

