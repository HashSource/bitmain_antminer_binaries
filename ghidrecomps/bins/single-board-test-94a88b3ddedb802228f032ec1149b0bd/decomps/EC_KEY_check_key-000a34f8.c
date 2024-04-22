
int EC_KEY_check_key(EC_KEY *key)

{
  int iVar1;
  BN_CTX *c;
  EC_POINT *r;
  EC_GROUP *group;
  int line;
  
  if (((key == (EC_KEY *)0x0) || (*(EC_GROUP **)(key + 4) == (EC_GROUP *)0x0)) ||
     (*(EC_POINT **)(key + 8) == (EC_POINT *)0x0)) {
    ERR_put_error(0x10,0xb1,0x43,DAT_000a3670,0x12e);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8));
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xb1,0x6a,DAT_000a3670,0x133);
    return 0;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  r = EC_POINT_new(*(EC_GROUP **)(key + 4));
  if (r == (EC_POINT *)0x0) {
    BN_CTX_free(c);
    return 0;
  }
  iVar1 = EC_POINT_is_on_curve(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),c);
  if (iVar1 < 1) {
    ERR_put_error(0x10,0xb1,0x6b,DAT_000a3670,0x13e);
    iVar1 = 0;
    goto LAB_000a3576;
  }
  group = *(EC_GROUP **)(key + 4);
  if (*(int *)(group + 0xc) == 0) {
    ERR_put_error(0x10,0xb1,0x7a,DAT_000a3670,0x144);
    iVar1 = 0;
    goto LAB_000a3576;
  }
  iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,*(EC_POINT **)(key + 8),(BIGNUM *)(group + 8),c);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xb1,0x10,DAT_000a3670,0x148);
    iVar1 = 0;
    goto LAB_000a3576;
  }
  iVar1 = EC_POINT_is_at_infinity(*(EC_GROUP **)(key + 4),r);
  line = 0x14c;
  if (iVar1 == 0) {
LAB_000a35dc:
    iVar1 = 0;
    ERR_put_error(0x10,0xb1,0x82,DAT_000a3670,line);
  }
  else {
    if (*(BIGNUM **)(key + 0xc) != (BIGNUM *)0x0) {
      iVar1 = BN_cmp(*(BIGNUM **)(key + 0xc),(BIGNUM *)(group + 8));
      if (-1 < iVar1) {
        line = 0x155;
        goto LAB_000a35dc;
      }
      iVar1 = EC_POINT_mul(*(EC_GROUP **)(key + 4),r,*(BIGNUM **)(key + 0xc),(EC_POINT *)0x0,
                           (BIGNUM *)0x0,c);
      if (iVar1 == 0) {
        ERR_put_error(0x10,0xb1,0x10,DAT_000a3670,0x15a);
        iVar1 = 0;
        goto LAB_000a3576;
      }
      iVar1 = EC_POINT_cmp(*(EC_GROUP **)(key + 4),r,*(EC_POINT **)(key + 8),c);
      if (iVar1 != 0) {
        iVar1 = 0;
        ERR_put_error(0x10,0xb1,0x7b,DAT_000a3670,0x15e);
        goto LAB_000a3576;
      }
    }
    iVar1 = 1;
  }
LAB_000a3576:
  BN_CTX_free(c);
  EC_POINT_free(r);
  return iVar1;
}

