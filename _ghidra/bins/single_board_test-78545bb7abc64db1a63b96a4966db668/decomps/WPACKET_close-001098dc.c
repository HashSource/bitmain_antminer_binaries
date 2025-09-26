
undefined4 WPACKET_close(int *param_1)

{
  undefined1 *puVar1;
  int *ptr;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  ptr = (int *)param_1[5];
  if ((ptr == (int *)0x0) || (iVar6 = *ptr, iVar6 == 0)) {
    return 0;
  }
  iVar4 = param_1[3];
  if (iVar4 - ptr[3] == 0) {
    if (ptr[4] << 0x1f < 0) {
      return 0;
    }
    if (ptr[4] << 0x1e < 0) {
      iVar8 = param_1[2] - ptr[2];
      bVar9 = iVar8 == ptr[1];
      if (bVar9) {
        iVar4 = iVar4 - ptr[2];
      }
      if (bVar9) {
        param_1[2] = iVar8;
      }
      if (bVar9) {
        param_1[3] = iVar4;
      }
      ptr[1] = 0;
      ptr[2] = 0;
      goto LAB_00109a2a;
    }
  }
  iVar8 = ptr[2];
  if (iVar8 != 0) {
    iVar6 = param_1[1];
    if (iVar6 == 0) {
      iVar6 = *(int *)(*param_1 + 4);
    }
    uVar5 = iVar8 - 1;
    uVar7 = iVar4 - ptr[3];
    puVar1 = (undefined1 *)(iVar8 + ptr[1] + -1 + iVar6);
    while (0x1f < uVar5) {
      *puVar1 = (char)uVar7;
      uVar5 = iVar8 - 0x21;
      HintPreloadData(puVar1 + -0x22);
      iVar8 = iVar8 + -0x20;
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
    puVar2 = puVar1;
    do {
      uVar5 = uVar7 >> 8;
      puVar3 = puVar2 + -1;
      *puVar2 = (char)uVar7;
      puVar2 = puVar3;
      uVar7 = uVar5;
    } while (puVar3 != puVar1 + -iVar8);
    if (uVar5 != 0) {
      return 0;
    }
    iVar6 = *ptr;
  }
LAB_00109a2a:
  param_1[5] = iVar6;
  CRYPTO_free(ptr);
  return 1;
}

