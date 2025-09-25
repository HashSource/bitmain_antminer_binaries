
undefined4 by_dir_hash_cmp(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)*param_2 < *(uint *)*param_1) {
    return 1;
  }
  if (*(uint *)*param_1 < *(uint *)*param_2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

