
/* WARNING: Unknown calling convention */

void reset_single_BM1385_global_arg(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  work *works;
  int iVar5;
  int iVar6;
  uint OpenCoreNum4;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint OpenCoreNum3;
  uint uVar10;
  uint OpenCoreNum2;
  uint uVar11;
  uint OpenCoreNum1;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined *local_30;
  
  uVar7 = Conf.OpenCoreNum4;
  uVar10 = Conf.OpenCoreNum3;
  uVar11 = Conf.OpenCoreNum2;
  uVar12 = Conf.OpenCoreNum1;
  iVar9 = 0x20;
  reset_global_arg();
  printf("\n--- %s\n",DAT_000116e8);
  uVar2 = Conf.pattern_number;
  iVar17 = 0;
  do {
    uVar1 = uVar12 & 1;
    uVar12 = uVar12 >> 1;
    if (uVar1 != 0) {
      iVar17 = iVar17 + 1;
    }
    uVar1 = uVar11 & 1;
    uVar11 = uVar11 >> 1;
    if (uVar1 != 0) {
      iVar17 = iVar17 + 1;
    }
    uVar1 = uVar10 & 1;
    uVar10 = uVar10 >> 1;
    if (uVar1 != 0) {
      iVar17 = iVar17 + 1;
    }
    uVar1 = uVar7 & 1;
    uVar7 = uVar7 >> 1;
    if (uVar1 != 0) {
      iVar17 = iVar17 + 1;
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_30 = DAT_000116ec;
  iVar5 = Conf.pattern_number * 0x44;
  iVar9 = 0;
  puVar13 = gSend_Work_Num;
  puVar14 = gValid_Nonce_Num;
  puVar15 = gRepeated_Nonce_Id;
  puVar16 = DAT_000116f4;
  do {
    *puVar15 = 0;
    *puVar14 = 0;
    local_30 = local_30 + 1;
    *local_30 = 0;
    *puVar13 = 0;
    if (iVar17 != 0) {
      piVar3 = DAT_000116f0;
      puVar8 = puVar16;
      do {
        piVar3 = piVar3 + 1;
        iVar4 = *piVar3;
        iVar6 = iVar4 + iVar9;
        if (uVar2 != 0) {
          do {
            *(undefined4 *)(iVar6 + 0x34) = 0;
            iVar6 = iVar6 + 0x44;
          } while (iVar6 != iVar4 + iVar9 + iVar5);
        }
        puVar8 = puVar8 + 1;
        *puVar8 = 0;
      } while (piVar3 != (int *)(cgpu.workdataFilePrefix + iVar17 * 4 + 0x3c));
    }
    iVar9 = iVar9 + 4;
    puVar16 = puVar16 + 0x20000;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
  } while (iVar9 != 0x10);
  return;
}

