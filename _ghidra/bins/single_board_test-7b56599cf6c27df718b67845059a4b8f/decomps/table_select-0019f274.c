
void table_select(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  int iVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  uint uVar38;
  int iVar39;
  undefined4 uVar40;
  int iVar41;
  undefined4 uVar42;
  int iVar43;
  undefined4 uVar44;
  
  uVar38 = param_3 + ((int)param_3 >> 0x1f & param_3) * -2 & 0xff;
  memset(param_1,0,0x28);
  *param_1 = 1;
  memset(param_1 + 10,0,0x28);
  param_1[10] = 1;
  memset(param_1 + 0x14,0,0x28);
  param_2 = param_2 * 0x3c0;
  iVar35 = (uVar38 ^ 1) - 1;
  uVar6 = *(undefined4 *)(&k25519Precomp + param_2);
  if (-1 < iVar35) {
    uVar6 = *param_1;
  }
  *param_1 = uVar6;
  uVar24 = *(undefined4 *)(&DAT_00228648 + param_2);
  if (-1 < iVar35) {
    uVar24 = param_1[1];
  }
  param_1[1] = uVar24;
  iVar39 = (uVar38 ^ 2) - 1;
  uVar25 = *(undefined4 *)(&DAT_0022864c + param_2);
  if (-1 < iVar35) {
    uVar25 = param_1[2];
  }
  param_1[2] = uVar25;
  uVar26 = *(undefined4 *)(&DAT_00228650 + param_2);
  if (-1 < iVar35) {
    uVar26 = param_1[3];
  }
  param_1[3] = uVar26;
  uVar27 = *(undefined4 *)(&DAT_00228654 + param_2);
  if (-1 < iVar35) {
    uVar27 = param_1[4];
  }
  param_1[4] = uVar27;
  uVar28 = *(undefined4 *)(&DAT_00228658 + param_2);
  if (-1 < iVar35) {
    uVar28 = param_1[5];
  }
  param_1[5] = uVar28;
  uVar29 = *(undefined4 *)(&DAT_0022865c + param_2);
  if (-1 < iVar35) {
    uVar29 = param_1[6];
  }
  param_1[6] = uVar29;
  uVar30 = *(undefined4 *)(&DAT_00228660 + param_2);
  if (-1 < iVar35) {
    uVar30 = param_1[7];
  }
  param_1[7] = uVar30;
  uVar31 = *(undefined4 *)(&DAT_00228664 + param_2);
  if (-1 < iVar35) {
    uVar31 = param_1[8];
  }
  param_1[8] = uVar31;
  uVar7 = *(undefined4 *)(&DAT_00228668 + param_2);
  if (-1 < iVar35) {
    uVar7 = param_1[9];
  }
  param_1[9] = uVar7;
  uVar8 = *(undefined4 *)(&DAT_0022866c + param_2);
  if (-1 < iVar35) {
    uVar8 = param_1[10];
  }
  param_1[10] = uVar8;
  uVar9 = *(undefined4 *)(&DAT_00228670 + param_2);
  if (-1 < iVar35) {
    uVar9 = param_1[0xb];
  }
  param_1[0xb] = uVar9;
  uVar36 = *(undefined4 *)(&DAT_00228674 + param_2);
  if (-1 < iVar35) {
    uVar36 = param_1[0xc];
  }
  param_1[0xc] = uVar36;
  uVar10 = *(undefined4 *)(&DAT_00228678 + param_2);
  if (-1 < iVar35) {
    uVar10 = param_1[0xd];
  }
  param_1[0xd] = uVar10;
  uVar11 = *(undefined4 *)(&DAT_0022867c + param_2);
  if (-1 < iVar35) {
    uVar11 = param_1[0xe];
  }
  param_1[0xe] = uVar11;
  uVar12 = *(undefined4 *)(&DAT_00228680 + param_2);
  if (-1 < iVar35) {
    uVar12 = param_1[0xf];
  }
  param_1[0xf] = uVar12;
  uVar18 = *(undefined4 *)(&DAT_00228684 + param_2);
  if (-1 < iVar35) {
    uVar18 = param_1[0x10];
  }
  param_1[0x10] = uVar18;
  uVar13 = *(undefined4 *)(&DAT_00228688 + param_2);
  if (-1 < iVar35) {
    uVar13 = param_1[0x11];
  }
  param_1[0x11] = uVar13;
  uVar14 = *(undefined4 *)(&DAT_0022868c + param_2);
  if (-1 < iVar35) {
    uVar14 = param_1[0x12];
  }
  param_1[0x12] = uVar14;
  uVar1 = *(undefined4 *)(&DAT_00228690 + param_2);
  if (-1 < iVar35) {
    uVar1 = param_1[0x13];
  }
  param_1[0x13] = uVar1;
  iVar3 = *(int *)(&DAT_00228694 + param_2);
  if (-1 < iVar35) {
    iVar3 = param_1[0x14];
  }
  param_1[0x14] = iVar3;
  iVar4 = *(int *)(&DAT_00228698 + param_2);
  if (-1 < iVar35) {
    iVar4 = param_1[0x15];
  }
  param_1[0x15] = iVar4;
  iVar43 = *(int *)(&DAT_0022869c + param_2);
  if (-1 < iVar35) {
    iVar43 = param_1[0x16];
  }
  param_1[0x16] = iVar43;
  iVar19 = *(int *)(&DAT_002286a0 + param_2);
  if (-1 < iVar35) {
    iVar19 = param_1[0x17];
  }
  param_1[0x17] = iVar19;
  iVar20 = *(int *)(&DAT_002286a4 + param_2);
  if (-1 < iVar35) {
    iVar20 = param_1[0x18];
  }
  param_1[0x18] = iVar20;
  iVar21 = *(int *)(&DAT_002286a8 + param_2);
  if (-1 < iVar35) {
    iVar21 = param_1[0x19];
  }
  param_1[0x19] = iVar21;
  iVar5 = *(int *)(&DAT_002286ac + param_2);
  if (-1 < iVar35) {
    iVar5 = param_1[0x1a];
  }
  param_1[0x1a] = iVar5;
  iVar22 = *(int *)(&DAT_002286b0 + param_2);
  if (-1 < iVar35) {
    iVar22 = param_1[0x1b];
  }
  param_1[0x1b] = iVar22;
  iVar41 = param_1[0x1c];
  if (iVar35 < 0) {
    iVar41 = *(int *)(&DAT_002286b4 + param_2);
  }
  param_1[0x1c] = iVar41;
  iVar23 = *(int *)(&DAT_002286b8 + param_2);
  if (-1 < iVar35) {
    iVar23 = param_1[0x1d];
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_002286bc + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002286c0 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002286c4 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002286c8 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_002286cc + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002286d0 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002286d4 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002286d8 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002286dc + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 3) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002286e0 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002286e4 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002286e8 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002286ec + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002286f0 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002286f4 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002286f8 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002286fc + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00228700 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00228704 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00228708 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_0022870c + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_00228710 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_00228714 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_00228718 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_0022871c + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_00228720 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_00228724 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_00228728 + param_2);
  }
  param_1[0x1b] = iVar22;
  iVar2 = *(int *)(&DAT_0022872c + param_2);
  if (-1 < iVar39) {
    iVar2 = iVar41;
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_00228730 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00228734 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00228738 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_0022873c + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00228740 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00228744 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00228748 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_0022874c + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00228750 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00228754 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 4) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00228758 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_0022875c + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00228760 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00228764 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00228768 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_0022876c + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00228770 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00228774 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00228778 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_0022877c + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00228780 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00228784 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00228788 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_0022878c + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00228790 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00228794 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00228798 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_0022879c + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_002287a0 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_002287a4 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_002287a8 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_002287ac + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002287b0 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002287b4 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002287b8 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_002287bc + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002287c0 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002287c4 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002287c8 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002287cc + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 5) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002287d0 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002287d4 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002287d8 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002287dc + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002287e0 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002287e4 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002287e8 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002287ec + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002287f0 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002287f4 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002287f8 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002287fc + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_00228800 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_00228804 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_00228808 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_0022880c + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_00228810 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_00228814 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_00228818 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_0022881c + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_00228820 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00228824 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00228828 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_0022882c + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00228830 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00228834 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00228838 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_0022883c + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00228840 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00228844 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 6) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00228848 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_0022884c + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00228850 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00228854 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00228858 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_0022885c + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00228860 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00228864 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00228868 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_0022886c + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00228870 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00228874 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00228878 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_0022887c + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00228880 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00228884 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00228888 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_0022888c + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_00228890 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00228894 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_00228898 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_0022889c + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002288a0 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002288a4 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002288a8 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_002288ac + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002288b0 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002288b4 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002288b8 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002288bc + param_2);
  }
  iVar41 = (uVar38 ^ 8) - 1;
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 7) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002288c0 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002288c4 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002288c8 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002288cc + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002288d0 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002288d4 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002288d8 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002288dc + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002288e0 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002288e4 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002288e8 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002288ec + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002288f0 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002288f4 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002288f8 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002288fc + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_00228900 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_00228904 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_00228908 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_0022890c + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_00228910 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00228914 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00228918 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_0022891c + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00228920 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00228924 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00228928 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_0022892c + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00228930 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00228934 + param_2);
  }
  param_1[8] = uVar31;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00228938 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_0022893c + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00228940 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00228944 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00228948 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_0022894c + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00228950 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00228954 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00228958 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_0022895c + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00228960 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00228964 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00228968 + param_2);
  }
  param_1[0x15] = iVar4;
  iVar39 = *(int *)(&DAT_0022896c + param_2);
  if (-1 < iVar35) {
    iVar39 = iVar43;
  }
  param_1[0x16] = iVar39;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00228970 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00228974 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00228978 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_0022897c + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_00228980 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00228984 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_00228988 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar41 < 0) {
    uVar6 = *(undefined4 *)(&DAT_0022898c + param_2);
  }
  *param_1 = uVar6;
  if (iVar41 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00228990 + param_2);
  }
  param_1[1] = uVar24;
  uVar42 = *(undefined4 *)(&DAT_00228994 + param_2);
  if (-1 < iVar41) {
    uVar42 = uVar25;
  }
  param_1[2] = uVar42;
  if (iVar41 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00228998 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar41 < 0) {
    uVar27 = *(undefined4 *)(&DAT_0022899c + param_2);
  }
  param_1[4] = uVar27;
  if (iVar41 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002289a0 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar41 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002289a4 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar41 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002289a8 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar41 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002289ac + param_2);
  }
  param_1[8] = uVar31;
  if (iVar41 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002289b0 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar41 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002289b4 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar41 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002289b8 + param_2);
  }
  param_1[0xb] = uVar9;
  uVar25 = *(undefined4 *)(&DAT_002289bc + param_2);
  if (-1 < iVar41) {
    uVar25 = uVar36;
  }
  param_1[0xc] = uVar25;
  if (iVar41 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002289c0 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar41 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002289c4 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar41 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002289c8 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar41 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002289cc + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar41 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002289d0 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar41 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002289d4 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar41 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002289d8 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar41 < 0) {
    iVar3 = *(int *)(&DAT_002289dc + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar41 < 0) {
    iVar4 = *(int *)(&DAT_002289e0 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar41 < 0) {
    iVar39 = *(int *)(&DAT_002289e4 + param_2);
  }
  param_1[0x16] = iVar39;
  if (iVar41 < 0) {
    iVar19 = *(int *)(&DAT_002289e8 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar41 < 0) {
    iVar20 = *(int *)(&DAT_002289ec + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar41 < 0) {
    iVar21 = *(int *)(&DAT_002289f0 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar41 < 0) {
    iVar5 = *(int *)(&DAT_002289f4 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar41 < 0) {
    iVar22 = *(int *)(&DAT_002289f8 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar41 < 0) {
    iVar2 = *(int *)(&DAT_002289fc + param_2);
  }
  param_1[0x1c] = iVar2;
  uVar15 = param_1[10];
  uVar32 = param_1[0xb];
  uVar36 = param_1[0xc];
  if (iVar41 < 0) {
    iVar23 = *(int *)(&DAT_00228a00 + param_2);
  }
  uVar16 = param_1[4];
  uVar33 = param_1[5];
  uVar37 = param_1[6];
  uVar40 = param_1[7];
  uVar17 = param_1[8];
  uVar34 = param_1[9];
  uVar44 = param_1[2];
  if (-1 < (int)param_3) {
    uVar44 = uVar25;
  }
  param_1[0xc] = uVar44;
  uVar25 = param_1[1];
  if (-1 < (int)param_3) {
    uVar25 = uVar9;
  }
  if ((int)param_3 < 0) {
    uVar8 = *param_1;
  }
  param_1[10] = uVar8;
  if ((int)param_3 < 0) {
    uVar31 = param_1[0x12];
  }
  uVar8 = param_1[0x13];
  if (-1 < (int)param_3) {
    uVar8 = uVar7;
  }
  param_1[8] = uVar31;
  if ((int)param_3 < 0) {
    uVar27 = param_1[0xe];
    uVar29 = param_1[0x10];
    uVar30 = param_1[0x11];
    uVar28 = param_1[0xf];
  }
  param_1[4] = uVar27;
  param_1[0xb] = uVar25;
  uVar25 = param_1[0xd];
  if (-1 < (int)param_3) {
    uVar25 = uVar26;
  }
  param_1[7] = uVar30;
  if (-1 < (int)param_3) {
    uVar32 = uVar24;
    uVar36 = uVar42;
  }
  param_1[6] = uVar29;
  param_1[9] = uVar8;
  if (-1 < (int)param_3) {
    uVar15 = uVar6;
  }
  param_1[5] = uVar28;
  uVar6 = param_1[3];
  if (-1 < (int)param_3) {
    uVar6 = uVar10;
  }
  if ((int)param_3 < 0) {
    uVar12 = uVar33;
  }
  param_1[0xf] = uVar12;
  if ((int)param_3 < 0) {
    uVar11 = uVar16;
  }
  iVar35 = -iVar3;
  if (-1 < (int)param_3) {
    iVar35 = iVar3;
  }
  param_1[0x14] = iVar35;
  iVar35 = -iVar4;
  if (-1 < (int)param_3) {
    iVar35 = iVar4;
  }
  param_1[0x15] = iVar35;
  iVar35 = -iVar39;
  if (-1 < (int)param_3) {
    iVar35 = iVar39;
  }
  param_1[0x16] = iVar35;
  iVar35 = -iVar19;
  if (-1 < (int)param_3) {
    iVar35 = iVar19;
  }
  param_1[3] = uVar25;
  iVar39 = -iVar20;
  if (-1 < (int)param_3) {
    iVar39 = iVar20;
  }
  param_1[1] = uVar32;
  *param_1 = uVar15;
  iVar3 = -iVar21;
  if (-1 < (int)param_3) {
    iVar3 = iVar21;
  }
  param_1[0xd] = uVar6;
  iVar4 = -iVar2;
  if (-1 < (int)param_3) {
    iVar4 = iVar2;
  }
  param_1[2] = uVar36;
  param_1[0xe] = uVar11;
  iVar20 = -iVar22;
  iVar43 = -iVar5;
  iVar19 = -iVar23;
  if (-1 < (int)param_3) {
    iVar20 = iVar22;
    iVar43 = iVar5;
    iVar19 = iVar23;
  }
  param_1[0x17] = iVar35;
  param_1[0x18] = iVar39;
  if (-1 < (int)param_3) {
    uVar34 = uVar1;
  }
  param_1[0x13] = uVar34;
  if ((int)param_3 < 0) {
    uVar14 = uVar17;
  }
  param_1[0x12] = uVar14;
  if (-1 < (int)param_3) {
    uVar40 = uVar13;
  }
  param_1[0x11] = uVar40;
  param_1[0x19] = iVar3;
  if (-1 < (int)param_3) {
    uVar37 = uVar18;
  }
  param_1[0x1a] = iVar43;
  param_1[0x10] = uVar37;
  param_1[0x1b] = iVar20;
  param_1[0x1c] = iVar4;
  param_1[0x1d] = iVar19;
  return;
}

