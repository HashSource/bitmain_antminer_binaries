
void EC_KEY_free(EC_KEY *key)

{
  int iVar1;
  
  if (key != (EC_KEY *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(key + 0x18),-1,0x21,DAT_000a3244,0x71);
    if (iVar1 < 1) {
      if (*(EC_GROUP **)(key + 4) != (EC_GROUP *)0x0) {
        EC_GROUP_free(*(EC_GROUP **)(key + 4));
      }
      if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
        EC_POINT_free(*(EC_POINT **)(key + 8));
      }
      if (*(BIGNUM **)(key + 0xc) != (BIGNUM *)0x0) {
        BN_clear_free(*(BIGNUM **)(key + 0xc));
      }
      EC_EX_DATA_free_all_data(key + 0x20);
      OPENSSL_cleanse(key,0x24);
      CRYPTO_free(key);
      return;
    }
  }
  return;
}

