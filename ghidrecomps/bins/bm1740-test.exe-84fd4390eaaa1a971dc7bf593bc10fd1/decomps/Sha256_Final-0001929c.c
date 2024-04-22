
void Sha256_Final(int param_1,undefined *param_2)

{
  undefined *local_30;
  uint local_28;
  uint local_24;
  uint local_20;
  uint uStack_1c;
  
  uStack_1c = *(int *)(param_1 + 0x24) << 3 | *(uint *)(param_1 + 0x20) >> 0x1d;
  local_20 = *(uint *)(param_1 + 0x20) << 3;
  local_24 = *(uint *)(param_1 + 0x20) & 0x3f;
  *(undefined *)(param_1 + local_24 + 0x28) = 0x80;
  while (local_24 = local_24 + 1, local_24 != 0x38) {
    local_24 = local_24 & 0x3f;
    if (local_24 == 0) {
      Sha256_WriteByteBlock(param_1);
    }
    *(undefined *)(param_1 + local_24 + 0x28) = 0;
  }
  for (local_28 = 0; local_28 < 8; local_28 = local_28 + 1) {
    *(char *)(param_1 + local_24 + 0x28) = (char)(uStack_1c >> 0x18);
    local_24 = local_24 + 1;
    uStack_1c = uStack_1c << 8 | local_20 >> 0x18;
    local_20 = local_20 << 8;
  }
  Sha256_WriteByteBlock(param_1);
  local_30 = param_2;
  for (local_28 = 0; local_28 < 8; local_28 = local_28 + 1) {
    *local_30 = (char)((uint)*(undefined4 *)(param_1 + local_28 * 4) >> 0x18);
    local_30[1] = (char)((uint)*(undefined4 *)(param_1 + local_28 * 4) >> 0x10);
    local_30[2] = (char)((uint)*(undefined4 *)(param_1 + local_28 * 4) >> 8);
    local_30[3] = (char)*(undefined4 *)(param_1 + local_28 * 4);
    local_30 = local_30 + 4;
  }
  Sha256_Init(param_1);
  return;
}

