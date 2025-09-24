
void fe_tobytes(undefined1 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined1 local_3c;
  byte local_30;
  byte local_2c;
  
  iVar4 = param_2[9];
  iVar10 = param_2[3];
  iVar13 = param_2[4];
  iVar7 = param_2[5];
  iVar9 = param_2[6];
  iVar5 = param_2[7];
  iVar2 = param_2[8];
  uVar12 = *param_2 +
           (iVar4 + (iVar2 + (iVar5 + (iVar9 + (iVar7 + (iVar13 + (iVar10 + (param_2[2] +
                                                                             (param_2[1] +
                                                                              (*param_2 +
                                                                               (iVar4 * 0x13 +
                                                                                0x1000000 >> 0x19)
                                                                              >> 0x1a) >> 0x19) >>
                                                                            0x1a) >> 0x19) >> 0x1a)
                                               >> 0x19) >> 0x1a) >> 0x19) >> 0x1a) >> 0x19) * 0x13;
  uVar15 = param_2[1] + ((int)uVar12 >> 0x1a);
  uVar12 = uVar12 & 0x3ffffff;
  uVar16 = param_2[2] + ((int)uVar15 >> 0x19);
  *param_1 = (char)uVar12;
  param_1[2] = (char)(uVar12 >> 0x10);
  uVar15 = uVar15 & 0x1ffffff;
  uVar11 = iVar10 + ((int)uVar16 >> 0x1a);
  param_1[1] = (char)(uVar12 >> 8);
  uVar1 = iVar13 + ((int)uVar11 >> 0x19);
  uVar11 = uVar11 & 0x1ffffff;
  uVar8 = iVar7 + ((int)uVar1 >> 0x1a);
  uVar16 = uVar16 & 0x3ffffff;
  param_1[3] = (byte)(uVar15 << 2) | (byte)(uVar12 >> 0x18);
  uVar14 = iVar9 + ((int)uVar8 >> 0x19);
  uVar1 = uVar1 & 0x3ffffff;
  uVar8 = uVar8 & 0x1ffffff;
  uVar12 = iVar5 + ((int)uVar14 >> 0x1a);
  local_2c = (byte)(uVar11 << 5) | (byte)(uVar16 >> 0x15);
  uVar14 = uVar14 & 0x3ffffff;
  uVar3 = iVar2 + ((int)uVar12 >> 0x19);
  local_3c = (undefined1)uVar8;
  param_1[6] = (byte)(uVar16 << 3) | (byte)(uVar15 >> 0x16);
  param_1[0x10] = local_3c;
  uVar6 = iVar4 + ((int)uVar3 >> 0x1a) & 0x1ffffff;
  local_30 = (byte)(uVar1 << 6) | (byte)(uVar11 >> 0x13);
  uVar12 = uVar12 & 0x1ffffff;
  uVar3 = uVar3 & 0x3ffffff;
  param_1[7] = (char)((int)uVar16 >> 5);
  param_1[4] = (char)((int)uVar15 >> 6);
  param_1[5] = (char)((int)uVar15 >> 0xe);
  param_1[8] = (char)((int)uVar16 >> 0xd);
  param_1[9] = local_2c;
  param_1[10] = (char)((int)uVar11 >> 3);
  param_1[0xb] = (char)((int)uVar11 >> 0xb);
  param_1[0xd] = (char)((int)uVar1 >> 2);
  param_1[0xc] = local_30;
  param_1[0xe] = (char)((int)uVar1 >> 10);
  param_1[0xf] = (char)((int)uVar1 >> 0x12);
  param_1[0x11] = (char)(uVar8 >> 8);
  param_1[0x12] = (char)(uVar8 >> 0x10);
  param_1[0x13] = (byte)(uVar14 << 1) | (byte)(uVar8 >> 0x18);
  param_1[0x14] = (char)((int)uVar14 >> 7);
  param_1[0x15] = (char)((int)uVar14 >> 0xf);
  param_1[0x16] = (byte)(uVar12 << 3) | (byte)(uVar14 >> 0x17);
  param_1[0x17] = (char)((int)uVar12 >> 5);
  param_1[0x18] = (char)((int)uVar12 >> 0xd);
  param_1[0x19] = (byte)(uVar3 << 4) | (byte)(uVar12 >> 0x15);
  param_1[0x1a] = (char)((int)uVar3 >> 4);
  param_1[0x1b] = (char)((int)uVar3 >> 0xc);
  param_1[0x1c] = (byte)(uVar6 << 6) | (byte)(uVar3 >> 0x14);
  param_1[0x1d] = (char)((int)uVar6 >> 2);
  param_1[0x1e] = (char)((int)uVar6 >> 10);
  param_1[0x1f] = (char)((int)uVar6 >> 0x12);
  return;
}

