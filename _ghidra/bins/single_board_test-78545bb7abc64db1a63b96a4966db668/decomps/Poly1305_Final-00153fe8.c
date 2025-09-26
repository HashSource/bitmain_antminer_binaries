
void Poly1305_Final(uint *param_1,undefined1 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint local_88;
  uint local_80;
  uint local_78;
  uint local_48;
  
  uVar6 = param_1[0x38];
  if (uVar6 == 0) {
    local_78 = param_1[1];
    uVar7 = *param_1;
    uVar14 = param_1[2];
    uVar6 = param_1[3];
    uVar8 = param_1[4];
  }
  else {
    *(undefined1 *)((int)param_1 + uVar6 + 0xd0) = 1;
    if (uVar6 + 1 < 0x10) {
      memset((void *)(uVar6 + 0xd1 + (int)param_1),0,0xf - uVar6);
    }
    uVar18 = param_1[5];
    uVar6 = (uint)CARRY4(param_1[0x34],*param_1);
    uVar7 = param_1[0x35] + param_1[1];
    uVar12 = uVar6 + uVar7;
    uVar14 = (uint)CARRY4(param_1[0x35],param_1[1]) + (uint)CARRY4(uVar6,uVar7);
    uVar13 = param_1[8] + (param_1[8] >> 2);
    uVar6 = param_1[0x36] + param_1[2];
    uVar7 = uVar6 + uVar14;
    uVar14 = (uint)CARRY4(param_1[0x36],param_1[2]) + (uint)CARRY4(uVar6,uVar14);
    uVar6 = param_1[0x37] + param_1[3];
    uVar9 = param_1[6];
    uVar19 = param_1[7] + (param_1[7] >> 2);
    uVar11 = uVar9 + (uVar9 >> 2);
    uVar8 = *param_1 + param_1[0x34];
    uVar15 = uVar14 + uVar6;
    iVar5 = param_1[4] + (uint)CARRY4(param_1[0x37],param_1[3]) + (uint)CARRY4(uVar14,uVar6);
    uVar1 = (ulonglong)uVar18 * (ulonglong)uVar8 + (ulonglong)uVar12 * (ulonglong)uVar13 +
            (ulonglong)uVar7 * (ulonglong)uVar19 + (ulonglong)uVar11 * (ulonglong)uVar15;
    uVar2 = (ulonglong)uVar9 * (ulonglong)uVar8 + (ulonglong)uVar18 * (ulonglong)uVar12 +
            (ulonglong)uVar13 * (ulonglong)uVar7 + (ulonglong)uVar15 * (ulonglong)uVar19 +
            (uVar1 >> 0x20) + (ulonglong)(iVar5 * uVar11);
    uVar6 = (uint)uVar2;
    uVar4 = (ulonglong)param_1[7] * (ulonglong)uVar8 + (ulonglong)uVar12 * (ulonglong)uVar9 +
            (ulonglong)uVar18 * (ulonglong)uVar7;
    uVar2 = (ulonglong)uVar13 * (ulonglong)uVar15 + (uVar4 & 0xffffffff) +
            CONCAT44((int)(uVar4 >> 0x20),iVar5 * uVar19) + (uVar2 >> 0x20);
    uVar4 = (ulonglong)param_1[8] * (ulonglong)uVar8 + (ulonglong)param_1[7] * (ulonglong)uVar12 +
            (ulonglong)uVar7 * (ulonglong)uVar9;
    lVar3 = (ulonglong)uVar18 * (ulonglong)uVar15 + (uVar4 & 0xffffffff) +
            CONCAT44((int)(uVar4 >> 0x20),iVar5 * uVar13) + (uVar2 >> 0x20);
    uVar8 = iVar5 * uVar18 + (int)((ulonglong)lVar3 >> 0x20);
    local_48 = (uint)uVar1;
    uVar14 = (uVar8 & 0xfffffffc) + (uVar8 >> 2);
    uVar7 = uVar14 + local_48;
    *param_1 = uVar7;
    local_80 = (uint)uVar2;
    local_78 = uVar6 - ((int)(uVar7 ^ (uVar14 ^ uVar7 | uVar14 ^ local_48)) >> 0x1f);
    param_1[1] = local_78;
    uVar14 = local_80 - ((int)(local_78 ^ (uVar6 | local_78)) >> 0x1f);
    param_1[2] = uVar14;
    local_88 = (uint)lVar3;
    uVar6 = local_88 - ((int)(uVar14 ^ (uVar14 | local_80)) >> 0x1f);
    param_1[3] = uVar6;
    uVar8 = (uVar8 & 3) - ((int)((uVar6 | local_88) ^ uVar6) >> 0x1f);
    param_1[4] = uVar8;
  }
  uVar9 = (uint)CARRY4((uint)(0xfffffffa < uVar7),local_78);
  uVar11 = (uint)CARRY4(uVar9,uVar14);
  uVar8 = -(uVar8 + CARRY4(uVar11,uVar6) >> 2);
  uVar12 = (uVar7 ^ uVar7 + 5) & uVar8 ^ uVar7;
  local_78 = ((0xfffffffa < uVar7) + local_78 ^ local_78) & uVar8 ^ local_78;
  uVar14 = uVar14 ^ (uVar14 ^ uVar9 + uVar14) & uVar8;
  uVar7 = (uint)CARRY4(param_1[0x30],uVar12);
  uVar9 = param_1[0x31] + local_78;
  iVar5 = uVar9 + uVar7;
  uVar7 = (uint)CARRY4(param_1[0x31],local_78) + (uint)CARRY4(uVar9,uVar7);
  uVar9 = param_1[0x32] + uVar14;
  iVar17 = uVar9 + uVar7;
  iVar16 = param_1[0x33] + ((uVar6 ^ uVar11 + uVar6) & uVar8 ^ uVar6) +
           (uint)CARRY4(param_1[0x32],uVar14) + (uint)CARRY4(uVar9,uVar7);
  iVar10 = param_1[0x30] + uVar12;
  param_2[0xd] = (char)((uint)iVar16 >> 8);
  local_88._0_1_ = (undefined1)iVar16;
  local_78._0_1_ = (undefined1)((uint)iVar16 >> 0x10);
  param_2[8] = (char)iVar17;
  param_2[4] = (char)iVar5;
  *param_2 = (char)iVar10;
  param_2[0xc] = (undefined1)local_88;
  param_2[0xe] = (undefined1)local_78;
  param_2[0xf] = (char)((uint)iVar16 >> 0x18);
  param_2[9] = (char)((uint)iVar17 >> 8);
  param_2[10] = (char)((uint)iVar17 >> 0x10);
  param_2[0xb] = (char)((uint)iVar17 >> 0x18);
  param_2[5] = (char)((uint)iVar5 >> 8);
  param_2[6] = (char)((uint)iVar5 >> 0x10);
  param_2[7] = (char)((uint)iVar5 >> 0x18);
  local_80._0_1_ = (undefined1)((uint)iVar10 >> 0x10);
  param_2[1] = (char)((uint)iVar10 >> 8);
  param_2[3] = (char)((uint)iVar10 >> 0x18);
  param_2[2] = (undefined1)local_80;
  OPENSSL_cleanse(param_1,0xf0);
  return;
}

