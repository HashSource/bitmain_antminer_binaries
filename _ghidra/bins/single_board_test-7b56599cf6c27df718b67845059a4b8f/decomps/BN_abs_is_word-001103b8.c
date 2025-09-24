
undefined4 BN_abs_is_word(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1[1] == 1) && (*(int *)*param_1 == param_2)) {
    uVar1 = 1;
  }
  else if (param_2 == 0 && param_1[1] == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

