
undefined4 blake2b_init_param(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_14;
  
  blake2b_init0(param_1);
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    puVar1 = (uint *)(param_1 + local_14 * 8);
    uVar2 = *puVar1;
    uVar3 = puVar1[1];
    uVar4 = load64(param_2 + local_14 * 8);
    puVar1 = (uint *)(param_1 + local_14 * 8);
    *puVar1 = (uint)uVar4 ^ uVar2;
    puVar1[1] = (uint)((ulonglong)uVar4 >> 0x20) ^ uVar3;
  }
  return 0;
}

