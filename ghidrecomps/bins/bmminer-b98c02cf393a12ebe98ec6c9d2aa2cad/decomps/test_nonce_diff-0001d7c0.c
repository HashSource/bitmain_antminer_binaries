
bool test_nonce_diff(int param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  DFtype unaff_d8;
  UDItype UVar3;
  
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  regen_hash();
  UVar3 = __fixunsdfdi(unaff_d8);
  uVar1 = (uint)(UVar3 >> 0x20);
  bVar2 = *(uint *)(param_1 + 0xdc) <= uVar1;
  if (uVar1 == *(uint *)(param_1 + 0xdc)) {
    bVar2 = *(uint *)(param_1 + 0xd8) <= (uint)UVar3;
  }
  return bVar2;
}

