
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
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  byte *pbVar20;
  
  uVar19 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  if (param_3 == 1) {
    param_1 = *param_2 + param_1;
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    uVar19 = param_1 + uVar19;
    if (0xfff0 < uVar19) {
      uVar19 = uVar19 - 0xfff1;
    }
    uVar1 = param_1 | uVar19 << 0x10;
    goto LAB_00055be4;
  }
  if (param_2 == (byte *)0x0) {
    uVar1 = 1;
    goto LAB_00055be4;
  }
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      do {
        pbVar10 = param_2 + 1;
        param_1 = param_1 + *param_2;
        uVar19 = uVar19 + param_1;
        param_2 = pbVar10;
      } while (pbVar10 != param_2 + param_3);
    }
    uVar1 = param_1;
    if (0xfff0 < param_1) {
      uVar1 = param_1 - 0xff00;
    }
    param_2 = (byte *)(uVar19 * -0x7ff87f8f);
    if (0xfff0 < param_1) {
      uVar1 = uVar1 - 0xf1;
    }
    uVar1 = uVar1 | (uVar19 % 0xfff1) * 0x10000;
    goto LAB_00055be4;
  }
  pbVar10 = param_2;
  uVar1 = param_3;
  if (param_3 < 0x15b0) {
LAB_00055cdc:
    do {
      param_3 = param_3 - 0x10;
      iVar2 = param_1 + *pbVar10;
      iVar16 = (uint)pbVar10[1] + iVar2;
      iVar8 = (uint)pbVar10[2] + iVar16;
      iVar9 = iVar8 + (uint)pbVar10[3];
      iVar3 = iVar9 + (uint)pbVar10[4];
      iVar4 = iVar3 + (uint)pbVar10[5];
      iVar17 = (uint)pbVar10[6] + iVar4;
      iVar12 = (uint)pbVar10[7] + iVar17;
      iVar13 = iVar12 + (uint)pbVar10[8];
      iVar5 = (uint)pbVar10[9] + iVar13;
      iVar6 = iVar5 + (uint)pbVar10[10];
      iVar18 = (uint)pbVar10[0xb] + iVar6;
      iVar14 = (uint)pbVar10[0xc] + iVar18;
      iVar15 = iVar14 + (uint)pbVar10[0xd];
      iVar7 = (uint)pbVar10[0xe] + iVar15;
      param_1 = iVar7 + (uint)pbVar10[0xf];
      uVar19 = uVar19 + iVar2 + iVar16 + iVar8 + iVar9 + iVar3 + iVar4 + iVar17 + iVar12 + iVar13 +
                        iVar5 + iVar6 + iVar18 + iVar14 + iVar15 + iVar7 + param_1;
      pbVar10 = pbVar10 + 0x10;
    } while (0xf < param_3);
    param_3 = uVar1 & 0xf;
    pbVar10 = param_2 + (uVar1 - 0x10 & 0xfffffff0) + 0x10;
    if (param_3 != 0) goto LAB_00055d6e;
  }
  else {
    do {
      param_3 = param_3 - 0x15b0;
      pbVar20 = pbVar10 + 0x15b0;
      do {
        iVar2 = param_1 + *pbVar10;
        iVar16 = iVar2 + (uint)pbVar10[1];
        iVar12 = iVar16 + (uint)pbVar10[2];
        iVar13 = iVar12 + (uint)pbVar10[3];
        iVar6 = iVar13 + (uint)pbVar10[4];
        iVar7 = iVar6 + (uint)pbVar10[5];
        iVar3 = iVar7 + (uint)pbVar10[6];
        iVar4 = iVar3 + (uint)pbVar10[7];
        iVar17 = iVar4 + (uint)pbVar10[8];
        iVar18 = iVar17 + (uint)pbVar10[9];
        iVar14 = iVar18 + (uint)pbVar10[10];
        iVar15 = iVar14 + (uint)pbVar10[0xb];
        iVar8 = iVar15 + (uint)pbVar10[0xc];
        pbVar11 = pbVar10 + 0xf;
        iVar9 = iVar8 + (uint)pbVar10[0xd];
        iVar5 = iVar9 + (uint)pbVar10[0xe];
        pbVar10 = pbVar10 + 0x10;
        param_1 = iVar5 + (uint)*pbVar11;
        uVar19 = uVar19 + iVar16 + iVar2 + iVar12 + iVar13 + iVar6 + iVar7 + iVar3 + iVar4 + iVar17
                          + iVar18 + iVar14 + iVar15 + iVar8 + iVar9 + iVar5 + param_1;
      } while (pbVar10 != pbVar20);
      param_1 = param_1 % 0xfff1;
      param_2 = (byte *)((uVar19 / 0xfff1) * 0xfff1);
      uVar19 = uVar19 % 0xfff1;
    } while (0x15af < param_3);
    if (param_3 == 0) {
      uVar1 = param_1 | uVar19 * 0x10000;
      goto LAB_00055be4;
    }
    param_2 = pbVar10;
    uVar1 = param_3;
    if (0xf < param_3) goto LAB_00055cdc;
LAB_00055d6e:
    pbVar20 = pbVar10;
    do {
      pbVar11 = pbVar20 + 1;
      param_1 = param_1 + *pbVar20;
      uVar19 = uVar19 + param_1;
      pbVar20 = pbVar11;
    } while (pbVar11 != pbVar10 + param_3);
  }
  param_2 = (byte *)((uVar19 / 0xfff1) * 0xfff);
  uVar1 = param_1 % 0xfff1 | (uVar19 % 0xfff1) * 0x10000;
LAB_00055be4:
  return CONCAT44(param_2,uVar1);
}

