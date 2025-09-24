
int BN_GF2m_mod_exp(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                   undefined4 param_5)

{
  int iVar1;
  void *ptr;
  int iVar2;
  
  iVar1 = BN_num_bits(param_4);
  iVar1 = iVar1 + 1;
  ptr = CRYPTO_malloc(iVar1 * 4,"crypto/bn/bn_gf2m.c",0x38a);
  if (ptr == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = BN_GF2m_poly2arr(param_4,ptr,iVar1);
    if (iVar2 == 0 || iVar1 < iVar2) {
      ERR_put_error(3,0x84,0x6a,"crypto/bn/bn_gf2m.c",0x38e);
    }
    else {
      iVar2 = BN_GF2m_mod_exp_arr(param_1,param_2,param_3,ptr,param_5);
    }
  }
  CRYPTO_free(ptr);
  return iVar2;
}

