
void gcm_gmult_4bit(byte *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint *puVar10;
  
  pbVar8 = param_1 + 0xf;
  iVar2 = (*pbVar8 & 0xf) * 0x10;
  uVar9 = *(uint *)(param_2 + iVar2);
  iVar2 = param_2 + iVar2;
  puVar5 = (uint *)((*pbVar8 & 0xf0) + param_2);
  uVar7 = (uVar9 >> 4 | *(uint *)(iVar2 + 4) << 0x1c) ^ *puVar5;
  uVar1 = (*(uint *)(iVar2 + 8) >> 4 | *(uint *)(iVar2 + 0xc) << 0x1c) ^ puVar5[2];
  uVar9 = (*(uint *)(iVar2 + 0xc) >> 4 | uVar9 << 0x1c) ^ puVar5[3];
  uVar6 = *(uint *)(&rem_4bit + (*(uint *)(iVar2 + 8) & 0xf) * 4) ^
          *(uint *)(iVar2 + 4) >> 4 ^ puVar5[1];
  do {
    pbVar8 = pbVar8 + -1;
    puVar5 = (uint *)(param_2 + (*pbVar8 & 0xf) * 0x10);
    puVar10 = (uint *)((*pbVar8 & 0xf0) + param_2);
    uVar3 = *puVar5 ^ (uVar7 >> 4 | uVar6 << 0x1c);
    uVar4 = puVar5[2] ^ (uVar1 >> 4 | uVar9 << 0x1c);
    uVar9 = puVar5[3] ^ (uVar9 >> 4 | uVar7 << 0x1c);
    uVar6 = puVar5[1] ^ uVar6 >> 4 ^ *(uint *)(&rem_4bit + (uVar1 & 0xf) * 4);
    uVar1 = (uVar4 >> 4 | uVar9 << 0x1c) ^ puVar10[2];
    uVar9 = (uVar3 << 0x1c | uVar9 >> 4) ^ puVar10[3];
    uVar7 = (uVar3 >> 4 | uVar6 << 0x1c) ^ *puVar10;
    uVar6 = *(uint *)(&rem_4bit + (uVar4 & 0xf) * 4) ^ uVar6 >> 4 ^ puVar10[1];
  } while (param_1 != pbVar8);
  param_1[3] = (byte)uVar6;
  param_1[7] = (byte)uVar7;
  param_1[0xb] = (byte)uVar9;
  param_1[0xf] = (byte)uVar1;
  *param_1 = (byte)(uVar6 >> 0x18);
  param_1[1] = (byte)(uVar6 >> 0x10);
  param_1[2] = (byte)(uVar6 >> 8);
  param_1[4] = (byte)(uVar7 >> 0x18);
  param_1[5] = (byte)(uVar7 >> 0x10);
  param_1[6] = (byte)(uVar7 >> 8);
  param_1[8] = (byte)(uVar9 >> 0x18);
  param_1[9] = (byte)(uVar9 >> 0x10);
  param_1[10] = (byte)(uVar9 >> 8);
  param_1[0xc] = (byte)(uVar1 >> 0x18);
  param_1[0xd] = (byte)(uVar1 >> 0x10);
  param_1[0xe] = (byte)(uVar1 >> 8);
  return;
}

