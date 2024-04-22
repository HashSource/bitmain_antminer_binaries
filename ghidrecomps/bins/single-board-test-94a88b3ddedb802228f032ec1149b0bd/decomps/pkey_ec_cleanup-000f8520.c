
void pkey_ec_cleanup(int param_1)

{
  EC_GROUP **ptr;
  
  ptr = *(EC_GROUP ***)(param_1 + 0x14);
  if (ptr != (EC_GROUP **)0x0) {
    if (*ptr != (EC_GROUP *)0x0) {
      EC_GROUP_free(*ptr);
    }
    if ((EC_KEY *)ptr[2] != (EC_KEY *)0x0) {
      EC_KEY_free((EC_KEY *)ptr[2]);
    }
    if (ptr[5] != (EC_GROUP *)0x0) {
      CRYPTO_free(ptr[5]);
    }
    CRYPTO_free(ptr);
    return;
  }
  return;
}

