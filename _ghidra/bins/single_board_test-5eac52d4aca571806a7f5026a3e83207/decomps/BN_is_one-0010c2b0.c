
uint BN_is_one(int param_1)

{
  uint uVar1;
  
  uVar1 = BN_abs_is_word(param_1,1);
  if (uVar1 != 0) {
    uVar1 = (uint)(*(int *)(param_1 + 0xc) == 0);
  }
  return uVar1;
}

