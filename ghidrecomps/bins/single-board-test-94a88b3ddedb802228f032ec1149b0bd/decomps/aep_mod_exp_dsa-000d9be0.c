
void aep_mod_exp_dsa(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                    BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  
  iVar1 = BN_num_bits(param_5);
  if (iVar1 < 0x881) {
    aep_mod_exp_part_0(param_2,param_3,param_4,param_5);
    return;
  }
  if (AEPHK_lib_error_code == 0) {
    AEPHK_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
  BN_mod_exp(param_2,param_3,param_4,param_5,param_6);
  return;
}

