
void ubsec_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                       BN_CTX *param_5,BN_MONT_CTX *param_6)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  
  iVar1 = BN_num_bits(param_4);
  if (iVar1 <= *(int *)(DAT_000def78 + 0xcc)) {
    ubsec_mod_exp(param_1,param_2,param_3,param_4);
    return;
  }
  pRVar2 = RSA_PKCS1_SSLeay();
  (*pRVar2->bn_mod_exp)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

