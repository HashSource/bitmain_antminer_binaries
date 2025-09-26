
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
  uVar24 = *(undefined4 *)(&DAT_00234124 + param_2);
  if (-1 < iVar35) {
    uVar24 = param_1[1];
  }
  param_1[1] = uVar24;
  iVar39 = (uVar38 ^ 2) - 1;
  uVar25 = *(undefined4 *)(&DAT_00234128 + param_2);
  if (-1 < iVar35) {
    uVar25 = param_1[2];
  }
  param_1[2] = uVar25;
  uVar26 = *(undefined4 *)(&DAT_0023412c + param_2);
  if (-1 < iVar35) {
    uVar26 = param_1[3];
  }
  param_1[3] = uVar26;
  uVar27 = *(undefined4 *)(&DAT_00234130 + param_2);
  if (-1 < iVar35) {
    uVar27 = param_1[4];
  }
  param_1[4] = uVar27;
  uVar28 = *(undefined4 *)(&DAT_00234134 + param_2);
  if (-1 < iVar35) {
    uVar28 = param_1[5];
  }
  param_1[5] = uVar28;
  uVar29 = *(undefined4 *)(&DAT_00234138 + param_2);
  if (-1 < iVar35) {
    uVar29 = param_1[6];
  }
  param_1[6] = uVar29;
  uVar30 = *(undefined4 *)(&DAT_0023413c + param_2);
  if (-1 < iVar35) {
    uVar30 = param_1[7];
  }
  param_1[7] = uVar30;
  uVar31 = *(undefined4 *)(&DAT_00234140 + param_2);
  if (-1 < iVar35) {
    uVar31 = param_1[8];
  }
  param_1[8] = uVar31;
  uVar7 = *(undefined4 *)(&DAT_00234144 + param_2);
  if (-1 < iVar35) {
    uVar7 = param_1[9];
  }
  param_1[9] = uVar7;
  uVar8 = *(undefined4 *)(&DAT_00234148 + param_2);
  if (-1 < iVar35) {
    uVar8 = param_1[10];
  }
  param_1[10] = uVar8;
  uVar9 = *(undefined4 *)(&DAT_0023414c + param_2);
  if (-1 < iVar35) {
    uVar9 = param_1[0xb];
  }
  param_1[0xb] = uVar9;
  uVar36 = *(undefined4 *)(&DAT_00234150 + param_2);
  if (-1 < iVar35) {
    uVar36 = param_1[0xc];
  }
  param_1[0xc] = uVar36;
  uVar10 = *(undefined4 *)(&DAT_00234154 + param_2);
  if (-1 < iVar35) {
    uVar10 = param_1[0xd];
  }
  param_1[0xd] = uVar10;
  uVar11 = *(undefined4 *)(&DAT_00234158 + param_2);
  if (-1 < iVar35) {
    uVar11 = param_1[0xe];
  }
  param_1[0xe] = uVar11;
  uVar12 = *(undefined4 *)(&DAT_0023415c + param_2);
  if (-1 < iVar35) {
    uVar12 = param_1[0xf];
  }
  param_1[0xf] = uVar12;
  uVar18 = *(undefined4 *)(&DAT_00234160 + param_2);
  if (-1 < iVar35) {
    uVar18 = param_1[0x10];
  }
  param_1[0x10] = uVar18;
  uVar13 = *(undefined4 *)(&DAT_00234164 + param_2);
  if (-1 < iVar35) {
    uVar13 = param_1[0x11];
  }
  param_1[0x11] = uVar13;
  uVar14 = *(undefined4 *)(&DAT_00234168 + param_2);
  if (-1 < iVar35) {
    uVar14 = param_1[0x12];
  }
  param_1[0x12] = uVar14;
  uVar1 = *(undefined4 *)(&DAT_0023416c + param_2);
  if (-1 < iVar35) {
    uVar1 = param_1[0x13];
  }
  param_1[0x13] = uVar1;
  iVar3 = *(int *)(&DAT_00234170 + param_2);
  if (-1 < iVar35) {
    iVar3 = param_1[0x14];
  }
  param_1[0x14] = iVar3;
  iVar4 = *(int *)(&DAT_00234174 + param_2);
  if (-1 < iVar35) {
    iVar4 = param_1[0x15];
  }
  param_1[0x15] = iVar4;
  iVar43 = *(int *)(&DAT_00234178 + param_2);
  if (-1 < iVar35) {
    iVar43 = param_1[0x16];
  }
  param_1[0x16] = iVar43;
  iVar19 = *(int *)(&DAT_0023417c + param_2);
  if (-1 < iVar35) {
    iVar19 = param_1[0x17];
  }
  param_1[0x17] = iVar19;
  iVar20 = *(int *)(&DAT_00234180 + param_2);
  if (-1 < iVar35) {
    iVar20 = param_1[0x18];
  }
  param_1[0x18] = iVar20;
  iVar21 = *(int *)(&DAT_00234184 + param_2);
  if (-1 < iVar35) {
    iVar21 = param_1[0x19];
  }
  param_1[0x19] = iVar21;
  iVar5 = *(int *)(&DAT_00234188 + param_2);
  if (-1 < iVar35) {
    iVar5 = param_1[0x1a];
  }
  param_1[0x1a] = iVar5;
  iVar22 = *(int *)(&DAT_0023418c + param_2);
  if (-1 < iVar35) {
    iVar22 = param_1[0x1b];
  }
  param_1[0x1b] = iVar22;
  iVar41 = param_1[0x1c];
  if (iVar35 < 0) {
    iVar41 = *(int *)(&DAT_00234190 + param_2);
  }
  param_1[0x1c] = iVar41;
  iVar23 = *(int *)(&DAT_00234194 + param_2);
  if (-1 < iVar35) {
    iVar23 = param_1[0x1d];
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234198 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_0023419c + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002341a0 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002341a4 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_002341a8 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002341ac + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002341b0 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002341b4 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002341b8 + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 3) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002341bc + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002341c0 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002341c4 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002341c8 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002341cc + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002341d0 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002341d4 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002341d8 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002341dc + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002341e0 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002341e4 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002341e8 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002341ec + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002341f0 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002341f4 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002341f8 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_002341fc + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_00234200 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_00234204 + param_2);
  }
  param_1[0x1b] = iVar22;
  iVar2 = *(int *)(&DAT_00234208 + param_2);
  if (-1 < iVar39) {
    iVar2 = iVar41;
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_0023420c + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234210 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00234214 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00234218 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_0023421c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234220 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00234224 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00234228 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0023422c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00234230 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 4) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00234234 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00234238 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_0023423c + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00234240 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00234244 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00234248 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_0023424c + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00234250 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00234254 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00234258 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_0023425c + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00234260 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00234264 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_00234268 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_0023426c + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00234270 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00234274 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00234278 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_0023427c + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00234280 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_00234284 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234288 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_0023428c + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00234290 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00234294 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234298 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_0023429c + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_002342a0 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_002342a4 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002342a8 + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 5) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002342ac + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002342b0 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002342b4 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002342b8 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002342bc + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002342c0 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002342c4 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002342c8 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002342cc + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002342d0 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002342d4 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002342d8 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002342dc + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002342e0 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002342e4 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002342e8 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_002342ec + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_002342f0 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_002342f4 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_002342f8 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_002342fc + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234300 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00234304 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00234308 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_0023430c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234310 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00234314 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00234318 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0023431c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00234320 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 6) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00234324 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00234328 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_0023432c + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00234330 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00234334 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00234338 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_0023433c + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00234340 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00234344 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00234348 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_0023434c + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00234350 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00234354 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_00234358 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_0023435c + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00234360 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00234364 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00234368 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_0023436c + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00234370 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_00234374 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234378 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_0023437c + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00234380 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00234384 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234388 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_0023438c + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00234390 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00234394 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00234398 + param_2);
  }
  iVar41 = (uVar38 ^ 8) - 1;
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 7) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_0023439c + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002343a0 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002343a4 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002343a8 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002343ac + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002343b0 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002343b4 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002343b8 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002343bc + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002343c0 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002343c4 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002343c8 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002343cc + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002343d0 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002343d4 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002343d8 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_002343dc + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_002343e0 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_002343e4 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_002343e8 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_002343ec + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_002343f0 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002343f4 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002343f8 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002343fc + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234400 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00234404 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00234408 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0023440c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00234410 + param_2);
  }
  param_1[8] = uVar31;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00234414 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00234418 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_0023441c + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00234420 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00234424 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00234428 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_0023442c + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00234430 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00234434 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00234438 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_0023443c + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00234440 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_00234444 + param_2);
  }
  param_1[0x15] = iVar4;
  iVar39 = *(int *)(&DAT_00234448 + param_2);
  if (-1 < iVar35) {
    iVar39 = iVar43;
  }
  param_1[0x16] = iVar39;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_0023444c + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00234450 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_00234454 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00234458 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_0023445c + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00234460 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_00234464 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar41 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00234468 + param_2);
  }
  *param_1 = uVar6;
  if (iVar41 < 0) {
    uVar24 = *(undefined4 *)(&DAT_0023446c + param_2);
  }
  param_1[1] = uVar24;
  uVar42 = *(undefined4 *)(&DAT_00234470 + param_2);
  if (-1 < iVar41) {
    uVar42 = uVar25;
  }
  param_1[2] = uVar42;
  if (iVar41 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00234474 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar41 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00234478 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar41 < 0) {
    uVar28 = *(undefined4 *)(&DAT_0023447c + param_2);
  }
  param_1[5] = uVar28;
  if (iVar41 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00234480 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar41 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00234484 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar41 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00234488 + param_2);
  }
  param_1[8] = uVar31;
  if (iVar41 < 0) {
    uVar7 = *(undefined4 *)(&DAT_0023448c + param_2);
  }
  param_1[9] = uVar7;
  if (iVar41 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00234490 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar41 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00234494 + param_2);
  }
  param_1[0xb] = uVar9;
  uVar25 = *(undefined4 *)(&DAT_00234498 + param_2);
  if (-1 < iVar41) {
    uVar25 = uVar36;
  }
  param_1[0xc] = uVar25;
  if (iVar41 < 0) {
    uVar10 = *(undefined4 *)(&DAT_0023449c + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar41 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002344a0 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar41 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002344a4 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar41 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002344a8 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar41 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002344ac + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar41 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002344b0 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar41 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002344b4 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar41 < 0) {
    iVar3 = *(int *)(&DAT_002344b8 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar41 < 0) {
    iVar4 = *(int *)(&DAT_002344bc + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar41 < 0) {
    iVar39 = *(int *)(&DAT_002344c0 + param_2);
  }
  param_1[0x16] = iVar39;
  if (iVar41 < 0) {
    iVar19 = *(int *)(&DAT_002344c4 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar41 < 0) {
    iVar20 = *(int *)(&DAT_002344c8 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar41 < 0) {
    iVar21 = *(int *)(&DAT_002344cc + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar41 < 0) {
    iVar5 = *(int *)(&DAT_002344d0 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar41 < 0) {
    iVar22 = *(int *)(&DAT_002344d4 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar41 < 0) {
    iVar2 = *(int *)(&DAT_002344d8 + param_2);
  }
  param_1[0x1c] = iVar2;
  uVar15 = param_1[10];
  uVar32 = param_1[0xb];
  uVar36 = param_1[0xc];
  if (iVar41 < 0) {
    iVar23 = *(int *)(&DAT_002344dc + param_2);
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

