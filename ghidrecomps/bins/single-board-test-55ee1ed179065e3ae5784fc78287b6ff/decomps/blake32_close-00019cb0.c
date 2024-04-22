
void blake32_close(int param_1,byte param_2,uint param_3,int param_4,uint param_5)

{
  byte abStack_64 [55];
  byte local_2d;
  undefined auStack_2c [4];
  undefined auStack_28 [4];
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  
  local_10 = *(int *)(param_1 + 0x40);
  local_14 = local_10 * 8 + param_3;
  local_18 = 0x80 >> (param_3 & 0xff);
  abStack_64[local_10] = (byte)local_18 | param_2 & -(byte)local_18;
  local_1c = *(int *)(param_1 + 0x74) + local_14;
  local_20 = *(undefined4 *)(param_1 + 0x78);
  if ((local_10 == 0) && (param_3 == 0)) {
    *(undefined4 *)(param_1 + 0x74) = 0xfffffe00;
    *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  }
  else if (*(int *)(param_1 + 0x74) == 0) {
    *(uint *)(param_1 + 0x74) = local_14 - 0x200;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + -1;
  }
  else {
    *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + local_14 + -0x200;
  }
  if (local_14 < 0x1bf) {
    memset(abStack_64 + local_10 + 1,0,0x37 - local_10);
    if (param_5 == 8) {
      local_2d = local_2d | 1;
    }
    sph_enc32be_aligned(auStack_2c,local_20);
    sph_enc32be_aligned(auStack_28,local_1c);
    blake32(param_1,abStack_64 + local_10,0x40 - local_10);
  }
  else {
    memset(abStack_64 + local_10 + 1,0,0x3f - local_10);
    blake32(param_1,abStack_64 + local_10,0x40 - local_10);
    *(undefined4 *)(param_1 + 0x74) = 0xfffffe00;
    *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
    memset(abStack_64,0,0x38);
    if (param_5 == 8) {
      local_2d = 1;
    }
    sph_enc32be_aligned(auStack_2c,local_20);
    sph_enc32be_aligned(auStack_28,local_1c);
    blake32(param_1,abStack_64,0x40);
  }
  local_24 = param_4;
  for (local_c = 0; local_c < param_5; local_c = local_c + 1) {
    sph_enc32be(local_24 + local_c * 4,*(undefined4 *)(param_1 + (local_c + 0x10) * 4 + 4));
  }
  return;
}

