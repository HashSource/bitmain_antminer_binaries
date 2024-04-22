
undefined4 MakeAEPBigNum(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = param_1[1];
  if (0 < iVar13) {
    puVar6 = (undefined *)*param_1;
    if (iVar13 < 9) {
      iVar12 = 0;
    }
    else {
      puVar11 = puVar6 + 1;
      puVar10 = puVar6 + 3;
      puVar7 = puVar6 + 2;
      iVar12 = 0;
      puVar9 = param_3 + 8;
      puVar8 = puVar6;
      do {
        param_3 = puVar9;
        iVar12 = iVar12 + 8;
        HintPreloadData(puVar8 + 0x31);
        HintPreloadData(puVar8 + 0x30);
        param_3[-8] = CONCAT22(CONCAT11(*puVar10,*puVar7),CONCAT11(*puVar11,*puVar8));
        param_3[-7] = CONCAT22(CONCAT11(puVar10[4],puVar7[4]),CONCAT11(puVar11[4],puVar8[4]));
        param_3[-6] = CONCAT22(CONCAT11(puVar10[8],puVar7[8]),CONCAT11(puVar11[8],puVar8[8]));
        param_3[-5] = CONCAT22(CONCAT11(puVar10[0xc],puVar7[0xc]),CONCAT11(puVar11[0xc],puVar8[0xc])
                              );
        param_3[-4] = CONCAT22(CONCAT11(puVar10[0x10],puVar7[0x10]),
                               CONCAT11(puVar11[0x10],puVar8[0x10]));
        param_3[-3] = CONCAT22(CONCAT11(puVar10[0x14],puVar7[0x14]),
                               CONCAT11(puVar11[0x14],puVar8[0x14]));
        param_3[-2] = CONCAT22(CONCAT11(puVar10[0x18],puVar7[0x18]),
                               CONCAT11(puVar11[0x18],puVar8[0x18]));
        puVar4 = puVar8 + 0x1c;
        puVar8 = puVar8 + 0x20;
        puVar1 = puVar11 + 0x1c;
        puVar11 = puVar11 + 0x20;
        puVar2 = puVar10 + 0x1c;
        puVar10 = puVar10 + 0x20;
        puVar3 = puVar7 + 0x1c;
        puVar7 = puVar7 + 0x20;
        param_3[-1] = CONCAT22(CONCAT11(*puVar2,*puVar3),CONCAT11(*puVar1,*puVar4));
        puVar9 = param_3 + 8;
      } while (iVar12 != (iVar13 - 9U & 0xfffffff8) + 8);
    }
    puVar9 = (undefined4 *)(puVar6 + iVar12 * 4);
    do {
      iVar12 = iVar12 + 1;
      uVar5 = *puVar9;
      puVar9 = puVar9 + 1;
      *param_3 = uVar5;
      param_3 = param_3 + 1;
    } while (iVar12 < iVar13);
  }
  return 0;
}

