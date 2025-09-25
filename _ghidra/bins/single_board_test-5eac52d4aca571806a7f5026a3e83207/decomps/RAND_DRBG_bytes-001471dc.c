
undefined4 RAND_DRBG_bytes(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_24 [2];
  
  iVar1 = *(int *)(param_1 + 0x1c);
  local_24[0] = 0;
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      return 0;
    }
    iVar1 = rand_pool_new(0,0,0,*(undefined4 *)(param_1 + 0x3c));
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 == 0) {
LAB_00147224:
      uVar2 = 0;
      goto LAB_00147226;
    }
  }
  uVar2 = rand_drbg_get_additional_data(iVar1,local_24);
  if (param_3 != 0) {
    do {
      uVar3 = *(uint *)(param_1 + 0x24);
      if (param_3 <= *(uint *)(param_1 + 0x24)) {
        uVar3 = param_3;
      }
      iVar1 = RAND_DRBG_generate(param_1,param_2,uVar3,0,local_24[0],uVar2);
      if (iVar1 == 0) goto LAB_00147224;
      param_3 = param_3 - uVar3;
      param_2 = param_2 + uVar3;
    } while (param_3 != 0);
  }
  uVar2 = 1;
LAB_00147226:
  if (local_24[0] != 0) {
    rand_drbg_cleanup_additional_data(*(undefined4 *)(param_1 + 0x1c));
  }
  return uVar2;
}

