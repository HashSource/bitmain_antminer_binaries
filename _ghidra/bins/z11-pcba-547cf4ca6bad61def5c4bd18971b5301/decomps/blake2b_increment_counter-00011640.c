
undefined4 blake2b_increment_counter(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = param_3 + uVar1;
  *(uint *)(param_1 + 0x44) = param_4 + *(int *)(param_1 + 0x44) + (uint)CARRY4(param_3,uVar1);
  uVar1 = *(uint *)(param_1 + 0x48);
  bVar3 = param_4 <= *(uint *)(param_1 + 0x44);
  if (*(uint *)(param_1 + 0x44) == param_4) {
    bVar3 = param_3 <= *(uint *)(param_1 + 0x40);
  }
  if (!bVar3) {
    param_3 = 1;
  }
  bVar2 = (byte)param_3;
  if (bVar3) {
    bVar2 = 0;
  }
  *(uint *)(param_1 + 0x48) = bVar2 + uVar1;
  *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (uint)CARRY4((uint)bVar2,uVar1);
  return 0;
}

