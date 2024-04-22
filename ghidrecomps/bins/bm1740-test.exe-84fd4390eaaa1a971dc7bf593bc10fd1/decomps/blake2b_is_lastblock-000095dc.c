
undefined blake2b_is_lastblock(int param_1)

{
  undefined uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x54) | *(uint *)(param_1 + 0x50);
  bVar3 = uVar2 == 0;
  if (bVar3) {
    uVar2 = 0;
  }
  uVar1 = (undefined)uVar2;
  if (!bVar3) {
    uVar1 = 1;
  }
  return uVar1;
}

