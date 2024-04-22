
EC_KEY * EC_KEY_dup(EC_KEY *src)

{
  undefined4 *dst;
  EC_KEY *pEVar1;
  int iVar2;
  
  dst = (undefined4 *)CRYPTO_malloc(0x24,DAT_000a33e0,0x4b);
  if (dst == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,DAT_000a33e0,0x4d);
  }
  else {
    *dst = 1;
    dst[6] = 1;
    dst[7] = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[8] = 0;
    dst[5] = 4;
    pEVar1 = EC_KEY_copy((EC_KEY *)dst,src);
    if (pEVar1 == (EC_KEY *)0x0) {
      iVar2 = CRYPTO_add_lock(dst + 6,-1,0x21,DAT_000a33e0,0x71);
      if (iVar2 < 1) {
        if ((EC_GROUP *)dst[1] != (EC_GROUP *)0x0) {
          EC_GROUP_free((EC_GROUP *)dst[1]);
        }
        if ((EC_POINT *)dst[2] != (EC_POINT *)0x0) {
          EC_POINT_free((EC_POINT *)dst[2]);
        }
        if ((BIGNUM *)dst[3] != (BIGNUM *)0x0) {
          BN_clear_free((BIGNUM *)dst[3]);
        }
        EC_EX_DATA_free_all_data(dst + 8);
        OPENSSL_cleanse(dst,0x24);
        CRYPTO_free(dst);
        dst = (undefined4 *)0x0;
      }
      else {
        dst = (undefined4 *)0x0;
      }
    }
  }
  return (EC_KEY *)dst;
}

