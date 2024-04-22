
undefined4 tls1_set_sigalgs(int param_1,int param_2,uint param_3,int param_4)

{
  undefined *puVar1;
  int *piVar2;
  undefined *ptr;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (((param_3 & 1) != 0) ||
     (ptr = (undefined *)CRYPTO_malloc(param_3,DAT_000735b0,0xfd4), piVar2 = DAT_000735b4,
     ptr == (undefined *)0x0)) {
    return 0;
  }
  if (param_3 != 0) {
    param_2 = param_2 + 8;
    uVar6 = 0;
    puVar1 = ptr;
    do {
      iVar4 = *(int *)(param_2 + -8);
      iVar5 = DAT_000735c0;
      if (iVar4 == *piVar2) {
        iVar4 = DAT_000735b4[1];
LAB_0007352a:
        iVar3 = *(int *)(param_2 + -4);
        if (iVar3 != piVar2[0xc]) {
LAB_0007350e:
          iVar5 = DAT_000735c8;
          if ((iVar3 != piVar2[0xe]) && (iVar5 = DAT_000735cc, iVar3 != piVar2[0x10]))
          goto LAB_0007351a;
        }
      }
      else {
        if (iVar4 == piVar2[2]) {
          iVar4 = *(int *)(DAT_000735c4 + 4);
          goto LAB_0007352a;
        }
        if (iVar4 == piVar2[4]) {
          iVar4 = *(int *)(DAT_000735d0 + 4);
          goto LAB_0007352a;
        }
        if (iVar4 == piVar2[6]) {
          iVar4 = *(int *)(DAT_000735d4 + 4);
          goto LAB_0007352a;
        }
        iVar3 = DAT_000735bc;
        if ((iVar4 == piVar2[8]) || (iVar3 = DAT_000735b8, iVar4 == piVar2[10])) {
          iVar4 = *(int *)(iVar3 + 4);
          goto LAB_0007352a;
        }
        iVar3 = *(int *)(param_2 + -4);
        iVar4 = -1;
        if (iVar3 != piVar2[0xc]) goto LAB_0007350e;
      }
      iVar5 = *(int *)(iVar5 + 4);
      if (iVar5 == -1 || iVar4 == -1) {
LAB_0007351a:
        CRYPTO_free(ptr);
        return 0;
      }
      uVar6 = uVar6 + 2;
      *puVar1 = (char)iVar4;
      puVar1[1] = (char)iVar5;
      param_2 = param_2 + 8;
      puVar1 = puVar1 + 2;
    } while (uVar6 < param_3);
  }
  if (param_4 == 0) {
    if (*(void **)(param_1 + 300) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 300));
    }
    *(undefined **)(param_1 + 300) = ptr;
    *(uint *)(param_1 + 0x130) = param_3;
    return 1;
  }
  if (*(void **)(param_1 + 0x134) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x134));
  }
  *(undefined **)(param_1 + 0x134) = ptr;
  *(uint *)(param_1 + 0x138) = param_3;
  return 1;
}

