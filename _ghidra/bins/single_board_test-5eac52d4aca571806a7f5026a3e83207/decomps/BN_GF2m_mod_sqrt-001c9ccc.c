
int BN_GF2m_mod_sqrt(undefined4 param_1,undefined4 param_2,BIGNUM *param_3,undefined4 param_4)

{
  int iVar1;
  void *ptr;
  int iVar2;
  
  iVar1 = BN_num_bits(param_3);
  iVar1 = iVar1 + 1;
  ptr = CRYPTO_malloc(iVar1 * 4,"crypto/bn/bn_gf2m.c",0x3c5);
  if (ptr == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = BN_GF2m_poly2arr(param_3,ptr,iVar1);
    if (iVar2 == 0 || iVar1 < iVar2) {
      ERR_put_error(3,0x89,0x6a,"crypto/bn/bn_gf2m.c",0x3c9);
    }
    else {
      iVar2 = BN_GF2m_mod_sqrt_arr(param_1,param_2,ptr,param_4);
    }
  }
  CRYPTO_free(ptr);
  return iVar2;
}

