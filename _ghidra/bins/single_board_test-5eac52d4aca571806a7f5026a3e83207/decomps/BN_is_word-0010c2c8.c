
uint BN_is_word(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = BN_abs_is_word();
  if (uVar1 != 0) {
    if (param_2 != 0) {
      return (uint)(*(int *)(param_1 + 0xc) == 0);
    }
    uVar1 = 1;
  }
  return uVar1;
}

