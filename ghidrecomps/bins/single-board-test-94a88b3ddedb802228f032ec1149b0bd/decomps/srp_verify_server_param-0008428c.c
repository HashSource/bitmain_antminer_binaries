
undefined4
srp_verify_server_param(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x1ac),*(BIGNUM **)(param_1 + 0x1a8));
  if (((-1 < iVar1) ||
      (iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x1b4),*(BIGNUM **)(param_1 + 0x1a8)), -1 < iVar1)) ||
     (*(int *)(*(int *)(param_1 + 0x1b4) + 4) == 0)) {
    *param_2 = 0x2f;
    return 0;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x1a8));
  if (*(int *)(param_1 + 0x1cc) <= iVar1) {
    if (*(code **)(param_1 + 0x19c) == (code *)0x0) {
      iVar1 = SRP_check_known_gN_param
                        (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8),param_3,0
                         ,param_4);
      if (iVar1 == 0) {
        *param_2 = 0x47;
        return 0;
      }
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x19c))(param_1,*(undefined4 *)(param_1 + 0x194));
      if (iVar1 < 1) goto LAB_000842ea;
    }
    return 1;
  }
LAB_000842ea:
  *param_2 = 0x47;
  return 0;
}

