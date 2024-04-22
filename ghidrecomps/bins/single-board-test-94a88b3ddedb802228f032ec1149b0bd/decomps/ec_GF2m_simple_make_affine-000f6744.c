
int ec_GF2m_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *pBVar1;
  BIGNUM *b;
  int iVar2;
  BN_CTX *c;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (iVar2 = EC_POINT_is_at_infinity(param_1,param_2), iVar2 == 0)) {
    if (param_3 == (BN_CTX *)0x0) {
      param_3 = BN_CTX_new();
      c = param_3;
      if (param_3 == (BN_CTX *)0x0) {
        return 0;
      }
    }
    else {
      c = (BN_CTX *)0x0;
    }
    BN_CTX_start(param_3);
    pBVar1 = BN_CTX_get(param_3);
    b = BN_CTX_get(param_3);
    if ((((b == (BIGNUM *)0x0) ||
         (iVar2 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,pBVar1,b,param_3), iVar2 == 0
         )) || (pBVar1 = BN_copy((BIGNUM *)(param_2 + 4),pBVar1), pBVar1 == (BIGNUM *)0x0)) ||
       (pBVar1 = BN_copy((BIGNUM *)(param_2 + 0x18),b), pBVar1 == (BIGNUM *)0x0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
    BN_CTX_end(param_3);
    if (c != (BN_CTX *)0x0) {
      BN_CTX_free(c);
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

