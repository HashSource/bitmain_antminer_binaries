
undefined4 WPACKET_fill_lengths(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  
  piVar8 = (int *)param_1[5];
  if (piVar8 == (int *)0x0) {
    return 0;
  }
  do {
    if ((param_1[3] - piVar8[3] == 0) && ((piVar8[4] << 0x1f < 0 || (piVar8[4] << 0x1e < 0)))) {
      return 0;
    }
    iVar2 = piVar8[2];
    if (iVar2 != 0) {
      iVar7 = param_1[1];
      if (iVar7 == 0) {
        iVar7 = *(int *)(*param_1 + 4);
      }
      uVar6 = iVar2 - 1;
      uVar5 = param_1[3] - piVar8[3];
      puVar1 = (undefined1 *)(iVar2 + piVar8[1] + -1 + iVar7);
      while (0x1f < uVar6) {
        *puVar1 = (char)uVar5;
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
        puVar1[-1] = (char)(uVar5 >> 8);
        puVar1[-2] = (char)(uVar5 >> 0x10);
        puVar1[-3] = (char)(uVar5 >> 0x18);
        puVar1[-0x1f] = 0;
        uVar5 = 0;
        puVar1 = puVar1 + -0x20;
      }
      puVar3 = puVar1;
      do {
        uVar6 = uVar5 >> 8;
        puVar4 = puVar3 + -1;
        *puVar3 = (char)uVar5;
        puVar3 = puVar4;
        uVar5 = uVar6;
      } while (puVar4 != puVar1 + -iVar2);
      if (uVar6 != 0) {
        return 0;
      }
    }
    piVar8 = (int *)*piVar8;
    if (piVar8 == (int *)0x0) {
      return 1;
    }
  } while( true );
}

