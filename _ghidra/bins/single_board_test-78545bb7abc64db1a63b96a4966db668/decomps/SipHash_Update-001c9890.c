
void SipHash_Update(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *__src;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_70;
  uint local_48;
  uint uStack_44;
  uint *local_40;
  uint local_38;
  
  uVar4 = *param_1;
  uVar2 = param_1[10];
  local_48 = param_1[4];
  uStack_44 = param_1[5];
  *param_1 = uVar4 + param_3;
  param_1[1] = param_1[1] + (uint)CARRY4(uVar4,param_3);
  uVar9 = param_1[2];
  uVar10 = param_1[3];
  uVar7 = param_1[6];
  uVar8 = param_1[7];
  uVar4 = param_1[8];
  uVar6 = param_1[9];
  local_40 = param_2;
  local_38 = param_3;
  if (uVar2 != 0) {
    uVar1 = 8 - uVar2;
    if (param_3 < uVar1) {
      memcpy((void *)(uVar2 + 0x38 + (int)param_1),param_2,param_3);
      param_1[10] = param_1[10] + param_3;
      return;
    }
    local_38 = param_3 - uVar1;
    memcpy((void *)(uVar2 + 0x38 + (int)param_1),param_2,uVar1);
    local_40 = (uint *)((int)param_2 + uVar1);
    uVar4 = param_1[0xe] ^ uVar4;
    uVar6 = param_1[0xf] ^ uVar6;
    if (0 < (int)param_1[0xc]) {
      uVar2 = 0;
      do {
        uVar5 = local_48 + uVar9;
        uVar10 = uStack_44 + uVar10 + CARRY4(local_48,uVar9);
        uVar9 = uVar4 + uVar7;
        uVar7 = uVar6 + uVar8 + CARRY4(uVar4,uVar7);
        uVar2 = uVar2 + 1;
        uVar3 = (uStack_44 << 0xd | local_48 >> 0x13) ^ uVar10;
        uVar1 = (local_48 << 0xd | uStack_44 >> 0x13) ^ uVar5;
        uVar11 = (uVar6 << 0x10 | uVar4 >> 0x10) ^ uVar7;
        uVar6 = (uVar4 << 0x10 | uVar6 >> 0x10) ^ uVar9;
        uVar8 = uVar1 + uVar9;
        uVar7 = uVar3 + uVar7 + CARRY4(uVar1,uVar9);
        uVar9 = uVar10 + uVar6;
        uVar10 = uVar5 + uVar11 + CARRY4(uVar10,uVar6);
        local_48 = (uVar1 << 0x11 | uVar3 >> 0xf) ^ uVar8;
        uStack_44 = (uVar3 << 0x11 | uVar1 >> 0xf) ^ uVar7;
        uVar4 = (uVar6 << 0x15 | uVar11 >> 0xb) ^ uVar9;
        uVar6 = (uVar11 << 0x15 | uVar6 >> 0xb) ^ uVar10;
      } while (uVar2 != param_1[0xc]);
    }
    uVar9 = param_1[0xe] ^ uVar9;
    uVar10 = param_1[0xf] ^ uVar10;
  }
  uVar2 = local_38 & 7;
  __src = (uint *)((int)local_40 + (local_38 - uVar2));
  if (local_40 != __src) {
    do {
      HintPreloadData(local_40 + 0x10);
      uVar4 = *local_40 ^ uVar4;
      uVar6 = local_40[1] ^ uVar6;
      if (0 < (int)param_1[0xc]) {
        local_70 = 0;
        do {
          uVar5 = local_48 + uVar9;
          uVar10 = uStack_44 + uVar10 + CARRY4(local_48,uVar9);
          uVar9 = uVar4 + uVar7;
          uVar7 = uVar6 + uVar8 + CARRY4(uVar4,uVar7);
          uVar3 = (uStack_44 << 0xd | local_48 >> 0x13) ^ uVar10;
          uVar1 = (local_48 << 0xd | uStack_44 >> 0x13) ^ uVar5;
          uVar11 = (uVar6 << 0x10 | uVar4 >> 0x10) ^ uVar7;
          uVar6 = (uVar4 << 0x10 | uVar6 >> 0x10) ^ uVar9;
          uVar8 = uVar1 + uVar9;
          uVar7 = uVar3 + uVar7 + CARRY4(uVar1,uVar9);
          local_70 = local_70 + 1;
          uVar9 = uVar10 + uVar6;
          uVar10 = uVar5 + uVar11 + CARRY4(uVar10,uVar6);
          uVar4 = (uVar6 << 0x15 | uVar11 >> 0xb) ^ uVar9;
          uVar6 = (uVar11 << 0x15 | uVar6 >> 0xb) ^ uVar10;
          local_48 = (uVar1 << 0x11 | uVar3 >> 0xf) ^ uVar8;
          uStack_44 = (uVar3 << 0x11 | uVar1 >> 0xf) ^ uVar7;
        } while (local_70 != param_1[0xc]);
      }
      uVar10 = local_40[1] ^ uVar10;
      uVar9 = *local_40 ^ uVar9;
      local_40 = local_40 + 2;
    } while (__src != local_40);
  }
  if (uVar2 != 0) {
    memcpy(param_1 + 0xe,__src,uVar2);
  }
  param_1[2] = uVar9;
  param_1[3] = uVar10;
  param_1[10] = uVar2;
  param_1[4] = local_48;
  param_1[5] = uStack_44;
  param_1[6] = uVar7;
  param_1[7] = uVar8;
  param_1[8] = uVar4;
  param_1[9] = uVar6;
  return;
}

