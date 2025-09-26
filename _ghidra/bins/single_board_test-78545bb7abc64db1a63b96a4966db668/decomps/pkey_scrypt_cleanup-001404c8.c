
void pkey_scrypt_cleanup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(param_1 + 0x14);
  CRYPTO_clear_free(ptr[2],ptr[3],"crypto/kdf/scrypt.c",0x54,param_4);
  CRYPTO_clear_free(*ptr,ptr[1],"crypto/kdf/scrypt.c",0x55);
  CRYPTO_free(ptr);
  return;
}

