
/* WARNING: Unknown calling convention */

void reset_BHB91603_global_arg(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  work **works;
  undefined *puVar12;
  uint *puVar13;
  uint *puVar14;
  
  gBM1391_MISC_CONTROL_reg = 0x3a01;
  iVar9 = 0;
  reset_global_arg();
  uVar3 = Conf.pattern_number;
  uVar2 = BHB91603_ASIC_NUMBER;
  iVar8 = Conf.pattern_number * 0x44;
  iVar1 = BHB91603_ASIC_NUMBER * 4;
  puVar10 = gRepeated_Nonce_Id;
  puVar11 = DAT_00016a64;
  puVar12 = DAT_00016a60;
  puVar13 = gValid_Nonce_Num;
  puVar14 = gSend_Work_Num;
  do {
    puVar12 = puVar12 + 1;
    *puVar12 = 0;
    *puVar10 = 0;
    *puVar13 = 0;
    *puVar14 = 0;
    puVar7 = puVar11;
    works = DAT_00016a68;
    if (uVar2 != 0) {
      do {
        works = works + 1;
        puVar4 = puVar7 + -0x100;
        puVar6 = (*works)->data + iVar9 + -8;
        do {
          puVar4 = puVar4 + 1;
          *puVar4 = 0;
          puVar5 = puVar6 + iVar8;
          if (uVar3 != 0) {
            do {
              (*(uint (*) [1])(puVar6 + 0x34))[0] = 0;
              puVar6 = puVar6 + 0x44;
            } while (puVar6 != puVar5);
          }
          puVar6 = puVar5;
        } while (puVar4 != puVar7);
        puVar7 = puVar7 + 0x400;
      } while (works != (work **)(cgpu.workdataFilePrefix + iVar1 + 0x3c));
    }
    iVar9 = iVar9 + 4;
    puVar11 = puVar11 + 0x20000;
    puVar10 = puVar10 + 1;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
  } while (iVar9 != 0x10);
  return;
}

