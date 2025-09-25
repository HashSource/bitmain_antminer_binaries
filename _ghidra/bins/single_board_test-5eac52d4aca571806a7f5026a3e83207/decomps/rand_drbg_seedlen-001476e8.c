
uint rand_drbg_seedlen(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x20);
  uVar2 = *(uint *)(param_1 + 0x28);
  if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_1 + 0xfc) == 0)) {
    uVar2 = uVar2 + *(int *)(param_1 + 0x30);
    uVar3 = uVar3 + (int)uVar3 / 2 >> 3;
    if (uVar3 < uVar2) {
      uVar3 = uVar2;
    }
    return uVar3;
  }
  uVar1 = uVar3 >> 3;
  if (uVar3 >> 3 < uVar2) {
    uVar1 = uVar2;
  }
  return uVar1;
}

