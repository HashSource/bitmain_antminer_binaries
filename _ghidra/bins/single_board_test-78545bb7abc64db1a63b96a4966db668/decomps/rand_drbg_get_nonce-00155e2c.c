
undefined4
rand_drbg_get_nonce(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar1 = rand_pool_new(0,0,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = rand_pool_add_nonce_data();
  if (iVar2 != 0) {
    local_20 = param_1;
    CRYPTO_atomic_add(&rand_nonce_count,1,&local_1c,rand_nonce_lock);
    iVar2 = rand_pool_add(iVar1,&local_20,8,0);
    if (iVar2 != 0) {
      uVar4 = rand_pool_length(iVar1);
      uVar3 = rand_pool_detach(iVar1);
      *param_2 = uVar3;
      goto LAB_00155e54;
    }
  }
  uVar4 = 0;
LAB_00155e54:
  rand_pool_free(iVar1);
  return uVar4;
}

