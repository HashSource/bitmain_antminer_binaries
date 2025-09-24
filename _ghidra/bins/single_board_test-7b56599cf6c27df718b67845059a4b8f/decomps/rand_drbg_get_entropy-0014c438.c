
undefined4
rand_drbg_get_entropy
          (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_1c [2];
  
  iVar4 = *(int *)(param_1 + 4);
  local_1c[0] = param_1;
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x20) < *(int *)(param_1 + 0x20))) {
    ERR_put_error(0x24,0x78,0x83,"crypto/rand/rand_lib.c",0x8f);
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0x18);
  if (iVar5 == 0) {
    iVar5 = rand_pool_new(param_3,*(undefined4 *)(param_1 + 8),param_4,param_5);
    if (iVar5 == 0) {
      return 0;
    }
    iVar4 = *(int *)(local_1c[0] + 4);
  }
  else {
    *(undefined4 *)(iVar5 + 0x20) = param_3;
  }
  if (iVar4 == 0) {
    if (param_6 != 0) {
      ERR_put_error(0x24,0x78,0x85,"crypto/rand/rand_lib.c",0xc3);
      uVar2 = 0;
      goto LAB_0014c4ae;
    }
    iVar4 = rand_pool_acquire_entropy(iVar5);
LAB_0014c4f0:
    if (iVar4 != 0) {
      uVar2 = rand_pool_length(iVar5);
      uVar3 = rand_pool_detach(iVar5);
      *param_2 = uVar3;
      goto LAB_0014c4ae;
    }
  }
  else {
    iVar4 = rand_pool_bytes_needed(iVar5,1);
    iVar1 = rand_pool_add_begin(iVar5,iVar4);
    if (iVar1 != 0) {
      rand_drbg_lock(*(undefined4 *)(local_1c[0] + 4));
      iVar1 = RAND_DRBG_generate(*(undefined4 *)(local_1c[0] + 4),iVar1,iVar4,param_6,local_1c,4);
      if (iVar1 == 0) {
        iVar4 = 0;
        iVar1 = 0;
      }
      else {
        iVar1 = iVar4 << 3;
        if (*(int *)(local_1c[0] + 0x50) != 0) {
          iVar1 = iVar4 << 3;
          *(undefined4 *)(local_1c[0] + 0x54) = *(undefined4 *)(*(int *)(local_1c[0] + 4) + 0x54);
        }
      }
      rand_drbg_unlock(*(undefined4 *)(local_1c[0] + 4));
      rand_pool_add_end(iVar5,iVar4,iVar1);
      iVar4 = rand_pool_entropy_available(iVar5);
      goto LAB_0014c4f0;
    }
  }
  uVar2 = 0;
LAB_0014c4ae:
  if (*(int *)(local_1c[0] + 0x18) == 0) {
    rand_pool_free(iVar5);
  }
  return uVar2;
}

