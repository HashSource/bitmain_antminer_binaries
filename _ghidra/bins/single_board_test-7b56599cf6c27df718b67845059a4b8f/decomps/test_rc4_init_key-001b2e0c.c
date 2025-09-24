
undefined4 test_rc4_init_key(EVP_CIPHER_CTX *param_1,void *param_2)

{
  void *__dest;
  size_t __n;
  int iVar1;
  int len;
  uchar *data;
  
  fwrite("(TEST_ENG_OPENSSL_RC4) test_init_key() called\n",1,0x2e,stderr);
  __dest = (void *)EVP_CIPHER_CTX_get_cipher_data(param_1);
  __n = EVP_CIPHER_CTX_key_length(param_1);
  memcpy(__dest,param_2,__n);
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  len = EVP_CIPHER_CTX_key_length(param_1);
  data = (uchar *)EVP_CIPHER_CTX_get_cipher_data(param_1);
  RC4_set_key((RC4_KEY *)(iVar1 + 0x10),len,data);
  return 1;
}

