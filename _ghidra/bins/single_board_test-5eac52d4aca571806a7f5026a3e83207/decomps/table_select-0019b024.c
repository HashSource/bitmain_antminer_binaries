
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
  uVar24 = *(undefined4 *)(&DAT_00222f1c + param_2);
  if (-1 < iVar35) {
    uVar24 = param_1[1];
  }
  param_1[1] = uVar24;
  iVar39 = (uVar38 ^ 2) - 1;
  uVar25 = *(undefined4 *)(&DAT_00222f20 + param_2);
  if (-1 < iVar35) {
    uVar25 = param_1[2];
  }
  param_1[2] = uVar25;
  uVar26 = *(undefined4 *)(&DAT_00222f24 + param_2);
  if (-1 < iVar35) {
    uVar26 = param_1[3];
  }
  param_1[3] = uVar26;
  uVar27 = *(undefined4 *)(&DAT_00222f28 + param_2);
  if (-1 < iVar35) {
    uVar27 = param_1[4];
  }
  param_1[4] = uVar27;
  uVar28 = *(undefined4 *)(&DAT_00222f2c + param_2);
  if (-1 < iVar35) {
    uVar28 = param_1[5];
  }
  param_1[5] = uVar28;
  uVar29 = *(undefined4 *)(&DAT_00222f30 + param_2);
  if (-1 < iVar35) {
    uVar29 = param_1[6];
  }
  param_1[6] = uVar29;
  uVar30 = *(undefined4 *)(&DAT_00222f34 + param_2);
  if (-1 < iVar35) {
    uVar30 = param_1[7];
  }
  param_1[7] = uVar30;
  uVar31 = *(undefined4 *)(&DAT_00222f38 + param_2);
  if (-1 < iVar35) {
    uVar31 = param_1[8];
  }
  param_1[8] = uVar31;
  uVar7 = *(undefined4 *)(&DAT_00222f3c + param_2);
  if (-1 < iVar35) {
    uVar7 = param_1[9];
  }
  param_1[9] = uVar7;
  uVar8 = *(undefined4 *)(&DAT_00222f40 + param_2);
  if (-1 < iVar35) {
    uVar8 = param_1[10];
  }
  param_1[10] = uVar8;
  uVar9 = *(undefined4 *)(&DAT_00222f44 + param_2);
  if (-1 < iVar35) {
    uVar9 = param_1[0xb];
  }
  param_1[0xb] = uVar9;
  uVar36 = *(undefined4 *)(&DAT_00222f48 + param_2);
  if (-1 < iVar35) {
    uVar36 = param_1[0xc];
  }
  param_1[0xc] = uVar36;
  uVar10 = *(undefined4 *)(&DAT_00222f4c + param_2);
  if (-1 < iVar35) {
    uVar10 = param_1[0xd];
  }
  param_1[0xd] = uVar10;
  uVar11 = *(undefined4 *)(&DAT_00222f50 + param_2);
  if (-1 < iVar35) {
    uVar11 = param_1[0xe];
  }
  param_1[0xe] = uVar11;
  uVar12 = *(undefined4 *)(&DAT_00222f54 + param_2);
  if (-1 < iVar35) {
    uVar12 = param_1[0xf];
  }
  param_1[0xf] = uVar12;
  uVar18 = *(undefined4 *)(&DAT_00222f58 + param_2);
  if (-1 < iVar35) {
    uVar18 = param_1[0x10];
  }
  param_1[0x10] = uVar18;
  uVar13 = *(undefined4 *)(&DAT_00222f5c + param_2);
  if (-1 < iVar35) {
    uVar13 = param_1[0x11];
  }
  param_1[0x11] = uVar13;
  uVar14 = *(undefined4 *)(&DAT_00222f60 + param_2);
  if (-1 < iVar35) {
    uVar14 = param_1[0x12];
  }
  param_1[0x12] = uVar14;
  uVar1 = *(undefined4 *)(&DAT_00222f64 + param_2);
  if (-1 < iVar35) {
    uVar1 = param_1[0x13];
  }
  param_1[0x13] = uVar1;
  iVar3 = *(int *)(&DAT_00222f68 + param_2);
  if (-1 < iVar35) {
    iVar3 = param_1[0x14];
  }
  param_1[0x14] = iVar3;
  iVar4 = *(int *)(&DAT_00222f6c + param_2);
  if (-1 < iVar35) {
    iVar4 = param_1[0x15];
  }
  param_1[0x15] = iVar4;
  iVar43 = *(int *)(&DAT_00222f70 + param_2);
  if (-1 < iVar35) {
    iVar43 = param_1[0x16];
  }
  param_1[0x16] = iVar43;
  iVar19 = *(int *)(&DAT_00222f74 + param_2);
  if (-1 < iVar35) {
    iVar19 = param_1[0x17];
  }
  param_1[0x17] = iVar19;
  iVar20 = *(int *)(&DAT_00222f78 + param_2);
  if (-1 < iVar35) {
    iVar20 = param_1[0x18];
  }
  param_1[0x18] = iVar20;
  iVar21 = *(int *)(&DAT_00222f7c + param_2);
  if (-1 < iVar35) {
    iVar21 = param_1[0x19];
  }
  param_1[0x19] = iVar21;
  iVar5 = *(int *)(&DAT_00222f80 + param_2);
  if (-1 < iVar35) {
    iVar5 = param_1[0x1a];
  }
  param_1[0x1a] = iVar5;
  iVar22 = *(int *)(&DAT_00222f84 + param_2);
  if (-1 < iVar35) {
    iVar22 = param_1[0x1b];
  }
  param_1[0x1b] = iVar22;
  iVar41 = param_1[0x1c];
  if (iVar35 < 0) {
    iVar41 = *(int *)(&DAT_00222f88 + param_2);
  }
  param_1[0x1c] = iVar41;
  iVar23 = *(int *)(&DAT_00222f8c + param_2);
  if (-1 < iVar35) {
    iVar23 = param_1[0x1d];
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00222f90 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00222f94 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00222f98 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00222f9c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00222fa0 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00222fa4 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00222fa8 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00222fac + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00222fb0 + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 3) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00222fb4 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00222fb8 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00222fbc + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00222fc0 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00222fc4 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00222fc8 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00222fcc + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00222fd0 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_00222fd4 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00222fd8 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00222fdc + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_00222fe0 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_00222fe4 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_00222fe8 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_00222fec + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_00222ff0 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_00222ff4 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_00222ff8 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_00222ffc + param_2);
  }
  param_1[0x1b] = iVar22;
  iVar2 = *(int *)(&DAT_00223000 + param_2);
  if (-1 < iVar39) {
    iVar2 = iVar41;
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_00223004 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00223008 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_0022300c + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00223010 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00223014 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00223018 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_0022301c + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223020 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00223024 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00223028 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 4) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_0022302c + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00223030 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00223034 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00223038 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_0022303c + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00223040 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00223044 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00223048 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_0022304c + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00223050 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00223054 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00223058 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_0022305c + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_00223060 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00223064 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00223068 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_0022306c + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00223070 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_00223074 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00223078 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_0022307c + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00223080 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00223084 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00223088 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_0022308c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00223090 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00223094 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223098 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0022309c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_002230a0 + param_2);
  }
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 5) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_002230a4 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_002230a8 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_002230ac + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002230b0 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002230b4 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002230b8 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002230bc + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002230c0 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002230c4 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002230c8 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002230cc + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002230d0 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002230d4 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002230d8 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002230dc + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002230e0 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_002230e4 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_002230e8 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_002230ec + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_002230f0 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_002230f4 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_002230f8 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002230fc + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00223100 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_00223104 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00223108 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_0022310c + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223110 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00223114 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00223118 + param_2);
  }
  param_1[8] = uVar31;
  iVar39 = (uVar38 ^ 6) - 1;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_0022311c + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00223120 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00223124 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00223128 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_0022312c + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00223130 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00223134 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00223138 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_0022313c + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00223140 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00223144 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00223148 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_0022314c + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar35 < 0) {
    iVar43 = *(int *)(&DAT_00223150 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00223154 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00223158 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_0022315c + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00223160 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_00223164 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00223168 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_0022316c + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar39 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00223170 + param_2);
  }
  *param_1 = uVar6;
  if (iVar39 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00223174 + param_2);
  }
  param_1[1] = uVar24;
  if (iVar39 < 0) {
    uVar25 = *(undefined4 *)(&DAT_00223178 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar39 < 0) {
    uVar26 = *(undefined4 *)(&DAT_0022317c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar39 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00223180 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar39 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00223184 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar39 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223188 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar39 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0022318c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar39 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00223190 + param_2);
  }
  iVar41 = (uVar38 ^ 8) - 1;
  param_1[8] = uVar31;
  iVar35 = (uVar38 ^ 7) - 1;
  if (iVar39 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00223194 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar39 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00223198 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar39 < 0) {
    uVar9 = *(undefined4 *)(&DAT_0022319c + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar39 < 0) {
    uVar36 = *(undefined4 *)(&DAT_002231a0 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar39 < 0) {
    uVar10 = *(undefined4 *)(&DAT_002231a4 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar39 < 0) {
    uVar11 = *(undefined4 *)(&DAT_002231a8 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar39 < 0) {
    uVar12 = *(undefined4 *)(&DAT_002231ac + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar39 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002231b0 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar39 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002231b4 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar39 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002231b8 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar39 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002231bc + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar39 < 0) {
    iVar3 = *(int *)(&DAT_002231c0 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar39 < 0) {
    iVar4 = *(int *)(&DAT_002231c4 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar39 < 0) {
    iVar43 = *(int *)(&DAT_002231c8 + param_2);
  }
  param_1[0x16] = iVar43;
  if (iVar39 < 0) {
    iVar19 = *(int *)(&DAT_002231cc + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar39 < 0) {
    iVar20 = *(int *)(&DAT_002231d0 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar39 < 0) {
    iVar21 = *(int *)(&DAT_002231d4 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar39 < 0) {
    iVar5 = *(int *)(&DAT_002231d8 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar39 < 0) {
    iVar22 = *(int *)(&DAT_002231dc + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar39 < 0) {
    iVar2 = *(int *)(&DAT_002231e0 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar39 < 0) {
    iVar23 = *(int *)(&DAT_002231e4 + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar35 < 0) {
    uVar6 = *(undefined4 *)(&DAT_002231e8 + param_2);
  }
  *param_1 = uVar6;
  if (iVar35 < 0) {
    uVar24 = *(undefined4 *)(&DAT_002231ec + param_2);
  }
  param_1[1] = uVar24;
  if (iVar35 < 0) {
    uVar25 = *(undefined4 *)(&DAT_002231f0 + param_2);
  }
  param_1[2] = uVar25;
  if (iVar35 < 0) {
    uVar26 = *(undefined4 *)(&DAT_002231f4 + param_2);
  }
  param_1[3] = uVar26;
  if (iVar35 < 0) {
    uVar27 = *(undefined4 *)(&DAT_002231f8 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar35 < 0) {
    uVar28 = *(undefined4 *)(&DAT_002231fc + param_2);
  }
  param_1[5] = uVar28;
  if (iVar35 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223200 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar35 < 0) {
    uVar30 = *(undefined4 *)(&DAT_00223204 + param_2);
  }
  param_1[7] = uVar30;
  if (iVar35 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00223208 + param_2);
  }
  param_1[8] = uVar31;
  if (iVar35 < 0) {
    uVar7 = *(undefined4 *)(&DAT_0022320c + param_2);
  }
  param_1[9] = uVar7;
  if (iVar35 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00223210 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar35 < 0) {
    uVar9 = *(undefined4 *)(&DAT_00223214 + param_2);
  }
  param_1[0xb] = uVar9;
  if (iVar35 < 0) {
    uVar36 = *(undefined4 *)(&DAT_00223218 + param_2);
  }
  param_1[0xc] = uVar36;
  if (iVar35 < 0) {
    uVar10 = *(undefined4 *)(&DAT_0022321c + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar35 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00223220 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar35 < 0) {
    uVar12 = *(undefined4 *)(&DAT_00223224 + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar35 < 0) {
    uVar18 = *(undefined4 *)(&DAT_00223228 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar35 < 0) {
    uVar13 = *(undefined4 *)(&DAT_0022322c + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar35 < 0) {
    uVar14 = *(undefined4 *)(&DAT_00223230 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar35 < 0) {
    uVar1 = *(undefined4 *)(&DAT_00223234 + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar35 < 0) {
    iVar3 = *(int *)(&DAT_00223238 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar35 < 0) {
    iVar4 = *(int *)(&DAT_0022323c + param_2);
  }
  param_1[0x15] = iVar4;
  iVar39 = *(int *)(&DAT_00223240 + param_2);
  if (-1 < iVar35) {
    iVar39 = iVar43;
  }
  param_1[0x16] = iVar39;
  if (iVar35 < 0) {
    iVar19 = *(int *)(&DAT_00223244 + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar35 < 0) {
    iVar20 = *(int *)(&DAT_00223248 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar35 < 0) {
    iVar21 = *(int *)(&DAT_0022324c + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar35 < 0) {
    iVar5 = *(int *)(&DAT_00223250 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar35 < 0) {
    iVar22 = *(int *)(&DAT_00223254 + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar35 < 0) {
    iVar2 = *(int *)(&DAT_00223258 + param_2);
  }
  param_1[0x1c] = iVar2;
  if (iVar35 < 0) {
    iVar23 = *(int *)(&DAT_0022325c + param_2);
  }
  param_1[0x1d] = iVar23;
  if (iVar41 < 0) {
    uVar6 = *(undefined4 *)(&DAT_00223260 + param_2);
  }
  *param_1 = uVar6;
  if (iVar41 < 0) {
    uVar24 = *(undefined4 *)(&DAT_00223264 + param_2);
  }
  param_1[1] = uVar24;
  uVar42 = *(undefined4 *)(&DAT_00223268 + param_2);
  if (-1 < iVar41) {
    uVar42 = uVar25;
  }
  param_1[2] = uVar42;
  if (iVar41 < 0) {
    uVar26 = *(undefined4 *)(&DAT_0022326c + param_2);
  }
  param_1[3] = uVar26;
  if (iVar41 < 0) {
    uVar27 = *(undefined4 *)(&DAT_00223270 + param_2);
  }
  param_1[4] = uVar27;
  if (iVar41 < 0) {
    uVar28 = *(undefined4 *)(&DAT_00223274 + param_2);
  }
  param_1[5] = uVar28;
  if (iVar41 < 0) {
    uVar29 = *(undefined4 *)(&DAT_00223278 + param_2);
  }
  param_1[6] = uVar29;
  if (iVar41 < 0) {
    uVar30 = *(undefined4 *)(&DAT_0022327c + param_2);
  }
  param_1[7] = uVar30;
  if (iVar41 < 0) {
    uVar31 = *(undefined4 *)(&DAT_00223280 + param_2);
  }
  param_1[8] = uVar31;
  if (iVar41 < 0) {
    uVar7 = *(undefined4 *)(&DAT_00223284 + param_2);
  }
  param_1[9] = uVar7;
  if (iVar41 < 0) {
    uVar8 = *(undefined4 *)(&DAT_00223288 + param_2);
  }
  param_1[10] = uVar8;
  if (iVar41 < 0) {
    uVar9 = *(undefined4 *)(&DAT_0022328c + param_2);
  }
  param_1[0xb] = uVar9;
  uVar25 = *(undefined4 *)(&DAT_00223290 + param_2);
  if (-1 < iVar41) {
    uVar25 = uVar36;
  }
  param_1[0xc] = uVar25;
  if (iVar41 < 0) {
    uVar10 = *(undefined4 *)(&DAT_00223294 + param_2);
  }
  param_1[0xd] = uVar10;
  if (iVar41 < 0) {
    uVar11 = *(undefined4 *)(&DAT_00223298 + param_2);
  }
  param_1[0xe] = uVar11;
  if (iVar41 < 0) {
    uVar12 = *(undefined4 *)(&DAT_0022329c + param_2);
  }
  param_1[0xf] = uVar12;
  if (iVar41 < 0) {
    uVar18 = *(undefined4 *)(&DAT_002232a0 + param_2);
  }
  param_1[0x10] = uVar18;
  if (iVar41 < 0) {
    uVar13 = *(undefined4 *)(&DAT_002232a4 + param_2);
  }
  param_1[0x11] = uVar13;
  if (iVar41 < 0) {
    uVar14 = *(undefined4 *)(&DAT_002232a8 + param_2);
  }
  param_1[0x12] = uVar14;
  if (iVar41 < 0) {
    uVar1 = *(undefined4 *)(&DAT_002232ac + param_2);
  }
  param_1[0x13] = uVar1;
  if (iVar41 < 0) {
    iVar3 = *(int *)(&DAT_002232b0 + param_2);
  }
  param_1[0x14] = iVar3;
  if (iVar41 < 0) {
    iVar4 = *(int *)(&DAT_002232b4 + param_2);
  }
  param_1[0x15] = iVar4;
  if (iVar41 < 0) {
    iVar39 = *(int *)(&DAT_002232b8 + param_2);
  }
  param_1[0x16] = iVar39;
  if (iVar41 < 0) {
    iVar19 = *(int *)(&DAT_002232bc + param_2);
  }
  param_1[0x17] = iVar19;
  if (iVar41 < 0) {
    iVar20 = *(int *)(&DAT_002232c0 + param_2);
  }
  param_1[0x18] = iVar20;
  if (iVar41 < 0) {
    iVar21 = *(int *)(&DAT_002232c4 + param_2);
  }
  param_1[0x19] = iVar21;
  if (iVar41 < 0) {
    iVar5 = *(int *)(&DAT_002232c8 + param_2);
  }
  param_1[0x1a] = iVar5;
  if (iVar41 < 0) {
    iVar22 = *(int *)(&DAT_002232cc + param_2);
  }
  param_1[0x1b] = iVar22;
  if (iVar41 < 0) {
    iVar2 = *(int *)(&DAT_002232d0 + param_2);
  }
  param_1[0x1c] = iVar2;
  uVar15 = param_1[10];
  uVar32 = param_1[0xb];
  uVar36 = param_1[0xc];
  if (iVar41 < 0) {
    iVar23 = *(int *)(&DAT_002232d4 + param_2);
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

