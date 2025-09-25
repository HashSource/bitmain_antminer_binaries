
void SHA3_squeeze(int param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  undefined1 local_108;
  undefined1 auStack_f0 [204];
  undefined1 uVar4;
  undefined1 uVar5;
  
  if (param_3 == 0) {
    return;
  }
  do {
    uVar16 = 0;
    puVar7 = (uint *)(param_1 + -8);
    puVar12 = param_2;
    if (param_4 >> 3 != 0) {
      do {
        HintPreloadData(puVar7 + 8);
        uVar8 = puVar7[2];
        uVar16 = uVar16 + 1;
        uVar6 = uVar8 >> 0x10;
        uVar8 = uVar8 & 0xffff;
        uVar9 = puVar7[3] & 0xffff0000;
        uVar11 = puVar7[3] << 0x10;
        uVar13 = (uVar6 | uVar6 << 8) & 0xff00ff;
        uVar6 = (uVar8 | uVar8 << 8) & 0xff00ff;
        uVar8 = (uVar9 | uVar9 >> 8) & 0xff00ff00;
        uVar9 = (uVar11 | uVar11 >> 8) & 0xff00ff00;
        uVar15 = (uVar8 | uVar8 >> 4) & 0xf0f0f0f0;
        uVar11 = (uVar13 | uVar13 << 4) & 0xf0f0f0f;
        uVar8 = (uVar9 | uVar9 >> 4) & 0xf0f0f0f0;
        uVar6 = (uVar6 | uVar6 << 4) & 0xf0f0f0f;
        uVar13 = (uVar15 | uVar15 >> 2) & 0xcccccccc;
        uVar6 = (uVar6 | uVar6 << 2) & 0x33333333;
        uVar9 = (uVar11 | uVar11 << 2) & 0x33333333;
        uVar8 = (uVar8 | uVar8 >> 2) & 0xcccccccc;
        uVar9 = (uVar9 | uVar9 << 1) & 0x55555555 | (uVar13 | uVar13 >> 1) & 0xaaaaaaaa;
        uVar6 = (uVar8 | uVar8 >> 1) & 0xaaaaaaaa | (uVar6 | uVar6 << 1) & 0x55555555;
        uVar2 = (undefined1)(uVar6 >> 8);
        uVar1 = (undefined1)(uVar6 >> 0x10);
        uVar3 = (undefined1)(uVar6 >> 0x18);
        uVar4 = (undefined1)(uVar9 >> 0x10);
        uVar5 = (undefined1)(uVar9 >> 8);
        if (param_3 < 8) {
          *puVar12 = (char)uVar6;
          if (param_3 == 1) {
            return;
          }
          puVar12[1] = uVar2;
          if (param_3 == 2) {
            return;
          }
          puVar12[2] = uVar1;
          if (param_3 == 3) {
            return;
          }
          puVar12[3] = uVar3;
          if (param_3 == 4) {
            return;
          }
          puVar12[4] = (char)uVar9;
          if (param_3 == 5) {
            return;
          }
          puVar12[5] = uVar5;
          if (param_3 != 7) {
            return;
          }
          puVar12[6] = uVar4;
          return;
        }
        param_3 = param_3 - 8;
        puVar12[1] = uVar2;
        local_108 = (undefined1)(uVar9 >> 0x18);
        param_2 = puVar12 + 8;
        *puVar12 = (char)uVar6;
        puVar12[2] = uVar1;
        puVar12[3] = uVar3;
        puVar12[4] = (char)uVar9;
        puVar12[5] = uVar5;
        puVar12[6] = uVar4;
        puVar12[7] = local_108;
        puVar7 = puVar7 + 2;
        puVar12 = param_2;
      } while (uVar16 < param_4 >> 3 && param_3 != 0);
      if (param_3 == 0) {
        return;
      }
    }
    iVar14 = 0;
    do {
      Round(auStack_f0,param_1,iVar14);
      iVar10 = iVar14 + 1;
      iVar14 = iVar14 + 2;
      Round(param_1,auStack_f0,iVar10);
    } while (iVar14 != 0x18);
  } while( true );
}

