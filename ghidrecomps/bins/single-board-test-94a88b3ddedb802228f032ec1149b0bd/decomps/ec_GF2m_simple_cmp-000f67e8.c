
int ec_GF2m_simple_cmp(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *b;
  BIGNUM *b_00;
  uint uVar2;
  int iVar3;
  BN_CTX *c;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    uVar2 = EC_POINT_is_at_infinity(param_1,param_3);
    if (uVar2 < 2) {
      return 1 - uVar2;
    }
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 == 0) {
    if ((*(int *)(param_2 + 0x40) == 0) || (*(int *)(param_3 + 0x40) == 0)) {
      if (param_4 == (BN_CTX *)0x0) {
        param_4 = BN_CTX_new();
        c = param_4;
        if (param_4 == (BN_CTX *)0x0) {
          return -1;
        }
      }
      else {
        c = (BN_CTX *)0x0;
      }
      BN_CTX_start(param_4);
      a = BN_CTX_get(param_4);
      a_00 = BN_CTX_get(param_4);
      b = BN_CTX_get(param_4);
      b_00 = BN_CTX_get(param_4);
      if (((b_00 == (BIGNUM *)0x0) ||
          (iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,a,a_00,param_4), iVar1 == 0)
          ) || (iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,b,b_00,param_4),
               iVar1 == 0)) {
        iVar1 = -1;
      }
      else {
        iVar3 = BN_cmp(a,b);
        iVar1 = 1;
        if ((iVar3 == 0) && (iVar1 = BN_cmp(a_00,b_00), iVar1 != 0)) {
          iVar1 = 1;
        }
      }
      BN_CTX_end(param_4);
      if (c == (BN_CTX *)0x0) {
        return iVar1;
      }
      BN_CTX_free(c);
      return iVar1;
    }
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 4),(BIGNUM *)(param_3 + 4));
    if (iVar1 == 0) {
      iVar1 = BN_cmp((BIGNUM *)(param_2 + 0x18),(BIGNUM *)(param_3 + 0x18));
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}

