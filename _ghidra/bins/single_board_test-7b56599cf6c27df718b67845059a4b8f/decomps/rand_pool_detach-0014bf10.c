
undefined4 rand_pool_detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  param_1[7] = 0;
  *param_1 = 0;
  return uVar1;
}

