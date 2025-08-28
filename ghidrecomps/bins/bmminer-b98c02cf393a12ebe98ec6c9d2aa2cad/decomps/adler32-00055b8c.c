
undefined8 adler32(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  
  uVar20 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  if (param_3 == 1) {
    param_1 = *param_2 + param_1;
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    uVar20 = param_1 + uVar20;
    if (0xfff0 < uVar20) {
      uVar20 = uVar20 - 0xfff1;
    }
    uVar1 = param_1 | uVar20 << 0x10;
    goto LAB_00055be4;
  }
  if (param_2 == (byte *)0x0) {
    uVar1 = 1;
    goto LAB_00055be4;
  }
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      pbVar11 = param_2;
      do {
        pbVar10 = pbVar11 + 1;
        param_1 = param_1 + *pbVar11;
        uVar20 = uVar20 + param_1;
        pbVar11 = pbVar10;
      } while (pbVar10 != param_2 + param_3);
    }
    uVar1 = param_1;
    if (0xfff0 < param_1) {
      uVar1 = param_1 - 0xff00;
    }
    param_2 = (byte *)(uVar20 * -0x7ff87f8f);
    if (0xfff0 < param_1) {
      uVar1 = uVar1 - 0xf1;
    }
    uVar1 = uVar1 | (uVar20 % 0xfff1) * 0x10000;
    goto LAB_00055be4;
  }
  pbVar11 = param_2;
  uVar1 = param_3;
  if (param_3 < 0x15b0) {
LAB_00055cdc:
    do {
      param_3 = param_3 - 0x10;
      iVar2 = param_1 + *pbVar11;
      iVar17 = (uint)pbVar11[1] + iVar2;
      iVar8 = (uint)pbVar11[2] + iVar17;
      iVar9 = iVar8 + (uint)pbVar11[3];
      iVar3 = iVar9 + (uint)pbVar11[4];
      iVar4 = iVar3 + (uint)pbVar11[5];
      iVar18 = (uint)pbVar11[6] + iVar4;
      iVar13 = (uint)pbVar11[7] + iVar18;
      iVar14 = iVar13 + (uint)pbVar11[8];
      iVar5 = (uint)pbVar11[9] + iVar14;
      iVar6 = iVar5 + (uint)pbVar11[10];
      iVar19 = (uint)pbVar11[0xb] + iVar6;
      iVar15 = (uint)pbVar11[0xc] + iVar19;
      iVar16 = iVar15 + (uint)pbVar11[0xd];
      iVar7 = (uint)pbVar11[0xe] + iVar16;
      param_1 = iVar7 + (uint)pbVar11[0xf];
      uVar20 = uVar20 + iVar2 + iVar17 + iVar8 + iVar9 + iVar3 + iVar4 + iVar18 + iVar13 + iVar14 +
                        iVar5 + iVar6 + iVar19 + iVar15 + iVar16 + iVar7 + param_1;
      pbVar11 = pbVar11 + 0x10;
    } while (0xf < param_3);
    param_3 = uVar1 & 0xf;
    pbVar11 = param_2 + (uVar1 - 0x10 & 0xfffffff0) + 0x10;
    if (param_3 != 0) goto LAB_00055d6e;
  }
  else {
    do {
      param_3 = param_3 - 0x15b0;
      pbVar10 = pbVar11 + 0x15b0;
      do {
        iVar2 = param_1 + *pbVar11;
        iVar17 = iVar2 + (uint)pbVar11[1];
        iVar13 = iVar17 + (uint)pbVar11[2];
        iVar14 = iVar13 + (uint)pbVar11[3];
        iVar6 = iVar14 + (uint)pbVar11[4];
        iVar7 = iVar6 + (uint)pbVar11[5];
        iVar3 = iVar7 + (uint)pbVar11[6];
        iVar4 = iVar3 + (uint)pbVar11[7];
        iVar18 = iVar4 + (uint)pbVar11[8];
        iVar19 = iVar18 + (uint)pbVar11[9];
        iVar15 = iVar19 + (uint)pbVar11[10];
        iVar16 = iVar15 + (uint)pbVar11[0xb];
        iVar8 = iVar16 + (uint)pbVar11[0xc];
        pbVar12 = pbVar11 + 0xf;
        iVar9 = iVar8 + (uint)pbVar11[0xd];
        iVar5 = iVar9 + (uint)pbVar11[0xe];
        pbVar11 = pbVar11 + 0x10;
        param_1 = iVar5 + (uint)*pbVar12;
        uVar20 = uVar20 + iVar17 + iVar2 + iVar13 + iVar14 + iVar6 + iVar7 + iVar3 + iVar4 + iVar18
                          + iVar19 + iVar15 + iVar16 + iVar8 + iVar9 + iVar5 + param_1;
      } while (pbVar11 != pbVar10);
      param_1 = param_1 % 0xfff1;
      param_2 = (byte *)((uVar20 / 0xfff1) * 0xfff1);
      uVar20 = uVar20 % 0xfff1;
    } while (0x15af < param_3);
    if (param_3 == 0) {
      uVar1 = param_1 | uVar20 * 0x10000;
      goto LAB_00055be4;
    }
    param_2 = pbVar11;
    uVar1 = param_3;
    if (0xf < param_3) goto LAB_00055cdc;
LAB_00055d6e:
    pbVar10 = pbVar11;
    do {
      pbVar12 = pbVar10 + 1;
      param_1 = param_1 + *pbVar10;
      uVar20 = uVar20 + param_1;
      pbVar10 = pbVar12;
    } while (pbVar12 != pbVar11 + param_3);
  }
  param_2 = (byte *)((uVar20 / 0xfff1) * 0xfff);
  uVar1 = param_1 % 0xfff1 | (uVar20 % 0xfff1) * 0x10000;
LAB_00055be4:
  return CONCAT44(param_2,uVar1);
}

