
int EC_GROUP_check(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  EC_POINT *r;
  BIGNUM *n;
  BN_CTX *c;
  
  if ((**(uint **)group & 2) != 0) {
    return 1;
  }
  c = (BN_CTX *)0x0;
  if ((ctx == (BN_CTX *)0x0) && (c = BN_CTX_new(), ctx = c, c == (BN_CTX *)0x0)) {
    ERR_put_error(0x10,0xaa,0x41,"crypto/ec/ec_check.c",0x1b);
    r = (EC_POINT *)0x0;
    iVar1 = 0;
  }
  else {
    iVar1 = EC_GROUP_check_discriminant(group,ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0xaa,0x76,"crypto/ec/ec_check.c",0x22);
      r = (EC_POINT *)0x0;
      iVar1 = 0;
    }
    else if (*(EC_POINT **)(group + 4) == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xaa,0x71,"crypto/ec/ec_check.c",0x28);
      r = (EC_POINT *)0x0;
      iVar1 = 0;
    }
    else {
      iVar1 = EC_POINT_is_on_curve(group,*(EC_POINT **)(group + 4),ctx);
      if (iVar1 < 1) {
        r = (EC_POINT *)0x0;
        ERR_put_error(0x10,0xaa,0x6b,"crypto/ec/ec_check.c",0x2c);
        iVar1 = 0;
      }
      else {
        r = EC_POINT_new(group);
        if ((r != (EC_POINT *)0x0) && (n = (BIGNUM *)EC_GROUP_get0_order(group), n != (BIGNUM *)0x0)
           ) {
          iVar1 = BN_is_zero();
          if (iVar1 == 0) {
            iVar1 = EC_POINT_mul(group,r,n,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
            if (iVar1 != 0) {
              iVar1 = EC_POINT_is_at_infinity(group,r);
              if (iVar1 == 0) {
                ERR_put_error(0x10,0xaa,0x7a,"crypto/ec/ec_check.c",0x3e);
                iVar1 = 0;
              }
              else {
                iVar1 = 1;
              }
              goto LAB_00126512;
            }
          }
          else {
            ERR_put_error(0x10,0xaa,0x80,"crypto/ec/ec_check.c",0x37);
          }
        }
        iVar1 = 0;
      }
    }
  }
LAB_00126512:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar1;
}

