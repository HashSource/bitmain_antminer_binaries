
uint gf_deserialize(int param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  uint local_50;
  int local_4c;
  int local_44;
  uint *local_40;
  uint local_3c;
  
  local_40 = (uint *)(param_1 + -4);
  local_44 = 0;
  uVar11 = 0;
  local_50 = 0;
  local_4c = 0;
  puVar10 = &MODULUS;
  uVar5 = 0;
  local_3c = 0xfffffff;
  uVar6 = 0;
  uVar7 = 0;
  do {
    bVar13 = 0x1a < uVar5;
    bVar12 = uVar5 == 0x1b;
    if (uVar5 < 0x1c) {
      bVar13 = 0x36 < uVar11;
      bVar12 = uVar11 == 0x37;
    }
    if (!bVar13 || bVar12) {
      pbVar9 = (byte *)(param_2 + uVar11);
      do {
        bVar12 = uVar11 == 0x37;
        uVar8 = uVar5 - 0x20;
        uVar4 = 0x20 - uVar5;
        bVar1 = *pbVar9;
        uVar11 = uVar11 + 1;
        if (bVar12) {
          uVar3 = 0x20 - uVar5;
          uVar11 = 0x38;
          uVar2 = (uint)bVar1 & ~param_4;
          uVar4 = uVar5 & 0xff;
          uVar5 = uVar5 + 8;
          uVar6 = uVar6 | uVar2 << uVar4;
          uVar7 = uVar7 | uVar2 << (uVar8 & 0xff) | uVar2 >> (uVar3 & 0xff);
          break;
        }
        uVar2 = uVar5 & 0xff;
        uVar5 = uVar5 + 8;
        bVar13 = 0x1a < uVar5;
        bVar12 = uVar5 == 0x1b;
        if (uVar5 < 0x1c) {
          bVar13 = 0x36 < uVar11;
          bVar12 = uVar11 == 0x37;
        }
        uVar6 = uVar6 | (uint)bVar1 << uVar2;
        uVar7 = uVar7 | (uint)bVar1 << (uVar8 & 0xff) | (uint)(bVar1 >> (uVar4 & 0xff));
        pbVar9 = pbVar9 + 1;
      } while (!bVar13 || bVar12);
    }
    if (local_44 == 0xf) {
      uVar4 = uVar6 >> 0x1c | uVar7 << 4;
      local_50 = (local_4c + (uint)CARRY4(local_50,uVar6)) - (uint)(local_50 + uVar6 < local_3c);
      *(uint *)(param_1 + 0x3c) = uVar6;
LAB_001adf44:
      uVar6 = 0xffffffff;
      if (param_3 == 0) {
        uVar6 = gf_hibit(param_1);
        uVar6 = ~uVar6;
      }
      return uVar6 & (int)(uVar4 - 1 & ~uVar4) >> 0x1f & ~((int)(local_50 - 1 & ~local_50) >> 0x1f);
    }
    uVar8 = uVar6 & 0xfffffff;
    local_44 = local_44 + 1;
    local_40 = local_40 + 1;
    *local_40 = uVar8;
    uVar4 = uVar6 >> 0x1c | uVar7 << 4;
    uVar5 = uVar5 - 0x1c;
    local_50 = (local_4c + (uint)CARRY4(local_50,uVar8)) - (uint)(local_50 + uVar8 < *puVar10);
    local_4c = (int)local_50 >> 0x1f;
    if ((uint *)(param_1 + 0x3c) == local_40) goto LAB_001adf44;
    puVar10 = puVar10 + 1;
    local_3c = *puVar10;
    uVar6 = uVar4;
    uVar7 = uVar7 >> 0x1c;
  } while( true );
}

