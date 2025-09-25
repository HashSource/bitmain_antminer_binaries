
int rand_drbg_get_additional_data(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rand_pool_add_additional_data();
  if (iVar1 != 0) {
    iVar1 = rand_pool_length(param_1);
    uVar2 = rand_pool_detach(param_1);
    *param_2 = uVar2;
  }
  return iVar1;
}

