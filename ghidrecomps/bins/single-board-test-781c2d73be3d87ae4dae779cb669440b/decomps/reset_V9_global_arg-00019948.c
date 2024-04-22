
/* WARNING: Unknown calling convention */

void reset_V9_global_arg(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  work **works;
  undefined *puVar10;
  uint *puVar11;
  uint *puVar12;
  
  reset_global_arg();
  uVar1 = Conf.pattern_number;
  iVar7 = 0;
  iVar6 = Conf.pattern_number * 0x44;
  puVar8 = gRepeated_Nonce_Id;
  puVar9 = DAT_000199dc;
  puVar10 = DAT_000199d8;
  puVar11 = gValid_Nonce_Num;
  puVar12 = gSend_Work_Num;
  do {
    works = DAT_000199e0;
    puVar10 = puVar10 + 1;
    *puVar10 = 0;
    *puVar8 = 0;
    *puVar11 = 0;
    *puVar12 = 0;
    puVar5 = puVar9;
    do {
      works = works + 1;
      puVar2 = puVar5 + -0x32;
      puVar4 = (*works)->data + iVar7 + -8;
      do {
        puVar2 = puVar2 + 1;
        *puVar2 = 0;
        puVar3 = puVar4 + iVar6;
        if (uVar1 != 0) {
          do {
            (*(uint (*) [1])(puVar4 + 0x34))[0] = 0;
            puVar4 = puVar4 + 0x44;
          } while (puVar4 != puVar3);
        }
        puVar4 = puVar3;
      } while (puVar5 != puVar2);
      puVar5 = puVar5 + 0x400;
    } while (works != DAT_000199d4);
    iVar7 = iVar7 + 4;
    puVar9 = puVar9 + 0x20000;
    puVar8 = puVar8 + 1;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  } while (iVar7 != 0x10);
  return;
}

