
uint SHA3_absorb(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined1 auStack_f0 [204];
  
  if (param_4 <= param_3) {
    do {
      if (param_4 >> 3 != 0) {
        puVar3 = param_2 + (param_4 >> 3) * 2;
        puVar5 = param_1;
        do {
          uVar2 = *param_2;
          puVar1 = param_2 + 1;
          HintPreloadData(param_2 + 6);
          param_2 = param_2 + 2;
          uVar8 = uVar2 & 0x55555555;
          uVar2 = uVar2 & 0xaaaaaaaa;
          uVar6 = *puVar1 & 0xaaaaaaaa;
          uVar7 = *puVar1 & 0x55555555;
          uVar9 = (uVar8 | uVar8 >> 1) & 0x33333333;
          uVar8 = (uVar6 | uVar6 << 1) & 0xcccccccc;
          uVar2 = (uVar2 | uVar2 << 1) & 0xcccccccc;
          uVar6 = (uVar7 | uVar7 >> 1) & 0x33333333;
          uVar7 = (uVar9 | uVar9 >> 2) & 0xf0f0f0f;
          uVar8 = (uVar8 | uVar8 << 2) & 0xf0f0f0f0;
          uVar7 = uVar7 | uVar7 >> 4;
          uVar8 = uVar8 | uVar8 << 4;
          uVar2 = (uVar2 | uVar2 << 2) & 0xf0f0f0f0;
          uVar6 = (uVar6 | uVar6 >> 2) & 0xf0f0f0f;
          uVar6 = (uVar6 | uVar6 >> 4) & 0xff00ff;
          uVar2 = (uVar2 | uVar2 << 4) & 0xff00ff00;
          *puVar5 = *puVar5 ^ (uVar7 & 0xff | (uVar7 & 0xff00ff) >> 8 | (uVar6 | uVar6 >> 8) << 0x10
                              );
          puVar5[1] = puVar5[1] ^
                      (uVar8 & 0xff000000 | (uVar8 & 0xff00ff00) << 8 | (uVar2 | uVar2 << 8) >> 0x10
                      );
          puVar5 = puVar5 + 2;
        } while (puVar3 != param_2);
      }
      iVar10 = 0;
      do {
        Round(auStack_f0,param_1,iVar10);
        iVar4 = iVar10 + 1;
        iVar10 = iVar10 + 2;
        Round(param_1,auStack_f0,iVar4);
      } while (iVar10 != 0x18);
      param_3 = param_3 - param_4;
    } while (param_4 <= param_3);
  }
  return param_3;
}

