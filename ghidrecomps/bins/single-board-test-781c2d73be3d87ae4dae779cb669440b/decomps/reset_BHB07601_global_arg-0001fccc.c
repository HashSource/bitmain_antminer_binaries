
/* WARNING: Unknown calling convention */

void reset_BHB07601_global_arg(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  undefined4 *puVar7;
  int iVar8;
  _Bool (*pa_Var9) [4];
  uint *puVar10;
  uint *puVar11;
  undefined4 *puVar12;
  work **works;
  uint *puVar13;
  int iVar14;
  undefined *local_34;
  
  gBM1397_MISC_CONTROL_reg = 0x3a01;
  reset_global_arg();
  uVar3 = Conf.pattern_number;
  uVar2 = BHB07601_ASIC_NUMBER;
  local_34 = DAT_0001fdac;
  iVar14 = 0;
  iVar8 = Conf.pattern_number * 0x44;
  iVar1 = BHB07601_ASIC_NUMBER * 4;
  pa_Var9 = gSensor_OK;
  puVar10 = gValid_Nonce_Num;
  puVar11 = gRepeated_Nonce_Id;
  puVar12 = DAT_0001fdb0;
  puVar13 = gSend_Work_Num;
  do {
    *puVar11 = 0;
    *puVar10 = 0;
    local_34 = local_34 + 1;
    *local_34 = 0;
    *puVar13 = 0;
    puVar7 = puVar12;
    works = DAT_0001fdb4;
    if (uVar2 != 0) {
      do {
        works = works + 1;
        puVar4 = puVar7 + -0x2a0;
        puVar6 = (*works)->data + iVar14 + -8;
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
    iVar14 = iVar14 + 4;
    (*pa_Var9)[0] = false;
    (*pa_Var9)[1] = false;
    (*pa_Var9)[2] = false;
    puVar12 = puVar12 + 0x20000;
    (*pa_Var9)[3] = false;
    pa_Var9 = pa_Var9 + 1;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
    puVar13 = puVar13 + 1;
  } while (iVar14 != 0x10);
  return;
}

