
uint crc32_combine64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int **ppiVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint auStack_120 [32];
  int *apiStack_a0 [33];
  
  if ((int)(param_4 - (param_3 == 0)) < 0 == (SBORROW4(param_4,(uint)(param_3 == 0)) != false)) {
    apiStack_a0[0] = (int *)0xedb88320;
    piVar4 = (int *)0x1;
    ppiVar2 = apiStack_a0;
    do {
      ppiVar2 = ppiVar2 + 1;
      *ppiVar2 = piVar4;
      piVar4 = (int *)((int)piVar4 << 1);
    } while (ppiVar2 != apiStack_a0 + 0x1f);
    iVar8 = 0;
    do {
      while (uVar3 = *(uint *)((int)apiStack_a0 + iVar8), uVar3 == 0) {
        *(undefined4 *)((int)auStack_120 + iVar8) = 0;
        iVar8 = iVar8 + 4;
        if (iVar8 == 0x80) goto LAB_00042250;
      }
      uVar6 = 0;
      ppiVar2 = apiStack_a0;
      do {
        if ((int)(uVar3 << 0x1f) < 0) {
          uVar6 = uVar6 ^ (uint)*ppiVar2;
        }
        uVar3 = uVar3 >> 1;
        ppiVar2 = ppiVar2 + 1;
      } while (uVar3 != 0);
      *(uint *)((int)auStack_120 + iVar8) = uVar6;
      iVar8 = iVar8 + 4;
    } while (iVar8 != 0x80);
LAB_00042250:
    iVar8 = 0;
    do {
      while (uVar3 = *(uint *)((int)auStack_120 + iVar8), uVar3 == 0) {
        *(undefined4 *)((int)apiStack_a0 + iVar8) = 0;
        iVar8 = iVar8 + 4;
        if (iVar8 == 0x80) goto LAB_00042288;
      }
      uVar6 = 0;
      puVar1 = auStack_120;
      do {
        if ((int)(uVar3 << 0x1f) < 0) {
          uVar6 = uVar6 ^ *puVar1;
        }
        uVar3 = uVar3 >> 1;
        puVar1 = puVar1 + 1;
      } while (uVar3 != 0);
      *(uint *)((int)apiStack_a0 + iVar8) = uVar6;
      iVar8 = iVar8 + 4;
    } while (iVar8 != 0x80);
LAB_00042288:
    do {
      iVar8 = 0;
      do {
        while (uVar3 = *(uint *)((int)apiStack_a0 + iVar8), uVar3 == 0) {
          *(undefined4 *)((int)auStack_120 + iVar8) = 0;
          iVar8 = iVar8 + 4;
          if (iVar8 == 0x80) goto LAB_000422bc;
        }
        uVar6 = 0;
        ppiVar2 = apiStack_a0;
        do {
          if ((int)(uVar3 << 0x1f) < 0) {
            uVar6 = uVar6 ^ (uint)*ppiVar2;
          }
          uVar3 = uVar3 >> 1;
          ppiVar2 = ppiVar2 + 1;
        } while (uVar3 != 0);
        *(uint *)((int)auStack_120 + iVar8) = uVar6;
        iVar8 = iVar8 + 4;
      } while (iVar8 != 0x80);
LAB_000422bc:
      if (((param_3 & 1) != 0) && (param_1 != 0)) {
        uVar3 = 0;
        uVar6 = param_1;
        puVar1 = auStack_120;
        do {
          param_1 = uVar3;
          if ((int)(uVar6 << 0x1f) < 0) {
            param_1 = param_1 ^ *puVar1;
          }
          uVar6 = uVar6 >> 1;
          uVar3 = param_1;
          puVar1 = puVar1 + 1;
        } while (uVar6 != 0);
      }
      uVar6 = (int)param_4 >> 1;
      uVar3 = (uint)((param_4 & 1) != 0) << 0x1f | param_3 >> 1;
      if ((uVar3 | uVar6) == 0) break;
      iVar8 = 0;
      do {
        while (uVar7 = *(uint *)((int)auStack_120 + iVar8), uVar7 == 0) {
          *(undefined4 *)((int)apiStack_a0 + iVar8) = 0;
          iVar8 = iVar8 + 4;
          if (iVar8 == 0x80) goto LAB_00042328;
        }
        uVar5 = 0;
        puVar1 = auStack_120;
        do {
          if ((int)(uVar7 << 0x1f) < 0) {
            uVar5 = uVar5 ^ *puVar1;
          }
          uVar7 = uVar7 >> 1;
          puVar1 = puVar1 + 1;
        } while (uVar7 != 0);
        *(uint *)((int)apiStack_a0 + iVar8) = uVar5;
        iVar8 = iVar8 + 4;
      } while (iVar8 != 0x80);
LAB_00042328:
      if (((param_3 >> 1 & 1) != 0) && (param_1 != 0)) {
        uVar7 = 0;
        uVar5 = param_1;
        ppiVar2 = apiStack_a0;
        do {
          param_1 = uVar7;
          if ((int)(uVar5 << 0x1f) < 0) {
            param_1 = param_1 ^ (uint)*ppiVar2;
          }
          uVar5 = uVar5 >> 1;
          uVar7 = param_1;
          ppiVar2 = ppiVar2 + 1;
        } while (uVar5 != 0);
      }
      param_4 = (int)param_4 >> 2;
      param_3 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar3 >> 1;
    } while ((param_3 | param_4) != 0);
    param_1 = param_1 ^ param_2;
  }
  return param_1;
}

