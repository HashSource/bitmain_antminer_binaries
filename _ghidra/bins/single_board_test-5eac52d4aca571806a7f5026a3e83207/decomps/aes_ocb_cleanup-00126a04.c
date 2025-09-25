
undefined4 aes_ocb_cleanup(void)

{
  int iVar1;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  CRYPTO_ocb128_cleanup(iVar1 + 0x1f8);
  return 1;
}

