
void bn_GF2m_mul_1x1(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint local_40 [7];
  uint local_24;
  
  local_40[1] = param_3 & 0x3fffffff;
  local_40[2] = local_40[1] << 1;
  local_40[4] = local_40[1] << 2;
  local_40[3] = local_40[2] ^ local_40[1];
  local_24 = local_40[2] ^ local_40[1] ^ local_40[4];
  local_40[6] = local_40[4] ^ local_40[2];
  local_40[5] = local_40[4] ^ local_40[1];
  local_40[0] = 0;
  bVar3 = (param_3 >> 0x1e & 1) != 0;
  uVar1 = local_40[param_4 & 7] ^ local_40[param_4 >> 0x1e] << 0x1e ^
          local_40[(param_4 << 0x1a) >> 0x1d] << 3 ^ local_40[(param_4 << 0x17) >> 0x1d] << 6 ^
          local_40[(param_4 << 0x14) >> 0x1d] << 9 ^ local_40[(param_4 << 0x11) >> 0x1d] << 0xc ^
          local_40[(param_4 << 0xe) >> 0x1d] << 0xf ^ local_40[(param_4 << 0xb) >> 0x1d] << 0x12 ^
          local_40[(param_4 << 8) >> 0x1d] << 0x15 ^ local_40[(param_4 << 5) >> 0x1d] << 0x18 ^
          local_40[(param_4 << 2) >> 0x1d] << 0x1b;
  uVar2 = local_40[(param_4 << 0x17) >> 0x1d] >> 0x1a ^ local_40[(param_4 << 0x1a) >> 0x1d] >> 0x1d
          ^ local_40[param_4 >> 0x1e] >> 2 ^ local_40[(param_4 << 0x14) >> 0x1d] >> 0x17 ^
          local_40[(param_4 << 0x11) >> 0x1d] >> 0x14 ^ local_40[(param_4 << 0xe) >> 0x1d] >> 0x11 ^
          local_40[(param_4 << 0xb) >> 0x1d] >> 0xe ^ local_40[(param_4 << 8) >> 0x1d] >> 0xb ^
          local_40[(param_4 << 5) >> 0x1d] >> 8 ^ local_40[(param_4 << 2) >> 0x1d] >> 5;
  if (bVar3) {
    uVar1 = uVar1 ^ param_4 << 0x1e;
  }
  if (bVar3) {
    uVar2 = uVar2 ^ param_4 >> 2;
  }
  if ((int)param_3 < 0) {
    uVar1 = uVar1 ^ param_4 << 0x1f;
  }
  if ((int)param_3 < 0) {
    uVar2 = uVar2 ^ param_4 >> 1;
  }
  *param_1 = uVar2;
  *param_2 = uVar1;
  return;
}

