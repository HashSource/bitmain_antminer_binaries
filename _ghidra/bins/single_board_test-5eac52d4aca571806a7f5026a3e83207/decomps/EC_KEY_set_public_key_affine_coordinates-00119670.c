
int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key,BIGNUM *x,BIGNUM *y)

{
  BN_CTX *ctx;
  EC_POINT *pub;
  BIGNUM *b;
  BIGNUM *b_00;
  int iVar1;
  
  if (((key == (EC_KEY *)0x0) || (*(int *)(key + 0xc) == 0)) ||
     (y == (BIGNUM *)0x0 || x == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xe5,0x43,"crypto/ec/ec_key.c",0x15c);
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_start(ctx);
  pub = EC_POINT_new(*(EC_GROUP **)(key + 0xc));
  if (pub != (EC_POINT *)0x0) {
    b = BN_CTX_get(ctx);
    b_00 = BN_CTX_get(ctx);
    if (((b_00 != (BIGNUM *)0x0) &&
        (iVar1 = EC_POINT_set_affine_coordinates(*(undefined4 *)(key + 0xc),pub,x,y,ctx), iVar1 != 0
        )) && (iVar1 = EC_POINT_get_affine_coordinates(*(undefined4 *)(key + 0xc),pub,b,b_00,ctx),
              iVar1 != 0)) {
      iVar1 = BN_cmp(x,b);
      if (((iVar1 == 0) && (iVar1 = BN_cmp(y,b_00), iVar1 == 0)) &&
         ((iVar1 = BN_cmp(x,*(BIGNUM **)(*(int *)(key + 0xc) + 0x28)), iVar1 < 0 &&
          (iVar1 = BN_cmp(y,*(BIGNUM **)(*(int *)(key + 0xc) + 0x28)), iVar1 < 0)))) {
        iVar1 = EC_KEY_set_public_key(key,pub);
        if (iVar1 != 0) {
          iVar1 = EC_KEY_check_key(key);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
          goto LAB_001196e0;
        }
      }
      else {
        ERR_put_error(0x10,0xe5,0x92,"crypto/ec/ec_key.c",0x17b);
      }
    }
  }
  iVar1 = 0;
LAB_001196e0:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(pub);
  return iVar1;
}

