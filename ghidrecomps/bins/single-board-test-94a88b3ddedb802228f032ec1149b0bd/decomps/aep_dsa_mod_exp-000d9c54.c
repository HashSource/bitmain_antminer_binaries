
int aep_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   BIGNUM *param_5,BIGNUM *param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  int iVar2;
  BIGNUM BStack_34;
  
  BN_init(&BStack_34);
  iVar1 = BN_num_bits(param_7);
  iVar2 = DAT_000d9d34;
  if (iVar1 < 0x881) {
    iVar2 = aep_mod_exp_part_0(param_2,param_3,param_4,param_7,param_8);
  }
  else {
    iVar1 = *(int *)(DAT_000d9d34 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x68,0x74,DAT_000d9d30,0x265);
    iVar2 = BN_mod_exp(param_2,param_3,param_4,param_7,param_8);
  }
  if (iVar2 != 0) {
    iVar1 = BN_num_bits(param_7);
    iVar2 = DAT_000d9d34;
    if (iVar1 < 0x881) {
      iVar2 = aep_mod_exp_part_0(&BStack_34,param_5,param_6,param_7,param_8);
    }
    else {
      iVar1 = *(int *)(DAT_000d9d34 + 4);
      if (iVar1 == 0) {
        iVar1 = ERR_get_next_error_library();
        *(int *)(iVar2 + 4) = iVar1;
      }
      ERR_put_error(iVar1,0x68,0x74,DAT_000d9d30,0x265);
      iVar2 = BN_mod_exp(&BStack_34,param_5,param_6,param_7,param_8);
    }
    if (iVar2 != 0) {
      iVar2 = BN_mod_mul(param_2,param_2,&BStack_34,param_7,param_8);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      goto LAB_000d9c88;
    }
  }
  iVar2 = 0;
LAB_000d9c88:
  BN_free(&BStack_34);
  return iVar2;
}

