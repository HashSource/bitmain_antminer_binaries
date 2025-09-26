
undefined4 SipHash_Final(int *param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_c0;
  uint local_bc;
  uint local_58;
  uint local_54;
  
  if (param_1[0xb] == param_3) {
    local_54 = *param_1 << 0x18;
    local_58 = 0;
    switch(param_1[10]) {
    case 7:
      local_54 = local_54 | (uint)*(byte *)((int)param_1 + 0x3e) << 0x10;
    case 6:
      local_54 = local_54 | (uint)*(byte *)((int)param_1 + 0x3d) << 8;
    case 5:
      local_54 = local_54 | *(byte *)(param_1 + 0xf);
    case 4:
      local_58 = (uint)*(byte *)((int)param_1 + 0x3b) << 0x18;
    case 3:
      local_58 = local_58 | (uint)*(byte *)((int)param_1 + 0x3a) << 0x10;
    case 2:
      local_58 = local_58 | (uint)*(byte *)((int)param_1 + 0x39) << 8;
    case 1:
      local_58 = local_58 | *(byte *)(param_1 + 0xe);
    }
    local_c0 = param_1[6];
    local_bc = param_1[7];
    uVar8 = param_1[2];
    uVar9 = param_1[3];
    uVar3 = local_58 ^ param_1[8];
    uVar6 = local_54 ^ param_1[9];
    uVar4 = param_1[4];
    uVar7 = param_1[5];
    if (0 < param_1[0xc]) {
      iVar11 = 0;
      do {
        uVar5 = uVar4 + uVar8;
        uVar9 = uVar7 + uVar9 + (uint)CARRY4(uVar4,uVar8);
        iVar11 = iVar11 + 1;
        uVar8 = local_c0 + uVar3;
        uVar10 = (uVar7 << 0xd | uVar4 >> 0x13) ^ uVar9;
        local_c0 = local_bc + uVar6 + (uint)CARRY4(local_c0,uVar3);
        uVar7 = (uVar4 << 0xd | uVar7 >> 0x13) ^ uVar5;
        uVar2 = (uVar6 << 0x10 | uVar3 >> 0x10) ^ local_c0;
        uVar6 = (uVar3 << 0x10 | uVar6 >> 0x10) ^ uVar8;
        local_bc = uVar8 + uVar7;
        local_c0 = local_c0 + uVar10 + CARRY4(uVar8,uVar7);
        uVar8 = uVar9 + uVar6;
        uVar9 = uVar5 + uVar2 + (uint)CARRY4(uVar9,uVar6);
        uVar4 = (uVar7 << 0x11 | uVar10 >> 0xf) ^ local_bc;
        uVar7 = (uVar10 << 0x11 | uVar7 >> 0xf) ^ local_c0;
        uVar3 = uVar8 ^ (uVar6 << 0x15 | uVar2 >> 0xb);
        uVar6 = uVar9 ^ (uVar2 << 0x15 | uVar6 >> 0xb);
      } while (iVar11 != param_1[0xc]);
    }
    local_54 = local_54 ^ uVar9;
    local_58 = local_58 ^ uVar8;
    if (param_1[0xb] == 0x10) {
      local_c0 = local_c0 ^ 0xee;
    }
    else {
      local_c0 = local_c0 ^ 0xff;
    }
    if (0 < param_1[0xd]) {
      iVar11 = 0;
      do {
        uVar2 = uVar4 + local_58;
        uVar5 = uVar7 + local_54 + (uint)CARRY4(uVar4,local_58);
        iVar11 = iVar11 + 1;
        uVar8 = local_c0 + uVar3;
        uVar10 = (uVar7 << 0xd | uVar4 >> 0x13) ^ uVar5;
        local_c0 = local_bc + uVar6 + (uint)CARRY4(local_c0,uVar3);
        uVar7 = (uVar4 << 0xd | uVar7 >> 0x13) ^ uVar2;
        uVar9 = (uVar6 << 0x10 | uVar3 >> 0x10) ^ local_c0;
        uVar6 = (uVar3 << 0x10 | uVar6 >> 0x10) ^ uVar8;
        local_bc = uVar8 + uVar7;
        local_c0 = local_c0 + uVar10 + CARRY4(uVar8,uVar7);
        local_58 = uVar5 + uVar6;
        local_54 = uVar2 + uVar9 + (uint)CARRY4(uVar5,uVar6);
        uVar4 = (uVar7 << 0x11 | uVar10 >> 0xf) ^ local_bc;
        uVar7 = (uVar10 << 0x11 | uVar7 >> 0xf) ^ local_c0;
        uVar3 = local_58 ^ (uVar6 << 0x15 | uVar9 >> 0xb);
        uVar6 = local_54 ^ (uVar9 << 0x15 | uVar6 >> 0xb);
      } while (iVar11 != param_1[0xd]);
    }
    uVar8 = local_c0 ^ local_58 ^ uVar4 ^ uVar3;
    uVar9 = local_bc ^ local_54 ^ uVar7 ^ uVar6;
    *param_2 = (char)uVar8;
    param_2[4] = (char)uVar9;
    param_2[6] = (char)(uVar9 >> 0x10);
    param_2[1] = (char)(uVar8 >> 8);
    param_2[2] = (char)(uVar8 >> 0x10);
    param_2[3] = (char)(uVar8 >> 0x18);
    param_2[5] = (char)(uVar9 >> 8);
    param_2[7] = (char)(uVar9 >> 0x18);
    if (param_1[0xb] != 8) {
      uVar4 = uVar4 ^ 0xdd;
      if (0 < param_1[0xd]) {
        iVar11 = 0;
        do {
          uVar2 = uVar4 + local_58;
          uVar5 = uVar7 + local_54 + (uint)CARRY4(uVar4,local_58);
          iVar11 = iVar11 + 1;
          uVar8 = local_c0 + uVar3;
          uVar10 = (uVar7 << 0xd | uVar4 >> 0x13) ^ uVar5;
          local_c0 = local_bc + uVar6 + (uint)CARRY4(local_c0,uVar3);
          uVar7 = (uVar4 << 0xd | uVar7 >> 0x13) ^ uVar2;
          uVar9 = (uVar6 << 0x10 | uVar3 >> 0x10) ^ local_c0;
          uVar6 = (uVar3 << 0x10 | uVar6 >> 0x10) ^ uVar8;
          local_bc = uVar8 + uVar7;
          local_c0 = local_c0 + uVar10 + CARRY4(uVar8,uVar7);
          local_58 = uVar5 + uVar6;
          local_54 = uVar2 + uVar9 + (uint)CARRY4(uVar5,uVar6);
          uVar4 = (uVar7 << 0x11 | uVar10 >> 0xf) ^ local_bc;
          uVar7 = (uVar10 << 0x11 | uVar7 >> 0xf) ^ local_c0;
          uVar3 = local_58 ^ (uVar6 << 0x15 | uVar9 >> 0xb);
          uVar6 = local_54 ^ (uVar9 << 0x15 | uVar6 >> 0xb);
        } while (param_1[0xd] != iVar11);
      }
      uVar3 = uVar3 ^ local_c0 ^ local_58 ^ uVar4;
      uVar6 = uVar6 ^ local_bc ^ local_54 ^ uVar7;
      param_2[8] = (char)uVar3;
      param_2[0xc] = (char)uVar6;
      param_2[9] = (char)(uVar3 >> 8);
      param_2[10] = (char)(uVar3 >> 0x10);
      param_2[0xb] = (char)(uVar3 >> 0x18);
      param_2[0xd] = (char)(uVar6 >> 8);
      param_2[0xe] = (char)(uVar6 >> 0x10);
      param_2[0xf] = (char)(uVar6 >> 0x18);
      return 1;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

