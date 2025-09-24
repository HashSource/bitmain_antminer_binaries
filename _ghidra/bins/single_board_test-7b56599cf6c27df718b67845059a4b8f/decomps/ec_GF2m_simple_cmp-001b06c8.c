
uint ec_GF2m_simple_cmp(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *b;
  BIGNUM *b_00;
  uint uVar2;
  BN_CTX *c;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
    return (uint)(iVar1 == 0);
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 == 0) {
    if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_3 + 0x14) == 0)) {
      c = (BN_CTX *)0x0;
      if ((param_4 == (BN_CTX *)0x0) &&
         (param_4 = BN_CTX_new(), c = param_4, param_4 == (BN_CTX *)0x0)) {
        return 0xffffffff;
      }
      BN_CTX_start(param_4);
      a = BN_CTX_get(param_4);
      a_00 = BN_CTX_get(param_4);
      b = BN_CTX_get(param_4);
      b_00 = BN_CTX_get(param_4);
      if (((b_00 == (BIGNUM *)0x0) ||
          (iVar1 = EC_POINT_get_affine_coordinates(param_1,param_2,a,a_00,param_4), iVar1 == 0)) ||
         (iVar1 = EC_POINT_get_affine_coordinates(param_1,param_3,b,b_00,param_4), iVar1 == 0)) {
        uVar2 = 0xffffffff;
      }
      else {
        iVar1 = BN_cmp(a,b);
        uVar2 = 1;
        if ((iVar1 == 0) && (uVar2 = BN_cmp(a_00,b_00), uVar2 != 0)) {
          uVar2 = 1;
        }
      }
      BN_CTX_end(param_4);
      BN_CTX_free(c);
      return uVar2;
    }
    iVar1 = BN_cmp(*(BIGNUM **)(param_2 + 8),*(BIGNUM **)(param_3 + 8));
    if (iVar1 == 0) {
      iVar1 = BN_cmp(*(BIGNUM **)(param_2 + 0xc),*(BIGNUM **)(param_3 + 0xc));
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}

