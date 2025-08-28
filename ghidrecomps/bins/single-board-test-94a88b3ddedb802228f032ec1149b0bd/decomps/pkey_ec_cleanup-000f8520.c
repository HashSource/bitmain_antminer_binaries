
void pkey_ec_cleanup(int param_1)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(param_1 + 0x14);
  if (ptr != (undefined4 *)0x0) {
    if ((EC_GROUP *)*ptr != (EC_GROUP *)0x0) {
      EC_GROUP_free((EC_GROUP *)*ptr);
    }
    if ((EC_KEY *)ptr[2] != (EC_KEY *)0x0) {
      EC_KEY_free((EC_KEY *)ptr[2]);
    }
    if ((void *)ptr[5] != (void *)0x0) {
      CRYPTO_free((void *)ptr[5]);
    }
    CRYPTO_free(ptr);
    return;
  }
  return;
}

