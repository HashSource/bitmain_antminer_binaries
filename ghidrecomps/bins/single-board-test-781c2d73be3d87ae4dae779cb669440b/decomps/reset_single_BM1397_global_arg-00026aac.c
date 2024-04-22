
/* WARNING: Unknown calling convention */

void reset_single_BM1397_global_arg(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  work *works;
  int iVar7;
  uint OpenCoreNum8;
  uint uVar8;
  undefined4 *puVar9;
  uint OpenCoreNum5;
  uint uVar10;
  uint OpenCoreNum7;
  uint uVar11;
  uint OpenCoreNum6;
  uint uVar12;
  uint OpenCoreNum4;
  uint uVar13;
  uint *puVar14;
  uint OpenCoreNum3;
  uint uVar15;
  uint *puVar16;
  uint OpenCoreNum2;
  uint uVar17;
  uint *puVar18;
  uint OpenCoreNum1;
  uint uVar19;
  undefined4 *puVar20;
  int iVar21;
  undefined *local_30;
  
  uVar8 = Conf.OpenCoreNum8;
  uVar11 = Conf.OpenCoreNum7;
  uVar12 = Conf.OpenCoreNum6;
  uVar10 = Conf.OpenCoreNum5;
  uVar13 = Conf.OpenCoreNum4;
  uVar15 = Conf.OpenCoreNum3;
  uVar17 = Conf.OpenCoreNum2;
  uVar19 = Conf.OpenCoreNum1;
  gBM1397_MISC_CONTROL_reg = 0x3a01;
  reset_global_arg();
  printf("\n--- %s\n",DAT_00026c00);
  uVar2 = Conf.pattern_number;
  iVar5 = 0x20;
  iVar21 = 0;
  do {
    uVar1 = uVar19 & 1;
    uVar19 = uVar19 >> 1;
    if (uVar1 != 0) {
      iVar21 = iVar21 + 1;
    }
    uVar1 = uVar17 & 1;
    uVar17 = uVar17 >> 1;
    if (uVar1 != 0) {
      iVar21 = iVar21 + 1;
    }
    uVar1 = uVar15 & 1;
    uVar15 = uVar15 >> 1;
    if (uVar1 != 0) {
      iVar21 = iVar21 + 1;
    }
    uVar1 = uVar13 & 1;
    uVar13 = uVar13 >> 1;
    if (uVar1 != 0) {
      iVar21 = iVar21 + 1;
    }
    iVar3 = uVar10 << 0x1f;
    uVar10 = uVar10 >> 1;
    if (iVar3 < 0) {
      iVar21 = iVar21 + 1;
    }
    iVar3 = uVar12 << 0x1f;
    uVar12 = uVar12 >> 1;
    if (iVar3 < 0) {
      iVar21 = iVar21 + 1;
    }
    iVar3 = uVar11 << 0x1f;
    uVar11 = uVar11 >> 1;
    if (iVar3 < 0) {
      iVar21 = iVar21 + 1;
    }
    iVar3 = uVar8 << 0x1f;
    uVar8 = uVar8 >> 1;
    if (iVar3 < 0) {
      iVar21 = iVar21 + 1;
    }
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_30 = DAT_00026c04;
  iVar3 = Conf.pattern_number * 0x44;
  iVar5 = 0;
  puVar14 = gSend_Work_Num;
  puVar16 = gValid_Nonce_Num;
  puVar18 = gRepeated_Nonce_Id;
  puVar20 = DAT_00026c0c;
  do {
    *puVar18 = 0;
    *puVar16 = 0;
    local_30 = local_30 + 1;
    *local_30 = 0;
    *puVar14 = 0;
    if (iVar21 != 0) {
      piVar4 = DAT_00026c08;
      puVar9 = puVar20;
      do {
        piVar4 = piVar4 + 1;
        iVar6 = *piVar4;
        iVar7 = iVar6 + iVar5;
        if (uVar2 != 0) {
          do {
            *(undefined4 *)(iVar7 + 0x34) = 0;
            iVar7 = iVar7 + 0x44;
          } while (iVar7 != iVar6 + iVar5 + iVar3);
        }
        puVar9 = puVar9 + 1;
        *puVar9 = 0;
      } while (piVar4 != (int *)(cgpu.workdataFilePrefix + iVar21 * 4 + 0x3c));
    }
    iVar5 = iVar5 + 4;
    puVar20 = puVar20 + 0x20000;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
    puVar18 = puVar18 + 1;
  } while (iVar5 != 0x10);
  return;
}

