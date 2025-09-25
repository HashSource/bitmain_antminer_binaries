
void pkey_sm2_cleanup(int param_1)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(param_1 + 0x14);
  if (ptr != (undefined4 *)0x0) {
    EC_GROUP_free((EC_GROUP *)*ptr);
    CRYPTO_free((void *)ptr[2]);
    CRYPTO_free(ptr);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

