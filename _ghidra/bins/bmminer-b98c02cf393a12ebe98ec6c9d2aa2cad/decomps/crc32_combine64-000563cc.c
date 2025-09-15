
/* WARNING: Type propagation algorithm not settling */

uint crc32_combine64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint auStack_120 [32];
  uint auStack_a0 [31];
  undefined1 auStack_24 [8];
  
  if ((int)(uint)(param_3 == 0) <= (int)param_4) {
    auStack_a0[0] = 0xedb88320;
    uVar2 = 1;
    puVar1 = auStack_a0;
    do {
      puVar1 = puVar1 + 1;
      *puVar1 = uVar2;
      uVar2 = uVar2 << 1;
    } while (puVar1 != auStack_a0 + 0x1f);
    iVar6 = 0;
    do {
      while (uVar2 = *(uint *)((int)auStack_a0 + iVar6), uVar2 == 0) {
        *(undefined4 *)((int)auStack_120 + iVar6) = 0;
        iVar6 = iVar6 + 4;
        if (iVar6 == 0x80) goto LAB_00055f48;
      }
      puVar1 = auStack_a0;
      uVar4 = 0;
      do {
        puVar1 = (uint *)((int)puVar1 + 4);
        if ((int)(uVar2 << 0x1f) < 0) {
          uVar4 = uVar4 ^ (uint)puVar1[0xffffffff];
        }
        uVar2 = uVar2 >> 1;
      } while (uVar2 != 0);
      *(uint *)((int)auStack_120 + iVar6) = uVar4;
      iVar6 = iVar6 + 4;
    } while (iVar6 != 0x80);
LAB_00055f48:
    iVar6 = 0;
    do {
      while (uVar2 = *(uint *)((int)auStack_120 + iVar6), uVar2 == 0) {
        *(undefined4 *)((int)auStack_a0 + iVar6) = 0;
        iVar6 = iVar6 + 4;
        if (iVar6 == 0x80) goto LAB_00055f80;
      }
      uVar4 = 0;
      puVar1 = auStack_120;
      do {
        if ((int)(uVar2 << 0x1f) < 0) {
          uVar4 = uVar4 ^ *puVar1;
        }
        uVar2 = uVar2 >> 1;
        puVar1 = puVar1 + 1;
      } while (uVar2 != 0);
      *(uint *)((int)auStack_a0 + iVar6) = uVar4;
      iVar6 = iVar6 + 4;
    } while (iVar6 != 0x80);
LAB_00055f80:
    do {
      iVar6 = 0;
      do {
        while (uVar2 = *(uint *)((int)auStack_a0 + iVar6), uVar2 == 0) {
          *(undefined4 *)((int)auStack_120 + iVar6) = 0;
          iVar6 = iVar6 + 4;
          if (iVar6 == 0x80) goto LAB_00055fb4;
        }
        puVar1 = auStack_a0;
        uVar4 = 0;
        do {
          puVar1 = (uint *)((int)puVar1 + 4);
          if ((int)(uVar2 << 0x1f) < 0) {
            uVar4 = uVar4 ^ puVar1[0xffffffff];
          }
          uVar2 = uVar2 >> 1;
        } while (uVar2 != 0);
        *(uint *)((int)auStack_120 + iVar6) = uVar4;
        iVar6 = iVar6 + 4;
      } while (iVar6 != 0x80);
LAB_00055fb4:
      if (((param_3 & 1) != 0) && (param_1 != 0)) {
        uVar2 = 0;
        uVar4 = param_1;
        puVar1 = auStack_120;
        do {
          param_1 = uVar2;
          if ((int)(uVar4 << 0x1f) < 0) {
            param_1 = param_1 ^ *puVar1;
          }
          uVar4 = uVar4 >> 1;
          uVar2 = param_1;
          puVar1 = puVar1 + 1;
        } while (uVar4 != 0);
      }
      uVar4 = (int)param_4 >> 1;
      uVar2 = (uint)((param_4 & 1) != 0) << 0x1f | param_3 >> 1;
      if (uVar2 == 0 && uVar4 == 0) break;
      iVar6 = 0;
      do {
        while (uVar5 = *(uint *)((int)auStack_120 + iVar6), uVar5 == 0) {
          *(undefined4 *)((int)auStack_a0 + iVar6) = 0;
          iVar6 = iVar6 + 4;
          if (iVar6 == 0x80) goto LAB_00056020;
        }
        uVar3 = 0;
        puVar1 = auStack_120;
        do {
          if ((int)(uVar5 << 0x1f) < 0) {
            uVar3 = uVar3 ^ *puVar1;
          }
          uVar5 = uVar5 >> 1;
          puVar1 = puVar1 + 1;
        } while (uVar5 != 0);
        *(uint *)((int)auStack_a0 + iVar6) = uVar3;
        iVar6 = iVar6 + 4;
      } while (iVar6 != 0x80);
LAB_00056020:
      if (((param_3 >> 1 & 1) != 0) && (param_1 != 0)) {
        puVar1 = auStack_a0;
        uVar5 = 0;
        uVar3 = param_1;
        do {
          param_1 = uVar5;
          puVar1 = (uint *)((int)puVar1 + 4);
          if ((int)(uVar3 << 0x1f) < 0) {
            param_1 = param_1 ^ puVar1[0xffffffff];
          }
          uVar3 = uVar3 >> 1;
          uVar5 = param_1;
        } while (uVar3 != 0);
      }
      param_4 = (int)param_4 >> 2;
      param_3 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar2 >> 1;
    } while (param_3 != 0 || param_4 != 0);
    param_1 = param_1 ^ param_2;
  }
  return param_1;
}

