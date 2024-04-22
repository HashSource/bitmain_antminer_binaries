
int ec_GFp_mont_field_decode(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    iVar1 = BN_from_montgomery(param_2,param_3,*(BN_MONT_CTX **)(param_1 + 0xa0),param_4);
    return iVar1;
  }
  ERR_put_error(0x10,0x85,0x6f,DAT_001244d8,0x122);
  return 0;
}

