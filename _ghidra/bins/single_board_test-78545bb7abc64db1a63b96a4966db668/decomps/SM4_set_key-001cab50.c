
undefined4 SM4_set_key(byte *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint local_38 [5];
  
  puVar1 = (uint *)(param_2 + -4);
  local_38[0] = ((uint)param_1[1] << 0x10 | (uint)*param_1 << 0x18 | (uint)param_1[3] |
                (uint)param_1[2] << 8) ^ 0xa3b1bac6;
  local_38[2] = ((uint)param_1[9] << 0x10 | (uint)param_1[8] << 0x18 | (uint)param_1[0xb] |
                (uint)param_1[10] << 8) ^ 0x677d9197;
  local_38[1] = ((uint)param_1[5] << 0x10 | (uint)param_1[4] << 0x18 | (uint)param_1[7] |
                (uint)param_1[6] << 8) ^ 0x56aa3350;
  local_38[3] = ((uint)param_1[0xd] << 0x10 | (uint)param_1[0xc] << 0x18 | (uint)param_1[0xf] |
                (uint)param_1[0xe] << 8) ^ 0xb27022dc;
  puVar6 = (uint *)&UNK_0024543c;
  uVar4 = 0;
  while( true ) {
    puVar6 = puVar6 + 1;
    local_38[3] = local_38[3] ^ local_38[2] ^ local_38[1] ^ *puVar6;
    uVar5 = uVar4 + 1;
    uVar2 = (uint)(byte)SM4_S[local_38[3] & 0xff] | (uint)(byte)SM4_S[local_38[3] >> 0x18] << 0x18 |
            (uint)(byte)SM4_S[(local_38[3] << 8) >> 0x18] << 0x10;
    uVar3 = uVar2 | (uint)(byte)SM4_S[(local_38[3] << 0x10) >> 0x18] << 8;
    local_38[0] = uVar3 ^ (uVar2 >> 0x13 | uVar3 << 0xd) ^ (uVar3 >> 9 | uVar3 << 0x17) ^
                  local_38[0];
    puVar1 = puVar1 + 1;
    *puVar1 = local_38[0];
    local_38[uVar4 & 3] = local_38[0];
    if (uVar5 == 0x20) break;
    local_38[1] = local_38[uVar4 + 2 & 3];
    local_38[2] = local_38[uVar4 + 3 & 3];
    local_38[3] = local_38[uVar4 & 3];
    local_38[0] = local_38[uVar5 & 3];
    uVar4 = uVar5;
  }
  return 1;
}

