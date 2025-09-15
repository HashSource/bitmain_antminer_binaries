
undefined4 blake2b_init_param(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_14;
  
  blake2b_init0(param_1);
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    uVar4 = load64(local_14 * 8 + param_2);
    puVar2 = (uint *)(local_14 * 8 + param_1);
    uVar3 = puVar2[1];
    puVar1 = (uint *)(local_14 * 8 + param_1);
    *puVar1 = *puVar2 ^ (uint)uVar4;
    puVar1[1] = uVar3 ^ (uint)((ulonglong)uVar4 >> 0x20);
  }
  return 0;
}

