
void sha2_finish(uint *param_1,undefined *param_2)

{
  uint uVar1;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  
  uVar1 = param_1[1] << 3;
  local_c = uVar1 | *param_1 >> 0x1d;
  local_10 = *param_1 << 3;
  local_20 = (undefined)(uVar1 >> 0x18);
  local_1f = (undefined)(uVar1 >> 0x10);
  local_1e = (undefined)(uVar1 >> 8);
  local_1d = (undefined)local_c;
  local_1c = (undefined)((uint)local_10 >> 0x18);
  local_1b = (undefined)((uint)local_10 >> 0x10);
  local_1a = (undefined)((uint)local_10 >> 8);
  local_19 = (undefined)local_10;
  local_14 = *param_1 & 0x3f;
  if (local_14 < 0x38) {
    local_18 = 0x38 - local_14;
  }
  else {
    local_18 = 0x78 - local_14;
  }
  sha2_update(param_1,&sha2_padding,local_18);
  sha2_update(param_1,&local_20,8);
  *param_2 = (char)(param_1[2] >> 0x18);
  param_2[1] = (char)(param_1[2] >> 0x10);
  param_2[2] = (char)(param_1[2] >> 8);
  param_2[3] = (char)param_1[2];
  param_2[4] = (char)(param_1[3] >> 0x18);
  param_2[5] = (char)(param_1[3] >> 0x10);
  param_2[6] = (char)(param_1[3] >> 8);
  param_2[7] = (char)param_1[3];
  param_2[8] = (char)(param_1[4] >> 0x18);
  param_2[9] = (char)(param_1[4] >> 0x10);
  param_2[10] = (char)(param_1[4] >> 8);
  param_2[0xb] = (char)param_1[4];
  param_2[0xc] = (char)(param_1[5] >> 0x18);
  param_2[0xd] = (char)(param_1[5] >> 0x10);
  param_2[0xe] = (char)(param_1[5] >> 8);
  param_2[0xf] = (char)param_1[5];
  param_2[0x10] = (char)(param_1[6] >> 0x18);
  param_2[0x11] = (char)(param_1[6] >> 0x10);
  param_2[0x12] = (char)(param_1[6] >> 8);
  param_2[0x13] = (char)param_1[6];
  param_2[0x14] = (char)(param_1[7] >> 0x18);
  param_2[0x15] = (char)(param_1[7] >> 0x10);
  param_2[0x16] = (char)(param_1[7] >> 8);
  param_2[0x17] = (char)param_1[7];
  param_2[0x18] = (char)(param_1[8] >> 0x18);
  param_2[0x19] = (char)(param_1[8] >> 0x10);
  param_2[0x1a] = (char)(param_1[8] >> 8);
  param_2[0x1b] = (char)param_1[8];
  param_2[0x1c] = (char)(param_1[9] >> 0x18);
  param_2[0x1d] = (char)(param_1[9] >> 0x10);
  param_2[0x1e] = (char)(param_1[9] >> 8);
  param_2[0x1f] = (char)param_1[9];
  return;
}

