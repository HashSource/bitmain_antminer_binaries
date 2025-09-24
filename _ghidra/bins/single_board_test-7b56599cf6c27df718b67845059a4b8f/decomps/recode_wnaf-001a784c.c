
int recode_wnaf(undefined4 *param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  bool bVar18;
  
  uVar15 = 1;
  iVar5 = __aeabi_uidiv(0x1be,param_3 + 1U);
  uVar10 = (uint)*param_2;
  uVar17 = 1 << (param_3 + 1U & 0xff);
  param_1[(iVar5 + 2) * 2] = 0xffffffff;
  iVar16 = 0;
  uVar11 = 0;
  iVar13 = iVar5 + 1;
  param_1[(iVar5 + 2) * 2 + 1] = 0;
  do {
    uVar6 = uVar11;
    if (uVar15 < 0x1c) {
      uVar6 = (*(uint *)(param_2 + (uVar15 & 0xfffffffe)) >> ((uVar15 & 1) << 4)) * 0x10000;
      bVar18 = CARRY4(uVar10,uVar6);
      uVar10 = uVar10 + uVar6;
      uVar6 = uVar11 + bVar18;
    }
    if ((uVar10 & 0xffff) != 0) {
      puVar12 = param_1 + iVar13 * 2;
      do {
        bVar2 = (byte)uVar10;
        bVar3 = (byte)(uVar10 >> 8);
        bVar4 = (byte)(uVar10 >> 0x10);
        bVar1 = (byte)(uVar10 >> 0x18);
        iVar7 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                         << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                      bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                        0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                              bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                            bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                         << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                      bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                        | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                           bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                         bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
        param_1[iVar13 * 2] = iVar7 + iVar16;
        iVar13 = iVar13 + -1;
        uVar11 = uVar17 - 1 & uVar10 >> iVar7;
        if ((uVar10 >> iVar7 & uVar17) != 0) {
          uVar11 = uVar11 - uVar17;
        }
        uVar8 = uVar11 << iVar7;
        puVar12[1] = uVar11;
        bVar18 = uVar10 < uVar8;
        uVar10 = uVar10 - uVar8;
        uVar6 = (uVar6 - ((int)uVar8 >> 0x1f)) - (uint)bVar18;
        puVar12 = puVar12 + -2;
      } while ((uVar10 & 0xffff) != 0);
    }
    uVar15 = uVar15 + 1;
    uVar11 = uVar6 >> 0x10;
    uVar10 = uVar10 >> 0x10 | uVar6 << 0x10;
    iVar16 = iVar16 + 0x10;
  } while (uVar15 != 0x1e);
  uVar11 = (iVar5 + 3) - (iVar13 + 1);
  if (uVar11 != 0) {
    if (uVar11 < 5) {
      uVar10 = 0;
    }
    else {
      uVar10 = (uVar11 - 5 & 0xfffffffc) + 4;
      uVar15 = 0;
      puVar12 = param_1;
      puVar14 = param_1 + iVar13 * 2;
      do {
        uVar9 = puVar14[3];
        HintPreloadData(puVar14 + 0x24);
        *puVar12 = puVar14[2];
        puVar12[1] = uVar9;
        uVar15 = uVar15 + 4;
        uVar9 = puVar14[5];
        puVar12[2] = puVar14[4];
        puVar12[3] = uVar9;
        uVar9 = puVar14[7];
        puVar12[4] = puVar14[6];
        puVar12[5] = uVar9;
        uVar9 = puVar14[9];
        puVar12[6] = puVar14[8];
        puVar12[7] = uVar9;
        puVar12 = puVar12 + 8;
        puVar14 = puVar14 + 8;
      } while (uVar10 != uVar15);
    }
    puVar12 = param_1 + (iVar13 + uVar10) * 2;
    do {
      iVar5 = uVar10 * 2;
      uVar9 = puVar12[3];
      uVar10 = uVar10 + 1;
      param_1[iVar5] = puVar12[2];
      (param_1 + iVar5)[1] = uVar9;
      puVar12 = puVar12 + 2;
    } while (uVar10 < uVar11);
  }
  return uVar11 - 1;
}

