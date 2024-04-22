
void Sha256_Update(int param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int local_24;
  undefined *local_20;
  uint local_14;
  
  local_24 = param_3;
  local_20 = param_2;
  local_14 = *(uint *)(param_1 + 0x20) & 0x3f;
  while (local_24 != 0) {
    uVar2 = local_14 + 1;
    puVar1 = local_20 + 1;
    *(undefined *)(local_14 + param_1 + 0x28) = *local_20;
    uVar3 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar3 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar3);
    local_24 = local_24 + -1;
    local_20 = puVar1;
    local_14 = uVar2;
    if (uVar2 == 0x40) {
      local_14 = 0;
      Sha256_WriteByteBlock(param_1);
    }
  }
  return;
}

