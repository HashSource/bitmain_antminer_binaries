
void Sha256_Update(int param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  int local_1c;
  undefined *local_18;
  uint local_c;
  
  local_c = *(uint *)(param_1 + 0x20) & 0x3f;
  local_1c = param_3;
  local_18 = param_2;
  while (local_1c != 0) {
    *(undefined *)(param_1 + local_c + 0x28) = *local_18;
    local_c = local_c + 1;
    local_18 = local_18 + 1;
    uVar1 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar1 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar1);
    local_1c = local_1c + -1;
    if (local_c == 0x40) {
      local_c = 0;
      Sha256_WriteByteBlock(param_1);
    }
  }
  return;
}

