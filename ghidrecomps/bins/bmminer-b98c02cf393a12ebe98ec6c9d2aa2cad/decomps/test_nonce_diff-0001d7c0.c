
bool test_nonce_diff(int param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 extraout_s1;
  UDItype UVar4;
  
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  uVar3 = regen_hash();
  UVar4 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar3));
  uVar1 = (uint)(UVar4 >> 0x20);
  bVar2 = *(uint *)(param_1 + 0xdc) <= uVar1;
  if (uVar1 == *(uint *)(param_1 + 0xdc)) {
    bVar2 = *(uint *)(param_1 + 0xd8) <= (uint)UVar4;
  }
  return bVar2;
}

