
uint crc32(uint param_1,byte *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  if (param_2 == (byte *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = ~param_1;
    if (param_3 != 0) {
      uVar7 = (uint)param_2 & 3;
      while (uVar7 != 0) {
        param_3 = param_3 - 1;
        param_1 = *(uint *)(DAT_000630f8 + ((*param_2 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
        if (param_3 == 0) goto LAB_00062e2c;
        uVar7 = (uint)(param_2 + 1) & 3;
        param_2 = param_2 + 1;
      }
      if (0x1f < param_3) {
        pbVar8 = param_2 + 0x40;
        pbVar6 = param_2;
        uVar7 = param_3;
        do {
          uVar7 = uVar7 - 0x20;
          puVar1 = (uint *)(pbVar6 + 0x10);
          HintPreloadData(pbVar8);
          HintPreloadData(pbVar6 + 0x44);
          param_1 = param_1 ^ *(uint *)(pbVar8 + -0x40);
          pbVar8 = pbVar8 + 0x20;
          puVar2 = (uint *)(pbVar6 + 0x14);
          uVar9 = *(uint *)(DAT_000630f8 + ((param_1 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (param_1 >> 0x18) * 4) ^ *(uint *)(pbVar6 + 4) ^
                  *(uint *)(DAT_000630f8 + (((param_1 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((param_1 << 8) >> 0x18) + 0x100) * 4);
          puVar3 = (uint *)(pbVar6 + 0x18);
          puVar4 = (uint *)(pbVar6 + 0x1c);
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *(uint *)(pbVar6 + 8) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          puVar5 = (uint *)(pbVar6 + 0xc);
          pbVar6 = pbVar6 + 0x20;
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *puVar5 ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *puVar1 ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *puVar2 ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *puVar3 ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          uVar9 = *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                  *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^ *puVar4 ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                  *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
          param_1 = *(uint *)(DAT_000630f8 + (uVar9 >> 0x18) * 4) ^
                    *(uint *)(DAT_000630f8 + ((uVar9 & 0xff) + 0x300) * 4) ^
                    *(uint *)(DAT_000630f8 + (((uVar9 << 0x10) >> 0x18) + 0x200) * 4) ^
                    *(uint *)(DAT_000630f8 + (((uVar9 << 8) >> 0x18) + 0x100) * 4);
        } while (0x1f < uVar7);
        uVar7 = param_3 - 0x20;
        param_3 = param_3 & 0x1f;
        param_2 = param_2 + (uVar7 & 0xffffffe0) + 0x20;
      }
      if (3 < param_3) {
        uVar7 = param_3 - 4;
        pbVar6 = param_2 + 4;
        do {
          puVar1 = (uint *)(pbVar6 + -4);
          pbVar6 = pbVar6 + 4;
          param_1 = param_1 ^ *puVar1;
          param_1 = *(uint *)(DAT_000630f8 + (param_1 >> 0x18) * 4) ^
                    *(uint *)(DAT_000630f8 + ((param_1 & 0xff) + 0x300) * 4) ^
                    *(uint *)(DAT_000630f8 + (((param_1 << 0x10) >> 0x18) + 0x200) * 4) ^
                    *(uint *)(DAT_000630f8 + (((param_1 << 8) >> 0x18) + 0x100) * 4);
        } while (pbVar6 != param_2 + (uVar7 & 0xfffffffc) + 8);
        param_3 = param_3 & 3;
        param_2 = param_2 + ((uVar7 >> 2) + 1) * 4;
      }
      if (param_3 != 0) {
        pbVar6 = param_2;
        do {
          pbVar8 = pbVar6 + 1;
          param_1 = *(uint *)(DAT_000630f8 + ((*pbVar6 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
          pbVar6 = pbVar8;
        } while (pbVar8 != param_2 + param_3);
      }
    }
LAB_00062e2c:
    param_1 = ~param_1;
  }
  return param_1;
}

