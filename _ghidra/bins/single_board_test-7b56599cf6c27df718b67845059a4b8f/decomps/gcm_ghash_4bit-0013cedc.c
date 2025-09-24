
void gcm_ghash_4bit(byte *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  uint *puVar11;
  byte *local_70;
  int local_38;
  int local_34;
  
  local_38 = param_3 + 0x2f;
  local_34 = param_4;
  do {
    HintPreloadData(local_38);
    local_70 = (byte *)(local_38 + -0x20);
    iVar1 = ((*local_70 ^ param_1[0xf]) & 0xf) * 0x10;
    puVar3 = (uint *)(((*local_70 ^ param_1[0xf]) & 0xf0) + param_2);
    uVar6 = *(uint *)(param_2 + iVar1);
    iVar1 = param_2 + iVar1;
    uVar2 = (*(uint *)(iVar1 + 8) >> 4 | *(uint *)(iVar1 + 0xc) << 0x1c) ^ puVar3[2];
    uVar4 = (*(uint *)(iVar1 + 0xc) >> 4 | uVar6 << 0x1c) ^ puVar3[3];
    uVar6 = (uVar6 >> 4 | *(uint *)(iVar1 + 4) << 0x1c) ^ *puVar3;
    uVar7 = *(uint *)(&rem_4bit + (*(uint *)(iVar1 + 8) & 0xf) * 4) ^
            *(uint *)(iVar1 + 4) >> 4 ^ puVar3[1];
    pbVar10 = param_1 + 0xf;
    do {
      pbVar10 = pbVar10 + -1;
      local_70 = local_70 + -1;
      puVar3 = (uint *)(param_2 + ((*pbVar10 ^ *local_70) & 0xf) * 0x10);
      puVar11 = (uint *)(((*pbVar10 ^ *local_70) & 0xf0) + param_2);
      uVar8 = *puVar3 ^ (uVar6 >> 4 | uVar7 << 0x1c);
      uVar9 = puVar3[1] ^ uVar7 >> 4 ^ *(uint *)(&rem_4bit + (uVar2 & 0xf) * 4);
      uVar5 = puVar3[3] ^ (uVar6 << 0x1c | uVar4 >> 4);
      uVar7 = puVar3[2] ^ (uVar2 >> 4 | uVar4 << 0x1c);
      uVar6 = (uVar8 >> 4 | uVar9 << 0x1c) ^ *puVar11;
      uVar2 = puVar11[2] ^ (uVar7 >> 4 | uVar5 << 0x1c);
      uVar4 = puVar11[3] ^ (uVar8 << 0x1c | uVar5 >> 4);
      uVar7 = *(uint *)(&rem_4bit + (uVar7 & 0xf) * 4) ^ uVar9 >> 4 ^ puVar11[1];
    } while (param_1 != pbVar10);
    param_1[3] = (byte)uVar7;
    param_1[7] = (byte)uVar6;
    param_1[0xb] = (byte)uVar4;
    local_38 = local_38 + 0x10;
    param_1[0xf] = (byte)uVar2;
    *param_1 = (byte)(uVar7 >> 0x18);
    param_1[1] = (byte)(uVar7 >> 0x10);
    param_1[2] = (byte)(uVar7 >> 8);
    param_1[10] = (byte)(uVar4 >> 8);
    param_1[5] = (byte)(uVar6 >> 0x10);
    param_1[6] = (byte)(uVar6 >> 8);
    local_34 = local_34 + -0x10;
    param_1[4] = (byte)(uVar6 >> 0x18);
    param_1[8] = (byte)(uVar4 >> 0x18);
    param_1[9] = (byte)(uVar4 >> 0x10);
    param_1[0xc] = (byte)(uVar2 >> 0x18);
    param_1[0xd] = (byte)(uVar2 >> 0x10);
    param_1[0xe] = (byte)(uVar2 >> 8);
  } while (local_34 != 0);
  return;
}

