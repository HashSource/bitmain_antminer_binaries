
EC_KEY * EC_KEY_dup(EC_KEY *src)

{
  EC_KEY *dst;
  EC_KEY *pEVar1;
  int iVar2;
  
  dst = (EC_KEY *)CRYPTO_malloc(0x24,"ec_key.c",0x4b);
  if (dst == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,"ec_key.c",0x4d);
  }
  else {
    *(undefined4 *)dst = 1;
    *(undefined4 *)(dst + 0x18) = 1;
    *(undefined4 *)(dst + 0x1c) = 0;
    *(undefined4 *)(dst + 4) = 0;
    *(undefined4 *)(dst + 8) = 0;
    *(undefined4 *)(dst + 0xc) = 0;
    *(undefined4 *)(dst + 0x10) = 0;
    *(undefined4 *)(dst + 0x20) = 0;
    *(undefined4 *)(dst + 0x14) = 4;
    pEVar1 = EC_KEY_copy(dst,src);
    if (pEVar1 == (EC_KEY *)0x0) {
      iVar2 = CRYPTO_add_lock((int *)(dst + 0x18),-1,0x21,"ec_key.c",0x71);
      if (iVar2 < 1) {
        if (*(EC_GROUP **)(dst + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_free(*(EC_GROUP **)(dst + 4));
        }
        if (*(EC_POINT **)(dst + 8) != (EC_POINT *)0x0) {
          EC_POINT_free(*(EC_POINT **)(dst + 8));
        }
        if (*(BIGNUM **)(dst + 0xc) != (BIGNUM *)0x0) {
          BN_clear_free(*(BIGNUM **)(dst + 0xc));
        }
        EC_EX_DATA_free_all_data(dst + 0x20);
        OPENSSL_cleanse(dst,0x24);
        CRYPTO_free(dst);
        dst = (EC_KEY *)0x0;
      }
      else {
        dst = (EC_KEY *)0x0;
      }
    }
  }
  return dst;
}

