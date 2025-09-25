
undefined4 srp_verify_server_param(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x624),*(BIGNUM **)(param_1 + 0x620));
  if (((-1 < iVar1) ||
      (iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x62c),*(BIGNUM **)(param_1 + 0x620)), -1 < iVar1)) ||
     (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0x62c)), iVar1 != 0)) {
    ossl_statem_fatal(param_1,0x2f,0x254,0x186,"ssl/tls_srp.c",0x156);
    return 0;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x620));
  uVar3 = 0;
  if (iVar1 < *(int *)(param_1 + 0x644)) {
    uVar2 = 0x15c;
LAB_000fa8ba:
    ossl_statem_fatal(param_1,0x47,0x254,0xf1,"ssl/tls_srp.c",uVar2);
  }
  else {
    if (*(code **)(param_1 + 0x614) == (code *)0x0) {
      iVar1 = SRP_check_known_gN_param
                        (*(undefined4 *)(param_1 + 0x624),*(undefined4 *)(param_1 + 0x620));
      if (iVar1 == 0) {
        uVar2 = 0x169;
        goto LAB_000fa8ba;
      }
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x614))(param_1,*(undefined4 *)(param_1 + 0x60c));
      if (iVar1 < 1) {
        ossl_statem_fatal(param_1,0x47,0x254,0xea,"ssl/tls_srp.c",0x164);
        return 0;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

