
undefined4 ec_GF2m_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *b;
  undefined4 uVar3;
  BN_CTX *c;
  
  if ((*(int *)(param_2 + 0x14) != 0) ||
     (iVar1 = EC_POINT_is_at_infinity(param_1,param_2), iVar1 != 0)) {
    return 1;
  }
  c = (BN_CTX *)0x0;
  if ((param_3 == (BN_CTX *)0x0) && (param_3 = BN_CTX_new(), c = param_3, param_3 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_3);
  pBVar2 = BN_CTX_get(param_3);
  b = BN_CTX_get(param_3);
  if ((((b == (BIGNUM *)0x0) ||
       (iVar1 = EC_POINT_get_affine_coordinates(param_1,param_2,pBVar2,b,param_3), iVar1 == 0)) ||
      (pBVar2 = BN_copy(*(BIGNUM **)(param_2 + 8),pBVar2), pBVar2 == (BIGNUM *)0x0)) ||
     ((pBVar2 = BN_copy(*(BIGNUM **)(param_2 + 0xc),b), pBVar2 == (BIGNUM *)0x0 ||
      (iVar1 = BN_set_word(*(BIGNUM **)(param_2 + 0x10),1), iVar1 == 0)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    *(undefined4 *)(param_2 + 0x14) = 1;
  }
  BN_CTX_end(param_3);
  BN_CTX_free(c);
  return uVar3;
}

