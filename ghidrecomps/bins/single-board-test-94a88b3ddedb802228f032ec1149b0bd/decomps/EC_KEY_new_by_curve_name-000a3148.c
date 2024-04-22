
EC_KEY * EC_KEY_new_by_curve_name(int nid)

{
  undefined4 *ptr;
  EC_GROUP *pEVar1;
  int iVar2;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x24,DAT_000a31e8,0x4b);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,DAT_000a31e8,0x4d);
  }
  else {
    *ptr = 1;
    ptr[6] = 1;
    ptr[7] = 0;
    ptr[1] = 0;
    ptr[2] = 0;
    ptr[3] = 0;
    ptr[4] = 0;
    ptr[8] = 0;
    ptr[5] = 4;
    pEVar1 = EC_GROUP_new_by_curve_name(nid);
    ptr[1] = pEVar1;
    if (pEVar1 == (EC_GROUP *)0x0) {
      iVar2 = CRYPTO_add_lock(ptr + 6,-1,0x21,DAT_000a31e8,0x71);
      if (iVar2 < 1) {
        if ((EC_GROUP *)ptr[1] != (EC_GROUP *)0x0) {
          EC_GROUP_free((EC_GROUP *)ptr[1]);
        }
        if ((EC_POINT *)ptr[2] != (EC_POINT *)0x0) {
          EC_POINT_free((EC_POINT *)ptr[2]);
        }
        if ((BIGNUM *)ptr[3] != (BIGNUM *)0x0) {
          BN_clear_free((BIGNUM *)ptr[3]);
        }
        EC_EX_DATA_free_all_data(ptr + 8);
        OPENSSL_cleanse(ptr,0x24);
        CRYPTO_free(ptr);
        ptr = (undefined4 *)0x0;
      }
      else {
        ptr = (undefined4 *)0x0;
      }
    }
  }
  return (EC_KEY *)ptr;
}

