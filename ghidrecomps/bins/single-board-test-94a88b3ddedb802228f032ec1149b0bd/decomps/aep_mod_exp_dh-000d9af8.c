
void aep_mod_exp_dh(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = BN_num_bits(param_5);
  iVar1 = DAT_000d9b68;
  if (iVar2 < 0x881) {
    aep_mod_exp_part_0(param_2,param_3,param_4,param_5);
    return;
  }
  iVar2 = *(int *)(DAT_000d9b68 + 4);
  if (iVar2 == 0) {
    iVar2 = ERR_get_next_error_library();
    *(int *)(iVar1 + 4) = iVar2;
  }
  ERR_put_error(iVar2,0x68,0x74,DAT_000d9b64,0x265);
  BN_mod_exp(param_2,param_3,param_4,param_5,param_6);
  return;
}

