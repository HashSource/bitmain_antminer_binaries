
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
      iVar2 = DAT_00196610;
      if ((((iVar3 == tls12_md) || (iVar2 = DAT_00196618, iVar3 == DAT_00196614)) ||
          (iVar2 = DAT_00196620, iVar3 == DAT_0019661c)) ||
         (iVar2 = DAT_00196628, iVar3 == DAT_00196624)) {
LAB_0007352a:
        iVar3 = *(int *)(param_2 + -4);
        if (iVar3 != tls12_sig._0_4_) goto LAB_0007350e;
LAB_00073534:
        puVar5 = tls12_sig;
      }
      else {
        if (iVar3 == DAT_0019662c) {
          puVar4 = &DAT_0019662c;
LAB_00073528:
          iVar2 = puVar4[1];
          goto LAB_0007352a;
        }
        if (iVar3 == DAT_00196634) {
          puVar4 = &DAT_00196634;
          goto LAB_00073528;
        }
        iVar3 = *(int *)(param_2 + -4);
        iVar2 = -1;
        if (iVar3 == tls12_sig._0_4_) goto LAB_00073534;
LAB_0007350e:
        if (iVar3 == tls12_sig._8_4_) {
          puVar5 = (undefined1 *)0x196644;
        }
        else {
          if (iVar3 != tls12_sig._16_4_) goto LAB_0007351a;
          puVar5 = (undefined1 *)0x19664c;
        }
      }
      iVar3 = *(int *)(puVar5 + 4);
      if (iVar3 == -1 || iVar2 == -1) {
LAB_0007351a:
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

