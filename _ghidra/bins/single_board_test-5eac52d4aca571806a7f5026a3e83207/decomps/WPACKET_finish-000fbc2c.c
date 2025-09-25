
undefined4 WPACKET_finish(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *ptr;
  int iVar8;
  bool bVar9;
  
  ptr = (int *)param_1[5];
  if ((ptr == (int *)0x0) || (*ptr != 0)) {
    return 0;
  }
  iVar5 = param_1[3];
  iVar8 = 0;
  if (iVar5 - ptr[3] == 0) {
    if (ptr[4] << 0x1f < 0) {
      return 0;
    }
    if (ptr[4] << 0x1e < 0) {
      iVar2 = param_1[2] - ptr[2];
      bVar9 = iVar2 == ptr[1];
      if (bVar9) {
        iVar5 = iVar5 - ptr[2];
      }
      if (bVar9) {
        param_1[2] = iVar2;
      }
      if (bVar9) {
        param_1[3] = iVar5;
      }
      ptr[1] = 0;
      ptr[2] = 0;
      goto LAB_000fbc68;
    }
  }
  iVar2 = ptr[2];
  if (iVar2 != 0) {
    iVar8 = param_1[1];
    if (iVar8 == 0) {
      iVar8 = *(int *)(*param_1 + 4);
    }
    uVar6 = iVar2 - 1;
    uVar7 = iVar5 - ptr[3];
    puVar1 = (undefined1 *)(iVar2 + ptr[1] + -1 + iVar8);
    while (0x1f < uVar6) {
      *puVar1 = (char)uVar7;
      uVar6 = iVar2 - 0x21;
      HintPreloadData(puVar1 + -0x22);
      iVar2 = iVar2 + -0x20;
      puVar1[-4] = 0;
      puVar1[-5] = 0;
      puVar1[-6] = 0;
      puVar1[-7] = 0;
      puVar1[-8] = 0;
      puVar1[-9] = 0;
      puVar1[-10] = 0;
      puVar1[-0xb] = 0;
      puVar1[-0xc] = 0;
      puVar1[-0xd] = 0;
      puVar1[-0xe] = 0;
      puVar1[-0xf] = 0;
      puVar1[-0x10] = 0;
      puVar1[-0x11] = 0;
      puVar1[-0x12] = 0;
      puVar1[-0x13] = 0;
      puVar1[-0x14] = 0;
      puVar1[-0x15] = 0;
      puVar1[-0x16] = 0;
      puVar1[-0x17] = 0;
      puVar1[-0x18] = 0;
      puVar1[-0x19] = 0;
      puVar1[-0x1a] = 0;
      puVar1[-0x1b] = 0;
      puVar1[-0x1c] = 0;
      puVar1[-0x1d] = 0;
      puVar1[-0x1e] = 0;
      puVar1[-1] = (char)(uVar7 >> 8);
      puVar1[-2] = (char)(uVar7 >> 0x10);
      puVar1[-3] = (char)(uVar7 >> 0x18);
      puVar1[-0x1f] = 0;
      uVar7 = 0;
      puVar1 = puVar1 + -0x20;
    }
    puVar3 = puVar1;
    do {
      uVar6 = uVar7 >> 8;
      puVar4 = puVar3 + -1;
      *puVar3 = (char)uVar7;
      puVar3 = puVar4;
      uVar7 = uVar6;
    } while (puVar4 != puVar1 + -iVar2);
    if (uVar6 != 0) {
      return 0;
    }
    iVar8 = *ptr;
  }
LAB_000fbc68:
  param_1[5] = iVar8;
  CRYPTO_free(ptr);
  CRYPTO_free((void *)param_1[5]);
  param_1[5] = 0;
  return 1;
}

