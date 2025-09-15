
EC_KEY * EC_KEY_new_by_curve_name(int nid)

{
  EC_KEY *ptr;
  EC_GROUP *pEVar1;
  int iVar2;
  
  ptr = (EC_KEY *)CRYPTO_malloc(0x24,"ec_key.c",0x4b);
  if (ptr == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xb6,0x41,"ec_key.c",0x4d);
  }
  else {
    *(undefined4 *)ptr = 1;
    *(undefined4 *)(ptr + 0x18) = 1;
    *(undefined4 *)(ptr + 0x1c) = 0;
    *(undefined4 *)(ptr + 4) = 0;
    *(undefined4 *)(ptr + 8) = 0;
    *(undefined4 *)(ptr + 0xc) = 0;
    *(undefined4 *)(ptr + 0x10) = 0;
    *(undefined4 *)(ptr + 0x20) = 0;
    *(undefined4 *)(ptr + 0x14) = 4;
    pEVar1 = EC_GROUP_new_by_curve_name(nid);
    *(EC_GROUP **)(ptr + 4) = pEVar1;
    if (pEVar1 == (EC_GROUP *)0x0) {
      iVar2 = CRYPTO_add_lock((int *)(ptr + 0x18),-1,0x21,"ec_key.c",0x71);
      if (iVar2 < 1) {
        if (*(EC_GROUP **)(ptr + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_free(*(EC_GROUP **)(ptr + 4));
        }
        if (*(EC_POINT **)(ptr + 8) != (EC_POINT *)0x0) {
          EC_POINT_free(*(EC_POINT **)(ptr + 8));
        }
        if (*(BIGNUM **)(ptr + 0xc) != (BIGNUM *)0x0) {
          BN_clear_free(*(BIGNUM **)(ptr + 0xc));
        }
        EC_EX_DATA_free_all_data(ptr + 0x20);
        OPENSSL_cleanse(ptr,0x24);
        CRYPTO_free(ptr);
        ptr = (EC_KEY *)0x0;
      }
      else {
        ptr = (EC_KEY *)0x0;
      }
    }
  }
  return ptr;
}

